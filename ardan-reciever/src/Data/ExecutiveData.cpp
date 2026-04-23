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

#include "Data/ExecutiveData.h"

/*
===============================================================================================
                                    class
===============================================================================================
*/

/**
 *
 */
ExecutiveData::ExecutiveData()
{
    // Initialize default values
    systemState = OPERATING_HIGH_VOLTAGE;
    previousSystemState = 0;
    readyToDrive = false;
    enableInverter = false;
    driveDirection = 0;
    driveMode = ECO;
    torqueCommand = 0;
    velocity = 0.0f;
    coastRegen = 0.0f;
    brakeRegen = 0.0f;
}

/**
 *
 */
ExecutiveData::~ExecutiveData()
{
    // Destructor implementation if needed
}

// Getters
ExecutiveData::SystemStateType ExecutiveData::getSystemState() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return systemState;
}

uint8_t ExecutiveData::getPreviousSystemState() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return previousSystemState;
}

bool ExecutiveData::getReadyToDrive() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return readyToDrive;
}

bool ExecutiveData::getEnableInverter() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return enableInverter;
}

uint8_t ExecutiveData::getDriveDirection() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return driveDirection;
}

ExecutiveData::DriveModeType ExecutiveData::getDriveMode() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return driveMode;
}

uint16_t ExecutiveData::getTorqueCommand() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return torqueCommand;
}

bool ExecutiveData::getEnableVicore() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return enableVicore;
}

float ExecutiveData::getVelocity() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return velocity;
}

float ExecutiveData::getCoastRegen() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return coastRegen;
}

float ExecutiveData::getBrakeRegen() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return brakeRegen;
}

// Setters
void ExecutiveData::setSystemState(SystemStateType value)
{
    std::lock_guard<std::mutex> lock(mutex);
    systemState = value;
}

void ExecutiveData::setPreviousSystemState(uint8_t value)
{
    std::lock_guard<std::mutex> lock(mutex);
    previousSystemState = value;
}

void ExecutiveData::setReadyToDrive(bool value)
{
    std::lock_guard<std::mutex> lock(mutex);
    readyToDrive = value;
}

void ExecutiveData::setEnableInverter(bool value)
{
    std::lock_guard<std::mutex> lock(mutex);
    enableInverter = value;
}

void ExecutiveData::setDriveDirection(uint8_t value)
{
    std::lock_guard<std::mutex> lock(mutex);
    driveDirection = value;
}

void ExecutiveData::setDriveMode(DriveModeType value)
{
    std::lock_guard<std::mutex> lock(mutex);
    driveMode = value;
}

void ExecutiveData::setTorqueCommand(uint16_t value)
{
    std::lock_guard<std::mutex> lock(mutex);
    torqueCommand = value;
}

void ExecutiveData::setEnableVicore(bool value)
{
    std::lock_guard<std::mutex> lock(mutex);
    enableVicore = value;
}

void ExecutiveData::setVelocity(float value)
{
    std::lock_guard<std::mutex> lock(mutex);
    velocity = value;
}

void ExecutiveData::setCoastRegen(float value)
{
    std::lock_guard<std::mutex> lock(mutex);
    coastRegen = value;
}

void ExecutiveData::setBrakeRegen(float value)
{
    std::lock_guard<std::mutex> lock(mutex);
    brakeRegen = value;
}