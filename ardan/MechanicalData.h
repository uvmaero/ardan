#ifndef MECHANICALDATA_H
#define MECHANICALDATA_H

// includes
#include <QReadWriteLock>


// defines


// enums
typedef enum DriveModes {
    SLOW = 1,
    ECO = 2,
    FAST = 3
} DriveModes;


/**
 * @brief The MechanicalData class
 */
class MechanicalData
{
public:
    // constructor
    MechanicalData();

    // getters
    float getSpeed();
    float getBrakePosition();
    float getAcceloratorPosition();
    DriveModes getDriveMode();

    float getFRWheelSpeed();
    float getFLWheelSpeed();
    float getBRWheelSpeed();
    float getBLWheelSpeed();

    float getFRWheelHeight();
    float getFLWheelHeight();
    float getBRWheelHeight();
    float getBLWheelHeight();

    // setters
    void setSpeed(float num);
    void setBrakePosition(float num);
    void setAcceloratorPosition(float num);
    void setDriveMode(float num);

    void setFRWheelSpeed(float num);
    void setFlWheelSpeed(float num);
    void setBRWheelSpeed(float num);
    void setBLWheelSpeed(float num);

    void setFRWheelHeight(float num);
    void setFlWheelHeight(float num);
    void setBRWheelHeight(float num);
    void setBLWheelHeight(float num);


private:
    // mutex
    QReadWriteLock m_lock;

    // variables
    float m_speed;
    float m_brakePosition;
    float m_acceloratorPosition;
    DriveModes m_driveMode;

    float m_FRWheelSpeed;
    float m_FLWheelSpeed;
    float m_BRWheelSpeed;
    float m_BLWheelSpeed;

    float m_FRWheelHeight;
    float m_FLWheelHeight;
    float m_BRWheelHeight;
    float m_BLWheelHeight;
};

#endif // MECHANICALDATA_H
