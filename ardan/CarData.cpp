// Dominic Gasperini
// ARDAN

// includes
#include "CarData.h"

/**
 * @brief CarData::CarData
 */
CarData::CarData()
{
    // init variables
    // tractive core - tractive
    m_readyToDrive = false;
    m_enableInverter = false;
    m_prechargeState = PRECHARGE_OFF;
    m_rinehartVoltage = 0.0f;
    m_commandedTorque = 0;
    m_driveDirection = false;    // for
    m_driveMode = ECO;
    m_currentSpeed = 0.0f;
    m_tractionControlEnable = true;
    m_tractionControlModifier = 1.00f;
    m_coastRegen = 0;

    // tractive core - sensors
    m_imdFault = true;
    m_bmsFault = true;
    m_coolingTempIn = 0.0f;
    m_coolingTempOut = 0.0f;
    m_vicoreTemp = 0.0f;
    m_glvReading = 0.0f;
    m_frontWheelsSpeed = 0.0f;
    m_frontWheelSpeedCount = 0;
    m_frontWheelSpeedTime = 0;
    m_brWheelSpeed = 0.0f;
    m_brWheelSpeedCount = 0;
    m_brWheelSpeedTime = 0;
    m_blWheelSpeed = 0.0f;
    m_blWheelSpeedCount = 0;
    m_blWheelSpeedTime = 0;

    // tractive core - inputs
    m_pedal0 = 0;
    m_pedal1 = 0;
    m_frontBrake = 0;
    m_rearBrake = 0;

    // tractive core - outputs
    m_driveModeLED = ECO;
    m_brakeLightEnable = false;
    m_fansEnable = false;
    m_buzzerEnable = false;

    // orion
    m_batteryChargeState = 0;
    m_busVoltage = 0;
    m_packCurrent = 0.0f;
    m_minCellVoltage = 0.0f;
    m_maxCellVoltage = 0.0f;
    m_minCellTemp = 0.0f;
    m_maxCellTemp = 0.0f;
}


// --- Setters & Getters --- //
bool CarData::getReadyToDrive() {
    QReadLocker locker(&m_lock);

    return m_readyToDrive;
}

void CarData::setReadyToDrive(bool ready) {
    QWriteLocker locker(&m_lock);

    m_readyToDrive = ready;
}

bool CarData::getEnableInverter() {
    QReadLocker locker(&m_lock);

    return m_enableInverter;
}

void CarData::setEnableInverter(bool enable) {
    QWriteLocker locker(&m_lock);

    m_enableInverter = enable;
}

PrechargeStates CarData::getPrechargeState()  {
    QReadLocker locker(&m_lock);

    return m_prechargeState;
}

void CarData::setPrechargeState(PrechargeStates state) {
    QWriteLocker locker(&m_lock);

    m_prechargeState = state;
}

bool CarData::getImdFault()  {
    QReadLocker locker(&m_lock);

    return m_imdFault;
}

void CarData::setImdFault(bool fault) {
    QWriteLocker locker(&m_lock);

    m_imdFault = fault;
}

bool CarData::getBmsFault()  {
    QReadLocker locker(&m_lock);

    return m_bmsFault;
}

void CarData::setBmsFault(bool fault) {
    QWriteLocker locker(&m_lock);

    m_bmsFault = fault;
}

uint16_t CarData::getCommandedTorque()  {
    QReadLocker locker(&m_lock);

    return m_commandedTorque;
}

void CarData::setCommandedTorque(uint16_t torque) {
    QWriteLocker locker(&m_lock);

    m_commandedTorque = torque;
}

float CarData::getCurrentSpeed()  {
    QReadLocker locker(&m_lock);

    return m_currentSpeed;
}

void CarData::setCurrentSpeed(float speed) {
    QWriteLocker locker(&m_lock);

    m_currentSpeed = speed;
}

bool CarData::getDriveDirection()  {
    QReadLocker locker(&m_lock);

    return m_driveDirection;
}

void CarData::setDriveDirection(bool direction) {
    QWriteLocker locker(&m_lock);

    m_driveDirection = direction;
}

DriveModes CarData::getDriveMode()  {
    QReadLocker locker(&m_lock);

    return m_driveMode;
}

void CarData::setDriveMode(DriveModes mode) {
    QWriteLocker locker(&m_lock);

    m_driveMode = mode;
}

float CarData::getBatteryChargeState()  {
    QReadLocker locker(&m_lock);

    return m_batteryChargeState;
}

void CarData::setBatteryChargeState(float state) {
    QWriteLocker locker(&m_lock);

    m_batteryChargeState = state;
}

float CarData::getBusVoltage()  {
    QReadLocker locker(&m_lock);

    return m_busVoltage;
}

