// Dominic Gasperini
// ARDAN

// includes
#include "MainWindow.h"
#include "ui_MainWindow.h"

// defines
#define SERIAL_UPDATE_INTERVAL      10      // in milliseconds, the interval in which the serial bus is read
#define DISPLAY_UPDATE_INTERVAL     25      // in milliseconds
#define PLOTS_UPDATE_INTERVAL       100     // in milliseconds
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
    m_steeringWheel = QPixmap(":/images/steering-wheel.png");
    ui->steeringDeflectionLblImage->setPixmap(m_steeringWheel);

    // init data classes
    m_pCarData = new CarData();
    m_pDataManager = new DataManager();

    // init plots
    SetupPlotting();

    // init timers
    m_pUpdateDataTimer = new QTimer();
    m_pUpdateDataTimer->setInterval(DISPLAY_UPDATE_INTERVAL);
    connect(m_pUpdateDataTimer, SIGNAL(timeout()), this, SLOT(UpdateWindow()));
    m_pUpdateDataTimer->start();

    m_pPlotDataTimer = new QTimer();
    m_pPlotDataTimer->setInterval(PLOTS_UPDATE_INTERVAL);
    connect(m_pPlotDataTimer, SIGNAL(timeout()), this, SLOT(UpdatePlots()));
    m_pPlotDataTimer->start();

    // connect signals and slots
    connect(m_portSelectDialog, SIGNAL(sPortSelected(QString)), this, SLOT(GetPortName(QString)));

    // init variables
    m_portName = "";
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief MainWindow::UpdateWindow
 */
void MainWindow::UpdateWindow() {
    // attempt to start serial thread
    if (!m_portName.isEmpty())
    {
        m_pDataManager->StartDataManager(m_portName, WAIT_TIMEOUT, m_pCarData);
    }

    // Update Data
    UpdateMechanicalData();
    UpdateElectricalData();
    UpdateTelemetryData();

    // recording
    if (m_pDataManager->getRecording()) {
        RecordData();
    }
}


/**
 * @brief MainWindow::UpdateMechanicalData
 */
void MainWindow::UpdateMechanicalData() {
    // update current speed
    ui->currentSpeedDataLbl->setText(QString::number(m_pCarData->getCurrentSpeed()));

    // update steering wheel position (THIS DOES NOT WORK)
    QTransform rotator;
    rotator.rotate((float)m_pCarData->getSteeringWheelDeflection());
    m_steeringWheel.transformed(rotator);
    ui->steeringDeflectionLblImage->setPixmap(m_steeringWheel.scaledToHeight(ui->steeringDeflectionLblImage->height()));

    // update pedal values
    float average = (m_pCarData->getPedal0() + m_pCarData->getPedal1()) / 2;
    ui->AccelPedalProgressBar->setValue(mapValue(average, 0, 255, 0, 100));
    average = (m_pCarData->getBrakesFront() + m_pCarData->getBrakesRear()) / 2;
    ui->BrakePedalProgressBar->setValue(mapValue(average, 0, 255, 0, 100));

    // update wheel speed values
    ui->FRWheelSpeedSbx->setValue(m_pCarData->getFrontWheelsSpeed());
    ui->BRWheelSpeedSbx->setValue(m_pCarData->getWheelSpeedBR());
    ui->BLWheelSpeedSbx->setValue(m_pCarData->getWheelSpeedBL());

    // update wheel height values
    ui->FRWheelHeightSbx->setValue(m_pCarData->getSuspensionDamperFR());
    ui->FLWheelHeightSbx->setValue(m_pCarData->getSuspensionDamperFL());
    ui->BRWheelHeightSbx->setValue(m_pCarData->getSuspensionDamperBR());
    ui->BLWheelHeightSbx->setValue(m_pCarData->getSuspensionDamperBL());

    // update drive mode
    switch (m_pCarData->getDriveMode()) {
    case SLOW:
        ui->DriveModeTbx->setText("SLOW");
        break;

    case ECO:
        ui->DriveModeTbx->setText("ECO");
        break;

    case FAST:
        ui->DriveModeTbx->setText("FAST");
        break;

    default:
        ui->DriveModeTbx->setText("ERROR");
        break;
    }
}


