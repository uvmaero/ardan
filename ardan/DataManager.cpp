// Dominic Gasperini
// ARDAN

// includes
#include "DataManager.h"

// defines
#define READ_SERIAL_INTERVAL        1      // in milliseconds

/**
 * @brief DataManager::DataManager
 */
DataManager::DataManager()
{
    // init timers
    m_pReadTimer = new QTimer();
    m_pReadTimer->setInterval(READ_SERIAL_INTERVAL);
    connect(m_pReadTimer, SIGNAL(timeout()), this, SLOT(parseData()));


}


/**
 * @brief DataManager::parseData
 */
void DataManager::parseData() {
    // read data


    // update data classes

}
