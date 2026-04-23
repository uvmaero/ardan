/**
 * @file GpioData.cpp
 * @brief
 * @date 2026-04-16
 */

/*
===============================================================================================
                                   includes
===============================================================================================
*/

#include "Data/GpioData.h"

/*
===============================================================================================
                                    class
===============================================================================================
*/

GpioData::GpioData()
{
    // Initialize faults
    imdFault = false;
    bmsFault = false;
    vicoreFault = false;

    // Cooling temperatures
    coolingTempIn = 0.0f;
    coolingTempOut = 0.0f;

    // Front wheels
    frontWheelsSpeed = 0.0f;
    frontWheelSpeedCount = 0;
    frontWheelSpeedTime = 0;

    // Back right wheel
    brWheelSpeed = 0.0f;
    brWheelSpeedCount = 0;
    brWheelSpeedTime = 0;

    // Back left wheel
    blWheelSpeed = 0.0f;
    blWheelSpeedCount = 0;
    blWheelSpeedTime = 0;

    // Inputs
    pedal0 = 0;
    pedal1 = 0;
    frontBrake = 0;
    rearBrake = 0;

    // Outputs
    vicoreEnable = false;
    brakeLightEnable = false;
    fansEnable = false;
    buzzerEnable = false;
}

// Fault getters and setters
bool GpioData::getImdFault() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return imdFault;
}

void GpioData::setImdFault(bool value)
{
    std::lock_guard<std::mutex> lock(mutex);
    imdFault = value;
}

bool GpioData::getBmsFault() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return bmsFault;
}

void GpioData::setBmsFault(bool value)
{
    std::lock_guard<std::mutex> lock(mutex);
    bmsFault = value;
}

bool GpioData::getVicoreFault() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return vicoreFault;
}

void GpioData::setVicoreFault(bool value)
{
    std::lock_guard<std::mutex> lock(mutex);
    vicoreFault = value;
}

// Cooling temperature getters and setters
float GpioData::getCoolingTempIn() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return coolingTempIn;
}

void GpioData::setCoolingTempIn(float value)
{
    std::lock_guard<std::mutex> lock(mutex);
    coolingTempIn = value;
}

float GpioData::getCoolingTempOut() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return coolingTempOut;
}

void GpioData::setCoolingTempOut(float value)
{
    std::lock_guard<std::mutex> lock(mutex);
    coolingTempOut = value;
}

// Front wheels getters and setters
float GpioData::getFrontWheelsSpeed() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return frontWheelsSpeed;
}

void GpioData::setFrontWheelsSpeed(float value)
{
    std::lock_guard<std::mutex> lock(mutex);
    frontWheelsSpeed = value;
}

int GpioData::getFrontWheelSpeedCount() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return frontWheelSpeedCount;
}

void GpioData::setFrontWheelSpeedCount(int value)
{
    std::lock_guard<std::mutex> lock(mutex);
    frontWheelSpeedCount = value;
}

int GpioData::getFrontWheelSpeedTime() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return frontWheelSpeedTime;
}

void GpioData::setFrontWheelSpeedTime(int value)
{
    std::lock_guard<std::mutex> lock(mutex);
    frontWheelSpeedTime = value;
}

// Back right wheel getters and setters
float GpioData::getBrWheelSpeed() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return brWheelSpeed;
}

void GpioData::setBrWheelSpeed(float value)
{
    std::lock_guard<std::mutex> lock(mutex);
    brWheelSpeed = value;
}

int GpioData::getBrWheelSpeedCount() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return brWheelSpeedCount;
}

void GpioData::setBrWheelSpeedCount(int value)
{
    std::lock_guard<std::mutex> lock(mutex);
    brWheelSpeedCount = value;
}

int GpioData::getBrWheelSpeedTime() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return brWheelSpeedTime;
}

void GpioData::setBrWheelSpeedTime(int value)
{
    std::lock_guard<std::mutex> lock(mutex);
    brWheelSpeedTime = value;
}

// Back left wheel getters and setters
float GpioData::getBlWheelSpeed() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return blWheelSpeed;
}

void GpioData::setBlWheelSpeed(float value)
{
    std::lock_guard<std::mutex> lock(mutex);
    blWheelSpeed = value;
}

int GpioData::getBlWheelSpeedCount() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return blWheelSpeedCount;
}

void GpioData::setBlWheelSpeedCount(int value)
{
    std::lock_guard<std::mutex> lock(mutex);
    blWheelSpeedCount = value;
}

int GpioData::getBlWheelSpeedTime() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return blWheelSpeedTime;
}

void GpioData::setBlWheelSpeedTime(int value)
{
    std::lock_guard<std::mutex> lock(mutex);
    blWheelSpeedTime = value;
}

// Input getters and setters
int GpioData::getPedal0() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return pedal0;
}

void GpioData::setPedal0(int value)
{
    std::lock_guard<std::mutex> lock(mutex);
    pedal0 = value;
}

int GpioData::getPedal1() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return pedal1;
}

void GpioData::setPedal1(int value)
{
    std::lock_guard<std::mutex> lock(mutex);
    pedal1 = value;
}

int GpioData::getFrontBrake() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return frontBrake;
}

void GpioData::setFrontBrake(int value)
{
    std::lock_guard<std::mutex> lock(mutex);
    frontBrake = value;
}

int GpioData::getRearBrake() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return rearBrake;
}

void GpioData::setRearBrake(int value)
{
    std::lock_guard<std::mutex> lock(mutex);
    rearBrake = value;
}

// Output getters and setters
bool GpioData::getVicoreEnable() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return vicoreEnable;
}

void GpioData::setVicoreEnable(bool value)
{
    std::lock_guard<std::mutex> lock(mutex);
    vicoreEnable = value;
}

bool GpioData::getBrakeLightEnable() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return brakeLightEnable;
}

void GpioData::setBrakeLightEnable(bool value)
{
    std::lock_guard<std::mutex> lock(mutex);
    brakeLightEnable = value;
}

bool GpioData::getFansEnable() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return fansEnable;
}

void GpioData::setFansEnable(bool value)
{
    std::lock_guard<std::mutex> lock(mutex);
    fansEnable = value;
}

bool GpioData::getBuzzerEnable() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return buzzerEnable;
}

void GpioData::setBuzzerEnable(bool value)
{
    std::lock_guard<std::mutex> lock(mutex);
    buzzerEnable = value;
}

bool GpioData::getprechargeCompleteLedEnable() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return prechargeCompleteLedEnable;
}

void GpioData::setprechargeCompleteLedEnable(bool value)
{
    std::lock_guard<std::mutex> lock(mutex);
    prechargeCompleteLedEnable = value;
}