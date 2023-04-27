/**
 * @file main.cpp
 * @author dominic gasperini
 * @brief ardan reciever
 * @version 1.0
 * @date 2023-04-27
 * 
 * @copyright Copyright (c) 2023
 * 
 * @ref https://espressif-docs.readthedocs-hosted.com/projects/arduino-esp32/en/latest/libraries.html#apis
 */


/*
===============================================================================================
                                    Includes 
===============================================================================================
*/


#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>
#include <esp_wifi.h>
#include "driver/can.h"
#include "rtc.h"
#include "rtc_clk_common.h"

#include <data_types.h>
#include <pin_config.h>


/*
===============================================================================================
                                    Definitions
===============================================================================================
*/


// ESP-NOW
#define ARDAN_ESP_NOW_ADDRESS           {0xC4, 0xDE, 0xE2, 0xC0, 0x75, 0x83}

// tasks & timers
#define WRITE_SERIAL_INTERVAL           200000      // 0.2 seconds in microseconds
#define TASK_STACK_SIZE                 4096        // in bytes

// debug
#define ENABLE_DEBUG                    true       // master debug message control
#if ENABLE_DEBUG
  #define MAIN_LOOP_DELAY               1000        // delay in main loop
#else
  #define MAIN_LOOP_DELAY               1
#endif


/*
===============================================================================================
                                  Global Variables
===============================================================================================
*/


/**
 * @brief debugger structure used for organizing debug information
 * 
 */
Debugger debugger = {
  // debug toggle
  .debugEnabled = ENABLE_DEBUG,
  .reciever_debugEnabled = false,
  .serial_debugEnabled = false,
  .scheduler_debugEnable = true,

  // debug data
  .recievedMessage = {},

  // scheduler data
  .serialTaskCount = 0,
};


/**
 * @brief the dataframe that describes the entire state of the car
 * 
 */
CarData carData = {
  // driving data
  .drivingData = {
    .readyToDrive = false,
    .enableInverter = false,
    .prechargeState = PRECHARGE_OFF,

    .imdFault = true,
    .bmsFault = true,

    .commandedTorque = 0,
    .currentSpeed = 0.0f,
    .driveDirection = false,
    .driveMode = ECO, 
  },

  // Battery Status
  .batteryStatus = {
    .batteryChargeState = 0,
    .busVoltage = 0,
    .rinehartVoltage = 0,
    .pack1Temp = 0.0f,
    .pack2Temp = 0.0f,
    .packCurrent = 0.0f,
    .minCellVoltage = 0.0f,
    .maxCellVoltage = 0.0f,
  },

  // Sensors
  .sensors = {
    .rpmCounterFR = 0,
    .rpmCounterFL = 0,
    .rpmCounterBR = 0,
    .rpmCounterBL = 0,
    .rpmTimeFR = 0,
    .rpmTimeFL = 0,
    .rpmTimeBR = 0,
    .rpmTimeBL = 0,

    .wheelSpeedFR = 0.0f,
    .wheelSpeedFL = 0.0f,
    .wheelSpeedBR = 0.0f,
    .wheelSpeedBL = 0.0f,

    .wheelHeightFR = 0.0f,
    .wheelHeightFL = 0.0f,
    .wheelHeightBR = 0.0f,
    .wheelHeightBL = 0.0f,

    .steeringWheelAngle = 0,

    .vicoreTemp = 0.0f,
    .pumpTempIn = 0.0f,
    .pumpTempOut = 0.0f,
  },

  // Inputs
  .inputs = {
    .pedal0 = 0,
    .pedal1 = 0,
    .brakeFront = 0,
    .brakeRear = 0,
    .brakeRegen = 0,
    .coastRegen = 0,
  },

  // Outputs
  .outputs = {
    .buzzerActive = false,
    .buzzerCounter = 0,
    .brakeLight = false,
    .fansActive = false,
    .pumpActive = false,
  }
};


// Hardware Timers
hw_timer_t *timer1 = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;


/*
===============================================================================================
                                    Function Declarations 
===============================================================================================
*/


// callbacks
void SerialCallback();

// tasks
void WriteSerialTask(void* pvParameters);

// ISRs
void ARDANDataReceived(const uint8_t* mac, const uint8_t* incomingData, int length);


/*
===============================================================================================
                                            Setup 
===============================================================================================
*/


