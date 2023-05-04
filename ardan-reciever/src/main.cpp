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
#include "rtc.h"
#include "rtc_clk_common.h"
#include <string>

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
#define ENABLE_DEBUG                    false      // master debug message control
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
  .reciever_debugEnabled = true,
  .serial_debugEnabled = false,
  .scheduler_debugEnable = false,

  // debug data
  .recievedCount = 0,
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

  setup.serialActive = true;

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

  if (debugger.debugEnabled) {
    debugger.recievedCount++;
  }

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
  Serial.write((uint8_t *) &carData, sizeof(carData));

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
void PrintRecieverDebug_Better() {
  // spacer
  std::string text = "test";

  // driving data
  text += "--- Driving Data ---";

  text += "RTD: ";
  if (carData.drivingData.readyToDrive) {
    text += "Ready!";
  }
  else {
    text += "Not Ready :/";
  }

  text += " | ";

  text += "Inverter Enabled: ";
  if (carData.drivingData.enableInverter) {
    text += "Enabled";
  }
  else {
    text += "Disabled";
  }

  text += " | ";

  text += "Precharge State: " + std::to_string((int)carData.drivingData.prechargeState) + "\n";

  text += "IMD Fault: ";
  if (carData.drivingData.imdFault) {
    text += "Faulted";
  }
  else {
    text += "Cleared";
  }

  text += " | ";

  text += "BMS Fault: ";
  if (carData.drivingData.imdFault) {
    text += "Faulted\n";
  }
  else {
    text += "Cleared\n";
  }

  text += "Commanded Torque: " + std::to_string(carData.drivingData.commandedTorque) + "\n";

  text += "Drive Mode: " + std::to_string(carData.drivingData.driveMode) + "\n";

  text += "Speed (MPH): " + std::to_string(carData.drivingData.currentSpeed) + "\n";

  text += "Drive Direction: " + std::to_string(carData.drivingData.driveDirection) + "\n";

  // battery Status
  text += "\n --- Battery Status ---\n";

  text += "Bus Voltage: " + std::to_string(carData.batteryStatus.busVoltage) + "\n";

  text += "Rinehart Voltage: " + std::to_string(carData.batteryStatus.rinehartVoltage) + "\n";

  text += "Current: " + std::to_string(carData.batteryStatus.packCurrent) + "\n";

  text += "Pack 1 Temp: " + std::to_string(carData.batteryStatus.pack1Temp) + "\n";
  text += "Pack 2 Temp: " + std::to_string(carData.batteryStatus.pack2Temp) + "\n";
  text += "Cell Voltage: " + std::to_string(carData.batteryStatus.minCellVoltage) + "\n";
  text += "Cell Voltage: " + std::to_string(carData.batteryStatus.maxCellVoltage) + "\n";

  // Sensors
  text += "\n--- Sensor Inputs ---\n";
  text += "FR Wheel Speed: " + std::to_string(carData.sensors.wheelSpeedFR) + "\n";
  text += "FL Wheel Speed: " + std::to_string(carData.sensors.wheelSpeedFL) + "\n";
  text += "BR Wheel Speed: " + std::to_string(carData.sensors.wheelSpeedBR) + "\n";
  text += "BL Wheel Speed: " + std::to_string(carData.sensors.wheelSpeedBL) + "\n";

  text += "FR Wheel Height: " + std::to_string(carData.sensors.wheelHeightFR) + "\n";
  text += "FL Wheel Height: " + std::to_string(carData.sensors.wheelHeightFL) + "\n";
  text += "BR Wheel Height: " + std::to_string(carData.sensors.wheelHeightBR) + "\n";
  text += "BL Wheel Height: " + std::to_string(carData.sensors.wheelHeightBL) + "\n";

  text += "Steering Wheel Angle: " + std::to_string(carData.sensors.steeringWheelAngle) + "\n";

  text += "Vicore Temp: " + std::to_string(carData.sensors.vicoreTemp) + "\n";
  text += "Pump In Temp: " + std::to_string(carData.sensors.pumpTempIn) + "\n";
  text += "Pump Out Temp: " + std::to_string(carData.sensors.pumpTempOut) + "\n";

  // Inputs  
  text += "\n--- Inputs ---\n";
  text += "Pedal 0: " + std::to_string(carData.inputs.pedal0);
  text += " | ";
  text += "Pedal 1: " + std::to_string(carData.inputs.pedal1) + "\n";

  text += "Brake Front: ", std::to_string(carData.inputs.brakeFront);
  text += " | ";
  text += "Brake Rear: " + std::to_string(carData.inputs.brakeRear) + "\n";

  text += "Coast Regen: " + std::to_string(carData.inputs.coastRegen);
  text += " | ";
  text += "Brake Regen: " + std::to_string(carData.inputs.brakeRegen) + "\n";

  // Outputs
  text += "\n--- Outputs ---\n";
  text += "Buzzer: ";
  if (carData.outputs.buzzerActive) {
    text += "Active";
  }
  else {
    text += "Inactive";
  }
  text += " | ";
  text += "Buzzer Counter: " + std::to_string(carData.outputs.buzzerCounter) + "\n";

  text += "Brake Light: ";
  if (carData.outputs.brakeLight) {
    text += "On\n";
  }
  else {
    text += "Off\n";
  }

  text += "Fans: ";
  if (carData.outputs.fansActive) {
    text += "Running\n";
  }
  else {
    text += "Off\n";
  }

  text += "Pump: ";
  if (carData.outputs.pumpActive) {
    text += "Running\n";
  }
  else {
    text += "Off\n";
  }

  // print it
  Serial.printf("%s\r", text.c_str());
}


