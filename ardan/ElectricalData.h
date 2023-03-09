#ifndef ELECTRICALDATA_H
#define ELECTRICALDATA_H

// includes

// defines


/**
 * @brief The ElectricalData class
 */
class ElectricalData
{
public:
    // constructor
    ElectricalData();

    // getters
    float getAverageCellVoltage();
    float getMinCellVoltage();
    float getMaxCellVoltage();

    float getBatteryPercentage();
    float getBusVoltage();
    float getBusCurrent();
    float getRinehartVoltage();

    float getMinCellTemp();
    float getMaxCellTemp();
    float getAverageCellTemp();

    bool getWheelBoardConnectionStatus();

    // setters
    void setAverageCellVoltage(float num);
    void setMinCellVoltage(float num);
    void setMaxCellVoltage(float num);

    void setBatteryPercentage(float num);
    void setBusVoltage(float num);
    void setBusCurrent(float num);
    void setRinehartVoltage(float num);

    void setMinCellTemp(float num);
    void setMaxCellTemp(float num);
    void setAverageCellTemp(float num);

    void setWheelBoardConnectionStatus(bool status);


private:
    // variables
    float m_averageCellVoltage;
    float m_minCellVoltage;
    float m_maxCellVoltage;

    float m_batteryPercentage;
    float m_busVoltage;
    float m_busCurrent;
    float m_rinehartVoltage;

    float m_minCellTemp;
    float m_maxCellTemp;
    float m_averageCellTemp;

    bool m_wheelBoardConnectionStatus;

};

#endif // ELECTRICALDATA_H
