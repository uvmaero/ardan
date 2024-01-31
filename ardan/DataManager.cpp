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
    TelemetryCoreData carData;

    // collect struct from message
    memcpy((uint8_t *) &carData, incomingData, sizeof(carData));

//    qDebug() << carData.Tractive.readyToDrive;

    // tractive - tractive
    m_pCarData->setReadyToDrive(carData.tractiveCoreData.tractive.readyToDrive);
    m_pCarData->setEnableInverter(carData.tractiveCoreData.tractive.enableInverter);
    m_pCarData->setPrechargeState(carData.tractiveCoreData.tractive.prechargeState);
    m_pCarData->setRinehartVoltage(carData.tractiveCoreData.tractive.rinehartVoltage);
    m_pCarData->setCommandedTorque(carData.tractiveCoreData.tractive.commandedTorque);
    m_pCarData->setDriveDirection(carData.tractiveCoreData.tractive.driveDirection);
    m_pCarData->setDriveMode(carData.tractiveCoreData.tractive.driveMode);
    m_pCarData->setCurrentSpeed(carData.tractiveCoreData.tractive.currentSpeed);
    m_pCarData->setTractionControlEnable(carData.tractiveCoreData.tractive.tractionControlEnable);
    m_pCarData->setTractionControlModifier(carData.tractiveCoreData.tractive.tractionControlModifier);
    m_pCarData->setCoastRegen(carData.tractiveCoreData.tractive.coastRegen);
    m_pCarData->setCoastRegen(carData.tractiveCoreData.tractive.brakeRegen);

    // sensors
    m_pCarData->setImdFault(carData.tractiveCoreData.criticalSensors.imdFault);
    m_pCarData->setBmsFault(carData.tractiveCoreData.criticalSensors.bmsFault);
    m_pCarData->setVicoreTemp(carData.tractiveCoreData.criticalSensors.vicoreFault);
    m_pCarData->setPumpTempIn(carData.tractiveCoreData.criticalSensors.coolingTempIn);
    m_pCarData->setPumpTempOut(carData.tractiveCoreData.criticalSensors.coolingTempOut);
    m_pCarData->setFrontWheelsSpeed(carData.tractiveCoreData.criticalSensors.frontWheelsSpeed);
    m_pCarData->setWheelSpeedBR(carData.tractiveCoreData.criticalSensors.brWheelSpeed);
    m_pCarData->setWheelSpeedBL(carData.tractiveCoreData.criticalSensors.blWheelSpeed);

    // inputs
    m_pCarData->setPedal0(carData.tractiveCoreData.inputs.pedal0);
    m_pCarData->setPedal1(carData.tractiveCoreData.inputs.pedal1);
    m_pCarData->setBrakesFront(carData.tractiveCoreData.inputs.frontBrake);
    m_pCarData->setBrakesRear(carData.tractiveCoreData.inputs.rearBrake);

    // outputs
    m_pCarData->setVicoreEnable(carData.tractiveCoreData.outputs.vicoreEnable);
    m_pCarData->setBuzzerEnable(carData.tractiveCoreData.outputs.buzzerEnable);
    m_pCarData->setBrakeLightEnable(carData.tractiveCoreData.outputs.brakeLightEnable);
    m_pCarData->setFansEnable(carData.tractiveCoreData.outputs.fansEnable);

    // battery status
    // m_pCarData->setBatteryChargeState(carData.batteryStatus.batteryChargeState);
    // m_pCarData->setBusVoltage(carData.batteryStatus.busVoltage);
    // m_pCarData->setRinehartVoltage(carData.batteryStatus.rinehartVoltage);
    // m_pCarData->setPack1Temp(carData.batteryStatus.pack1Temp);
    // m_pCarData->setPack2Temp(carData.batteryStatus.pack2Temp);
    // m_pCarData->setPackCurrent(carData.batteryStatus.packCurrent);
    // m_pCarData->setMinCellVoltage(carData.batteryStatus.minCellVoltage);
    // m_pCarData->setMaxCellVoltage(carData.batteryStatus.maxCellVoltage);

    // telemetry

}
