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
    // driving data
    bool getReadyToDrive() ;
    void setReadyToDrive(bool ready);

    bool getEnableInverter() ;
    void setEnableInverter(bool enable);

    PrechargeStates getPrechargeState() ;
    void setPrechargeState(PrechargeStates state);

    bool getImdFault() ;
    void setImdFault(bool fault);

    bool getBmsFault() ;
    void setBmsFault(bool fault);

    uint16_t getCommandedTorque() ;
    void setCommandedTorque(uint16_t torque);

    float getCurrentSpeed() ;
    void setCurrentSpeed(float speed);

    bool getDriveDirection() ;
    void setDriveDirection(bool direction);

    DriveModes getDriveMode() ;
    void setDriveMode(DriveModes mode);


    // battery status
    float getBatteryChargeState() ;
    void setBatteryChargeState(float state);

    float getBusVoltage() ;
    void setBusVoltage(float voltage);

    float getRinehartVoltage() ;
    void setRinehartVoltage(float voltage);

    float getPack1Temp() ;
    void setPack1Temp(float temp);

    float getPack2Temp() ;
    void setPack2Temp(float temp);

    float getPackCurrent() ;
    void setPackCurrent(float current);

    float getMinCellVoltage() ;
    void setMinCellVoltage(float voltage);

    float getMaxCellVoltage() ;
    void setMaxCellVoltage(float voltage);


    // sensors
    uint8_t getRpmCounterFR() ;
    void setRpmCounterFR(uint8_t value);

    uint8_t getRpmCounterFL() ;
    void setRpmCounterFL(uint8_t value);

    uint8_t getRpmCounterBR() ;
    void setRpmCounterBR(uint8_t value);

    uint8_t getRpmCounterBL() ;
    void setRpmCounterBL(uint8_t value);

    uint64_t getRpmTimeFR() ;
    void setRpmTimeFR(uint64_t value);

    uint64_t getRpmTimeFL() ;
    void setRpmTimeFL(uint64_t value);

    uint64_t getRpmTimeBR() ;
    void setRpmTimeBR(uint64_t value);

    uint64_t getRpmTimeBL() ;
    void setRpmTimeBL(uint64_t value);

    float getWheelSpeedFR() ;
    void setWheelSpeedFR(float speed);

    float getWheelSpeedFL() ;
    void setWheelSpeedFL(float speed);

    float getWheelSpeedBR() ;
    void setWheelSpeedBR(float speed);

    float getWheelSpeedBL() ;
    void setWheelSpeedBL(float speed);

    float getWheelHeightFR() ;
    void setWheelHeightFR(float height);

    float getWheelHeightFL() ;
    void setWheelHeightFL(float value);

    float getWheelHeightBR() ;
    void setWheelHeightBR(float value);

    float getWheelHeightBL() ;
    void setWheelHeightBL(float value);

    uint16_t getSteeringWheelAngle() ;
    void setSteeringWheelAngle(uint16_t value);

    float getVicoreTemp() ;
    void setVicoreTemp(float temp);

    float getPumpTempIn() ;
    void setPumpTempIn(float temp);

    float getPumpTempOut() ;
    void setPumpTempOut(float temp);


    // inputs
    uint16_t getPedal0() ;
    void setPedal0(uint16_t pedal);

    uint16_t getPedal1() ;
    void setPedal1(uint16_t pedal);

    uint16_t getBrakeFront() ;
    void setBrakeFront(uint16_t brake);

    uint16_t getBrakeRear() ;
    void setBrakeRear(uint16_t brake);

    uint16_t getBrakeRegen() ;
    void setBrakeRegen(uint16_t brake);

    uint16_t getCoastRegen() ;
    void setCoastRegen(uint16_t coast);


    // outputs
    bool getBuzzerActive() ;
    void setBuzzerActive(bool active);

    uint8_t getBuzzerCounter() ;
    void setBuzzerCounter(uint8_t counter);

    bool getBrakeLight() ;
    void setBrakeLight(bool light);

    bool getFansActive() ;
    void setFansActive(bool active);

    bool getPumpActive() ;
    void setPumpActive(bool active);


private:
    // mutex
    QReadWriteLock m_lock;

    // --- variables --- //
    // driving data
    bool m_readyToDrive;
    bool m_enableInverter;
    PrechargeStates m_prechargeState;

    bool m_imdFault;
    bool m_bmsFault;

    uint16_t m_commandedTorque;
    float m_currentSpeed;
    bool m_driveDirection;             // true = forward | false = reverse
    DriveModes m_driveMode;


    // battery status
    float m_batteryChargeState;
    float m_busVoltage;
    float m_rinehartVoltage;
    float m_pack1Temp;
    float m_pack2Temp;
    float m_packCurrent;
    float m_minCellVoltage;
    float m_maxCellVoltage;


    // sensors
    uint8_t m_rpmCounterFR;
    uint8_t m_rpmCounterFL;
    uint8_t m_rpmCounterBR;
    uint8_t m_rpmCounterBL;
    uint64_t m_rpmTimeFR;
    uint64_t m_rpmTimeFL;
    uint64_t m_rpmTimeBR;
    uint64_t m_rpmTimeBL;

    float m_wheelSpeedFR;
    float m_wheelSpeedFL;
    float m_wheelSpeedBR;
    float m_wheelSpeedBL;

    float m_wheelHeightFR;
    float m_wheelHeightFL;
    float m_wheelHeightBR;
    float m_wheelHeightBL;

    uint16_t m_steeringWheelAngle;

    float m_vicoreTemp;
    float m_pumpTempIn;
    float m_pumpTempOut;


    // inputs
    uint16_t m_pedal0;
    uint16_t m_pedal1;
    uint16_t m_brakeFront;
    uint16_t m_brakeRear;
    uint16_t m_brakeRegen;
    uint16_t m_coastRegen;

    // outputs
    bool m_buzzerActive;
    uint8_t m_buzzerCounter;
    bool m_brakeLight;
    bool m_fansActive;
    bool m_pumpActive;
};

#endif // CARDATA_H
