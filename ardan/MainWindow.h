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

private:
    // ui
    Ui::MainWindow *ui;
    QPalette m_defaultPalette;

    // dialogs
    AboutDlg *m_pAboutDlg;
    PortSelectDialog *m_portSelectDialog;

    // timers
    QTimer *m_pUpdateDataTimer;

    // data classes
    CarData *m_pCarData;
    DataManager *m_pDataManager;

    // variables
    QString m_portName;


private slots:
    void UpdateWindow();
    void on_Dark_Mode_triggered(bool checked);
    void on_About_Dlg_triggered();
    void on_actionSelect_Serial_Port_triggered();

    void GetPortName(QString portName);
};
#endif // MAINWINDOW_H