void CarData::setBusVoltage(float voltage) {
    QWriteLocker locker(&m_lock);

    m_busVoltage = voltage;
}

float CarData::getRinehartVoltage()  {
    QReadLocker locker(&m_lock);

    return m_rinehartVoltage;
}

void CarData::setRinehartVoltage(float voltage) {
    QWriteLocker locker(&m_lock);

    m_rinehartVoltage = voltage;
}

float CarData::getPack1Temp()  {
    QReadLocker locker(&m_lock);

    return m_pack1Temp;
}

void CarData::setPack1Temp(float temp) {
    QWriteLocker locker(&m_lock);

    m_pack1Temp = temp;
}

float CarData::getPack2Temp()  {
    QReadLocker locker(&m_lock);

    return m_pack2Temp;
}

void CarData::setPack2Temp(float temp) {
    QWriteLocker locker(&m_lock);

    m_pack2Temp = temp;
}

float CarData::getPackCurrent()  {
    QReadLocker locker(&m_lock);

    return m_packCurrent;
}

void CarData::setPackCurrent(float current) {
    QWriteLocker locker(&m_lock);

    m_packCurrent = current;
}

float CarData::getMinCellVoltage()  {
    QReadLocker locker(&m_lock);

    return m_minCellVoltage;
}

void CarData::setMinCellVoltage(float voltage) {
    QWriteLocker locker(&m_lock);

    m_minCellVoltage = voltage;
}

float CarData::getMaxCellVoltage()  {
    QReadLocker locker(&m_lock);

    return m_maxCellVoltage;
}

void CarData::setMaxCellVoltage(float voltage) {
    QWriteLocker locker(&m_lock);

    m_maxCellVoltage = voltage;
}

uint8_t CarData::getRpmCounterFR()  {
    QReadLocker locker(&m_lock);

    return m_rpmCounterFR;
}

void CarData::setRpmCounterFR(uint8_t value) {
    QWriteLocker locker(&m_lock);

    m_rpmCounterFR = value;
}

uint8_t CarData::getRpmCounterFL()  {
    QReadLocker locker(&m_lock);

    return m_rpmCounterFL;
}

void CarData::setRpmCounterFL(uint8_t value) {
    QWriteLocker locker(&m_lock);

    m_rpmCounterFL = value;
}

uint8_t CarData::getRpmCounterBR()  {
    QReadLocker locker(&m_lock);

    return m_rpmCounterBR;
}

void CarData::setRpmCounterBR(uint8_t value) {
    QWriteLocker locker(&m_lock);

    m_rpmCounterBR = value;
}

uint8_t CarData::getRpmCounterBL()  {
    QReadLocker locker(&m_lock);

    return m_rpmCounterBL;
}

void CarData::setRpmCounterBL(uint8_t value) {
    QWriteLocker locker(&m_lock);

    m_rpmCounterBL = value;
}

uint64_t CarData::getRpmTimeFR()  {
    QReadLocker locker(&m_lock);

    return m_rpmTimeFR;
}

void CarData::setRpmTimeFR(uint64_t value) {
    QWriteLocker locker(&m_lock);

    m_rpmTimeFR = value;
}

uint64_t CarData::getRpmTimeFL()  {
    QReadLocker locker(&m_lock);

    return m_rpmTimeFL;
}

void CarData::setRpmTimeFL(uint64_t value) {
    QWriteLocker locker(&m_lock);

    m_rpmTimeFL = value;
}

float CarData::getWheelSpeedFR()  {
    QReadLocker locker(&m_lock);

    return m_wheelSpeedFR;
}

void CarData::setWheelSpeedFR(float Speed) {
    QWriteLocker locker(&m_lock);

    m_wheelSpeedFR = Speed;
}

float CarData::getWheelSpeedFL()  {
    QReadLocker locker(&m_lock);

    return m_wheelSpeedFL;
}

void CarData::setWheelSpeedFL(float Speed) {
    QWriteLocker locker(&m_lock);

    m_wheelSpeedFL = Speed;
}

float CarData::getWheelSpeedBR()  {
    QReadLocker locker(&m_lock);

    return m_wheelSpeedBR;
}

void CarData::setWheelSpeedBR(float Speed) {
    QWriteLocker locker(&m_lock);

    m_wheelSpeedBR = Speed;
}

float CarData::getWheelSpeedBL()  {
    QReadLocker locker(&m_lock);

    return m_wheelSpeedBL;
}

void CarData::setWheelSpeedBL(float Speed) {
    QWriteLocker locker(&m_lock);

    m_wheelSpeedBL = Speed;
}

float CarData::getWheelHeightFR()  {
    QReadLocker locker(&m_lock);

    return m_wheelHeightFR;
}

void CarData::setWheelHeightFR(float height) {
    QWriteLocker locker(&m_lock);

    m_wheelHeightFR = height;
}

