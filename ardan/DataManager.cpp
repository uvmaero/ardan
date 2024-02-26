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
    // inits
    m_recording = false;
    m_recordingBuffered = false;
    m_recordingDuration = 0.0f;
    m_recordedData = {};
    m_pRecordingTimestamps = {};
}


/**
 * @brief DataManager::~DataManager
 */
DataManager::~DataManager()
{
    // nothing!
}


/**
 * @brief DataManager::getRawData
 * @return
 */
TelemetryCoreData DataManager::getRawData() {
    return m_carData;
}


/**
 * @brief DataManager::getRecording
 * @return
 */
bool DataManager::getRecording() {
    return m_recording;
}


/**
 * @brief DataManager::getRecordingBuffered
 * @return
 */
bool DataManager::getRecordingBuffered() {
    return m_recordingBuffered;
}

/**
 * @brief DataManager::getRecordingDuration
 * @return
 */
float DataManager::getRecordingDuration() {
    return m_recordingDuration;
}


/**
 * @brief DataManager::getRecordedData
 * @return
 */
QVector<TelemetryCoreData> DataManager::getRecordedData() {
    return m_recordedData;
}


/**
 * @brief DataManager::getRecordingTimestamps
 * @return
 */
QVector<float> DataManager::getRecordingTimestamps() {
    return m_pRecordingTimestamps;
}


/**
 * @brief DataManager::setRecording
 * @param state
 */
void DataManager::setRecording(bool state) {
    m_recording = state;
}


/**
 * @brief DataManager::setRecordingBuffered
 * @param state
 */
void DataManager::setRecordingBuffered(bool state) {
    m_recordingBuffered = state;
}

/**
 * @brief DataManager::setRecordingDuration
 * @param duration
 */
void DataManager::setRecordingDuration(float duration) {
    m_recordingDuration = duration;
}

/**
 * @brief DataManager::setRecordedData
 * @param vec
 */
void DataManager::setRecordedData(QVector<TelemetryCoreData> vec) {
    m_recordedData = vec;
}


/**
 * @brief DataManager::setRecordingTimestamps
 * @param vec
 */
void DataManager::setRecordingTimestamps(QVector<float> vec) {
    m_pRecordingTimestamps = vec;
}

/**
 * @brief DataManager::StartDataManager
 * @param portName
 * @param waitTimeout
 * @param m_carData
 */
