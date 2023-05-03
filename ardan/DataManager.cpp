// Dominic Gasperini
// ARDAN

// includes
#include "DataManager.h"

// defines
#define READ_SERIAL_INTERVAL        1      // in milliseconds


/**
 * @brief DataManager::DataManager
 */
DataManager::DataManager(QObject *parent) : QThread(parent)
{
    // nothing!
}


/**
 * @brief DataManager::~DataManager
 */
DataManager::~DataManager()
{
    // nothing!
}


void DataManager::StartDataManager(const QString &portName, int waitTimeout)
{
    m_portName = portName;
    m_waitTimeout = waitTimeout;

    if (!isRunning())
        start();
}


void DataManager::run()
{
    bool currentPortNameChanged = false;

    QString currentPortName;
    if (currentPortName != m_portName) {
        currentPortName = m_portName;
        currentPortNameChanged = true;
    }

    int currentWaitTimeout = m_waitTimeout;

    QSerialPort serial;

    while (!m_quit) {

        if (currentPortNameChanged) {
            serial.close();
            serial.setPortName(currentPortName);

            if (!serial.open(QIODevice::ReadOnly)) {
                emit error(tr("Can't open %1, error code %2").arg(m_portName).arg(serial.error()));
                return;
            }
        }

        if (serial.waitForReadyRead(currentWaitTimeout))
        {
            // read data
            QByteArray incomingData = serial.readAll();
            while (serial.waitForReadyRead(10))
            {
                incomingData += serial.readAll();
            }
            qDebug() << incomingData;

            // parse out data
//            parseData(incomingData);

        } else {
            emit timeout(tr("Wait read request timeout %1").arg(QTime::currentTime().toString()));
        }

        if (currentPortName != m_portName) {
            currentPortName = m_portName;
            currentPortNameChanged = true;
        } else {
            currentPortNameChanged = false;
        }
        currentWaitTimeout = m_waitTimeout;
    }
}

void DataManager::parseData(QByteArray incomingData)
{
    // inits
    bool tmpBool;
    PrechargeStates tmpPrechargeState;
    uint8_t tmpUInt8;
    uint16_t tmpUInt16;
    uint64_t tmpUInt64;
    float tmpFloat;

    QDataStream stream;

    // parse data
//    stream << incomingData;

}
