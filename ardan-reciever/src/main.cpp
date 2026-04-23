/**
 * @file main.cpp
 * @author dominic gasperini
 * @brief ardan reciever
 * @version 2.0
 * @date 2023-02-25
 *
 * @ref https://espressif-docs.readthedocs-hosted.com/projects/arduino-esp32/en/latest/libraries.html#apis      (api and hal docs)
 * @ref https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/_images/ESP32-S3_DevKitC-1_pinlayout.jpg  (pinout & overview)
 * @ref https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/system/freertos_idf.html      (FreeRTOS for ESP32 docs)
 * @ref https://github.com/sandeepmistry/arduino-LoRa?tab=readme-ov-file                                        (LoRa docs)
 */

/*
===============================================================================================
                                    Includes
===============================================================================================
*/

#include <Arduino.h>
#include "rtc.h"
#include "rtc_clk_common.h"
#include <string>
#include <vector>
#include <esp_now.h>
#include <WiFi.h>
#include <esp_wifi.h>

#include "Data/GpioData.h"
#include "Data/TwaiData.h"
#include "Data/ExecutiveData.h"
#include <Data/DataLogger.h>

#include <data_types.h>
#include <pin_config.h>

/*
===============================================================================================
                                    Definitions
===============================================================================================
*/

// esp now
#define ESP_NOW_TRACTIVE_ADDRESS     {0xC4, 0xDE, 0xE2, 0xC0, 0x75, 0x80}
#define ESP_NOW_TELEMETRY_ADDRESS    {0xC4, 0xDE, 0xE2, 0xC0, 0x75, 0x81}
#define ESPNOW_MAX_PAYLOAD_LEN 250

// tasks
#define SERIAL_REFRESH_RATE 100 // measured in ticks (RTOS ticks interrupt at 1 kHz)
#define ARDAN_REFRESH_RATE 20
#define DEBUG_REFRESH_RATE 1000     // measured in ticks (RTOS ticks interrupt at 1 kHz)

#define TASK_STACK_SIZE 20000 // in bytes

// debug
#define ENABLE_DEBUG false // master debug message control

/*
===============================================================================================
                                    Function Declarations
===============================================================================================
*/

// tasks
void SerialTask(void *pvParameters);
void ArdanTask(void *pvParameters);
void DebugTask(void *pvParameters);

// helpers
void TelemetryDataReceived(const uint8_t *mac, const uint8_t *data, int len);

void PrintSchedulerDebug();
void PrintRecieverDebug();

ExecutiveSnapshotType MakeExecutiveSnapshot(ExecutiveData *data);
GpioSnapshotType MakeGpioSnapshot(GpioData *data);
TwaiSnapshotType MakeTwaiSnapshot(TwaiData *data);

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
    .serialWriteTaskCount = 0,
    .serialWritePreviousTaskCount = 0,
    .ardanReadTaskCount = 0,
    .ardanReadPreviousTaskCount = 0,
};

// esp now
esp_now_peer_info_t tractiveInfo = {
  .peer_addr = ESP_NOW_TRACTIVE_ADDRESS,
  .channel = 1,
  .ifidx = WIFI_IF_STA,
  .encrypt = false,
};

// data
ExecutiveData *g_executiveData = new ExecutiveData();
GpioData *g_gpioData = new GpioData();
TwaiData *g_twaiData = new TwaiData(); 


CarData g_carData = {
      .executive = MakeExecutiveSnapshot(g_executiveData),
      .gpio = MakeGpioSnapshot(g_gpioData),
      .twai = MakeTwaiSnapshot(g_twaiData),
    };

int g_counter = 0;

// RTOS Task Handles
TaskHandle_t xHandleSerialWrite = NULL;
TaskHandle_t xHandleArdanRead = NULL;
TaskHandle_t xHandleDebug = NULL;


/*
===============================================================================================
                                            Setup
===============================================================================================
*/