void DataManager::StartDataManager(const QString &portName, int waitTimeout, CarData *m_carData)
{
    m_portName = portName;
    m_waitTimeout = waitTimeout;

    if (!isRunning())
        start();

    m_pCarData = m_carData;
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
    // collect struct from message
    memcpy((uint8_t *) &m_carData, incomingData, sizeof(m_carData));

//    qDebug() << m_carData.Tractive.readyToDrive;

    // tractive - tractive
    m_pCarData->setReadyToDrive(m_carData.tractiveCoreData.tractive.readyToDrive);
    m_pCarData->setEnableInverter(m_carData.tractiveCoreData.tractive.enableInverter);
    m_pCarData->setPrechargeState(m_carData.tractiveCoreData.tractive.prechargeState);
    m_pCarData->setRinehartVoltage(m_carData.tractiveCoreData.tractive.rinehartVoltage);
    m_pCarData->setCommandedTorque(m_carData.tractiveCoreData.tractive.commandedTorque);
    m_pCarData->setDriveDirection(m_carData.tractiveCoreData.tractive.driveDirection);
    m_pCarData->setDriveMode(m_carData.tractiveCoreData.tractive.driveMode);
    m_pCarData->setCurrentSpeed(m_carData.tractiveCoreData.tractive.currentSpeed);
    m_pCarData->setTractionControlEnable(m_carData.tractiveCoreData.tractive.tractionControlEnable);
    m_pCarData->setTractionControlModifier(m_carData.tractiveCoreData.tractive.tractionControlModifier);
    m_pCarData->setCoastRegen(m_carData.tractiveCoreData.tractive.coastRegen);
    m_pCarData->setCoastRegen(m_carData.tractiveCoreData.tractive.brakeRegen);

    // sensors
    m_pCarData->setImdFault(m_carData.tractiveCoreData.criticalSensors.imdFault);
    m_pCarData->setBmsFault(m_carData.tractiveCoreData.criticalSensors.bmsFault);
    m_pCarData->setVicoreFault(m_carData.tractiveCoreData.criticalSensors.vicoreFault);
    m_pCarData->setPumpTempIn(m_carData.tractiveCoreData.criticalSensors.coolingTempIn);
    m_pCarData->setPumpTempOut(m_carData.tractiveCoreData.criticalSensors.coolingTempOut);
    m_pCarData->setFrontWheelsSpeed(m_carData.tractiveCoreData.criticalSensors.frontWheelsSpeed);
    m_pCarData->setWheelSpeedBR(m_carData.tractiveCoreData.criticalSensors.brWheelSpeed);
    m_pCarData->setWheelSpeedBL(m_carData.tractiveCoreData.criticalSensors.blWheelSpeed);

    // inputs
    m_pCarData->setPedal0(m_carData.tractiveCoreData.inputs.pedal0);
    m_pCarData->setPedal1(m_carData.tractiveCoreData.inputs.pedal1);
    m_pCarData->setBrakesFront(m_carData.tractiveCoreData.inputs.frontBrake);
    m_pCarData->setBrakesRear(m_carData.tractiveCoreData.inputs.rearBrake);

    // outputs
    m_pCarData->setVicoreEnable(m_carData.tractiveCoreData.outputs.vicoreEnable);
    m_pCarData->setBuzzerEnable(m_carData.tractiveCoreData.outputs.buzzerEnable);
    m_pCarData->setBrakeLightEnable(m_carData.tractiveCoreData.outputs.brakeLightEnable);
    m_pCarData->setFansEnable(m_carData.tractiveCoreData.outputs.fansEnable);

    // battery status
    // m_pCarData->setBatteryChargeState(m_carData.batteryStatus.batteryChargeState);
    // m_pCarData->setBusVoltage(m_carData.batteryStatus.busVoltage);
    // m_pCarData->setRinehartVoltage(m_carData.batteryStatus.rinehartVoltage);
    // m_pCarData->setPack1Temp(m_carData.batteryStatus.pack1Temp);
    // m_pCarData->setPack2Temp(m_carData.batteryStatus.pack2Temp);
    // m_pCarData->setPackCurrent(m_carData.batteryStatus.packCurrent);
    // m_pCarData->setMinCellVoltage(m_carData.batteryStatus.minCellVoltage);
    // m_pCarData->setMaxCellVoltage(m_carData.batteryStatus.maxCellVoltage);

    // telemetry
    m_pCarData->setSuspensionDamperFR(m_carData.dampers.frSuspensionDamper);
    m_pCarData->setSuspensionDamperFL(m_carData.dampers.flSuspensionDamper);
    m_pCarData->setSuspensionDamperBR(m_carData.dampers.brSuspensionDamper);
    m_pCarData->setSuspensionDamperBL(m_carData.dampers.blSuspensionDamper);

    m_pCarData->setTireTempFR(m_carData.tireTemp.frTireTemp);
    m_pCarData->setTireTempFL(m_carData.tireTemp.flTireTemp);
    m_pCarData->setTireTempBR(m_carData.tireTemp.brTireTemp);
    m_pCarData->setTireTempBL(m_carData.tireTemp.blTireTemp);

    m_pCarData->setFRStrain1(m_carData.strain.frStrain1);
    m_pCarData->setFLStrain1(m_carData.strain.flStrain1);
    m_pCarData->setBRStrain1(m_carData.strain.brStrain1);
    m_pCarData->setBLStrain1(m_carData.strain.blStrain1);

    m_pCarData->setFRStrain2(m_carData.strain.frStrain2);
    m_pCarData->setFLStrain2(m_carData.strain.flStrain2);
    m_pCarData->setBRStrain2(m_carData.strain.brStrain2);
    m_pCarData->setBLStrain2(m_carData.strain.blStrain2);

    m_pCarData->setSteeringWheelDeflection(m_carData.steering.steeringWheelDeflection);

    m_pCarData->setXAcceleration(m_carData.imu.xAcceleration);
    m_pCarData->setYAcceleration(m_carData.imu.yAcceleration);
    m_pCarData->setZAcceleration(m_carData.imu.zAcceleration);

    m_pCarData->setXGyro(m_carData.imu.xGyro);
    m_pCarData->setYGyro(m_carData.imu.yGyro);
    m_pCarData->setZGyro(m_carData.imu.zGyro);

    m_pCarData->setLatitude(m_carData.gps.latitide);
    m_pCarData->setLongitude(m_carData.gps.longitude);
    m_pCarData->setAltitude(m_carData.gps.altitude);

    m_pCarData->setGPSYear(m_carData.gps.year);
    m_pCarData->setGPSMonth(m_carData.gps.month);
    m_pCarData->setGPSDay(m_carData.gps.day);
}


/**
 * @brief DataManager::writeToFile
 * @param mode
 * @return
 */
int DataManager::writeToFile(int mode) {
    // inits

    // write mode
    switch (mode) {
    case 1:

        break;
    case 2:
        break;

    default:
        break;
    }

}
