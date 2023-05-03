// Dominic Gasperini
// ARDAN

#ifndef DATAMANAGER_H
#define DATAMANAGER_H

// includes
#include <QThread>
#include <QWaitCondition>
#include <QSerialPort>
#include <QTime>
#include <QDebug>
#include "CarData.h"


/**
 * @brief The DataManager class
 */
class DataManager : public QThread
{
    Q_OBJECT

public:
    explicit DataManager(QObject *parent = nullptr);
    ~DataManager();
    void StartDataManager(const QString &porName, int waitTimeout);


private:
    void run() override;
    QString m_portName;
    int m_waitTimeout = 0;
    bool m_quit = false;

    // functions
    void parseData(QByteArray incomingData);

    // data classes
    CarData *m_pcarData;

    // variables
    QSerialPort *m_esp;
    bool m_serialConnected;


signals:
    void request(const QString &s);
    void error(const QString &s);
    void timeout(const QString &s);


private slots:
};

#endif // DATAMANAGER_H