void setup()
{
  if (debugger.debugEnabled)
  {
    // delay startup by 3 seconds
    vTaskDelay(3000);
  }

  // setup managment struct
  struct setup
  {
    bool serialActive = false;
    bool tractiveActive = false;
  };
  setup setup;

  // -------------------------- initialize serial connection ------------------------ //
  Serial.begin(9600);
  Serial.printf("\n\n|--- STARTING SETUP ---|\n\n");
  setup.serialActive = true;
  // --------------------------------------------------------------------------- //

  // -------------------------- initialize serial connection ------------------------ //

  // --------------------------------------------------------------------------- //

  // -------------------------- initialize LoRa  ---------------------------- //
  Serial.printf("\ntelemetry:\n");

  // init wifi and config
  if (WiFi.mode(WIFI_STA)) {
    Serial.printf("\twifi init [ success ]\n");

    // set custom mac address
    const uint8_t telemetryAddress[6] = ESP_NOW_TELEMETRY_ADDRESS;
    if (esp_wifi_set_mac(WIFI_IF_STA, telemetryAddress) == ESP_OK) {
      Serial.printf("\twifi set mac [ success ]\n");
    
      esp_wifi_set_channel(1, WIFI_SECOND_CHAN_NONE);
      Serial.print("\tmac: "); Serial.println(WiFi.macAddress());
      Serial.print("\tchannel: "); Serial.println(WiFi.channel());

      if (esp_now_init() == ESP_OK) {
        Serial.printf("\tesp-now init [ success ]\n");

        // add peers
        esp_err_t tractiveResult = esp_now_add_peer(&tractiveInfo);

        if (tractiveResult == ESP_OK) {
          Serial.printf("\tadd peers [ success ]\n");

          esp_now_register_recv_cb(TelemetryDataReceived);
          setup.tractiveActive = true;
        }
        else {
          Serial.printf("\tadd peers [ failed ]\n");
        }
      }

      else {
        Serial.printf("\tesp-now init [ failed ]\n");
      }
    }
    else {
      Serial.printf("\twifi set mac [ failed ]\n");
    }
  }

  else {
    Serial.printf("\twifi init [ failed ]\n");
  }
  // ------------------------------------------------------------------------ //

  // ------------------------------- Scheduler & Task Status --------------------------------- //
  // task setup status
  Serial.printf("\nTask Setup Status:\n");
  Serial.printf("SERIAL TASK SETUP: %s\n", setup.serialActive ? "COMPLETE" : "FAILED");
  Serial.printf("ARDAN TASK SETUP: %s\n", setup.tractiveActive ? "COMPLETE" : "FAILED");

  // start tasks
  if (setup.serialActive)
  {
    xTaskCreatePinnedToCore(SerialTask, "Serial", TASK_STACK_SIZE, NULL, tskIDLE_PRIORITY, &xHandleSerialWrite, 0);
  }

  if (setup.tractiveActive)
  {
    xTaskCreatePinnedToCore(ArdanTask, "ardan", TASK_STACK_SIZE, NULL, tskIDLE_PRIORITY, &xHandleArdanRead, 1);
  }

  if (debugger.debugEnabled)
  {
    xTaskCreate(DebugTask, "Debugger", TASK_STACK_SIZE, NULL, tskIDLE_PRIORITY, &xHandleDebug);
  }

  // scheduler status
  if (xTaskGetSchedulerState() == taskSCHEDULER_RUNNING)
  {
    Serial.printf("\nscheduler status: running\n");
  }
  else
  {
    Serial.printf("\nscheduler status: FAILED\nHALTING OPERATIONS");
    while (1)
    {
    };
  }
  Serial.printf("\n|--- init complete ---|\n\n");
  // ---------------------------------------------------------------------------------------- //
}

/*
===============================================================================================
                                FreeRTOS Task Functions
===============================================================================================
*/

/**
 * @brief reads and writes i/o
 * @param pvParameters parameters passed to task
 */
void SerialTask(void *pvParameters)
{
  // inits
  const TickType_t xFrequency = pdMS_TO_TICKS(SERIAL_REFRESH_RATE);
  TickType_t taskLastWakeTick = xTaskGetTickCount();

  for (;;)
  {
    // limit task refresh rate
    vTaskDelayUntil(&taskLastWakeTick, xFrequency);

    // write message to bus
    Serial.write((uint8_t *)&g_carData, sizeof(g_carData));
    Serial.write("\r");
    // g_counter++;

    // datalogger
    if (debugger.debugEnabled)
    {
      debugger.serialWriteTaskCount++;
    }
  }
}

