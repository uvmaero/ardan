// Dominic Gasperini
// ARDAN

#ifndef CARDATA_H
#define CARDATA_H

// includes
#include <QReadWriteLock>
#include "data_types.h"

/**
 * @brief The CarData class
 */
class CarData
{
public:
    // constuctor & destructor
    CarData();
    ~CarData();

    // --- getters & setters --- //

    // tractive core - tractive
    bool getReadyToDrive() ;
    void setReadyToDrive(bool ready);

    bool getEnableInverter() ;
    void setEnableInverter(bool enable);

    PrechargeStates getPrechargeState() ;
    void setPrechargeState(PrechargeStates state);

    float getRinehartVoltage() ;
    void setRinehartVoltage(float voltage);

    uint16_t getCommandedTorque() ;
    void setCommandedTorque(uint16_t torque);

    bool getDriveDirection() ;
    void setDriveDirection(bool direction);

    DriveMode getDriveMode() ;
    void setDriveMode(DriveMode mode);

    float getCurrentSpeed() ;
    void setCurrentSpeed(float speed);

    bool getTractionControlEnable();
    void setTractionControlEnable(bool active);

    float getTractionControlModifier();
    void setTractionControlModifier(float value);

    uint16_t getBrakeRegen() ;
    void setBrakeRegen(uint16_t brake);

    uint16_t getCoastRegen() ;
    void setCoastRegen(uint16_t coast);


    // tractive core - sensors

    bool getImdFault() ;
    void setImdFault(bool fault);

    bool getBmsFault() ;
    void setBmsFault(bool fault);

    float getPumpTempIn() ;
    void setPumpTempIn(float temp);

    float getPumpTempOut() ;
    void setPumpTempOut(float temp);

    bool getVicoreFault() ;
    void setVicoreFault(bool state);

    float getFrontWheelsSpeed() ;
    void setFrontWheelsSpeed(float speed);

    float getWheelSpeedBR() ;
    void setWheelSpeedBR(float speed);

    float getWheelSpeedBL() ;
    void setWheelSpeedBL(float speed);


    // tractive core - inputs

    uint16_t getPedal0() ;
    void setPedal0(uint16_t pedal);

    uint16_t getPedal1() ;
    void setPedal1(uint16_t pedal);

    uint16_t getBrakesFront() ;
    void setBrakesFront(uint16_t brake);

    uint16_t getBrakesRear() ;
    void setBrakesRear(uint16_t brake);


    // tractive core - outputs

    bool getVicoreEnable();
    void setVicoreEnable(bool state);

    bool getBrakeLightEnable() ;
    void setBrakeLightEnable(bool light);

    bool getFansEnable() ;
    void setFansEnable(bool active);

    bool getBuzzerEnable() ;
    void setBuzzerEnable(bool active);


    // tractive core - orion

    float getBatteryChargeState() ;
    void setBatteryChargeState(float state);

    float getBusVoltage() ;
    void setBusVoltage(float voltage);

    float getPackCurrent() ;
    void setPackCurrent(float current);

    float getPack1Temp() ;
    void setPack1Temp(float temp);

    float getPack2Temp() ;
    void setPack2Temp(float temp);

    float getMinCellVoltage() ;
    void setMinCellVoltage(float voltage);

    float getMaxCellVoltage() ;
    void setMaxCellVoltage(float voltage);

    // --- telemetry core --- //

    // dampers

    float getSuspensionDamperFR() ;
    void setSuspensionDamperFR(float height);

    float getSuspensionDamperFL() ;
    void setSuspensionDamperFL(float value);

    float getSuspensionDamperBR() ;
    void setSuspensionDamperBR(float value);

    float getSuspensionDamperBL() ;
    void setSuspensionDamperBL(float value);

    // tire temps

    float getTireTempFR();
    void setTireTempFR(float value);

    float getTireTempFL();
    void setTireTempFL(float value);

    float getTireTempBR();
    void setTireTempBR(float value);

    float getTireTempBL();
    void setTireTempBL(float value);

