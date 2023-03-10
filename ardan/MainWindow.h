#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// includes
#include <QMainWindow>
#include <QTimer>
#include <QStyleFactory>
#include "ElectricalData.h"
#include "MechanicalData.h"
#include "AboutDlg.h"


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

    // timers
    QTimer *m_pUpdateDataTimer;

    // data classes
    ElectricalData *m_pElectricalData;
    MechanicalData *m_pMechanicalData;


private slots:
    void UpdateWindow();
    void on_Dark_Mode_triggered(bool checked);
    void on_About_Dlg_triggered();
};
#endif // MAINWINDOW_H
