// Dominic Gasperini
// ARDAN

// includes
#include "MainWindow.h"
#include "ui_MainWindow.h"

// defines
#define SERIAL_UPDATE_INTERVAL      10      // in milliseconds, the interval in which the serial bus is read
#define DISPLAY_UPDATE_INTERVAL     25      // in milliseconds
#define WAIT_TIMEOUT                10      // in milliseconds

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
    m_portSelectDialog = new PortSelectDialog();

    // initialize images
    ui->CarImage->setPixmap(QPixmap(":/images/car.jpeg").scaledToWidth(ui->CarImage->width()));
    ui->AccelPedalImage->setPixmap(QPixmap(":/images/go_pedal.jpeg").scaledToHeight(ui->AccelPedalImage->height()));
    ui->BrakePedalImage->setPixmap(QPixmap(":/images/stop_pedal.jpeg").scaledToHeight(ui->BrakePedalImage->height()));
    ui->BatteryImage->setPixmap(QPixmap(":/images/battery.png").scaledToWidth(ui->BatteryImage->width()));
    ui->WheelConnectionStatusImage->setPixmap(QPixmap(":/images/connected_icon.png").scaledToHeight(ui->WheelConnectionStatusImage->height()));

    // init data classes
    m_pCarData = new CarData();
    m_pDataManager = new DataManager();

    // init timers
    m_pUpdateDataTimer = new QTimer();
    m_pUpdateDataTimer->setInterval(DISPLAY_UPDATE_INTERVAL);
    connect(m_pUpdateDataTimer, SIGNAL(timeout()), this, SLOT(UpdateWindow()));
    m_pUpdateDataTimer->start();

    // connect signals and slots
    connect(m_portSelectDialog, SIGNAL(sPortSelected(QString)), this, SLOT(GetPortName(QString)));

    // init variables
    m_portName = "";
}


void MainWindow::UpdateWindow() {
    // attempt to start serial thread
    if (!m_portName.isEmpty())
    {
        m_pDataManager->StartDataManager(m_portName, WAIT_TIMEOUT);
    }

    // Update Data
    UpdateMechanicalData();
    UpdateElectricalData();
}


/**
 * @brief MainWindow::UpdateMechanicalData
 */
void MainWindow::UpdateMechanicalData() {
    // update current speed
    ui->CurrentSpeedLCD->display(m_pCarData->getCurrentSpeed());

    // update steering wheel position


    // update pedal values
//    ui->AccelPedalProgressBar->setValue(m_pCarData->getAcceleratorPosition());
//    ui->BrakePedalProgressBar->setValue(m_pCarData->getBrakePosition());

    // update wheel speed values
    ui->FRWheelSpeedSbx->setValue(m_pCarData->getWheelSpeedFR());
    ui->FLWheelSpeedSbx->setValue(m_pCarData->getWheelSpeedFL());
    ui->BRWheelSpeedSbx->setValue(m_pCarData->getWheelSpeedBR());
    ui->BLWheelSpeedSbx->setValue(m_pCarData->getWheelSpeedBL());

    // update wheel height values
    ui->FRWheelHeightSbx->setValue(m_pCarData->getWheelHeightFR());
    ui->FLWheelHeightSbx->setValue(m_pCarData->getWheelHeightFL());
    ui->BRWheelHeightSbx->setValue(m_pCarData->getWheelHeightBR());
    ui->BLWheelHeightSbx->setValue(m_pCarData->getWheelHeightBL());

    // update drive mode
    switch (m_pCarData->getDriveMode()) {
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


/**
 * @brief MainWindow::on_actionSelect_Serial_Port_triggered
 */
void MainWindow::on_actionSelect_Serial_Port_triggered()
{
    m_portSelectDialog->show();
}

/**
 * @brief MainWindow::GetPortName
 * @param portName
 */
void MainWindow::GetPortName(QString portName)
{
    m_portName = portName;
    qDebug() << "Port name: " << m_portName;
}
