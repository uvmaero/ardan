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
    void setTractionControlModifier();

    uint16_t getBrakeRegen() ;
    void setBrakeRegen(uint16_t brake);

    uint16_t getCoastRegen() ;
    void setCoastRegen(uint16_t coast);


    // tractive core - sensores

    bool getImdFault() ;
    void setImdFault(bool fault);

    bool getBmsFault() ;
    void setBmsFault(bool fault);

    float getPumpTempIn() ;
    void setPumpTempIn(float temp);

    float getPumpTempOut() ;
    void setPumpTempOut(float temp);

    float getVicoreTemp() ;
    void setVicoreTemp(float temp);

    float getGlvReading();
    void setGlvReading();

    float getWheelSpeedFR() ;
    void setWheelSpeedFR(float speed);

    float getWheelSpeedFL() ;
    void setWheelSpeedFL(float speed);

    float getWheelSpeedBR() ;
    void setWheelSpeedBR(float speed);

    float getWheelSpeedBL() ;
    void setWheelSpeedBL(float speed);


    // tractive core - inputs

    uint16_t getPedal0() ;
    void setPedal0(uint16_t pedal);

    uint16_t getPedal1() ;
    void setPedal1(uint16_t pedal);

    uint16_t getBrakeFront() ;
    void setBrakeFront(uint16_t brake);

    uint16_t getBrakeRear() ;
    void setBrakeRear(uint16_t brake);


    // tractive core - outputs

    bool getBrakeLightEnable() ;
    void setBrakeLightEnable(bool light);

    bool getFansActive() ;
    void setFansActive(bool active);

    bool getBuzzerActive() ;
    void setBuzzerActive(bool active);


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

    float getWheelHeightFR() ;
    void setWheelHeightFR(float height);

    float getSuspensionDamperFL() ;
    void setSuspensionDamperFL(float value);

    float getSuspensionDamperBR() ;
    void setSuspensionDamperBR(float value);

    float getSuspensionDamperBL() ;
    void setSuspensionDamperBL(float value);

    // tire temps

    uint8_t getFRTireTemp();
    void setFRTireTemp(uint8_t value);

    uint8_t getFLTireTemp();
    void setFLTireTemp(uint8_t value);

    uint8_t getBRTireTemp();
    void setBRTireTemp(uint8_t value);

    uint8_t getBLTireTemp();
    void setBLTireTemp(uint8_t value);

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
    void setXAcceleration();

    float getYAcceleration();
    void setYAcceleration();

    float getZAcceleration();
    void setZAcceleration();

    float getXGyro();
    void setXGyro();

    float getYGyro();
    void setYGyro();

    float getZGyro();
    void setZGyro();

    // GPS
    float getLatitude();
    void setLatitude();

    float getLongitude();
    void setLongitude();

    float getAltitude();
    void setAltitude();

    uint8_t getGPSYear();
    void setGPSYear();

    uint8_t getGPSMonth();
    void setGPSMonth();

    uint8_t getGPSDay();
    void setGPSDay();


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
    float m_vicoreTemp;

    float m_glvReading;

    float m_frontWheelsSpeed;
    int16_t m_frontWheelSpeedCount;
    int16_t m_frontWheelSpeedTime;

    float m_brWheelSpeed;
    int16_t m_brWheelSpeedCount;
    int16_t m_brWheelSpeedTime;

    float m_blWheelSpeed;
    int16_t m_blWheelSpeedCount;
    int16_t m_blWheelSpeedTime;


    // tractive core - inputs
    uint16_t m_pedal0;
    uint16_t m_pedal1;

    uint16_t m_frontBrake;
    uint16_t m_rearBrake;

    // tractive core - outputs
    DriveMode m_driveModeLED;

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
};

#endif // CARDATA_H
