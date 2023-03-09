#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// includes
#include <QMainWindow>
#include "ElectricalData.h"
#include "MechanicalData.h"


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

    // data classes
    ElectricalData *m_pElectricalData;
    MechanicalData *m_pMechanicalData;

};
#endif // MAINWINDOW_H
