// Dominic Gasperini
// ARDAN

// includes
#include "Interface/DataManager.h"
#include "QSerialPortInfo"

/**
 * @brief SerialInterfaceManager::SerialInterfaceManager
 */
SerialInterfaceManager::SerialInterfaceManager(QObject *parent) : QThread(parent)
{
    // inits
    m_recording = false;
    m_recordingBuffered = false;
    m_recordingDuration = 0.0f;
    m_recordedData = {};
    m_pRecordingTimestamps = {};

    // init buffer
    m_rxBuffer = {};

    // data classes
    m_pExecutiveData = ExecutiveData::GetInstance();
    m_pGpioData      = GpioData::GetInstance();
    m_pTwaiData      = TwaiData::GetInstance();

    // configure port settings
    const auto availablePorts = QSerialPortInfo::availablePorts();
    if (!availablePorts.empty())
    {
        qDebug() << "SERIAL-> setting port name to: " << availablePorts.front().portName();
        m_port.setPortName(availablePorts.front().portName());
    }
    else
    {
        qDebug() << "SERIAL-> No available serial ports detected!";
        return;
    }

    // configure port
    m_port.setBaudRate(QSerialPort::Baud9600, QSerialPort::AllDirections);

    // data and error handeling signal and slot connections
    connect(&m_port, &QSerialPort::readyRead, this, &SerialInterfaceManager::ReadData);

    if (!m_port.open(QIODevice::ReadOnly))
    {
        qDebug() << "Failed to open serial port:" << m_port.errorString();
        return;
    }
}

/**
 * @brief SerialInterfaceManager::~SerialInterfaceManager
 */
SerialInterfaceManager::~SerialInterfaceManager()
{
    // nothing!
}

CarData SerialInterfaceManager::getRawData()
{
    return m_carData;
}

/**
 * @brief SerialInterfaceManager::getRecording
 * @return
 */
bool SerialInterfaceManager::getRecording() {
    return m_recording;
}


/**
 * @brief SerialInterfaceManager::getRecordingBuffered
 * @return
 */
bool SerialInterfaceManager::getRecordingBuffered() {
    return m_recordingBuffered;
}

/**
 * @brief SerialInterfaceManager::getRecordingDuration
 * @return
 */
float SerialInterfaceManager::getRecordingDuration() {
    return m_recordingDuration;
}


/**
 * @brief SerialInterfaceManager::getRecordedData
 * @return
 */
QVector<CarData> SerialInterfaceManager::getRecordedData()
{
    return m_recordedData;
}

/**
 * @brief SerialInterfaceManager::getRecordingTimestamps
 * @return
 */
QVector<float> SerialInterfaceManager::getRecordingTimestamps() {
    return m_pRecordingTimestamps;
}


/**
 * @brief SerialInterfaceManager::setRecording
 * @param state
 */
void SerialInterfaceManager::setRecording(bool state) {
    m_recording = state;
}


/**
 * @brief SerialInterfaceManager::setRecordingBuffered
 * @param state
 */
void SerialInterfaceManager::setRecordingBuffered(bool state) {
    m_recordingBuffered = state;
}

/**
 * @brief SerialInterfaceManager::setRecordingDuration
 * @param duration
 */
void SerialInterfaceManager::setRecordingDuration(float duration) {
    m_recordingDuration = duration;
}

/**
 * @brief SerialInterfaceManager::setRecordedData
 * @param vec
 */
void SerialInterfaceManager::setRecordedData(QVector<CarData> vec)
{
    m_recordedData = vec;
}

/**
 * @brief SerialInterfaceManager::setRecordingTimestamps
 * @param vec
 */
void SerialInterfaceManager::setRecordingTimestamps(QVector<float> vec) {
    m_pRecordingTimestamps = vec;
}

/**
 * @brief SerialInterfaceManager::onReadyRead
 */
void SerialInterfaceManager::ReadData()
{
    // inits
    bool       validMessage = false;
    QByteArray msg          = {};

    // read incoming serial data
    m_rxBuffer.append(m_port.readAll());

    if (m_rxBuffer.contains('\r'))
    {
        int newlineIndex = m_rxBuffer.indexOf('\r');
        msg              = m_rxBuffer.left(newlineIndex);

        validMessage = true;
    }

    qDebug() << "msg: " << m_rxBuffer;

    if (validMessage)
    {
        parseData(m_rxBuffer);
        m_rxBuffer.clear();
    }
}

