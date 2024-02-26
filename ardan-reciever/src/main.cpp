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

#include "LoRa.h"

#include <data_types.h>
#include <pin_config.h>

/*
===============================================================================================
                                    Definitions
===============================================================================================
*/

// tasks
#define SERIAL_WRITE_REFRESH_RATE 9 // measured in ticks (RTOS ticks interrupt at 1 kHz)
#define SERIAL_READ_REFRESH_RATE 9  // measured in ticks (RTOS ticks interrupt at 1 kHz)
#define DEBUG_REFRESH_RATE 1000     // measured in ticks (RTOS ticks interrupt at 1 kHz)

#define TASK_STACK_SIZE 20000 // in bytes

// ESP-NOW
#define ARDAN_ESP_NOW_ADDRESS          \
  {                                    \
    0xC4, 0xDE, 0xE2, 0xC0, 0x75, 0x83 \
  }

// debug
#define ENABLE_DEBUG false // master debug message control

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

/**
 * @brief the dataframe that describes the entire state of the car
 *
 */
TelemetryCoreData telemetryCoreData = {
    // tractive data
    .tractiveCoreData = {
        .tractive = {
            .readyToDrive = false,
            .enableInverter = false,

            .prechargeState = PRECHARGE_OFF,

            .rinehartVoltage = 0.0f,
            .commandedTorque = 0,

            .driveDirection = false, // forward is false | reverse is true (we run backwards)
            .driveMode = ECO,

            .currentSpeed = 0.0f,

            .tractionControlEnable = true,
            .tractionControlModifier = 1.00f,

            .coastRegen = 0,
            .brakeRegen = 0,
        },

        // sensor data
        .sensors = {
            .imdFault = true,
            .bmsFault = true,
            .vicoreFault = false,

            .coolingTempIn = 0.0f,
            .coolingTempOut = 0.0f,

            .frontWheelsSpeed = 0.0f,
            .frontWheelSpeedCount = 0,
            .frontWheelSpeedTime = 0,

            .brWheelSpeed = 0.0f,
            .brWheelSpeedCount = 0,
            .brWheelSpeedTime = 0,

            .blWheelSpeed = 0.0f,
            .blWheelSpeedCount = 0,
            .blWheelSpeedTime = 0,
        },

        // inputs
        .inputs = {
            .pedal0 = 0,
            .pedal1 = 0,

            .frontBrake = 0,
            .rearBrake = 0,
        },

        // outputs
        .outputs = {
            .brakeLightEnable = false,

            .fansEnable = false,

            .buzzerEnable = false,
        },

        // orion
        .orion = {
            .batteryChargeState = 0,

            .busVoltage = 0,

            .packCurrent = 0.0f,

            .minCellVoltage = 0.0f,
            .maxCellVoltage = 0.0f,
            .minCellTemp = 0.0f,
            .maxCellTemp = 0.0f,
        }},

    // telemetry data

    // wheel damper sensors
    .dampers = {
        .frSuspensionDamper = 0,
        .flSuspensionDamper = 0,
        .brSuspensionDamper = 0,
        .blSuspensionDamper = 0,
    },

    // tire temperature sensors
    .tireTemp = {
        .frTireTemp = 0,
        .flTireTemp = 0,
        .brTireTemp = 0,
        .blTireTemp = 0,
    },

    // suspension strain sensors
    .strain = {
        .frStrain1 = 0,
        .flStrain1 = 0,
        .brStrain1 = 0,
        .blStrain1 = 0,

        .frStrain2 = 0,
        .flStrain2 = 0,
        .brStrain2 = 0,
        .blStrain2 = 0,
    },

    // steering wheel sensors
    .steering = {
        .steeringWheelDeflection = 0,
    },

    // inertial monitoring unit data
    .imu = {
        .xAcceleration = 0.0f,
        .yAcceleration = 0.0f,
        .zAcceleration = 0.0f,
        .xGyro = 0.0f,
        .yGyro = 0.0f,
        .zGyro = 0.0f,
    },

    // global positioning system data
    .gps = {
        .latitide = 0.0f,
        .longitude = 0.0f,
        .altitude = 0.0f,
        .speed = 0.0f,
        .year = 0,
        .month = 0,
        .day = 0,
    }};