/**
 * @brief reads and writes i/o
 * @param pvParameters parameters passed to task
 */
void ArdanTask(void *pvParameters)
{
  // inits
  const TickType_t xFrequency = pdMS_TO_TICKS(ARDAN_REFRESH_RATE);
  TickType_t taskLastWakeTick = xTaskGetTickCount();

  for (;;)
  {
    // limit task refresh rate
    vTaskDelayUntil(&taskLastWakeTick, xFrequency);

    // read esp now

    // // datalogger
    // if (g_datalogger->getDebugEnabled())
    // {
    //   g_datalogger->setExecutiveTaskCount(g_datalogger->getExecutiveTaskCount() + 1);
    //   g_datalogger->setExecutiveData(g_executiveData);
    // }
  }
}

/**
 * @brief manages toggle-able debug settings & scheduler debugging
 */
void DebugTask(void *pvParameters)
{
  for (;;)
  {
    // serial
    if (debugger.serial_debugEnabled)
    {
      // PrintSerialDebug();
    }

    // ardan
    if (debugger.reciever_debugEnabled)
    {
      PrintRecieverDebug();
    }

    // Scheduler
    if (debugger.scheduler_debugEnable)
    {
      PrintSchedulerDebug();
    }

    // limit refresh rate
    vTaskDelay(DEBUG_REFRESH_RATE);
  }
}

/*
===============================================================================================
                                    Main Loop
===============================================================================================
*/

/**
 * @brief main loop
 *
 */
void loop()
{
  // everything is managed by RTOS, so nothing really happens here!
  vTaskDelay(1); // prevent watchdog from getting upset
}

/*
===============================================================================================
                                    Helper Functions
===============================================================================================
*/

/**
 * 
 */
void TelemetryDataReceived(const uint8_t *mac, const uint8_t *incomingData, int len)
{
  if (!mac || !incomingData || len <= 0) return;
  
  CarDataType *carData = {};
  
  memcpy(&incomingData, &carData, len);

  g_carData.executive = carData->executive;
  g_carData.gpio = carData->gpio;
  g_carData.twai = carData->twai;
}

/**
 * 
 */
ExecutiveSnapshotType MakeExecutiveSnapshot(ExecutiveData *data)
{
    ExecutiveSnapshotType s{};
    s.systemState        = data->getSystemState();
    s.previousSystemState= data->getPreviousSystemState();
    s.readyToDrive       = data->getReadyToDrive();
    s.enableInverter     = data->getEnableInverter();
    s.driveDirection     = data->getDriveDirection();
    s.driveMode          = data->getDriveMode();
    s.torqueCommand      = data->getTorqueCommand();
    s.enableVicore       = data->getEnableVicore();
    s.velocity           = data->getVelocity();
    s.coastRegen         = data->getCoastRegen();
    s.brakeRegen         = data->getBrakeRegen();
    return s;
}

/**
 * 
 */
GpioSnapshotType MakeGpioSnapshot(GpioData *data)
{
    GpioSnapshotType s{};

    // Faults
    s.imdFault  = data->getImdFault();
    s.bmsFault  = data->getBmsFault();
    s.vicoreFault = data->getVicoreFault();

    // Cooling temperatures
    s.coolingTempIn  = data->getCoolingTempIn();
    s.coolingTempOut = data->getCoolingTempOut();

    // Front wheels
    s.frontWheelsSpeed     = data->getFrontWheelsSpeed();
    s.frontWheelSpeedCount = data->getFrontWheelSpeedCount();
    s.frontWheelSpeedTime  = data->getFrontWheelSpeedTime();

    // Back right wheel
    s.brWheelSpeed     = data->getBrWheelSpeed();
    s.brWheelSpeedCount= data->getBrWheelSpeedCount();
    s.brWheelSpeedTime = data->getBrWheelSpeedTime();

    // Back left wheel
    s.blWheelSpeed     = data->getBlWheelSpeed();
    s.blWheelSpeedCount= data->getBlWheelSpeedCount();
    s.blWheelSpeedTime = data->getBlWheelSpeedTime();

    // Inputs
    s.pedal0     = data->getPedal0();
    s.pedal1     = data->getPedal1();
    s.frontBrake = data->getFrontBrake();
    s.rearBrake  = data->getRearBrake();

    // Outputs
    s.vicoreEnable               = data->getVicoreEnable();
    s.brakeLightEnable           = data->getBrakeLightEnable();
    s.fansEnable                 = data->getFansEnable();
    s.buzzerEnable               = data->getBuzzerEnable();
    s.prechargeCompleteLedEnable = data->getprechargeCompleteLedEnable();

    return s;
}


