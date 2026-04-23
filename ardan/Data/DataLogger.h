#ifndef DATALOGGER_H
#define DATALOGGER_H

#include <cstdint>
#include <mutex>
#include <Data/ExecutiveData.h>
#include <Data/GpioData.h>
#include <Data/TwaiData.h>

typedef struct ExecutiveSnapshotType
{
    ExecutiveData::SystemStateType systemState;
    uint8_t previousSystemState;
    bool readyToDrive;
    bool enableInverter;
    uint8_t driveDirection;
    ExecutiveData::DriveModeType driveMode;
    uint16_t torqueCommand;
    bool enableVicore;
    float velocity;
    float coastRegen;
    float brakeRegen;
} ExecutiveSnapshot;

typedef struct GpioSnapshotType
{
    // Faults
    bool imdFault;
    bool bmsFault;
    bool vicoreFault;

    // Cooling temperatures
    float coolingTempIn;
    float coolingTempOut;

    // Front wheels
    float frontWheelsSpeed;
    int   frontWheelSpeedCount;
    int   frontWheelSpeedTime;

    // Back right wheel
    float brWheelSpeed;
    int   brWheelSpeedCount;
    int   brWheelSpeedTime;

    // Back left wheel
    float blWheelSpeed;
    int   blWheelSpeedCount;
    int   blWheelSpeedTime;

    // Inputs
    int pedal0;
    int pedal1;
    int frontBrake;
    int rearBrake;

    // Outputs
    bool vicoreEnable;
    bool brakeLightEnable;
    bool fansEnable;
    bool buzzerEnable;
    bool prechargeCompleteLedEnable;
} GpioSnapshot;

typedef struct TwaiSnapshotType
{
    uint16_t rinehartRelayWord;
    uint16_t rinehartTractiveWord;
    uint16_t rinehartBusVoltage;
    int16_t  bmsPackCurrent;
    uint16_t bmsBusVoltage;
    uint8_t  bmsBatteryCharge;
} TwaiSnapshot;

typedef struct CarDataType
{
    ExecutiveSnapshotType executive;
    GpioSnapshotType gpio;
    TwaiSnapshotType twai;
} CarData;

/**
 * 
 */
class DataLogger
{
private:
    // thread safety
    mutable std::mutex mutex;

    // debug toggle
    bool debugEnabled;
    bool executiveDebugEnabled;
    bool ioDebugEnabled;
    bool twaiDebugEnabled;
    bool schedulerDebugEnable;

    // data pointers
    ExecutiveData *executive;
    GpioData *ioData;
    TwaiData *twaiData;

    // scheduler data
    int executiveTaskCount;
    int ioTaskCount;
    int twaiTaskCount;
    int telemetryTaskCount;

    int executiveTaskPreviousCount;
    int ioTaskPreviousCount;
    int twaiTaskPreviousCount;
    int telemetryTaskPreviousCount;

public:
    DataLogger();
    ~DataLogger();

    void PrintExecutiveDebug();
    void PrintTWAIDebug();
    void PrintIODebug();
    void PrintScheduler();

    // debug toggle setters/getters
    void setDebugEnabled(bool value);
    bool getDebugEnabled() const;

    void setExecutiveDebugEnabled(bool value);
    bool getExecutiveDebugEnabled() const;

    void setIoDebugEnabled(bool value);
    bool getIoDebugEnabled() const;

    void setTwaiDebugEnabled(bool value);
    bool getTwaiDebugEnabled() const;

    void setSchedulerDebugEnable(bool value);
    bool getSchedulerDebugEnable() const;

    // data pointer setters/getters
    void setExecutiveData(ExecutiveData *data);
    ExecutiveData *getExecutive() const;

    void setIoData(GpioData *data);
    GpioData *getIoData() const;

    void setTwaiData(TwaiData *data);
    TwaiData *getTwaiData() const;

    // task count setters/getters
    void setExecutiveTaskCount(int count);
    int getExecutiveTaskCount() const;

    void setIoTaskCount(int count);
    int getIoTaskCount() const;

    void setTwaiTaskCount(int count);
    int getTwaiTaskCount() const;

    void setTelemetryTaskCount(int count);
    int getTelemetryTaskCount() const;

    // previous task count setters/getters
    void setExecutiveTaskPreviousCount(int count);
    int getExecutiveTaskPreviousCount() const;

    void setIoTaskPreviousCount(int count);
    int getIoTaskPreviousCount() const;

    void setTwaiTaskPreviousCount(int count);
    int getTwaiTaskPreviousCount() const;

    void setTelemetryTaskPreviousCount(int count);
    int getTelemetryTaskPreviousCount() const;
};

#endif // DATALOGGER_H
