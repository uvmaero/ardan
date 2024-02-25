// Dominic Gasperini
// ARDAN

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// includes
#include <QMainWindow>
#include <QTimer>
#include <QStyleFactory>
#include <QMessageBox>
#include "DataManager.h"
#include "CarData.h"
#include "AboutDlg.h"
#include "PortSelectDialog.h"
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QtCharts/QXYSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QTransform>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // gui updates
    void UpdateMechanicalData();
    void UpdateElectricalData();

    void SetupPlotting();
    void UpdateAccelPlot();
    void UpdateBrakePlot();
    void UpdateSpeedPlot();
    void UpdatePackVoltagePlot();
    void UpdatePackCurrentPlot();

    // helpers
    float mapValue(float x, float in_min, float in_max, float out_min, float out_max);

private:
    // ui
    Ui::MainWindow *ui;
    QPalette m_defaultPalette;
    QPixmap m_steeringWheel;


    // dialogs
    AboutDlg *m_pAboutDlg;
    PortSelectDialog *m_portSelectDialog;

    // timers
    QTimer *m_pUpdateDataTimer;
    QTimer *m_pPlotDataTimer;

    // data classes
    CarData *m_pCarData;
    DataManager *m_pDataManager;

    // plots
    QChart* m_pAccelChart;
    QChart* m_pBrakeChart;
    QChart* m_pSpeedChart;
    QChart* m_pPackVoltageChart;
    QChart* m_pPackCurrentChart;

    QXYSeries* m_pAccelSeries;
    QXYSeries* m_pBrakeSeries;
    QXYSeries* m_pSpeedSeries;
    QXYSeries* m_pPackVoltageSeries;
    QXYSeries* m_pPackCurrentSeries;

    QVector<QPointF> m_accelVector;
    QVector<QPointF> m_brakeVector;
    QVector<QPointF> m_speedVector;
    QVector<QPointF> m_packVoltageVector;
    QVector<QPointF> m_pacCurrentVector;

    QChartView* m_pAccelView;
    QChartView* m_pBrakeView;
    QChartView* m_pSpeedView;
    QChartView* m_pPackVoltageView;
    QChartView* m_pPackCurrentView;

    QValueAxis* m_pAxisXAccel;
    QValueAxis* m_pAxisYAccel;

    QValueAxis* m_pAxisXBrake;
    QValueAxis* m_pAxisYBrake;

    QValueAxis* m_pAxisXSpeed;
    QValueAxis* m_pAxisYSpeed;

    QValueAxis* m_pAxisXPackVoltage;
    QValueAxis* m_pAxisYPackVoltage;

    QValueAxis* m_pAxisXPackCurrent;
    QValueAxis* m_pAxisYPackCurrent;

    float m_refreshCounter;
    const int m_xAxisLength = 10;
    const int m_maxDataPoints = 100;

    // variables
    QString m_portName;


private slots:
    void UpdateWindow();
    void on_Dark_Mode_triggered(bool checked);
    void on_About_Dlg_triggered();
    void on_actionSelect_Serial_Port_triggered();

    void GetPortName(QString portName);
    void UpdatePlots();
};
#endif // MAINWINDOW_H
