// Dominic Gasperini
// ARDAN

// includes
#include "DataManager.h"

// defines
#define READ_SERIAL_INTERVAL        1      // in milliseconds

/**
 * @brief DataManager::DataManager
 */
DataManager::DataManager(MechanicalData *mechanicalData, ElectricalData *electricalData)
{
    // connect to data classes
    m_pMechanicalData = mechanicalData;
    m_pElectricalData = electricalData;

    m_serialConnected = false;

    // init serial port
//    m_esp = new QSerialPort();
//    m_esp->setPortName("esp32");
//    m_esp->open(QSerialPort::ReadOnly);
//    m_esp->setBaudRate(9600);
//    m_esp->setDataBits(QSerialPort::Data8);
//    m_esp->setParity(QSerialPort::NoParity);
//    m_esp->setStopBits(QSerialPort::OneStop);
//    m_esp->setFlowControl(QSerialPort::NoFlowControl);

    // call parse data
//    parseData();
}


/**
 * @brief DataManager::parseData
 */
void DataManager::parseData() {
    while (1) {
        QByteArray ba;
        while(m_esp->canReadLine()){
            ba = m_esp->readLine();
            qDebug() << ba;
        }


        // update data classes

    }
}