void setup() {
  // set power configuration
  esp_pm_configure(&power_configuration);

  if (debugger.debugEnabled) {
    // delay startup by 3 seconds
    vTaskDelay(3000);
  }

  // -------------------------- initialize serial connection ------------------------ //
  Serial.begin(9600);
  Serial.printf("\n\n|--- STARTING SETUP ---|\n\n");

  // setup managment struct
  struct setup
  {
    bool serialActive = false;
    bool ardanActive = false;
  };
  setup setup;

  // --------------------------------------------------------------------------- //

  // -------------------------- initialize serial connection ------------------------ //

  // ARDAN updates 4 times a second for a total of 8192 bits per second
  Serial2.begin(9600);  
  if (Serial2) {
    setup.serialActive = true;
  }

  // --------------------------------------------------------------------------- //

  // -------------------------- initialize ESP-NOW  ---------------------------- //
  // init wifi and config
  WiFi.enableLongRange(true);
  if (WiFi.mode(WIFI_STA)) {
    Serial.printf("WIFI INIT [ SUCCESS ]\n");

    // set custom mac address
    const uint8_t ardanAddress[6] = ARDAN_ESP_NOW_ADDRESS;
    if (esp_wifi_set_mac(WIFI_IF_STA, ardanAddress) == ESP_OK) {
      Serial.printf("WIFI SET MAC [ SUCCESS ]\n");
    
      esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);
      Serial.print("WIFI MAC: "); Serial.println(WiFi.macAddress());
      Serial.print("WIFI CHANNEL: "); Serial.println(WiFi.channel());

      if (esp_now_init() == ESP_OK) {
        Serial.printf("ESP-NOW INIT [ SUCCESS ]\n");

        if (esp_now_register_recv_cb(ARDANDataReceived) == ESP_OK) {
          Serial.printf("ESP-NOW CALLBACK INIT [ SUCCESS ]\n");

          setup.ardanActive = true;
        }
        else {
          Serial.printf("ESP-NOW CALLBACK INIT [ FAILED ]\n");
        }
      }

      else {
        Serial.printf("ESP-NOW INIT [ FAILED ]\n");
      }
    }
    else {
      Serial.printf("WIFI SET MAC [ FAILED ]\n");
    }
  }

  else {
    Serial.printf("WIFI INIT [ FAILED ]\n");
  }

  // ------------------------------------------------------------------------ //


  // ---------------------- initialize timer interrupts --------------------- //
  // timer 1 - Read Sensors 
  timer1 = timerBegin(0, 80, true);
  timerAttachInterrupt(timer1, &SerialCallback, true);
  timerAlarmWrite(timer1, WRITE_SERIAL_INTERVAL, true);

  // start timers
  if (setup.serialActive && setup.ardanActive)
    timerAlarmEnable(timer1);
  // ----------------------------------------------------------------------------------------- //


  // ------------------------------- Scheduler & Task Status --------------------------------- //
  Serial.printf("SERIAL TASK STATUS: %s\n", timerAlarmEnabled(timer1) ? "RUNNING" : "DISABLED");
  
  // scheduler status
  if (xTaskGetSchedulerState() == 2) {
    Serial.printf("\nScheduler Status: RUNNING\n");

    // clock frequency
    rtc_cpu_freq_config_t clock_config;
    rtc_clk_cpu_freq_get_config(&clock_config);
    Serial.printf("CPU Frequency: %dMHz\n", clock_config.freq_mhz);
  }
  else {
    Serial.printf("\nScheduler STATUS: FAILED\nHALTING OPERATIONS");
    while (1) {};
  }
  Serial.printf("\n\n|--- END SETUP ---|\n\n");
  // ---------------------------------------------------------------------------------------- //
}


/*
===============================================================================================
                                    Callback Functions
===============================================================================================
*/


/**
 * @brief callback function for writing to the serial bus
 * 
 * @param args arguments to be passed to the task
 */
void SerialCallback() 
{
  portENTER_CRITICAL_ISR(&timerMux);

  static uint8_t ucParameterToPass;
  TaskHandle_t xHandle = NULL;
  xTaskCreate(WriteSerialTask, "Write-To-Serial-Bus", TASK_STACK_SIZE, &ucParameterToPass, tskIDLE_PRIORITY, &xHandle);
  
  portEXIT_CRITICAL_ISR(&timerMux);

  return;
}


/**
 * @brief callback function for copying over ardan data
 * 
 * @param args arguments to be passed to the task
 */
void ARDANDataReceived(const uint8_t* mac, const uint8_t* incomingData, int length)
{
  portENTER_CRITICAL_ISR(&timerMux);

  // copy data to the wcbData struct 
  memcpy((uint8_t *) &carData, incomingData, sizeof(carData));

  portEXIT_CRITICAL_ISR(&timerMux);
  
  return;
}


/*
===============================================================================================
                                FreeRTOS Task Functions
===============================================================================================
*/


/**
 * @brief reads sensors and updates car data 
 * 
 * @param pvParameters parameters passed to task
 */
void WriteSerialTask(void* pvParameters)
{
  // write message to bus
  Serial2.write((uint8_t *) &carData, sizeof(carData));

  // debugging
  if (debugger.debugEnabled) {
    debugger.serialMessage = carData;
    debugger.serialTaskCount++;
  }

  // end task
  vTaskDelete(NULL);
}


/*
===============================================================================================
                                    Main Loop
===============================================================================================
*/


/**
 * @brief 
 * 
 */
void loop()
{
  // everything is managed by RTOS, so nothing really happens here!
  vTaskDelay(MAIN_LOOP_DELAY);    // prevent watchdog from getting upset

  // debugging
  if (debugger.debugEnabled) {
    PrintDebug();
  }
}


/* 
===============================================================================================
                                    DEBUG FUNCTIONS
================================================================================================
*/


/**
 * @brief 
 * 
 */
void PrintSerialDebug() {

}


/**
 * @brief 
 * 
 */
void PrintRecieverDebug() {

}


/**
 * @brief manages toggle-able debug settings
 * 
 */
void PrintDebug() {
  // Reciever
  if (debugger.reciever_debugEnabled) {
    PrintRecieverDebug();
  }

  // Serial
  if (debugger.serial_debugEnabled) {
    PrintSerialDebug();
  }

  // Scheduler
  if (debugger.scheduler_debugEnable) {
    Serial.printf("serial: %d \n", debugger.serialTaskCount);
  }
}