    // strain gauges

    uint8_t getFRStrain1();
    void setFRStrain1(uint8_t value);

    uint8_t getFLStrain1();
    void setFLStrain1(uint8_t value);

    uint8_t getBRStrain1();
    void setBRStrain1(uint8_t value);

    uint8_t getBLStrain1();
    void setBLStrain1(uint8_t value);

    uint8_t getFRStrain2();
    void setFRStrain2(uint8_t value);

    uint8_t getFLStrain2();
    void setFLStrain2(uint8_t value);

    uint8_t getBRStrain2();
    void setBRStrain2(uint8_t value);

    uint8_t getBLStrain2();
    void setBLStrain2(uint8_t value);

    // steering
    uint16_t getSteeringWheelDeflection() ;
    void setSteeringWheelDeflection(uint16_t value);

    // IMU
    float getXAcceleration();
    void setXAcceleration(float value);

    float getYAcceleration();
    void setYAcceleration(float value);

    float getZAcceleration();
    void setZAcceleration(float value);

    float getXGyro();
    void setXGyro(float value);

    float getYGyro();
    void setYGyro(float value);

    float getZGyro();
    void setZGyro(float value);

    // GPS
    float getLatitude();
    void setLatitude(float value);

    float getLongitude();
    void setLongitude(float value);

    float getAltitude();
    void setAltitude(float value);

    uint8_t getGPSYear();
    void setGPSYear(uint8_t value);

    uint8_t getGPSMonth();
    void setGPSMonth(uint8_t value);

    uint8_t getGPSDay();
    void setGPSDay(uint8_t value);


private:
    // mutex
    QReadWriteLock m_lock;

    // --- variables --- //
    // tractive core - tractive
    bool m_readyToDrive;
    bool m_enableInverter;

    PrechargeStates m_prechargeState;

    float m_rinehartVoltage;

    uint16_t m_commandedTorque;

    bool m_driveDirection;             // true = forward | false = reverse
    DriveMode m_driveMode;

    float m_currentSpeed;

    bool m_tractionControlEnable;
    float m_tractionControlModifier;

    uint16_t m_coastRegen;
    uint16_t m_brakeRegen;


    // tractive core - sensors
    bool m_imdFault;
    bool m_bmsFault;

    float m_coolingTempIn;
    float m_coolingTempOut;
    bool m_vicoreFault;

    float m_frontWheelsSpeed;
    float m_wheelSpeedBR;
    float m_wheelSpeedBL;


    // tractive core - inputs
    uint16_t m_pedal0;
    uint16_t m_pedal1;

    uint16_t m_frontBrakes;
    uint16_t m_rearBrakes;

    // tractive core - outputs
    bool m_vicoreEnable;

    bool m_brakeLightEnable;

    bool m_fansEnable;

    bool m_buzzerEnable;

    // orion
    float m_batteryChargeState;

    float m_busVoltage;

    float m_packCurrent;

    float m_minCellVoltage;
    float m_maxCellVoltage;
    float m_minCellTemp;
    float m_maxCellTemp;

    // telemetry core
    float m_suspensionDamperFR;
    float m_suspensionDamperFL;
    float m_suspensionDamperBR;
    float m_suspensionDamperBL;

    float m_tireTempFR;
    float m_tireTempFL;
    float m_tireTempBR;
    float m_tireTempBL;

    float m_strain1FR;
    float m_strain1FL;
    float m_strain1BR;
    float m_strain1BL;

    float m_strain2FR;
    float m_strain2FL;
    float m_strain2BR;
    float m_strain2BL;

    uint16_t m_steeringDeflection;

    float m_xAcceleration;
    float m_yAcceleration;
    float m_zAcceleration;

    float m_xGyro;
    float m_yGyro;
    float m_zGyro;

    float m_latitude;
    float m_longitude;
    float m_altitude;

    float m_gpsYear;
    float m_gpsMonth;
    float m_gpsDay;
};

#endif // CARDATA_H
