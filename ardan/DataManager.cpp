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


/**
 * @brief DataManager::StartDataManager
 * @param portName
 * @param waitTimeout
 * @param carData
 */
void DataManager::StartDataManager(const QString &portName, int waitTimeout, CarData *carData)
{
    m_portName = portName;
    m_waitTimeout = waitTimeout;

    if (!isRunning())
        start();

    m_pCarData = carData;
}


/**
 * @brief DataManager::run
 */
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
            parseData(incomingData);

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


/**
 * @brief DataManager::parseData
 * @param incomingData
 */
void DataManager::parseData(QByteArray incomingData)
{
    // inits
    CarDataStruct carData;

    // collect struct from message
    memcpy((uint8_t *) &carData, incomingData, sizeof(carData));

//    qDebug() << carData.drivingData.readyToDrive;

    // driving
    m_pCarData->setReadyToDrive(carData.drivingData.readyToDrive);
    m_pCarData->setEnableInverter(carData.drivingData.enableInverter);
    m_pCarData->setPrechargeState(carData.drivingData.prechargeState);
    m_pCarData->setImdFault(carData.drivingData.imdFault);
    m_pCarData->setBmsFault(carData.drivingData.bmsFault);
    m_pCarData->setCurrentSpeed(carData.drivingData.currentSpeed);
    m_pCarData->setDriveDirection(carData.drivingData.driveDirection);
    m_pCarData->setDriveMode(carData.drivingData.driveMode);

    // battery status
    m_pCarData->setBatteryChargeState(carData.batteryStatus.batteryChargeState);
    m_pCarData->setBusVoltage(carData.batteryStatus.busVoltage);
    m_pCarData->setRinehartVoltage(carData.batteryStatus.rinehartVoltage);
    m_pCarData->setPack1Temp(carData.batteryStatus.pack1Temp);
    m_pCarData->setPack2Temp(carData.batteryStatus.pack2Temp);
    m_pCarData->setPackCurrent(carData.batteryStatus.packCurrent);
    m_pCarData->setMinCellVoltage(carData.batteryStatus.minCellVoltage);
    m_pCarData->setMaxCellVoltage(carData.batteryStatus.maxCellVoltage);

    // sensors
    m_pCarData->setVicoreTemp(carData.sensors.vicoreTemp);
    m_pCarData->setPumpTempIn(carData.sensors.pumpTempIn);
    m_pCarData->setPumpTempOut(carData.sensors.pumpTempOut);

    // inputs
    m_pCarData->setPedal0(carData.inputs.pedal0);
    m_pCarData->setPedal1(carData.inputs.pedal1);
    m_pCarData->setBrakeFront(carData.inputs.brakeFront);
    m_pCarData->setBrakeRegen(carData.inputs.brakeRegen);
    m_pCarData->setCoastRegen(carData.inputs.coastRegen);

    // outputs
    m_pCarData->setBuzzerActive(carData.outputs.buzzerActive);
    m_pCarData->setBuzzerCounter(carData.outputs.buzzerCounter);
    m_pCarData->setBrakeLight(carData.outputs.brakeLight);
    m_pCarData->setFansActive(carData.outputs.fansActive);
    m_pCarData->setPumpActive(carData.outputs.pumpActive);
}
