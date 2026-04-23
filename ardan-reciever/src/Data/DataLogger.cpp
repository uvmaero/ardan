/**
 * @file DataLogger.cpp
 * @brief
 * @date 2026-04-16
 */

/*
===============================================================================================
                                   includes
===============================================================================================
*/

#include "Data/DataLogger.h"
#include <Arduino.h>
#include "vector"
#include "rtc.h"

/*
===============================================================================================
                                  definitions
===============================================================================================
*/

#define ENABLE_DEBUG true // master debug message control

/*
===============================================================================================
                                    class
===============================================================================================
*/

/**
 *
 */
DataLogger::DataLogger()
    : debugEnabled(ENABLE_DEBUG),
      executiveDebugEnabled(false),
      ioDebugEnabled(false),
      twaiDebugEnabled(false),
      schedulerDebugEnable(true),
      executive(nullptr),
      ioData(nullptr),
      twaiData(nullptr),
      executiveTaskCount(0),
      ioTaskCount(0),
      twaiTaskCount(0),
      telemetryTaskCount(0),
      executiveTaskPreviousCount(0),
      ioTaskPreviousCount(0),
      twaiTaskPreviousCount(0),
      telemetryTaskPreviousCount(0)
{
}

/**
 *
 */
DataLogger::~DataLogger()
{
    // Destructor - no dynamic memory to clean up
}

/**
 *
 */
void DataLogger::PrintExecutiveDebug()
{
    Serial.printf("\n--- START executive DEBUG ---\n\n");

    Serial.println("Executive Debug:");
    Serial.print("System State: ");
    Serial.println(static_cast<int>(executive->getSystemState()));
    Serial.print("Previous System State: ");
    Serial.println(executive->getPreviousSystemState());
    Serial.print("Ready to Drive: ");
    Serial.println(executive->getReadyToDrive() ? "true" : "false");
    Serial.print("Enable Inverter: ");
    Serial.println(executive->getEnableInverter() ? "true" : "false");
    Serial.print("Drive Direction: ");
    Serial.println(executive->getDriveDirection());
    Serial.print("Drive Mode: ");
    Serial.println(static_cast<int>(executive->getDriveMode()));
    Serial.print("Torque Command: ");
    Serial.println(executive->getTorqueCommand());
    Serial.print("Enable Vicore: ");
    Serial.println(executive->getEnableVicore() ? "true" : "false");
    Serial.print("Velocity: ");
    Serial.println(executive->getVelocity());
    Serial.print("Coast Regen: ");
    Serial.println(executive->getCoastRegen());
    Serial.print("Brake Regen: ");
    Serial.println(executive->getBrakeRegen());
    Serial.println();

    Serial.printf("\n\n--- END executive DEBUG ---\n");
}

/**
 *
 */
void DataLogger::PrintTWAIDebug()
{
    Serial.printf("\n--- START TWAI DEBUG ---\n\n");

    Serial.println("TWAI Debug:");
    Serial.print("Rinehart Relay Word: ");
    Serial.println(twaiData->getRinehartRelayWord());
    Serial.print("Rinehart Tractive Word: ");
    Serial.println(twaiData->getRinehartTractiveWord());
    Serial.print("Rinehart Bus Voltage: ");
    Serial.println(twaiData->getRinehartBusVoltage());
    Serial.print("BMS Pack Current: ");
    Serial.println(twaiData->getBmsPackCurrent());
    Serial.print("BMS Bus Voltage: ");
    Serial.println(twaiData->getBmsBusVoltage());
    Serial.print("BMS Battery Charge: ");
    Serial.println(twaiData->getBmsBatteryCharge());
    Serial.println();

    // // bus alerts
    // Serial.printf("TWAI BUS Alerts:\n");
    // uint32_t alerts;
    // twai_read_alerts(&alerts, pdMS_TO_TICKS(100));
    // if (alerts & TWAI_ALERT_TX_SUCCESS)
    // {
    //   Serial.printf("TWAI ALERT: TX Success\n");
    // }
    // if (alerts & TWAI_ALERT_TX_FAILED)
    // {
    //   Serial.printf("TWAI ALERT: TX Failed\n");
    // }
    // if (alerts & TWAI_ALERT_RX_QUEUE_FULL)
    // {
    //   Serial.printf("TWAI ALERT: RX Queue Full\n");
    // }
    // if (alerts & TWAI_ALERT_ABOVE_ERR_WARN)
    // {
    //   Serial.printf("TWAI ALERT: Surpassed Error Warning Limit\n");
    // }
    // if (alerts & TWAI_ALERT_ERR_PASS)
    // {
    //   Serial.printf("TWAI ALERT: Entered Error Passive state\n");
    // }
    // if (alerts & TWAI_ALERT_BUS_OFF)
    // {
    //   Serial.printf("TWAI ALERT: Bus Off\n");
    // }

    // Serial.printf("\n");

    // // --- incoming messages --- //

    // // --- outgoing messages --- //

    // // sent status
    // Serial.printf("Rine Ctrl Send Status: 0x%X\n", debugger.TWAI_rinehartCtrlResult);
    // Serial.printf("Precharge Ctrl Send Status: 0x%X\n", debugger.TWAI_prechargeCtrlResult);

    // // messages
    // Serial.printf("\n");
    // Serial.printf("Rinehart Ctrl Outgoing Message:\n");
    // for (int i = 0; i < 8; ++i)
    // {
    //   Serial.printf("Byte %d: %02X\t", i, debugger.TWAI_rinehartCtrlMessage[i]);
    // }

    // Serial.printf("\n");

    // Serial.printf("Precharge Ctrl Outgoing Message:\n");
    // for (int i = 0; i < 8; ++i)
    // {
    //   Serial.printf("Byte %d: %02X\t", i, debugger.TWAI_prechargeCtrlMessage[i]);
    // }

    Serial.printf("\n\n--- END TWAI DEBUG ---\n");
}

