/**
 * file: mainwindow.cpp
 * author: dominic gasperini
 * brief: this file manages the main window of the ARDAN base station program
*/

// includes
#include "MainWindow.h"
#include "ui_MainWindow.h"

// defines
#define SERIAL_UPDATE_INTERVAL      10      // in milliseconds, the interval in which the serial bus is read
#define DISPLAY_UPDATE_INTERVAL     25      // in milliseconds

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // initialize UI
    ui->setupUi(this);
    m_defaultPalette = QApplication::palette();
    this->setWindowTitle("ARDAN Base Station");
    ui->AccelPedalProgressBar->setMinimum(0);
    ui->AccelPedalProgressBar->setMaximum(100);
    ui->BrakePedalProgressBar->setMinimum(0);
    ui->BrakePedalProgressBar->setMaximum(100);

    // init dialogs
    m_pAboutDlg = new AboutDlg();

    // initialize images
    ui->CarImage->setPixmap(QPixmap(":/images/car.jpeg").scaledToWidth(ui->CarImage->width()));
    ui->AccelPedalImage->setPixmap(QPixmap(":/images/go_pedal.jpeg").scaledToHeight(ui->AccelPedalImage->height()));
    ui->BrakePedalImage->setPixmap(QPixmap(":/images/stop_pedal.jpeg").scaledToHeight(ui->BrakePedalImage->height()));
    ui->BatteryImage->setPixmap(QPixmap(":/images/battery.png").scaledToWidth(ui->BatteryImage->width()));
    ui->WheelConnectionStatusImage->setPixmap(QPixmap(":/images/connected_icon.png").scaledToHeight(ui->WheelConnectionStatusImage->height()));

    // init data classes
    m_pElectricalData = new ElectricalData();
    m_pMechanicalData = new MechanicalData();

    // init timers
    m_pUpdateDataTimer = new QTimer();
    m_pUpdateDataTimer->setInterval(DISPLAY_UPDATE_INTERVAL);
    connect(m_pUpdateDataTimer, SIGNAL(timeout()), this, SLOT(UpdateWindow()));
    m_pUpdateDataTimer->start();
}


void MainWindow::UpdateWindow() {
    // Update Data
    UpdateMechanicalData();
    UpdateElectricalData();
}


/**
 * @brief MainWindow::UpdateMechanicalData
 */
void MainWindow::UpdateMechanicalData() {
    // update current speed
    ui->CurrentSpeedLCD->display(m_pMechanicalData->getSpeed());

    // update steering wheel position


    // update pedal values
    ui->AccelPedalProgressBar->setValue(m_pMechanicalData->getAcceleratorPosition());
    ui->BrakePedalProgressBar->setValue(m_pMechanicalData->getBrakePosition());

    // update wheel speed values
    ui->FRWheelSpeedSbx->setValue(m_pMechanicalData->getFRWheelSpeed());
    ui->FLWheelSpeedSbx->setValue(m_pMechanicalData->getFLWheelSpeed());
    ui->BRWheelSpeedSbx->setValue(m_pMechanicalData->getBRWheelSpeed());
    ui->BLWheelSpeedSbx->setValue(m_pMechanicalData->getBLWheelSpeed());

    // update wheel height values
    ui->FRWheelHeightSbx->setValue(m_pMechanicalData->getFRWheelHeight());
    ui->FLWheelHeightSbx->setValue(m_pMechanicalData->getFLWheelHeight());
    ui->BRWheelHeightSbx->setValue(m_pMechanicalData->getBRWheelHeight());
    ui->BLWheelHeightSbx->setValue(m_pMechanicalData->getBLWheelHeight());

    // update drive mode
    switch (m_pMechanicalData->getDriveMode()) {
    case SLOW:
        ui->DriveModeTbx->setText("SLOW Mode");
        break;

    case ECO:
        ui->DriveModeTbx->setText("ECO Mode");
        break;

    case FAST:
        ui->DriveModeTbx->setText("FAST Mode");
        break;

    default:
        ui->DriveModeTbx->setText("ERROR Mode");
        break;
    }
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


/**
 * @brief MainWindow::on_Dark_Mode_triggered
 * @param checked
 */
void MainWindow::on_Dark_Mode_triggered(bool checked)
{
    if (checked) {
        qApp->setStyle(QStyleFactory::create("Fusion"));

        // modify palette to dark
        QPalette darkPalette;
        darkPalette.setColor(QPalette::Window,QColor(53,53,53));
        darkPalette.setColor(QPalette::WindowText,Qt::white);
        darkPalette.setColor(QPalette::Disabled,QPalette::WindowText,QColor(127,127,127));
        darkPalette.setColor(QPalette::Base,QColor(42,42,42));
        darkPalette.setColor(QPalette::AlternateBase,QColor(66,66,66));
        darkPalette.setColor(QPalette::ToolTipBase,Qt::white);
        darkPalette.setColor(QPalette::ToolTipText,Qt::white);
        darkPalette.setColor(QPalette::Text,Qt::white);
        darkPalette.setColor(QPalette::Disabled,QPalette::Text,QColor(127,127,127));
        darkPalette.setColor(QPalette::Dark,QColor(35,35,35));
        darkPalette.setColor(QPalette::Shadow,QColor(20,20,20));
        darkPalette.setColor(QPalette::Button,QColor(53,53,53));
        darkPalette.setColor(QPalette::ButtonText,Qt::white);
        darkPalette.setColor(QPalette::Disabled,QPalette::ButtonText,QColor(127,127,127));
        darkPalette.setColor(QPalette::BrightText,Qt::red);
        darkPalette.setColor(QPalette::Link,QColor(42,130,218));
        darkPalette.setColor(QPalette::Highlight, QColor(142,45,197));
        darkPalette.setColor(QPalette::Disabled,QPalette::Highlight,QColor(80,80,80));
        darkPalette.setColor(QPalette::HighlightedText,Qt::white);
        darkPalette.setColor(QPalette::Disabled,QPalette::HighlightedText,QColor(127,127,127));

        qApp->setPalette(darkPalette);
    }

    else {
        qApp->setPalette(m_defaultPalette);
    }
}


/**
 * @brief MainWindow::on_About_Dlg_triggered
 */
void MainWindow::on_About_Dlg_triggered()
{
    // open about dialog
    m_pAboutDlg->show();
}

