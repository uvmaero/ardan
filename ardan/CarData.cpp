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
    m_vicoreFault = false;
    m_frontWheelsSpeed = 0.0f;
    m_wheelSpeedBR = 0.0f;
    m_wheelSpeedBL = 0.0f;

    // tractive core - inputs
    m_pedal0 = 0;
    m_pedal1 = 0;
    m_frontBrakes = 0;
    m_rearBrakes = 0;

    // tractive core - outputs
    m_vicoreEnable = false;
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

    // telemetry

    m_suspensionDamperFR = 0.0f;
    m_suspensionDamperFL = 0.0f;
    m_suspensionDamperBR = 0.0f;
    m_suspensionDamperBL = 0.0f;

    m_tireTempFR = 0.0f;
    m_tireTempFL = 0.0f;
    m_tireTempBR = 0.0f;
    m_tireTempBL = 0.0f;

    m_strain1FR = 0.0f;
    m_strain1FL = 0.0f;
    m_strain1BR = 0.0f;
    m_strain1BL = 0.0f;

    m_strain2FR = 0.0f;
    m_strain2FL = 0.0f;
    m_strain2BR = 0.0f;
    m_strain2BL = 0.0f;

    m_steeringDeflection = 0;

    m_xAcceleration = 0.0f;
    m_yAcceleration = 0.0f;
    m_zAcceleration = 0.0f;
    m_xGyro = 0.0f;
    m_yGyro = 0.0f;
    m_zGyro = 0.0f;

    m_latitude = 0.0f;
    m_longitude = 0.0f;
    m_altitude = 0.0f;
    m_gpsYear = 0;
    m_gpsMonth = 0;
    m_gpsDay = 0;
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

DriveMode CarData::getDriveMode()  {
    QReadLocker locker(&m_lock);

    return m_driveMode;
}

void CarData::setDriveMode(DriveMode mode) {
    QWriteLocker locker(&m_lock);

    m_driveMode = mode;
}

bool CarData::getTractionControlEnable() {
    QReadLocker locker(&m_lock);

    return m_tractionControlEnable;
}

void CarData::setTractionControlEnable(bool state) {
    QWriteLocker locker(&m_lock);

    m_tractionControlEnable = state;
}

float CarData::getTractionControlModifier() {
    QReadLocker locker(&m_lock);

    return m_tractionControlModifier;
}

