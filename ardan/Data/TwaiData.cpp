/**
 * @file TwaiData.cpp
 * @brief
 * @date 2026-04-16
 */

/*                                                                                              \
=============================================================================================== \
                                   includes                                                     \
=============================================================================================== \
*/                                                                                              \
#include "Data/TwaiData.h"

/*
===============================================================================================
                                    class
===============================================================================================
*/

// Initialize static members
TwaiData* TwaiData::m_pInstance = nullptr;

/**
 * @brief ExecutiveData::GetInstance
 * @return 
 */
TwaiData* TwaiData::GetInstance()
{
    if (m_pInstance == nullptr)
    {
        m_pInstance = new TwaiData();
    }

    return m_pInstance;
}

/**
 * @brief    Deletes the instance of this singleton class
 *
 * @details  If the singleton class exists, then this function deletes the
 *           the single instance of this class.
 */
void TwaiData::DeleteInstance()
{
    if (m_pInstance != nullptr)
    {
        delete m_pInstance;
    }
}

/**
 * @brief TwaiData::TwaiData
 */
TwaiData::TwaiData()
{
    // init default values
    rinehartRelayWord = 0;
    rinehartTractiveWord = 0;
    rinehartBusVoltage = 0;
    bmsPackCurrent = 0;
    bmsBusVoltage = 0;
    bmsBatteryCharge = 0;
}

TwaiData::~TwaiData()
{
    // Destructor implementation if needed
}

// Setters
void TwaiData::setRinehartRelayWord(uint16_t value)
{
    std::lock_guard<std::mutex> lock(mutex);
    rinehartRelayWord = value;
}

void TwaiData::setRinehartTractiveWord(uint16_t value)
{
    std::lock_guard<std::mutex> lock(mutex);
    rinehartTractiveWord = value;
}

void TwaiData::setRinehartBusVoltage(uint16_t value)
{
    std::lock_guard<std::mutex> lock(mutex);
    rinehartBusVoltage = value;
}

void TwaiData::setBmsPackCurrent(int16_t value)
{
    std::lock_guard<std::mutex> lock(mutex);
    bmsPackCurrent = value;
}

void TwaiData::setBmsBusVoltage(uint16_t value)
{
    std::lock_guard<std::mutex> lock(mutex);
    bmsBusVoltage = value;
}

void TwaiData::setBmsBatteryCharge(uint8_t value)
{
    std::lock_guard<std::mutex> lock(mutex);
    bmsBatteryCharge = value;
}

// Getters
uint16_t TwaiData::getRinehartRelayWord() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return rinehartRelayWord;
}

uint16_t TwaiData::getRinehartTractiveWord() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return rinehartTractiveWord;
}

uint16_t TwaiData::getRinehartBusVoltage() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return rinehartBusVoltage;
}

int16_t TwaiData::getBmsPackCurrent() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return bmsPackCurrent;
}

uint16_t TwaiData::getBmsBusVoltage() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return bmsBusVoltage;
}

uint8_t TwaiData::getBmsBatteryCharge() const
{
    std::lock_guard<std::mutex> lock(mutex);
    return bmsBatteryCharge;
}