float CarData::getWheelHeightFL()  {
    QReadLocker locker(&m_lock);

    return m_wheelHeightFL;
}

void CarData::setWheelHeightFL(float height) {
    QWriteLocker locker(&m_lock);

    m_wheelHeightFL = height;
}

float CarData::getWheelHeightBR()  {
    QReadLocker locker(&m_lock);

    return m_wheelHeightBR;
}

void CarData::setWheelHeightBR(float height) {
    QWriteLocker locker(&m_lock);

    m_wheelHeightBR = height;
}

float CarData::getWheelHeightBL()  {
    QReadLocker locker(&m_lock);

    return m_wheelHeightBL;
}

void CarData::setWheelHeightBL(float height) {
    QWriteLocker locker(&m_lock);

    m_wheelHeightBL = height;
}

uint16_t CarData::getSteeringWheelAngle()  {
    QReadLocker locker(&m_lock);

    return m_steeringWheelAngle;
}

void CarData::setSteeringWheelAngle(uint16_t value) {
    QWriteLocker locker(&m_lock);

    m_steeringWheelAngle = value;
}

float CarData::getVicoreTemp()  {
    QReadLocker locker(&m_lock);

    return m_vicoreTemp;
}

void CarData::setVicoreTemp(float temp) {
    QWriteLocker locker(&m_lock);

    m_vicoreTemp = temp;
}

float CarData::getPumpTempIn()  {
    QReadLocker locker(&m_lock);

    return m_pumpTempIn;
}

void CarData::setPumpTempIn(float temp) {
    QWriteLocker locker(&m_lock);

    m_pumpTempIn = temp;
}

float CarData::getPumpTempOut()  {
    QReadLocker locker(&m_lock);

    return m_pumpTempOut;
}

void CarData::setPumpTempOut(float temp) {
    QWriteLocker locker(&m_lock);

    m_pumpTempOut = temp;
}

uint16_t CarData::getPedal0()  {
    QReadLocker locker(&m_lock);

    return m_pedal0;
}

void CarData::setPedal0(uint16_t pedal) {
    QWriteLocker locker(&m_lock);

    m_pedal0 = pedal;
}

uint16_t CarData::getPedal1()  {
    QReadLocker locker(&m_lock);

    return m_pedal1;
}

void CarData::setPedal1(uint16_t pedal) {
    QWriteLocker locker(&m_lock);

    m_pedal1 = pedal;
}

uint16_t CarData::getBrakeFront()  {
    QReadLocker locker(&m_lock);

    return m_brakeFront;
}

void CarData::setBrakeFront(uint16_t brake) {
    QWriteLocker locker(&m_lock);

    m_brakeFront = brake;
}

uint16_t CarData::getBrakeRear()  {
    return m_brakeRear;
}

void CarData::setBrakeRear(uint16_t brake) {
    QWriteLocker locker(&m_lock);

    m_brakeRear = brake;
}

uint16_t CarData::getBrakeRegen()  {
    QReadLocker locker(&m_lock);

    return m_brakeRegen;
}

void CarData::setBrakeRegen(uint16_t brake) {
    QWriteLocker locker(&m_lock);

    m_brakeRegen = brake;
}

uint16_t CarData::getCoastRegen()  {
    QReadLocker locker(&m_lock);

    return m_coastRegen;
}

void CarData::setCoastRegen(uint16_t coast) {
    QWriteLocker locker(&m_lock);

    m_coastRegen = coast;
}

bool CarData::getBuzzerActive()  {
    QReadLocker locker(&m_lock);

    return m_buzzerActive;
}

void CarData::setBuzzerActive(bool active) {
    QWriteLocker locker(&m_lock);

    m_buzzerActive = active;
}

uint8_t CarData::getBuzzerCounter()  {
    QReadLocker locker(&m_lock);

    return m_buzzerCounter;
}

void CarData::setBuzzerCounter(uint8_t counter) {
    QWriteLocker locker(&m_lock);

    m_buzzerCounter = counter;
}

bool CarData::getBrakeLight()  {
    QReadLocker locker(&m_lock);

    return m_brakeLight;
}

void CarData::setBrakeLight(bool light) {
    QWriteLocker locker(&m_lock);

    m_brakeLight = light;
}

bool CarData::getFansActive()  {
    QReadLocker locker(&m_lock);

    return m_fansActive;
}

void CarData::setFansActive(bool active) {
    QWriteLocker locker(&m_lock);

    m_fansActive = active;
}

bool CarData::getPumpActive()  {
    QReadLocker locker(&m_lock);

    return m_pumpActive;
}

void CarData::setPumpActive(bool active) {
    QWriteLocker locker(&m_lock);

    m_pumpActive = active;
}