/**
 * @brief 
 * 
 */
void PrintRecieverDebug() {
  // spacer
  std::string text = "";
  short newLines = 50;
  for (int i = 0; i < newLines; ++i) {
    Serial.printf("\n");
  }

  // driving data
  Serial.printf("--- Driving Data ---\n");

  Serial.printf("RTD: %s | Inverter Enable: %s | Precharge State: %d\n", carData.drivingData.readyToDrive ? "Ready!" : "Not Ready :(", 
  carData.drivingData.enableInverter ? "Enabled" : "Disabled", (int)carData.drivingData.prechargeState);

  Serial.printf("IMD Fault: %s | BMS Fault: %s\n", carData.drivingData.imdFault ? "Faulted" : "Cleared", carData.drivingData.bmsFault ? "Faulted" : "Cleared");

  Serial.printf("Commanded Torque: %d | Drive Mode: %d | Speed (MPH): %f | Direction: %d\n", carData.drivingData.commandedTorque, carData.drivingData.driveMode, carData.drivingData.currentSpeed, carData.drivingData.driveDirection);

  // battery Status
  Serial.printf("\n --- Battery Status ---\n");
  Serial.printf("Bus Voltage: %f\n", carData.batteryStatus.busVoltage);
  Serial.printf("Rinehart Voltage: %f\n", carData.batteryStatus.rinehartVoltage); 
  Serial.printf("Current: %f\n", carData.batteryStatus.packCurrent);
  Serial.printf("Pack 1 Temp: %f\n", carData.batteryStatus.pack1Temp);
  Serial.printf("Pack 2 Temp: %f\n", carData.batteryStatus.pack2Temp);
  Serial.printf("Cell Voltage%f\n", carData.batteryStatus.minCellVoltage);
  Serial.printf("Cell Voltage%f\n", carData.batteryStatus.maxCellVoltage);

  // Sensors
  Serial.printf("\n--- Sensor Inputs ---\n");
  printf("FR Wheel Speed: %f\n", carData.sensors.wheelSpeedFR);
  printf("FL Wheel Speed: %f\n", carData.sensors.wheelSpeedFL);
  printf("BR Wheel Speed: %f\n", carData.sensors.wheelSpeedBR);
  printf("BL Wheel Speed: %f\n", carData.sensors.wheelSpeedBL);

  printf("FR Wheel Height: %f\n", carData.sensors.wheelHeightFR);
  printf("FL Wheel Height: %f\n", carData.sensors.wheelHeightFL);
  printf("BR Wheel Height: %f\n", carData.sensors.wheelHeightBR);
  printf("BL Wheel Height: %f\n", carData.sensors.wheelHeightBL);

  printf("Steering Wheel Angle: %f\n", carData.sensors.steeringWheelAngle);

  printf("Vicore Temp: %f\n", carData.sensors.vicoreTemp);
  printf("Pump In Temp: %f\n", carData.sensors.pumpTempIn);
  printf("Pump Out Temp: %f\n", carData.sensors.pumpTempOut);

  // Inputs  
  Serial.printf("\n--- Inputs ---\n");
  printf("Pedal 0: %d | Pedal 1: %d\n", carData.inputs.pedal0, carData.inputs.pedal1);
  printf("Brake 0: %d | Brake 1: %d\n", carData.inputs.brakeFront, carData.inputs.brakeRear);
  printf("Coast Regen: %d | Brake Regen: %d\n", carData.inputs.coastRegen, carData.inputs.brakeRegen);

  // Outputs
  Serial.printf("\n--- Outputs ---\n");
  printf("Buzzer: %s | Buzzer Counter: %d\n", carData.outputs.buzzerActive ? "Active" : "Inactive", carData.outputs.buzzerCounter);
  printf("Brake Light: %s\n", carData.outputs.brakeLight ? "On" : "Off");
  printf("Fans: %s\n", carData.outputs.fansActive ? "Running" : "Off");
  printf("Pump: %s\n", carData.outputs.pumpActive ? "Running" : "Off");
}


/**
 * @brief manages toggle-able debug settings
 * 
 */
void PrintDebug() {
  // Reciever
  if (debugger.reciever_debugEnabled) {
    PrintRecieverDebug();
    // Serial.printf("count: %d", debugger.recievedCount);
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