/**
 * @brief SerialInterfaceManager::parseData
 * @param incomingData
 */
void SerialInterfaceManager::parseData(QByteArray incomingData)
{
    // inits
    CarData carData;

    // collect struct from message
    memcpy((uint8_t*)&carData, incomingData, sizeof(carData));

    // executive
    m_pExecutiveData->setSystemState(carData.executive.systemState);
    m_pExecutiveData->setPreviousSystemState(carData.executive.previousSystemState);
    m_pExecutiveData->setReadyToDrive(carData.executive.readyToDrive);
    m_pExecutiveData->setEnableInverter(carData.executive.enableInverter);
    m_pExecutiveData->setDriveDirection(carData.executive.driveDirection);
    m_pExecutiveData->setDriveMode(carData.executive.driveMode);
    m_pExecutiveData->setTorqueCommand(carData.executive.torqueCommand);
    m_pExecutiveData->setEnableVicore(carData.executive.enableVicore);
    m_pExecutiveData->setVelocity(carData.executive.velocity);
    m_pExecutiveData->setCoastRegen(carData.executive.coastRegen);
    m_pExecutiveData->setBrakeRegen(carData.executive.brakeRegen);

    // io
    // Faults
    m_pGpioData->setImdFault(carData.gpio.imdFault);
    m_pGpioData->setBmsFault(carData.gpio.bmsFault);
    m_pGpioData->setVicoreFault(carData.gpio.vicoreFault);

    // Cooling
    m_pGpioData->setCoolingTempIn(carData.gpio.coolingTempIn);
    m_pGpioData->setCoolingTempOut(carData.gpio.coolingTempOut);

    // Front wheels
    m_pGpioData->setFrontWheelsSpeed(carData.gpio.frontWheelsSpeed);
    m_pGpioData->setFrontWheelSpeedCount(carData.gpio.frontWheelSpeedCount);
    m_pGpioData->setFrontWheelSpeedTime(carData.gpio.frontWheelSpeedTime);

    // Back right wheel
    m_pGpioData->setBrWheelSpeed(carData.gpio.brWheelSpeed);
    m_pGpioData->setBrWheelSpeedCount(carData.gpio.brWheelSpeedCount);
    m_pGpioData->setBrWheelSpeedTime(carData.gpio.brWheelSpeedTime);

    // Back left wheel
    m_pGpioData->setBlWheelSpeed(carData.gpio.blWheelSpeed);
    m_pGpioData->setBlWheelSpeedCount(carData.gpio.blWheelSpeedCount);
    m_pGpioData->setBlWheelSpeedTime(carData.gpio.blWheelSpeedTime);

    // Inputs
    m_pGpioData->setPedal0(carData.gpio.pedal0);
    m_pGpioData->setPedal1(carData.gpio.pedal1);
    m_pGpioData->setFrontBrake(carData.gpio.frontBrake);
    m_pGpioData->setRearBrake(carData.gpio.rearBrake);

    // Outputs
    m_pGpioData->setVicoreEnable(carData.gpio.vicoreEnable);
    m_pGpioData->setBrakeLightEnable(carData.gpio.brakeLightEnable);
    m_pGpioData->setFansEnable(carData.gpio.fansEnable);
    m_pGpioData->setBuzzerEnable(carData.gpio.buzzerEnable);
    m_pGpioData->setprechargeCompleteLedEnable(carData.gpio.prechargeCompleteLedEnable);

    // twai
    m_pTwaiData->setRinehartRelayWord(carData.twai.rinehartRelayWord);
    m_pTwaiData->setRinehartTractiveWord(carData.twai.rinehartTractiveWord);
    m_pTwaiData->setRinehartBusVoltage(carData.twai.rinehartBusVoltage);
    m_pTwaiData->setBmsPackCurrent(carData.twai.bmsPackCurrent);
    m_pTwaiData->setBmsBusVoltage(carData.twai.bmsBusVoltage);
    m_pTwaiData->setBmsBatteryCharge(carData.twai.bmsBatteryCharge);

    // save
    // m_carData = carData;
}

/**
 * @brief SerialInterfaceManager::writeToFile
 * @param mode
 * @return
 */
int SerialInterfaceManager::writeToFile(int mode) {
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

    return 0;
}
