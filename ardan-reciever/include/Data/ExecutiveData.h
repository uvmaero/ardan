#ifndef EXECUTIVE_DATA_H
#define EXECUTIVE_DATA_H

#include <mutex>

class ExecutiveData
{
public:
    typedef enum
    {
        SLOW = 0,
        ECO,
        FAST,
    } DriveModeType;

    typedef enum
    {
        PRECHARGE_OFF = 0,
        PRECHARGE_ON,
        PRECHARGE_DONE,
        OPERATING_LOW_VOLTAGE,
        OPERATING_HIGH_VOLTAGE,
        OPERATING_FAULT,
        PRECHARGE_ERROR,
    } SystemStateType;

private:
    mutable std::mutex mutex;

    SystemStateType systemState;
    uint8_t previousSystemState;
    bool readyToDrive;
    bool enableInverter;
    uint8_t driveDirection;
    DriveModeType driveMode;
    uint16_t torqueCommand;
    bool enableVicore;
    float velocity;
    float coastRegen;
    float brakeRegen;

public:
    ExecutiveData();
    ~ExecutiveData();

    // Getters
    SystemStateType getSystemState() const;
    uint8_t getPreviousSystemState() const;
    bool getReadyToDrive() const;
    bool getEnableInverter() const;
    uint8_t getDriveDirection() const;
    DriveModeType getDriveMode() const;
    uint16_t getTorqueCommand() const;
    bool getEnableVicore() const;
    float getVelocity() const;
    float getCoastRegen() const;
    float getBrakeRegen() const;

    // Setters
    void setSystemState(SystemStateType value);
    void setPreviousSystemState(uint8_t value);
    void setReadyToDrive(bool value);
    void setEnableInverter(bool value);
    void setDriveDirection(uint8_t value);
    void setDriveMode(DriveModeType value);
    void setTorqueCommand(uint16_t value);
    void setEnableVicore(bool value);
    void setVelocity(float value);
    void setCoastRegen(float value);
    void setBrakeRegen(float value);
};

#endif // EXECUTIVE_DATA_H