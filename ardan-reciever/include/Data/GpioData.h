#ifndef GPIO_DATA_H
#define GPIO_DATA_H

#include <mutex>

class GpioData
{
private:
    mutable std::mutex mutex;

    // Faults
    bool imdFault;
    bool bmsFault;
    bool vicoreFault;

    // Cooling temperatures
    float coolingTempIn;
    float coolingTempOut;

    // Front wheels
    float frontWheelsSpeed;
    int frontWheelSpeedCount;
    int frontWheelSpeedTime;

    // Back right wheel
    float brWheelSpeed;
    int brWheelSpeedCount;
    int brWheelSpeedTime;

    // Back left wheel
    float blWheelSpeed;
    int blWheelSpeedCount;
    int blWheelSpeedTime;

    // Inputs
    int pedal0;
    int pedal1;
    int frontBrake;
    int rearBrake;

    // Outputs
    bool vicoreEnable;
    bool brakeLightEnable;
    bool fansEnable;
    bool buzzerEnable;
    bool prechargeCompleteLedEnable;

public:
    GpioData();

    // Fault getters and setters
    bool getImdFault() const;
    void setImdFault(bool value);

    bool getBmsFault() const;
    void setBmsFault(bool value);

    bool getVicoreFault() const;
    void setVicoreFault(bool value);

    // Cooling temperature getters and setters
    float getCoolingTempIn() const;
    void setCoolingTempIn(float value);

    float getCoolingTempOut() const;
    void setCoolingTempOut(float value);

    // Front wheels getters and setters
    float getFrontWheelsSpeed() const;
    void setFrontWheelsSpeed(float value);

    int getFrontWheelSpeedCount() const;
    void setFrontWheelSpeedCount(int value);

    int getFrontWheelSpeedTime() const;
    void setFrontWheelSpeedTime(int value);

    // Back right wheel getters and setters
    float getBrWheelSpeed() const;
    void setBrWheelSpeed(float value);

    int getBrWheelSpeedCount() const;
    void setBrWheelSpeedCount(int value);

    int getBrWheelSpeedTime() const;
    void setBrWheelSpeedTime(int value);

    // Back left wheel getters and setters
    float getBlWheelSpeed() const;
    void setBlWheelSpeed(float value);

    int getBlWheelSpeedCount() const;
    void setBlWheelSpeedCount(int value);

    int getBlWheelSpeedTime() const;
    void setBlWheelSpeedTime(int value);

    // Input getters and setters
    int getPedal0() const;
    void setPedal0(int value);

    int getPedal1() const;
    void setPedal1(int value);

    int getFrontBrake() const;
    void setFrontBrake(int value);

    int getRearBrake() const;
    void setRearBrake(int value);

    // Output getters and setters
    bool getVicoreEnable() const;
    void setVicoreEnable(bool value);

    bool getBrakeLightEnable() const;
    void setBrakeLightEnable(bool value);

    bool getFansEnable() const;
    void setFansEnable(bool value);

    bool getBuzzerEnable() const;
    void setBuzzerEnable(bool value);

    bool getprechargeCompleteLedEnable() const;
    void setprechargeCompleteLedEnable(bool value);
};

#endif // GPIO_DATA_H