TwaiSnapshotType MakeTwaiSnapshot(TwaiData *data)
{
    TwaiSnapshotType s{};
    s.rinehartRelayWord      = data->getRinehartRelayWord();
    s.rinehartTractiveWord   = data->getRinehartTractiveWord();
    s.rinehartBusVoltage     = data->getRinehartBusVoltage();
    s.bmsPackCurrent         = data->getBmsPackCurrent();
    s.bmsBusVoltage          = data->getBmsBusVoltage();
    s.bmsBatteryCharge       = data->getBmsBatteryCharge();
    return s;
}


/*
===============================================================================================
                                    Debug Functions
================================================================================================
*/

/**
 * @brief
 *
 */
void PrintRecieverDebug_v3()
{
  // // spacer
  // std::string text = "";
  // short newLines = 50;
  // for (int i = 0; i < newLines; ++i)
  // {
  //   Serial.printf("\n");
  // }

  // // driving data
  // Serial.printf("--- Driving Data ---\n");

  // Serial.printf("RTD: %s | Inverter Enable: %s | Precharge State: %d\n", carData.drivingData.readyToDrive ? "Ready!" : "Not Ready :(",
  //               carData.drivingData.enableInverter ? "Enabled" : "Disabled", (int)carData.drivingData.prechargeState);

  // Serial.printf("IMD Fault: %s | BMS Fault: %s\n", carData.drivingData.imdFault ? "Faulted" : "Cleared", carData.drivingData.bmsFault ? "Faulted" : "Cleared");

  // Serial.printf("Commanded Torque: %d | Drive Mode: %d | Speed (MPH): %f | Direction: %d\n", carData.drivingData.commandedTorque, carData.drivingData.driveMode, carData.drivingData.currentSpeed, carData.drivingData.driveDirection);

  // // battery Status
  // Serial.printf("\n --- Battery Status ---\n");
  // Serial.printf("SOC: %f\n", carData.batteryStatus.batteryChargeState);
  // Serial.printf("Bus Voltage: %f\n", carData.batteryStatus.busVoltage);
  // Serial.printf("Rinehart Voltage: %f\n", carData.batteryStatus.rinehartVoltage);
  // Serial.printf("Current: %f\n", carData.batteryStatus.packCurrent);
  // Serial.printf("Pack 1 Temp: %f\n", carData.batteryStatus.pack1Temp);
  // Serial.printf("Pack 2 Temp: %f\n", carData.batteryStatus.pack2Temp);
  // Serial.printf("Cell Voltage: %f\n", carData.batteryStatus.minCellVoltage);
  // Serial.printf("Cell Voltage: %f\n", carData.batteryStatus.maxCellVoltage);

  // // Sensors
  // Serial.printf("\n--- Sensor Inputs ---\n");
  // printf("FR Wheel Speed: %f\n", carData.sensors.wheelSpeedFR);
  // printf("FL Wheel Speed: %f\n", carData.sensors.wheelSpeedFL);
  // printf("BR Wheel Speed: %f\n", carData.sensors.wheelSpeedBR);
  // printf("BL Wheel Speed: %f\n", carData.sensors.wheelSpeedBL);

  // printf("FR Wheel Height: %f\n", carData.sensors.wheelHeightFR);
  // printf("FL Wheel Height: %f\n", carData.sensors.wheelHeightFL);
  // printf("BR Wheel Height: %f\n", carData.sensors.wheelHeightBR);
  // printf("BL Wheel Height: %f\n", carData.sensors.wheelHeightBL);

  // printf("Steering Wheel Angle: %f\n", carData.sensors.steeringWheelAngle);

  // printf("Vicore Temp: %f\n", carData.sensors.vicoreTemp);
  // printf("Pump In Temp: %f\n", carData.sensors.pumpTempIn);
  // printf("Pump Out Temp: %f\n", carData.sensors.pumpTempOut);

  // // Inputs
  // Serial.printf("\n--- Inputs ---\n");
  // printf("Pedal 0: %d | Pedal 1: %d\n", carData.inputs.pedal0, carData.inputs.pedal1);
  // printf("Brake 0: %d | Brake 1: %d\n", carData.inputs.brakeFront, carData.inputs.brakeRear);
  // printf("Coast Regen: %d | Brake Regen: %d\n", carData.inputs.coastRegen, carData.inputs.brakeRegen);

  // // Outputs
  // Serial.printf("\n--- Outputs ---\n");
  // printf("Buzzer: %s | Buzzer Counter: %d\n", carData.outputs.buzzerActive ? "Active" : "Inactive", carData.outputs.buzzerCounter);
  // printf("Brake Light: %s\n", carData.outputs.brakeLight ? "On" : "Off");
  // printf("Fans: %s\n", carData.outputs.fansActive ? "Running" : "Off");
  // printf("Pump: %s\n", carData.outputs.pumpActive ? "Running" : "Off");
}

