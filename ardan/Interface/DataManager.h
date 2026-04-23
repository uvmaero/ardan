// Dominic Gasperini
// ARDAN

#ifndef SERIALINTERFACEMANAGER_H
#define SERIALINTERFACEMANAGER_H

// includes
#include <QDebug>
#include <QSerialPort>
#include <QThread>
#include <QTime>
#include <QVector>
#include <QWaitCondition>

#include "Data/DataLogger.h"
#include "Data/ExecutiveData.h"
#include "Data/GpioData.h"
#include "Data/TwaiData.h"

/**
 * @brief The SerialInterfaceManager class
 */
class SerialInterfaceManager : public QThread
{
    Q_OBJECT

public:
    explicit SerialInterfaceManager(QObject* parent = nullptr);
    ~SerialInterfaceManager();

    // getters
    CarData          getRawData();
    bool             getRecording();
    bool             getRecordingBuffered();
    float            getRecordingDuration();
    QVector<CarData> getRecordedData();
    QVector<float>   getRecordingTimestamps();

    // setters
    void setRecording(bool state);
    void setRecordingBuffered(bool state);
    void setRecordingDuration(float duration);
    void setRecordedData(QVector<CarData> vec);
    void setRecordingTimestamps(QVector<float> vec);


private:
    QString m_portName;
    int m_waitTimeout = 0;

    // functions
    void parseData(QByteArray incomingData);
    int writeToFile(int mode);

    // data classes
    DataLogger*    m_pDataLoggerData;
    ExecutiveData* m_pExecutiveData;
    GpioData*      m_pGpioData;
    TwaiData*      m_pTwaiData;

    // raw data
    CarData m_carData;

    // variables
    QSerialPort m_port;
    bool m_serialConnected;
    QByteArray  m_rxBuffer;

    // recording
    bool m_recording;
    bool m_recordingBuffered;
    float m_recordingDuration;
    QString saveFilename;
    QVector<float> m_pRecordingTimestamps;
    QVector<CarData> m_recordedData;

signals:

private slots:
    void ReadData();
};

#endif // SERIALINTERFACEMANAGER_H