/**
 *
 */
void DataLogger::PrintIODebug()
{
    Serial.printf("\n--- START I/O DEBUG ---\n");

    Serial.println("IO Debug:");
    Serial.print("IMD Fault: ");
    Serial.println(ioData->getImdFault() ? "true" : "false");
    Serial.print("BMS Fault: ");
    Serial.println(ioData->getBmsFault() ? "true" : "false");
    Serial.print("Vicore Fault: ");
    Serial.println(ioData->getVicoreFault() ? "true" : "false");
    Serial.print("Cooling Temp In: ");
    Serial.println(ioData->getCoolingTempIn());
    Serial.print("Cooling Temp Out: ");
    Serial.println(ioData->getCoolingTempOut());
    Serial.print("Front Wheels Speed: ");
    Serial.println(ioData->getFrontWheelsSpeed());
    Serial.print("BR Wheel Speed: ");
    Serial.println(ioData->getBrWheelSpeed());
    Serial.print("BL Wheel Speed: ");
    Serial.println(ioData->getBlWheelSpeed());
    Serial.print("Pedal 0: ");
    Serial.println(ioData->getPedal0());
    Serial.print("Pedal 1: ");
    Serial.println(ioData->getPedal1());
    Serial.print("Front Brake: ");
    Serial.println(ioData->getFrontBrake());
    Serial.print("Rear Brake: ");
    Serial.println(ioData->getRearBrake());
    Serial.print("Vicore Enable: ");
    Serial.println(ioData->getVicoreEnable() ? "true" : "false");
    Serial.print("Brake Light Enable: ");
    Serial.println(ioData->getBrakeLightEnable() ? "true" : "false");
    Serial.print("Fans Enable: ");
    Serial.println(ioData->getFansEnable() ? "true" : "false");
    Serial.print("Buzzer Enable: ");
    Serial.println(ioData->getBuzzerEnable() ? "true" : "false");
    Serial.print("Precharge Complete LED Enable: ");
    Serial.println(ioData->getprechargeCompleteLedEnable() ? "true" : "false");
    Serial.println();

    Serial.printf("\n--- END I/O DEBUG ---\n");
}

/**
 *
 */
void DataLogger::PrintScheduler()
{
    // inits
    std::vector<int> taskRefreshRate;
    int uptime = esp_rtc_get_time_us() / 1000000;

    taskRefreshRate.push_back(executiveTaskCount - executiveTaskPreviousCount);
    taskRefreshRate.push_back(ioTaskCount - ioTaskPreviousCount);
    taskRefreshRate.push_back(twaiTaskCount - twaiTaskPreviousCount);
    taskRefreshRate.push_back(telemetryTaskCount - telemetryTaskPreviousCount);

    // print
    Serial.printf("uptime: %d | executive: <%d Hz> (%d) | io: <%d Hz> (%d) | twai: <%d Hz> (%d) | telemetry update: <%d Hz> (%d) \r",
                  uptime, taskRefreshRate.at(0), executiveTaskCount, taskRefreshRate.at(1), ioTaskCount,
                  taskRefreshRate.at(2), twaiTaskCount, taskRefreshRate.at(3), telemetryTaskCount);

    // update counters
    executiveTaskPreviousCount = executiveTaskCount;
    ioTaskPreviousCount = ioTaskCount;
    twaiTaskPreviousCount = twaiTaskCount;
    telemetryTaskPreviousCount = telemetryTaskCount;
}