/**
 * @brief
 *
 */
void PrintRecieverDebug_Better()
{
  // // spacer
  // std::string text = "test";

  // // driving data
  // text += "--- Driving Data ---";

  // text += "RTD: ";
  // if (carData.drivingData.readyToDrive)
  // {
  //   text += "Ready!";
  // }
  // else
  // {
  //   text += "Not Ready :/";
  // }

  // text += " | ";

  // text += "Inverter Enabled: ";
  // if (carData.drivingData.enableInverter)
  // {
  //   text += "Enabled";
  // }
  // else
  // {
  //   text += "Disabled";
  // }

  // text += " | ";

  // text += "Precharge State: " + std::to_string((int)carData.drivingData.prechargeState) + "\n";

  // text += "IMD Fault: ";
  // if (carData.drivingData.imdFault)
  // {
  //   text += "Faulted";
  // }
  // else
  // {
  //   text += "Cleared";
  // }

  // text += " | ";

  // text += "BMS Fault: ";
  // if (carData.drivingData.imdFault)
  // {
  //   text += "Faulted\n";
  // }
  // else
  // {
  //   text += "Cleared\n";
  // }

  // text += "Commanded Torque: " + std::to_string(carData.drivingData.commandedTorque) + "\n";

  // text += "Drive Mode: " + std::to_string(carData.drivingData.driveMode) + "\n";

  // text += "Speed (MPH): " + std::to_string(carData.drivingData.currentSpeed) + "\n";

  // text += "Drive Direction: " + std::to_string(carData.drivingData.driveDirection) + "\n";

  // // battery Status
  // text += "\n --- Battery Status ---\n";

  // text += "Bus Voltage: " + std::to_string(carData.batteryStatus.busVoltage) + "\n";

  // text += "Rinehart Voltage: " + std::to_string(carData.batteryStatus.rinehartVoltage) + "\n";

  // text += "Current: " + std::to_string(carData.batteryStatus.packCurrent) + "\n";

  // text += "Pack 1 Temp: " + std::to_string(carData.batteryStatus.pack1Temp) + "\n";
  // text += "Pack 2 Temp: " + std::to_string(carData.batteryStatus.pack2Temp) + "\n";
  // text += "Cell Voltage: " + std::to_string(carData.batteryStatus.minCellVoltage) + "\n";
  // text += "Cell Voltage: " + std::to_string(carData.batteryStatus.maxCellVoltage) + "\n";

  // // Sensors
  // text += "\n--- Sensor Inputs ---\n";
  // text += "FR Wheel Speed: " + std::to_string(carData.sensors.wheelSpeedFR) + "\n";
  // text += "FL Wheel Speed: " + std::to_string(carData.sensors.wheelSpeedFL) + "\n";
  // text += "BR Wheel Speed: " + std::to_string(carData.sensors.wheelSpeedBR) + "\n";
  // text += "BL Wheel Speed: " + std::to_string(carData.sensors.wheelSpeedBL) + "\n";

  // text += "FR Wheel Height: " + std::to_string(carData.sensors.wheelHeightFR) + "\n";
  // text += "FL Wheel Height: " + std::to_string(carData.sensors.wheelHeightFL) + "\n";
  // text += "BR Wheel Height: " + std::to_string(carData.sensors.wheelHeightBR) + "\n";
  // text += "BL Wheel Height: " + std::to_string(carData.sensors.wheelHeightBL) + "\n";

  // text += "Steering Wheel Angle: " + std::to_string(carData.sensors.steeringWheelAngle) + "\n";

  // text += "Vicore Temp: " + std::to_string(carData.sensors.vicoreTemp) + "\n";
  // text += "Pump In Temp: " + std::to_string(carData.sensors.pumpTempIn) + "\n";
  // text += "Pump Out Temp: " + std::to_string(carData.sensors.pumpTempOut) + "\n";

  // // Inputs
  // text += "\n--- Inputs ---\n";
  // text += "Pedal 0: " + std::to_string(carData.inputs.pedal0);
  // text += " | ";
  // text += "Pedal 1: " + std::to_string(carData.inputs.pedal1) + "\n";

  // text += "Brake Front: ", std::to_string(carData.inputs.brakeFront);
  // text += " | ";
  // text += "Brake Rear: " + std::to_string(carData.inputs.brakeRear) + "\n";

  // text += "Coast Regen: " + std::to_string(carData.inputs.coastRegen);
  // text += " | ";
  // text += "Brake Regen: " + std::to_string(carData.inputs.brakeRegen) + "\n";

  // // Outputs
  // text += "\n--- Outputs ---\n";
  // text += "Buzzer: ";
  // if (carData.outputs.buzzerActive)
  // {
  //   text += "Active";
  // }
  // else
  // {
  //   text += "Inactive";
  // }
  // text += " | ";
  // text += "Buzzer Counter: " + std::to_string(carData.outputs.buzzerCounter) + "\n";

  // text += "Brake Light: ";
  // if (carData.outputs.brakeLight)
  // {
  //   text += "On\n";
  // }
  // else
  // {
  //   text += "Off\n";
  // }

  // text += "Fans: ";
  // if (carData.outputs.fansActive)
  // {
  //   text += "Running\n";
  // }
  // else
  // {
  //   text += "Off\n";
  // }

  // text += "Pump: ";
  // if (carData.outputs.pumpActive)
  // {
  //   text += "Running\n";
  // }
  // else
  // {
  //   text += "Off\n";
  // }

  // // print it
  // Serial.printf("%s\r", text.c_str());
}