/**
 * @brief MainWindow::UpdateElectricalData
 */
void MainWindow::UpdateElectricalData() {
    // ready to drive
    if (m_pCarData->getReadyToDrive()) {
        ui->readyToDriveLED->setPixmap(QPixmap(":/images/active.png").scaledToHeight(ui->IMDFaultLED->height()));
    }
    else {
        ui->readyToDriveLED->setPixmap(QPixmap(":/images/inactive.png").scaledToHeight(ui->IMDFaultLED->height()));
    }

    // faults
    if (m_pCarData->getImdFault()) {
        ui->IMDFaultLED->setPixmap(QPixmap(":/images/inactive.png").scaledToHeight(ui->IMDFaultLED->height()));
    }
    else {
        ui->IMDFaultLED->setPixmap(QPixmap(":/images/active.png").scaledToHeight(ui->IMDFaultLED->height()));
    }

    if (m_pCarData->getBmsFault()) {
        ui->BMSFaultLED->setPixmap(QPixmap(":/images/inactive.png").scaledToHeight(ui->BMSFaultLED->height()));
    }
    else {
        ui->BMSFaultLED->setPixmap(QPixmap(":/images/active.png").scaledToHeight(ui->BMSFaultLED->height()));
    }

    // drive direction
    if (!m_pCarData->getDriveDirection()) {      // forward is false
        ui->driveDirectionTbx->setText("FORWARD");
    }
    else {
        ui->driveDirectionTbx->setText("REVERSE");
    }

    // inverter
    if (m_pCarData->getEnableInverter()) {
        ui->InverterStatusLED->setPixmap(QPixmap(":/images/active.png").scaledToHeight(ui->InverterStatusLED->height()));
    }
    else {
        ui->InverterStatusLED->setPixmap(QPixmap(":/images/inactive.png").scaledToHeight(ui->InverterStatusLED->height()));
    }

    // commanded torque
    ui->CommandedTorqueSbx->setValue(m_pCarData->getCommandedTorque());

    // vicore enable
    if (m_pCarData->getVicoreEnable()) {
        ui->vicoreEnableLED->setPixmap(QPixmap(":/images/active.png").scaledToHeight(ui->vicoreEnableLED->height()));
    }
    else {
        ui->vicoreEnableLED->setPixmap(QPixmap(":/images/inactive.png").scaledToHeight(ui->vicoreEnableLED->height()));
    }

    // vicore fault
    if (m_pCarData->getVicoreFault()) {
        ui->vicoreFaultLED->setPixmap(QPixmap(":/images/active.png").scaledToHeight(ui->vicoreEnableLED->height()));
    }
    else {
        ui->vicoreFaultLED->setPixmap(QPixmap(":/images/inactive.png").scaledToHeight(ui->vicoreEnableLED->height()));
    }

    // soc
    ui->BatteryPrecentageProgressBar->setValue(m_pCarData->getBatteryChargeState());

    // voltages
    ui->RinehartVoltageSbx->setValue(m_pCarData->getRinehartVoltage() / 10);
    ui->BusVoltageSbx->setValue(m_pCarData->getBusVoltage());

    // ui->minCellVoltageSbx->setValue(m_pCarData->getMinCellVoltage());
    // ui->maxCellVoltageSbx->setValue(m_pCarData->getMaxCellVoltage());

    // current
    ui->BusCurrentSbx->setValue(m_pCarData->getPackCurrent());

    // precharge
    if (m_pCarData->getPrechargeState() == PRECHARGE_OFF) {
        ui->prechargeStateTbx->setText("OFF");
    }
    else if (m_pCarData->getPrechargeState() == PRECHARGE_ON) {
        ui->prechargeStateTbx->setText("ON");
    }

    else if (m_pCarData->getPrechargeState() == PRECHARGE_DONE) {
        ui->prechargeStateTbx->setText("DONE");
    }
    else if (m_pCarData->getPrechargeState() == PRECHARGE_ERROR) {
        ui->prechargeStateTbx->setText("ERROR");
    }
    else {
        ui->prechargeStateTbx->setText("BROKEN :/");
    }

}


