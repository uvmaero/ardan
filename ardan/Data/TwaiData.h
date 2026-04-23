#ifndef TWAIDATA_H
#define TWAIDATA_H

#include <mutex>
#include <cstdint>

class TwaiData
{
private:
    TwaiData();
    ~TwaiData();

    mutable std::mutex mutex;

    uint16_t rinehartRelayWord;
    uint16_t rinehartTractiveWord;
    uint16_t rinehartBusVoltage;
    int16_t bmsPackCurrent;
    uint16_t bmsBusVoltage;
    uint8_t bmsBatteryCharge;

public:
    static TwaiData* m_pInstance;

    static TwaiData* GetInstance();
    static void      DeleteInstance();

    // Setters
    void setRinehartRelayWord(uint16_t value);
    void setRinehartTractiveWord(uint16_t value);
    void setRinehartBusVoltage(uint16_t value);
    void setBmsPackCurrent(int16_t value);
    void setBmsBusVoltage(uint16_t value);
    void setBmsBatteryCharge(uint8_t value);

    // Getters
    uint16_t getRinehartRelayWord() const;
    uint16_t getRinehartTractiveWord() const;
    uint16_t getRinehartBusVoltage() const;
    int16_t getBmsPackCurrent() const;
    uint16_t getBmsBusVoltage() const;
    uint8_t getBmsBatteryCharge() const;
};

#endif // TWAIDATA_H