/**
 * @brief
 *
 */
void PrintRecieverDebug()
{
  // spacer
  std::string text = "";
  short newLines = 50;
  for (int i = 0; i < newLines; ++i)
  {
    Serial.printf("\n");
  }

  // driving data
  Serial.printf("--- Driving Data ---\n");

  Serial.printf("RTD: %s | Inverter Enable: %s | system state: %d\n", g_carData.executive.readyToDrive ? "Ready!" : "Not Ready :(",
                g_carData.executive.enableInverter ? "Enabled" : "Disabled", (int)g_carData.executive.systemState);

  Serial.printf("IMD Fault: %s | BMS Fault: %s\n", g_carData.gpio.imdFault ? "Faulted" : "Cleared", g_carData.gpio.bmsFault ? "Faulted" : "Cleared");

  Serial.printf("Commanded Torque: %d | Drive Mode: %d | Direction: %d\n", g_carData.executive.torqueCommand, g_carData.executive.driveMode, g_carData.executive.driveDirection);

  // // battery Status
  // Serial.printf("\n --- Battery Status ---\n");
  // Serial.printf("SOC: %f\n", carData.batteryStatus.batteryChargeState);
  // Serial.printf("Bus Voltage: %f\n", carData.batteryStatus.busVoltage);
  // Serial.printf("Rinehart Voltage: %f\n", carData.batteryStatus.rinehartVoltage);
  // Serial.printf("Current: %f\n", carData.batteryStatus.packCurrent);
  // Serial.printf("Pack 1 Temp: %f\n", carData.batteryStatus.pack1Temp);
  // Serial.printf("Pack 2 Temp: %f\n", carData.batteryStatus.pack2Temp);
  // Serial.printf("Cell Voltage: %f\n", carData.batteryStatus.minCellVoltage);
  // Serial.printf("Cell Voltage: %f\n", carData.batteryStatus.maxCellVoltage);

  // // Sensors
  // Serial.printf("\n--- Sensor Inputs ---\n");
  // printf("FR Wheel Speed: %f\n", carData.sensors.wheelSpeedFR);
  // printf("FL Wheel Speed: %f\n", carData.sensors.wheelSpeedFL);
  // printf("BR Wheel Speed: %f\n", carData.sensors.wheelSpeedBR);
  // printf("BL Wheel Speed: %f\n", carData.sensors.wheelSpeedBL);

  // printf("FR Wheel Height: %f\n", carData.sensors.wheelHeightFR);
  // printf("FL Wheel Height: %f\n", carData.sensors.wheelHeightFL);
  // printf("BR Wheel Height: %f\n", carData.sensors.wheelHeightBR);
  // printf("BL Wheel Height: %f\n", carData.sensors.wheelHeightBL);

  // printf("Steering Wheel Angle: %f\n", carData.sensors.steeringWheelAngle);

  // printf("Vicore Temp: %f\n", carData.sensors.vicoreTemp);
  // printf("Pump In Temp: %f\n", carData.sensors.pumpTempIn);
  // printf("Pump Out Temp: %f\n", carData.sensors.pumpTempOut);

  // Inputs
  Serial.printf("\n--- Inputs ---\n");
  printf("Pedal 0: %d | Pedal 1: %d\n", g_carData.gpio.pedal0, g_carData.gpio.pedal1);
  printf("Brake 0: %d | Brake 1: %d\n", g_carData.gpio.frontBrake, g_carData.gpio.rearBrake);
  // printf("Coast Regen: %d | Brake Regen: %d\n", g_carData.gpio.coastRegen, g_carData.gpio.brakeRegen);

  // Outputs
  Serial.printf("\n--- Outputs ---\n");
  printf("Buzzer: %s\n", g_carData.gpio.buzzerEnable ? "Active" : "Inactive");
  printf("Brake Light: %s\n", g_carData.gpio.brakeLightEnable ? "On" : "Off");
  printf("Fans: %s\n", g_carData.gpio.fansEnable ? "Running" : "Off");
  // printf("Pump: %s\n", g_carData.gpio. ? "Running" : "Off");
}

/**
 * @brief scheudler debugging
 */
void PrintSchedulerDebug()
{
  // inits
  std::vector<int> taskRefreshRate;
  int uptime = esp_rtc_get_time_us() / 1000000;

  taskRefreshRate.push_back(debugger.serialWriteTaskCount - debugger.serialWritePreviousTaskCount);
  taskRefreshRate.push_back(debugger.ardanReadTaskCount - debugger.ardanReadPreviousTaskCount);

  // print it
  Serial.printf("uptime: %d | write serial:<%d Hz> (%d) | read ardan:<%d Hz> (%d) \r", uptime, taskRefreshRate.at(0), debugger.serialWriteTaskCount, taskRefreshRate.at(1), debugger.ardanReadTaskCount);

  // update counters
  debugger.serialWritePreviousTaskCount = debugger.serialWriteTaskCount;
  debugger.ardanReadPreviousTaskCount = debugger.ardanReadTaskCount;
}