/**
 * @brief MainWindow::UpdateTelemetryData
 */
void MainWindow::UpdateTelemetryData() {

}


/**
 * @brief MainWindow::UpdatePlots
 */
void MainWindow::UpdatePlots() {
    // update plotss
    UpdateAccelPlot();
    UpdateBrakePlot();
    UpdateSpeedPlot();
    UpdatePackVoltagePlot();
    UpdatePackCurrentPlot();

    // update counter
    m_refreshCounter = m_refreshCounter + ((float)PLOTS_UPDATE_INTERVAL / 1000);
}


/**
 * @brief MainWindow::UpdatePlots
 */
void MainWindow::UpdateAccelPlot()
{
    // inits
    float average, mappedValue;
    QPointF tmpQPoint;
    float newMin;

    // convert raw data to QPoint
    m_accelVector.reserve(m_maxDataPoints);
    average = (m_pCarData->getPedal0() + m_pCarData->getPedal1()) / 2;
    mappedValue = mapValue(average, 0, 255, 0, 100);
    tmpQPoint.setY(mappedValue);
    tmpQPoint.setX(m_refreshCounter);

    // Keep a fixed number of data points to create the scrolling effect
    if (m_accelVector.size() >= m_maxDataPoints) {
        m_accelVector.removeFirst();
    }
    else {
        m_accelVector.append(tmpQPoint);
    }

    // Update the series with the new data
    m_pAccelSeries->clear();
    for (const QPointF &point : m_accelVector) {
        m_pAccelSeries->append(point);
    }

    // update chart bounds
    newMin = m_refreshCounter - (float)m_xAxisLength;
    if (newMin > 0) {
        m_pAxisXAccel->setMin(newMin);
    }
    if (m_refreshCounter > m_xAxisLength) {
        m_pAxisXAccel->setMax(m_refreshCounter);
    }
}


/**
 * @brief MainWindow::UpdateBrakePlot
 */
void MainWindow::UpdateBrakePlot()
{
    // inits
    float average, mappedValue;
    QPointF tmpQPoint;
    float newMin;

    // convert raw data to QPoint
    m_brakeVector.reserve(m_maxDataPoints);
    average = (m_pCarData->getBrakesFront() + m_pCarData->getBrakesRear()) / 2;
    mappedValue = mapValue(average, 0, 255, 0, 100);
    tmpQPoint.setY(mappedValue);
    tmpQPoint.setX(m_refreshCounter);

    // Keep a fixed number of data points to create the scrolling effect
    if (m_brakeVector.size() >= m_maxDataPoints) {
        m_brakeVector.removeFirst();
    }
    else {
        m_brakeVector.append(tmpQPoint);
    }

    // Update the series with the new data
    m_pBrakeSeries->clear();
    for (const QPointF &point : m_brakeVector) {
        m_pBrakeSeries->append(point);
    }

    // update chart bounds
    newMin = m_refreshCounter - (float)m_xAxisLength;
    if (newMin > 0) {
        m_pAxisXBrake->setMin(newMin);
    }
    if (m_refreshCounter > m_xAxisLength) {
        m_pAxisXBrake->setMax(m_refreshCounter);
    }
}


/**
 * @brief MainWindow::UpdateSpeedPlot
 */
