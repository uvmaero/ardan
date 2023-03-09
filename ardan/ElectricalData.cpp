
// includes
#include "ElectricalData.h"


// defines


/**
 * @brief ElectricalData::ElectricalData
 */
ElectricalData::ElectricalData()
{
    // init electrical data
    m_averageCellVoltage = 0.0f;
    m_minCellVoltage = 0.0f;
    m_maxCellVoltage = 0.0f;

    m_batteryPercentage = 0.0f;
    m_busVoltage = 0.0f;
    m_busCurrent = 0.0f;
    m_rinehartVoltage = 0.0f;

    m_minCellTemp = 0.0f;
    m_maxCellTemp = 0.0f;
    m_averageCellTemp = 0.0f;

    m_wheelBoardConnectionStatus = false;
}


// --- getters --- //

/**
 * @brief ElectricalData::getAverageCellVoltage
 * @return
 */
float ElectricalData::getAverageCellVoltage() {
    QReadLocker locker(&m_lock);

    return m_averageCellVoltage;
}

/**
 * @brief ElectricalData::getMinCellVoltage
 * @return
 */
float ElectricalData::getMinCellVoltage() {
    QReadLocker locker(&m_lock);

    return m_minCellVoltage;
}

/**
 * @brief ElectricalData::getMaxCellVoltage
 * @return
 */
float ElectricalData::getMaxCellVoltage() {
    QReadLocker locker(&m_lock);

    return m_maxCellVoltage;
}

/**
 * @brief ElectricalData::getBatteryPercentage
 * @return
 */
float ElectricalData::getBatteryPercentage() {
    QReadLocker locker(&m_lock);

    return m_batteryPercentage;
}

/**
 * @brief ElectricalData::getBusVoltage
 * @return
 */
float ElectricalData::getBusVoltage() {
    QReadLocker locker(&m_lock);

    return m_busVoltage;
}

/**
 * @brief ElectricalData::getBusCurrent
 * @return
 */
float ElectricalData::getBusCurrent() {
    QReadLocker locker(&m_lock);

    return m_busCurrent;
}

/**
 * @brief ElectricalData::getRinehartVoltage
 * @return
 */
float ElectricalData::getRinehartVoltage() {
    QReadLocker locker(&m_lock);

    return m_rinehartVoltage;
}

/**
 * @brief ElectricalData::getMinCellTemp
 * @return
 */
float ElectricalData::getMinCellTemp() {
    QReadLocker locker(&m_lock);

    return m_minCellTemp;
}

/**
 * @brief ElectricalData::getMaxCellTemp
 * @return
 */
float ElectricalData::getMaxCellTemp() {
    QReadLocker locker(&m_lock);

    return m_maxCellTemp;
}

/**
 * @brief ElectricalData::getAverageCellTemp
 * @return
 */
float ElectricalData::getAverageCellTemp() {
    QReadLocker locker(&m_lock);

    return m_averageCellTemp;
}

/**
 * @brief ElectricalData::getWheelBoardConnectionStatus
 * @return
 */
bool ElectricalData::getWheelBoardConnectionStatus() {
    QReadLocker locker(&m_lock);

    return m_wheelBoardConnectionStatus;
}


// --- setters --- //

/**
 * @brief ElectricalData::setAverageCellVoltage
 * @param num
 */
void ElectricalData::setAverageCellVoltage(float num) {
    QWriteLocker locker(&m_lock);

    m_averageCellVoltage = num;
}

/**
 * @brief ElectricalData::setMinCellVoltage
 * @param num
 */
void ElectricalData::setMinCellVoltage(float num) {
    QWriteLocker locker(&m_lock);

    m_minCellVoltage = num;
}

/**
 * @brief ElectricalData::setMaxCellVoltage
 * @param num
 */
void ElectricalData::setMaxCellVoltage(float num) {
    QWriteLocker locker(&m_lock);

    m_maxCellVoltage = num;
}

/**
 * @brief ElectricalData::setBatteryPercentage
 * @param num
 */
void ElectricalData::setBatteryPercentage(float num) {
    QWriteLocker locker(&m_lock);

    m_batteryPercentage = num;
}

/**
 * @brief ElectricalData::setBusVoltage
 * @param num
 */
void ElectricalData::setBusVoltage(float num) {
    QWriteLocker locker(&m_lock);

    m_busVoltage = num;
}

/**
 * @brief ElectricalData::setBusCurrent
 * @param num
 */
void ElectricalData::setBusCurrent(float num) {
    QWriteLocker locker(&m_lock);

    m_busCurrent = num;
}

/**
 * @brief ElectricalData::setRinehartVoltage
 * @param num
 */
void ElectricalData::setRinehartVoltage(float num) {
    QWriteLocker locker(&m_lock);

    m_rinehartVoltage = num;
}

/**
 * @brief ElectricalData::setMinCellTemp
 * @param num
 */
void ElectricalData::setMinCellTemp(float num) {
    QWriteLocker locker(&m_lock);

    m_minCellTemp = num;
}

/**
 * @brief ElectricalData::setMaxCellTemp
 * @param num
 */
void ElectricalData::setMaxCellTemp(float num) {
    QWriteLocker locker(&m_lock);

    m_maxCellTemp = num;
}

/**
 * @brief ElectricalData::setAverageCellTemp
 * @param num
 */
void ElectricalData::setAverageCellTemp(float num) {
    QWriteLocker locker(&m_lock);

    m_averageCellTemp = num;
}

/**
 * @brief ElectricalData::setWheelBoardConnectionStatus
 * @param status
 */
void ElectricalData::setWheelBoardConnectionStatus(bool status) {
    QWriteLocker locker(&m_lock);

    m_wheelBoardConnectionStatus = status;
}
