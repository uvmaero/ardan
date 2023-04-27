#ifndef DATAMANAGER_H
#define DATAMANAGER_H

// Dominic Gasperini
// ARDAN

// includes
#include <QThread>
#include <QtSerialBus/QtSerialBus>
#include <QDebug>
#include "MechanicalData.h"
#include "ElectricalData.h"


/**
 * @brief The DataManager class
 */
class DataManager : public QThread
{
public:
    DataManager(MechanicalData *mechanicalData, ElectricalData *electricalData);


private:
    // functions
    void parseData();

    // data classes
    MechanicalData *m_pMechanicalData;
    ElectricalData *m_pElectricalData;

    // variables
    QSerialPort *m_esp;
    bool m_serialConnected;


private slots:
    void ReadSerial();
};

#endif // DATAMANAGER_H