void MainWindow::UpdateSpeedPlot()
{
    // inits
    QPointF tmpQPoint;
    float newMin;

    // convert raw data to QPoint
    m_speedVector.reserve(m_maxDataPoints);
    tmpQPoint.setY(m_pCarData->getCurrentSpeed());
    tmpQPoint.setX(m_refreshCounter);

    // Keep a fixed number of data points to create the scrolling effect
    if (m_speedVector.size() >= m_maxDataPoints) {
        m_speedVector.removeFirst();
    }
    else {
        m_speedVector.append(tmpQPoint);
    }

    // Update the series with the new data
    m_pSpeedSeries->clear();
    for (const QPointF &point : m_speedVector) {
        m_pSpeedSeries->append(point);
    }

    // update chart bounds
    newMin = m_refreshCounter - (float)m_xAxisLength;
    if (newMin > 0) {
        m_pAxisXSpeed->setMin(newMin);
    }
    if (m_refreshCounter > m_xAxisLength) {
        m_pAxisXSpeed->setMax(m_refreshCounter);
    }
}


/**
 * @brief MainWindow::UpdatePackVoltagePlot
 */
void MainWindow::UpdatePackVoltagePlot()
{
    // inits
    QPointF tmpQPoint;
    float newMin;

    // convert raw data to QPoint
    m_packVoltageVector.reserve(m_maxDataPoints);
    tmpQPoint.setY(m_pCarData->getBusVoltage());
    tmpQPoint.setX(m_refreshCounter);

    // Keep a fixed number of data points to create the scrolling effect
    if (m_packVoltageVector.size() >= m_maxDataPoints) {
        m_packVoltageVector.removeFirst();
    }
    else {
        m_packVoltageVector.append(tmpQPoint);
    }

    // Update the series with the new data
    m_pPackVoltageSeries->clear();
    for (const QPointF &point : m_packVoltageVector) {
        m_pPackVoltageSeries->append(point);
    }

    // update chart bounds
    newMin = m_refreshCounter - (float)m_xAxisLength;
    if (newMin > 0) {
        m_pAxisXPackVoltage->setMin(newMin);
    }
    if (m_refreshCounter > m_xAxisLength) {
        m_pAxisXPackVoltage->setMax(m_refreshCounter);
    }
}


/**
 * @brief MainWindow::UpdatePackCurrentPlot
 */
void MainWindow::UpdatePackCurrentPlot()
{
    // inits
    QPointF tmpQPoint;
    float newMin;

    // convert raw data to QPoint
    m_pacCurrentVector.reserve(m_maxDataPoints);
    tmpQPoint.setY(m_pCarData->getPackCurrent());
    tmpQPoint.setX(m_refreshCounter);

    // Keep a fixed number of data points to create the scrolling effect
    if (m_pacCurrentVector.size() >= m_maxDataPoints) {
        m_pacCurrentVector.removeFirst();
    }
    else {
        m_pacCurrentVector.append(tmpQPoint);
    }

    // Update the series with the new data
    m_pPackCurrentSeries->clear();
    for (const QPointF &point : m_pacCurrentVector) {
        m_pPackCurrentSeries->append(point);
    }

    // update chart bounds
    newMin = m_refreshCounter - (float)m_xAxisLength;
    if (newMin > 0) {
        m_pAxisXPackCurrent->setMin(newMin);
    }
    if (m_refreshCounter > m_xAxisLength) {
        m_pAxisXPackCurrent->setMax(m_refreshCounter);
    }
}


/**
 * @brief MainWindow::SetupPlotting
 */
