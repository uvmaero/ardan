
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


// --- getters --- //

/**
 * @brief MechanicalData::getSpeed
 * @return
 */
float MechanicalData::getSpeed() {
    QReadLocker locker(&m_lock);

    return m_speed;
}

/**
 * @brief MechanicalData::getBrakePosition
 * @return
 */
float MechanicalData::getBrakePosition() {
    QReadLocker locker(&m_lock);

    return m_brakePosition;
}

/**
 * @brief MechanicalData::getAcceloratorPosition
 * @return
 */
float MechanicalData::getAcceloratorPosition() {
    QReadLocker locker(&m_lock);

    return m_acceloratorPosition;
}

/**
 * @brief MechanicalData::getDriveMode
 * @return
 */
DriveModes MechanicalData::getDriveMode() {
    QReadLocker locker(&m_lock);

    return m_driveMode;
}

/**
 * @brief MechanicalData::getFRWheelSpeed
 * @return
 */
float MechanicalData::getFRWheelSpeed() {
    QReadLocker locker(&m_lock);

    return m_FRWheelSpeed;
}

/**
 * @brief MechanicalData::getFLWheelSpeed
 * @return
 */
float MechanicalData::getFLWheelSpeed() {
    QReadLocker locker(&m_lock);

    return m_FLWheelSpeed;
}

/**
 * @brief MechanicalData::getBRWheelSpeed
 * @return
 */
float MechanicalData::getBRWheelSpeed() {
    QReadLocker locker(&m_lock);

    return m_BRWheelSpeed;
}

/**
 * @brief MechanicalData::getBLWheelSpeed
 * @return
 */
float MechanicalData::getBLWheelSpeed() {
    QReadLocker locker(&m_lock);

    return m_BLWheelSpeed;
}

/**
 * @brief MechanicalData::getFRWheelHeight
 * @return
 */
float MechanicalData::getFRWheelHeight() {
    QReadLocker locker(&m_lock);

    return m_FRWheelHeight;
}

/**
 * @brief MechanicalData::getFLWheelHeight
 * @return
 */
float MechanicalData::getFLWheelHeight() {
    QReadLocker locker(&m_lock);

    return m_FLWheelHeight;
}

/**
 * @brief MechanicalData::getBRWheelHeight
 * @return
 */
float MechanicalData::getBRWheelHeight() {
    QReadLocker locker(&m_lock);

    return m_BRWheelHeight;
}

/**
 * @brief MechanicalData::getBLWheelHeight
 * @return
 */
float MechanicalData::getBLWheelHeight() {
    QReadLocker locker(&m_lock);

    return m_BLWheelHeight;
}


// --- setters --- //

/**
 * @brief MechanicalData::setSpeed
 * @param num
 */
void MechanicalData::setSpeed(float num) {
    QWriteLocker locker(&m_lock);

    m_speed = num;
}

/**
 * @brief MechanicalData::setBrakePosition
 * @param num
 */
void MechanicalData::setBrakePosition(float num) {
    QWriteLocker locker(&m_lock);

    m_brakePosition = num;
}

/**
 * @brief MechanicalData::setAcceloratorPosition
 * @param num
 */
void MechanicalData::setAcceloratorPosition(float num) {
    QWriteLocker locker(&m_lock);

    m_acceloratorPosition = num;
}

/**
 * @brief MechanicalData::setDriveMode
 * @param mode
 */
void MechanicalData::setDriveMode(DriveModes mode) {
    QWriteLocker locker(&m_lock);

    m_driveMode = mode;
}

/**
 * @brief MechanicalData::setFRWheelSpeed
 * @param num
 */
void MechanicalData::setFRWheelSpeed(float num) {
    QWriteLocker locker(&m_lock);

    m_FRWheelSpeed = num;
}

/**
 * @brief MechanicalData::setFLWheelSpeed
 * @param num
 */
void MechanicalData::setFLWheelSpeed(float num) {
    QWriteLocker locker(&m_lock);

    m_FLWheelSpeed = num;
}

/**
 * @brief MechanicalData::setBRWheelSpeed
 * @param num
 */
void MechanicalData::setBRWheelSpeed(float num) {
    QWriteLocker locker(&m_lock);

    m_BRWheelSpeed = num;
}

/**
 * @brief MechanicalData::setBLWheelSpeed
 * @param num
 */
void MechanicalData::setBLWheelSpeed(float num) {
    QWriteLocker locker(&m_lock);

    m_BLWheelSpeed = num;
}

/**
 * @brief MechanicalData::setFRWheelHeight
 * @param num
 */
void MechanicalData::setFRWheelHeight(float num) {
    QWriteLocker locker(&m_lock);

    m_FRWheelHeight = num;
}

/**
 * @brief MechanicalData::setFLWheelHeight
 * @param num
 */
void MechanicalData::setFLWheelHeight(float num) {
    QWriteLocker locker(&m_lock);

    m_FLWheelHeight = num;
}

/**
 * @brief MechanicalData::setBRWheelHeight
 * @param num
 */
void MechanicalData::setBRWheelHeight(float num) {
    QWriteLocker locker(&m_lock);

    m_BRWheelHeight = num;
}

/**
 * @brief MechanicalData::setBLWheelHeight
 * @param num
 */
void MechanicalData::setBLWheelHeight(float num) {
    QWriteLocker locker(&m_lock);

    m_BLWheelHeight = num;
}