// Debug toggle setters/getters
void DataLogger::setDebugEnabled(bool value)
{
    std::lock_guard<std::mutex> lock(mutex);
    debugEnabled = value;
}
bool DataLogger::getDebugEnabled() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return debugEnabled;
}

void DataLogger::setExecutiveDebugEnabled(bool value)
{
    std::lock_guard<std::mutex> lock(mutex);
    executiveDebugEnabled = value;
}
bool DataLogger::getExecutiveDebugEnabled() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return executiveDebugEnabled;
}

void DataLogger::setIoDebugEnabled(bool value)
{
    std::lock_guard<std::mutex> lock(mutex);
    ioDebugEnabled = value;
}
bool DataLogger::getIoDebugEnabled() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return ioDebugEnabled;
}

void DataLogger::setTwaiDebugEnabled(bool value)
{
    std::lock_guard<std::mutex> lock(mutex);
    twaiDebugEnabled = value;
}
bool DataLogger::getTwaiDebugEnabled() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return twaiDebugEnabled;
}

void DataLogger::setSchedulerDebugEnable(bool value)
{
    std::lock_guard<std::mutex> lock(mutex);
    schedulerDebugEnable = value;
}
bool DataLogger::getSchedulerDebugEnable() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return schedulerDebugEnable;
}

// Data pointer setters/getters
void DataLogger::setExecutiveData(ExecutiveData *data)
{
    std::lock_guard<std::mutex> lock(mutex);
    executive = data;
}
ExecutiveData *DataLogger::getExecutive() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return executive;
}

void DataLogger::setIoData(GpioData *data)
{
    std::lock_guard<std::mutex> lock(mutex);
    ioData = data;
}
GpioData *DataLogger::getIoData() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return ioData;
}

void DataLogger::setTwaiData(TwaiData *data)
{
    std::lock_guard<std::mutex> lock(mutex);
    twaiData = data;
}
TwaiData *DataLogger::getTwaiData() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return twaiData;
}

// Task count setters/getters
void DataLogger::setExecutiveTaskCount(int count)
{
    std::lock_guard<std::mutex> lock(mutex);
    executiveTaskCount = count;
}
int DataLogger::getExecutiveTaskCount() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return executiveTaskCount;
}

void DataLogger::setIoTaskCount(int count)
{
    std::lock_guard<std::mutex> lock(mutex);
    ioTaskCount = count;
}
int DataLogger::getIoTaskCount() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return ioTaskCount;
}

void DataLogger::setTwaiTaskCount(int count)
{
    std::lock_guard<std::mutex> lock(mutex);
    twaiTaskCount = count;
}
int DataLogger::getTwaiTaskCount() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return twaiTaskCount;
}

void DataLogger::setTelemetryTaskCount(int count)
{
    std::lock_guard<std::mutex> lock(mutex);
    telemetryTaskCount = count;
}
int DataLogger::getTelemetryTaskCount() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return telemetryTaskCount;
}

// Previous task count setters/getters
void DataLogger::setExecutiveTaskPreviousCount(int count)
{
    std::lock_guard<std::mutex> lock(mutex);
    executiveTaskPreviousCount = count;
}
int DataLogger::getExecutiveTaskPreviousCount() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return executiveTaskPreviousCount;
}

void DataLogger::setIoTaskPreviousCount(int count)
{
    std::lock_guard<std::mutex> lock(mutex);
    ioTaskPreviousCount = count;
}
int DataLogger::getIoTaskPreviousCount() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return ioTaskPreviousCount;
}

void DataLogger::setTwaiTaskPreviousCount(int count)
{
    std::lock_guard<std::mutex> lock(mutex);
    twaiTaskPreviousCount = count;
}
int DataLogger::getTwaiTaskPreviousCount() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return twaiTaskPreviousCount;
}

void DataLogger::setTelemetryTaskPreviousCount(int count)
{
    std::lock_guard<std::mutex> lock(mutex);
    telemetryTaskPreviousCount = count;
}
int DataLogger::getTelemetryTaskPreviousCount() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return telemetryTaskPreviousCount;
}