void MainWindow::SetupPlotting()
{
    // inits
    m_pAccelChart = new QChart();
    m_pBrakeChart = new QChart();
    m_pSpeedChart = new QChart();
    m_pPackVoltageChart = new QChart();
    m_pPackCurrentChart = new QChart();

    m_pAccelView = new QChartView(this);
    m_pBrakeView = new QChartView(this);
    m_pSpeedView = new QChartView(this);
    m_pPackVoltageView = new QChartView(this);
    m_pPackCurrentView = new QChartView(this);

    m_pAxisXAccel = new QValueAxis;
    m_pAxisYAccel = new QValueAxis;

    m_pAxisXBrake = new QValueAxis;
    m_pAxisYBrake = new QValueAxis;

    m_pAxisXSpeed = new QValueAxis;
    m_pAxisYSpeed = new QValueAxis;

    m_pAxisXPackVoltage = new QValueAxis;
    m_pAxisYPackVoltage = new QValueAxis;

    m_pAxisXPackCurrent = new QValueAxis;
    m_pAxisYPackCurrent = new QValueAxis;

    m_refreshCounter = 0;

    // --- accel --- //

    // Create the QChartView widget
    QVBoxLayout *accelLayout = new QVBoxLayout(ui->accelPlot);
    accelLayout->addWidget(m_pAccelView);
    accelLayout->expandingDirections();

    // Set up the chart properties
    m_pAccelView->setChart(m_pAccelChart);
    m_pAccelChart->setMaximumHeight(ui->accelPlot->maximumHeight());
    m_pAccelChart->setMaximumWidth(ui->accelPlot->maximumWidth());
    m_pAccelChart->legend()->hide();
    m_pAccelChart->setTitle("Accelerator Pedal Plot");

    m_pAccelSeries = new QLineSeries();
    m_pAccelChart->addSeries(m_pAccelSeries);

    // do axis
    m_pAxisXAccel->setLabelFormat("%.1f");
    m_pAxisXAccel->setMax(m_xAxisLength);
    m_pAxisXAccel->setMin(0);
    m_pAxisXAccel->setTitleText("time (sec)");
    m_pAccelChart->addAxis(m_pAxisXAccel, Qt::AlignBottom);
    m_pAccelSeries->attachAxis(m_pAxisXAccel);

    m_pAxisYAccel->setLabelFormat("%.1f");
    m_pAxisYAccel->setMax(100);
    m_pAxisYAccel->setMin(0);
    m_pAxisYAccel->setTitleText("pedal value");
    m_pAccelChart->addAxis(m_pAxisYAccel, Qt::AlignLeft);
    m_pAccelSeries->attachAxis(m_pAxisYAccel);

    // --- brakes --- //

    // Create the QChartView widget
    QVBoxLayout *brakeLayout = new QVBoxLayout(ui->brakePlot);
    brakeLayout->addWidget(m_pBrakeView);
    brakeLayout->expandingDirections();

    // Set up the chart properties
    m_pBrakeView->setChart(m_pBrakeChart);
    m_pBrakeChart->setMaximumHeight(ui->brakePlot->maximumHeight());
    m_pBrakeChart->setMaximumWidth(ui->brakePlot->maximumWidth());
    m_pBrakeChart->legend()->hide();
    m_pBrakeChart->setTitle("Brake Pedal Plot");

    m_pBrakeSeries = new QLineSeries();
    m_pBrakeChart->addSeries(m_pBrakeSeries);

    // do axis
    m_pAxisXBrake->setLabelFormat("%.1f");
    m_pAxisXBrake->setMax(m_xAxisLength);
    m_pAxisXBrake->setMin(0);
    m_pAxisXBrake->setTitleText("time (sec)");
    m_pBrakeChart->addAxis(m_pAxisXBrake, Qt::AlignBottom);
    m_pBrakeSeries->attachAxis(m_pAxisXBrake);

    m_pAxisYBrake->setLabelFormat("%.1f");
    m_pAxisYBrake->setMax(100);
    m_pAxisYBrake->setMin(0);
    m_pAxisYBrake->setTitleText("pedal value");
    m_pBrakeChart->addAxis(m_pAxisYBrake, Qt::AlignLeft);
    m_pBrakeSeries->attachAxis(m_pAxisYBrake);

    // --- speed --- //

    // Create the QChartView widget
    QVBoxLayout *speedLayout = new QVBoxLayout(ui->speedPlot);
    speedLayout->addWidget(m_pSpeedView);
    speedLayout->expandingDirections();

    // Set up the chart properties
    m_pSpeedView->setChart(m_pSpeedChart);
    m_pSpeedChart->setMaximumHeight(ui->speedPlot->maximumHeight());
    m_pSpeedChart->setMaximumWidth(ui->speedPlot->maximumWidth());
    m_pSpeedChart->legend()->hide();
    m_pSpeedChart->setTitle("Speed Plot");

    m_pSpeedSeries = new QLineSeries();
    m_pSpeedChart->addSeries(m_pSpeedSeries);

    // do axis
    m_pAxisXSpeed->setLabelFormat("%.1f");
    m_pAxisXSpeed->setMax(m_xAxisLength);
    m_pAxisXSpeed->setMin(0);
    m_pAxisXSpeed->setTitleText("time (sec)");
    m_pSpeedChart->addAxis(m_pAxisXSpeed, Qt::AlignBottom);
    m_pSpeedSeries->attachAxis(m_pAxisXSpeed);

    m_pAxisYSpeed->setLabelFormat("%.1f");
    m_pAxisYSpeed->setMax(50);
    m_pAxisYSpeed->setMin(0);
    m_pAxisYSpeed->setTitleText("mph");
    m_pSpeedChart->addAxis(m_pAxisYSpeed, Qt::AlignLeft);
    m_pSpeedSeries->attachAxis(m_pAxisYSpeed);

    // --- pack voltage --- //

    // Create the QChartView widget
    QVBoxLayout *packVoltageLayout = new QVBoxLayout(ui->packVoltagePlot);
    packVoltageLayout->addWidget(m_pPackVoltageView);
    packVoltageLayout->expandingDirections();

    // Set up the chart properties
    m_pPackVoltageView->setChart(m_pPackVoltageChart);
    m_pPackVoltageChart->setMaximumHeight(ui->speedPlot->maximumHeight());
    m_pPackVoltageChart->setMaximumWidth(ui->speedPlot->maximumWidth());
    m_pPackVoltageChart->legend()->hide();
    m_pPackVoltageChart->setTitle("Pack Voltage Plot");

    m_pPackVoltageSeries = new QLineSeries();
    m_pPackVoltageChart->addSeries(m_pPackVoltageSeries);

    // do axis
    m_pAxisXPackVoltage->setLabelFormat("%.1f");
    m_pAxisXPackVoltage->setMax(m_xAxisLength);
    m_pAxisXPackVoltage->setMin(0);
    m_pAxisXPackVoltage->setTitleText("time (sec)");
    m_pPackVoltageChart->addAxis(m_pAxisXPackVoltage, Qt::AlignBottom);
    m_pPackVoltageSeries->attachAxis(m_pAxisXPackVoltage);

    m_pAxisYPackVoltage->setLabelFormat("%.1f");
    m_pAxisYPackVoltage->setMax(450);
    m_pAxisYPackVoltage->setMin(0);
    m_pAxisYPackVoltage->setTitleText("volts");
    m_pPackVoltageChart->addAxis(m_pAxisYPackVoltage, Qt::AlignLeft);
    m_pPackVoltageSeries->attachAxis(m_pAxisYPackVoltage);

    // --- pack current --- //

    // Create the QChartView widget
    QVBoxLayout *packCurrentLayout = new QVBoxLayout(ui->packCurrentPlot);
    packCurrentLayout->addWidget(m_pPackCurrentView);
    packCurrentLayout->expandingDirections();

    // Set up the chart properties
    m_pPackCurrentView->setChart(m_pPackCurrentChart);
    m_pPackCurrentChart->setMaximumHeight(ui->speedPlot->maximumHeight());
    m_pPackCurrentChart->setMaximumWidth(ui->speedPlot->maximumWidth());
    m_pPackCurrentChart->legend()->hide();
    m_pPackCurrentChart->setTitle("Pack Current Plot");

    m_pPackCurrentSeries = new QLineSeries();
    m_pPackCurrentChart->addSeries(m_pPackCurrentSeries);

    // do axis
    m_pAxisXPackCurrent->setLabelFormat("%.1f");
    m_pAxisXPackCurrent->setMax(m_xAxisLength);
    m_pAxisXPackCurrent->setMin(0);
    m_pAxisXPackCurrent->setTitleText("time (sec)");
    m_pPackCurrentChart->addAxis(m_pAxisXPackCurrent, Qt::AlignBottom);
    m_pPackCurrentSeries->attachAxis(m_pAxisXPackCurrent);

    m_pAxisYPackCurrent->setLabelFormat("%.1f");
    m_pAxisYPackCurrent->setMax(175);
    m_pAxisYPackCurrent->setMin(0);
    m_pAxisYPackCurrent->setTitleText("amps");
    m_pPackCurrentChart->addAxis(m_pAxisYPackCurrent, Qt::AlignLeft);
    m_pPackCurrentSeries->attachAxis(m_pAxisYPackCurrent);
}


