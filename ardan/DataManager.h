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
#include <QVector>


/**
 * @brief The DataManager class
 */
class DataManager : public QThread
{
    Q_OBJECT

public:
    explicit DataManager(QObject *parent = nullptr);
    ~DataManager();
    void StartDataManager(const QString &porName, int waitTimeout, CarData *carData);

    // getters
    TelemetryCoreData getRawData();
    bool getRecording();
    bool getRecordingBuffered();
    float getRecordingDuration();
    QVector<TelemetryCoreData> getRecordedData();
    QVector<float> getRecordingTimestamps();

    // setters
    void setRecording(bool state);
    void setRecordingBuffered(bool state);
    void setRecordingDuration(float duration);
    void setRecordedData(QVector<TelemetryCoreData> vec);
    void setRecordingTimestamps(QVector<float> vec);


private:
    void run() override;
    QString m_portName;
    int m_waitTimeout = 0;
    bool m_quit = false;

    // functions
    void parseData(QByteArray incomingData);
    int writeToFile(int mode);

    // data classes
    CarData *m_pCarData;

    // raw data
    TelemetryCoreData m_carData;

    // variables
    QSerialPort *m_esp;
    bool m_serialConnected;

    // recording
    bool m_recording;
    bool m_recordingBuffered;
    float m_recordingDuration;
    QString saveFilename;
    QVector<float> m_pRecordingTimestamps;
    QVector<TelemetryCoreData> m_recordedData;


signals:
    void request(const QString &s);
    void error(const QString &s);
    void timeout(const QString &s);


private slots:
};

#endif // DATAMANAGER_H
