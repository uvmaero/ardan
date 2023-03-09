
// includes
#include "MechanicalData.h"


// defines


/**
 * @brief MechanicalData::MechanicalData
 */
MechanicalData::MechanicalData()
{
    // init variables
    m_speed = 0.0f;
    m_brakePosition = 0.0f;
    m_acceloratorPosition = 0.0f;
    m_driveMode = SLOW;

    m_FRWheelSpeed = 0.0f;
    m_FLWheelSpeed = 0.0f;
    m_BRWheelSpeed = 0.0f;
    m_BLWheelSpeed = 0.0f;

    m_FRWheelHeight = 0.0f;
    m_FLWheelHeight = 0.0f;
    m_BRWheelHeight = 0.0f;
    m_BLWheelHeight = 0.0f;
}


// --- setters --- //

float MechanicalData::getSpeed() {
    QReadLocker locker(&m_lock);

    return m_speed;
}

float MechanicalData::getBrakePosition() {
    QReadLocker locker(&m_lock);

    return m_brakePosition;
}

float MechanicalData::getAcceloratorPosition() {
    QReadLocker locker(&m_lock);

    return m_acceloratorPosition;
}

DriveModes MechanicalData::getDriveMode() {
    QReadLocker locker(&m_lock);

    return m_driveMode;
}

float MechanicalData::getFRWheelSpeed() {
    QReadLocker locker(&m_lock);

    return m_FRWheelSpeed;
}

float MechanicalData::getFLWheelSpeed() {
    QReadLocker locker(&m_lock);

    return m_FLWheelSpeed;
}

float MechanicalData::getBRWheelSpeed() {
    QReadLocker locker(&m_lock);

    return m_BRWheelSpeed;
}

float MechanicalData::getBLWheelSpeed() {
    QReadLocker locker(&m_lock);

    return m_BLWheelSpeed;
}

float MechanicalData::getFRWheelHeight() {
    QReadLocker locker(&m_lock);

    return m_FRWheelHeight;
}

float MechanicalData::getFLWheelHeight() {
    QReadLocker locker(&m_lock);

    return m_FLWheelHeight;
}

float MechanicalData::getBRWheelHeight() {
    QReadLocker locker(&m_lock);

    return m_BRWheelHeight;
}

float MechanicalData::getBLWheelHeight() {
    QReadLocker locker(&m_lock);

    return m_BLWheelHeight;
}


// --- getters --- //