/**
 * @brief MainWindow::RecordData
 */
void MainWindow::RecordData() {
    // update ui
    float duration = m_pDataManager->getRecordingDuration();
    QString durationStr = "RECORDING: " + QString::number(duration, 'f', 0) + "sec";
    ui->recordBtn->setStyleSheet("background-color: rgb(224, 27, 36);");    // red
    ui->recordBtn->setText(durationStr);

    // init data pipeline
    TelemetryCoreData tmpData = m_pDataManager->getRawData();
    QVector<TelemetryCoreData> tmpDataVec;

    // copy data
    qDebug() << "dataframe saved @ " << duration;
    tmpDataVec.append(tmpData);

    // write to data manager
    m_pDataManager->setRecordedData(tmpDataVec);

    // update recording duration
    float tmpDuration = m_pDataManager->getRecordingDuration();
    tmpDuration = tmpDuration + ((float)DISPLAY_UPDATE_INTERVAL / 1000);
    m_pDataManager->setRecordingDuration(tmpDuration);

    // save timestamp
    QVector<float> tmpTimestamps = m_pDataManager->getRecordingTimestamps();
    tmpTimestamps.append(tmpDuration);
    m_pDataManager->setRecordingTimestamps(tmpTimestamps);
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


/**
 * @brief MainWindow::mapValue
 * @param x
 * @param in_min
 * @param in_max
 * @param out_min
 * @param out_max
 * @return
 */
float MainWindow::mapValue(float x, float in_min, float in_max, float out_min, float out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void MainWindow::on_recordBtn_clicked()
{
    // stop recording
    if (m_pDataManager->getRecording()) {
        // update recording state
        m_pDataManager->setRecording(false);

        // update ui
        ui->recordBtn->setStyleSheet("background-color: rgb(230, 97, 0);");   // orange
        ui->recordBtn->setText("!! RESET !!");

        return;
    }

    // start recording
    if (!m_pDataManager->getRecording()) {
        // if there is data saved but maybe not written to a file yet
        if (m_pDataManager->getRecordingBuffered()) {
            // clear previous data
            QVector<TelemetryCoreData> emptyDataVec = {};
            QVector<float> emptyTimestampVec = {};
            m_pDataManager->setRecordingDuration(0);
            m_pDataManager->setRecordedData(emptyDataVec);
            m_pDataManager->setRecordingTimestamps(emptyTimestampVec);

            // updated buffered data state
            m_pDataManager->setRecordingBuffered(false);
            ui->recordBtn->setStyleSheet("background-color: rgb(38, 162, 105);");   // green
            ui->recordBtn->setText("Start Recording");

            return;
        }

        // there is no data saved and we are ready to start a new recording
        if (!m_pDataManager->getRecordingBuffered()) {
            // update recording state
            m_pDataManager->setRecording(true);
            m_pDataManager->setRecordingBuffered(true);

            return;
        }
    }
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