void CarData::setTractionControlModifier(float value) {
    QWriteLocker locker(&m_lock);

    m_tractionControlModifier = value;
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

float CarData::getFrontWheelsSpeed()  {
    QReadLocker locker(&m_lock);

    return m_frontWheelsSpeed;
}

void CarData::setFrontWheelsSpeed(float speed) {
    QWriteLocker locker(&m_lock);

    m_frontWheelsSpeed = speed;
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

float CarData::getSuspensionDamperFR()  {
    QReadLocker locker(&m_lock);

    return m_suspensionDamperFR;
}

void CarData::setSuspensionDamperFR(float height) {
    QWriteLocker locker(&m_lock);

    m_suspensionDamperFR = height;
}

float CarData::getSuspensionDamperFL()  {
    QReadLocker locker(&m_lock);

    return m_suspensionDamperFL;
}

void CarData::setSuspensionDamperFL(float height) {
    QWriteLocker locker(&m_lock);

    m_suspensionDamperFL = height;
}

float CarData::getSuspensionDamperBR()  {
    QReadLocker locker(&m_lock);

    return m_suspensionDamperBR;
}

void CarData::setSuspensionDamperBR(float height) {
    QWriteLocker locker(&m_lock);

    m_suspensionDamperBR = height;
}

float CarData::getSuspensionDamperBL()  {
    QReadLocker locker(&m_lock);

    return m_suspensionDamperBL;
}

void CarData::setSuspensionDamperBL(float height) {
    QWriteLocker locker(&m_lock);

    m_suspensionDamperBL = height;
}

uint16_t CarData::getSteeringWheelDeflection()  {
    QReadLocker locker(&m_lock);

    return m_steeringDeflection;
}

void CarData::setSteeringWheelDeflection(uint16_t value) {
    QWriteLocker locker(&m_lock);

    m_steeringDeflection = value;
}

bool CarData::getVicoreFault()  {
    QReadLocker locker(&m_lock);

    return m_vicoreFault;
}

void CarData::setVicoreFault(bool state) {
    QWriteLocker locker(&m_lock);

    m_vicoreFault = state;
}

float CarData::getPumpTempIn()  {
    QReadLocker locker(&m_lock);

    return m_coolingTempIn;
}

void CarData::setPumpTempIn(float temp) {
    QWriteLocker locker(&m_lock);

    m_coolingTempIn = temp;
}

float CarData::getPumpTempOut()  {
    QReadLocker locker(&m_lock);

    return m_coolingTempOut;
}

void CarData::setPumpTempOut(float temp) {
    QWriteLocker locker(&m_lock);

    m_coolingTempOut = temp;
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

uint16_t CarData::getBrakesFront()  {
    QReadLocker locker(&m_lock);

    return m_frontBrakes;
}

void CarData::setBrakesFront(uint16_t brake) {
    QWriteLocker locker(&m_lock);

    m_frontBrakes = brake;
}

uint16_t CarData::getBrakesRear()  {
    return m_rearBrakes;
}

void CarData::setBrakesRear(uint16_t brake) {
    QWriteLocker locker(&m_lock);

    m_rearBrakes = brake;
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

bool CarData::getBuzzerEnable()  {
    QReadLocker locker(&m_lock);

    return m_buzzerEnable;
}

void CarData::setBuzzerEnable(bool active) {
    QWriteLocker locker(&m_lock);

    m_buzzerEnable = active;
}


bool CarData::getVicoreEnable() {
    QReadLocker locker(&m_lock);

    return m_vicoreEnable;
}

void CarData::setVicoreEnable(bool state) {
    QWriteLocker locker(&m_lock);

    m_vicoreEnable = state;
}

bool CarData::getBrakeLightEnable() {
    QReadLocker locker(&m_lock);

    return m_brakeLightEnable;
}

void CarData::setBrakeLightEnable(bool light) {
    QWriteLocker locker(&m_lock);

    m_brakeLightEnable = light;
}

bool CarData::getFansEnable()  {
    QReadLocker locker(&m_lock);

    return m_fansEnable;
}

void CarData::setFansEnable(bool state) {
    QWriteLocker locker(&m_lock);

    m_fansEnable = state;
}

float CarData::getTireTempFR() {
    QReadLocker locker(&m_lock);

    return m_tireTempFR;
}

void CarData::setTireTempFR(float value) {
    QWriteLocker locker(&m_lock);

    m_tireTempFR = value;
}

float CarData::getTireTempFL() {
    QReadLocker locker(&m_lock);

    return m_tireTempFL;
}

void CarData::setTireTempFL(float value) {
    QWriteLocker locker(&m_lock);

    m_tireTempFL = value;
}

float CarData::getTireTempBR() {
    QReadLocker locker(&m_lock);

    return m_tireTempBR;
}

void CarData::setTireTempBR(float value) {
    QWriteLocker locker(&m_lock);

    m_tireTempBR = value;
}

float CarData::getTireTempBL() {
    QReadLocker locker(&m_lock);

    return m_tireTempBL;
}

void CarData::setTireTempBL(float value) {
    QWriteLocker locker(&m_lock);

    m_tireTempBL = value;
}

uint8_t CarData::getFRStrain1() {
    QReadLocker locker(&m_lock);

    return m_strain1FR;
}

void CarData::setFRStrain1(uint8_t value) {
    QWriteLocker locker(&m_lock);

    m_strain1FR = value;
}

uint8_t CarData::getFLStrain1() {
    QReadLocker locker(&m_lock);

    return m_strain1FL;
}

void CarData::setFLStrain1(uint8_t value) {
    QWriteLocker locker(&m_lock);

    m_strain1FL = value;
}

uint8_t CarData::getBRStrain1() {
    QReadLocker locker(&m_lock);

    return m_strain1BR;
}

void CarData::setBRStrain1(uint8_t value) {
    QWriteLocker locker(&m_lock);

    m_strain1BR = value;
}

uint8_t CarData::getBLStrain1() {
    QReadLocker locker(&m_lock);

    return m_strain1BL;
}

void CarData::setBLStrain1(uint8_t value) {
    QWriteLocker locker(&m_lock);

    m_strain1BL = value;
}

uint8_t CarData::getFRStrain2() {
    QReadLocker locker(&m_lock);

    return m_strain2FR;
}

void CarData::setFRStrain2(uint8_t value) {
    QWriteLocker locker(&m_lock);

    m_strain2FR = value;
}

uint8_t CarData::getFLStrain2() {
    QReadLocker locker(&m_lock);

    return m_strain2FL;
}

void CarData::setFLStrain2(uint8_t value) {
    QWriteLocker locker(&m_lock);

    m_strain2FL = value;
}

uint8_t CarData::getBRStrain2() {
    QReadLocker locker(&m_lock);

    return m_strain2BR;
}

void CarData::setBRStrain2(uint8_t value) {
    QWriteLocker locker(&m_lock);

    m_strain2BR = value;
}

uint8_t CarData::getBLStrain2() {
    QReadLocker locker(&m_lock);

    return m_strain2BL;
}

void CarData::setBLStrain2(uint8_t value) {
    QWriteLocker locker(&m_lock);

    m_strain2BL = value;
}

float CarData::getXAcceleration() {
    QReadLocker locker(&m_lock);

    return m_xAcceleration;
}

void CarData::setXAcceleration(float value) {
    QWriteLocker locker(&m_lock);

    m_xAcceleration = value;
}

float CarData::getYAcceleration() {
    QReadLocker locker(&m_lock);

    return m_yAcceleration;
}

void CarData::setYAcceleration(float value) {
    QWriteLocker locker(&m_lock);

    m_yAcceleration = value;
}

float CarData::getZAcceleration() {
    QReadLocker locker(&m_lock);

    return m_zAcceleration;
}

void CarData::setZAcceleration(float value) {
    QWriteLocker locker(&m_lock);

    m_zAcceleration = value;
}

float CarData::getXGyro() {
    QReadLocker locker(&m_lock);

    return m_xGyro;
}

void CarData::setXGyro(float value) {
    QWriteLocker locker(&m_lock);

    m_xGyro = value;
}

float CarData::getYGyro() {
    QReadLocker locker(&m_lock);

    return m_yGyro;
}

void CarData::setYGyro(float value) {
    QWriteLocker locker(&m_lock);

    m_yGyro = value;
}

float CarData::getZGyro() {
    QReadLocker locker(&m_lock);

    return m_zGyro;
}

void CarData::setZGyro(float value) {
    QWriteLocker locker(&m_lock);

    m_zGyro = value;
}

float CarData::getLatitude() {
    QReadLocker locker(&m_lock);

    return m_latitude;
}

void CarData::setLatitude(float value) {
    QWriteLocker locker(&m_lock);

    m_latitude = value;
}

float CarData::getLongitude() {
    QReadLocker locker(&m_lock);

    return m_longitude;
}

void CarData::setLongitude(float value) {
    QWriteLocker locker(&m_lock);

    m_longitude = value;
}

float CarData::getAltitude() {
    QReadLocker locker(&m_lock);

    return m_altitude;
}

void CarData::setAltitude(float value) {
    QWriteLocker locker(&m_lock);

    m_altitude = value;
}

uint8_t CarData::getGPSYear() {
    QReadLocker locker(&m_lock);

    return m_gpsYear;
}

void CarData::setGPSYear(uint8_t value) {
    QWriteLocker locker(&m_lock);

    m_gpsYear = value;
}

uint8_t CarData::getGPSMonth() {
    QReadLocker locker(&m_lock);

    return m_gpsMonth;
}

void CarData::setGPSMonth(uint8_t value) {
    QWriteLocker locker(&m_lock);

    m_gpsMonth = value;
}

uint8_t CarData::getGPSDay() {
    QReadLocker locker(&m_lock);

    return m_gpsDay;
}

void CarData::setGPSDay(uint8_t value) {
    QWriteLocker locker(&m_lock);

    m_gpsDay = value;
}
