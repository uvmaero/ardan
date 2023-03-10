#ifndef DATAMANAGER_H
#define DATAMANAGER_H

// Dominic Gasperini
// ARDAN

// includes
#include <QThread>
#include <QTimer>
#include <QDebug>
#include "MechanicalData.h"
#include "ElectricalData.h"
//#include "RadioHead/RadioHead.h"


/**
 * @brief The DataManager class
 */
class DataManager : public QThread
{
public:
    DataManager();


private:
    // functions
    void parseData();

    // data classes
    MechanicalData *m_pMechanicalData;
    ElectricalData *m_pElectricalData;

    // timers
    QTimer *m_pReadTimer;

    // variables




private slots:
    void ReadSerial();
};

#endif // DATAMANAGER_H
