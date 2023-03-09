/**
 * file: mainwindow.cpp
 * author: dominic gasperini
 * brief: this file manages the main window of the ARDAN base station program
*/

// includes
#include "mainwindow.h"
#include "ui_mainwindow.h"

// defines
#define SERIAL_UPDATE_INTERVAL      10      // in milliseconds, the interval in which the serial bus is read

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // initialize UI
    ui->setupUi(this);
    this->setWindowTitle("ARDAN Base Station");

    // initialize images
    ui->CarImage->setPixmap(QPixmap(":/images/car.jpeg").scaledToWidth(ui->CarImage->width()));
    ui->AccelPedalImage->setPixmap(QPixmap(":/images/go_pedal.jpeg").scaledToHeight(ui->AccelPedalImage->height()));
    ui->BrakePedalImage->setPixmap(QPixmap(":/images/stop_pedal.jpeg").scaledToHeight(ui->BrakePedalImage->height()));
    ui->BatteryImage->setPixmap(QPixmap(":/images/battery.png").scaledToWidth(ui->BatteryImage->width()));
    ui->WheelConnectionStatusImage->setPixmap(QPixmap(":/images/connected_icon.png").scaledToHeight(ui->WheelConnectionStatusImage->height()));

    // init classes
    m_pElectricalData = new ElectricalData();
    m_pMechanicalData = new MechanicalData();

    // Update Data
    UpdateMechanicalData();
    UpdateElectricalData();
}


/**
 * @brief MainWindow::UpdateMechanicalData
 */
void MainWindow::UpdateMechanicalData() {

}


/**
 * @brief MainWindow::UpdateElectricalData
 */
void MainWindow::UpdateElectricalData() {

}


/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