// Mutex
SemaphoreHandle_t xMutex = NULL;

// RTOS Task Handles
TaskHandle_t xHandleSerialWrite = NULL;
TaskHandle_t xHandleArdanRead = NULL;
TaskHandle_t xHandleDebug = NULL;

// Hardware Timers
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

/*
===============================================================================================
                                    Function Declarations
===============================================================================================
*/

// tasks
void SerialWriteTask(void *pvParameters);
void ArdanReadTask(void *pvParameters);

// helpers
String TaskStateToString(eTaskState state);

/*
===============================================================================================
                                            Setup
===============================================================================================
*/

void setup()
{
  // set power configuration
  esp_pm_configure(&power_configuration);

  if (debugger.debugEnabled)
  {
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

  // -------------------------- initialize LoRa  ---------------------------- //
  if (LoRa.begin(915E6))
  {
    Serial.printf("LoRa INIT [ SUCCESS ]\n");
  }

  else
  {
    Serial.printf("LoRa INIT [ FAILED ]\n");
  }

  // ------------------------------------------------------------------------ //

  // ------------------------------- Scheduler & Task Status --------------------------------- //
  // init mutex
  xMutex = xSemaphoreCreateMutex();

  // task setup status
  Serial.printf("\nTask Setup Status:\n");
  Serial.printf("SERIAL TASK SETUP: %s\n", setup.serialActive ? "COMPLETE" : "FAILED");
  Serial.printf("ARDAN TASK SETUP: %s\n", setup.ardanActive ? "COMPLETE" : "FAILED");

  if (xMutex != NULL)
  {
    // start tasks
    if (setup.serialActive)
    {
      xTaskCreatePinnedToCore(SerialWriteTask, "Serial-Write", TASK_STACK_SIZE, NULL, tskIDLE_PRIORITY, &xHandleSerialWrite, 0);
    }

    if (setup.ardanActive)
    {
      xTaskCreatePinnedToCore(ArdanReadTask, "ARDAN-Read", TASK_STACK_SIZE, NULL, tskIDLE_PRIORITY, &xHandleArdanRead, 1);
    }
  }
  else
  {
    Serial.printf("FAILED TO INIT MUTEX!\nHALTING OPERATIONS!");
    while (1)
    {
    };
  }

  // task status
  Serial.printf("\nTask Status:\n");
  if (xHandleSerialWrite != NULL)
    Serial.printf("SERIAL WRITE TASK STATUS: %s\n", TaskStateToString(eTaskGetState(xHandleSerialWrite)));
  else
    Serial.printf("SERIAL WRITE TASK STATUS: DISABLED!\n");

  if (xHandleArdanRead != NULL)
    Serial.printf("ARDAN READ TASK STATUS: %s\n", TaskStateToString(eTaskGetState(xHandleArdanRead)));
  else
    Serial.printf("ARDAN READ TASK STATUS: DISABLED!\n");

  // scheduler status
  if (xTaskGetSchedulerState() == taskSCHEDULER_RUNNING)
  {
    Serial.printf("\nScheduler Status: RUNNING\n");

    // clock frequency
    rtc_cpu_freq_config_t clock_config;
    rtc_clk_cpu_freq_get_config(&clock_config);
    Serial.printf("CPU Frequency: %dMHz\n", clock_config.freq_mhz);
  }
  else
  {
    Serial.printf("\nScheduler STATUS: FAILED\nHALTING OPERATIONS");
    while (1)
    {
    };
  }
  Serial.printf("\n|--- END SETUP ---|\n\n");
  // ---------------------------------------------------------------------------------------- //
}

/*
===============================================================================================
                                FreeRTOS Task Functions
===============================================================================================
*/

/**
 * @brief writes to serial bus
 *
 * @param pvParameters parameters passed to task
 */
void SerialWriteTask(void *pvParameters)
{
  for (;;)
  {
    if (xSemaphoreTake(xMutex, (TickType_t)10) == pdTRUE)
    {
      // write message to bus
      Serial.write((uint8_t *)&telemetryCoreData, sizeof(telemetryCoreData));

      // release mutex!
      xSemaphoreGive(xMutex);
    }

    // debugging
    if (debugger.debugEnabled)
    {
      debugger.serialMessage = telemetryCoreData;
      debugger.serialWriteTaskCount++;
    }

    // limit task refresh rate
    vTaskDelay(SERIAL_WRITE_REFRESH_RATE);
  }
}

/**
 * @brief reads ardan
 *
 * @param pvParameters parameters passed to task
 */
void ArdanReadTask(void *pvParameters)
{
  for (;;)
  {
    if (xSemaphoreTake(xMutex, (TickType_t)10) == pdTRUE)
    {
      // read ardan
      int packetSize = LoRa.parsePacket();
      if (packetSize) // Only read if there is some data to read..
      {
        LoRa.readBytes((uint8_t *)&telemetryCoreData, packetSize);
      }

      // release mutex!
      xSemaphoreGive(xMutex);
    }

    // debugging
    if (debugger.debugEnabled)
    {
      debugger.recievedMessage = telemetryCoreData;
      debugger.ardanReadTaskCount++;
    }

    // limit task refresh rate
    vTaskDelay(SERIAL_WRITE_REFRESH_RATE);
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
      PrintSerialDebug();
    }

    // ardan
    if (debugger.reciever_debugEnabled)
    {
      PrintRecieverDebug_Better();
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
 * convert a number to drive mode
 */
DriveMode NumberToDriveMode(uint8_t value)
{
  // inits
  DriveMode mode;

  // convert
  if (value == 1)
  {
    mode = SLOW;
  }
  if (value == 2)
  {
    mode = ECO;
  }
  if (value == 3)
  {
    mode = FAST;
  }

  return mode;
}

/**
 * convert a number to precharge state
 */
PrechargeStates NumberToPrechargeState(uint8_t value)
{
  // init
  PrechargeStates state;

  // convert
  if (value == 1)
  {
    state = PRECHARGE_OFF;
  }
  if (value == 2)
  {
    state = PRECHARGE_ON;
  }
  if (value == 3)
  {
    state = PRECHARGE_DONE;
  }
  if (value == 4)
  {
    state = PRECHARGE_ERROR;
  }

  return state;
}

/**
 *
 */
String TaskStateToString(eTaskState state)
{
  // init
  String stateStr;

  // get state
  switch (state)
  {
  case eReady:
    stateStr = "RUNNING";
    break;

  case eBlocked:
    stateStr = "BLOCKED";
    break;

  case eSuspended:
    stateStr = "SUSPENDED";
    break;

  case eDeleted:
    stateStr = "DELETED";
    break;

  default:
    stateStr = "ERROR";
    break;
  }

  return stateStr;
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
void PrintSerialDebug()
{
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
 * @brief scheudler debugging
 */
void PrintSchedulerDebug()
{
  // inits
  std::vector<eTaskState> taskStates;
  std::vector<String> taskStatesStrings;
  std::vector<int> taskRefreshRate;
  int uptime = esp_rtc_get_time_us() / 1000000;

  // gather task information
  if (xHandleSerialWrite != NULL)
  {
    taskStates.push_back(eTaskGetState(xHandleSerialWrite));
  }
  if (xHandleArdanRead != NULL)
  {
    taskStates.push_back(eTaskGetState(xHandleArdanRead));
  }

  taskRefreshRate.push_back(debugger.serialWriteTaskCount - debugger.serialWritePreviousTaskCount);
  taskRefreshRate.push_back(debugger.ardanReadTaskCount - debugger.ardanReadPreviousTaskCount);

  // make it usable
  for (int i = 0; i < taskStates.size() - 1; ++i)
  {
    taskStatesStrings.push_back(TaskStateToString(taskStates.at(i)));
  }

  // print it
  Serial.printf("uptime: %d | write serial:<%d Hz> (%d) | read ardan:<%d Hz> (%d) \r", uptime, taskRefreshRate.at(0), debugger.serialWriteTaskCount, taskRefreshRate.at(1), debugger.ardanReadTaskCount);

  // update counters
  debugger.serialWritePreviousTaskCount = debugger.serialWriteTaskCount;
  debugger.ardanReadPreviousTaskCount = debugger.ardanReadTaskCount;
}