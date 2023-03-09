
// includes
#include "ElectricalData.h"


// defines


/**
 * @brief ElectricalData::ElectricalData
 */
ElectricalData::ElectricalData()
{

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

