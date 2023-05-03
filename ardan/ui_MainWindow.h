/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *Dark_Mode;
    QAction *About_Dlg;
    QAction *actionSelect_Serial_Port;
    QWidget *centralwidget;
    QGroupBox *MechanicalDataGroupBox;
    QLabel *BrakePedalImage;
    QLabel *AccelPedalImage;
    QLabel *BrakePedalLbl;
    QLabel *AccelPedalLbl;
    QProgressBar *BrakePedalProgressBar;
    QProgressBar *AccelPedalProgressBar;
    QLabel *SpeedLbl;
    QLCDNumber *CurrentSpeedLCD;
    QGroupBox *groupBox_2;
    QLabel *BatteryImage;
    QProgressBar *BatteryPrecentageProgressBar;
    QWidget *layoutWidget;
    QGridLayout *PrimaryVoltageGridLayout;
    QLabel *BusVoltageLbl;
    QDoubleSpinBox *BusVoltageSbx;
    QLabel *BusCurrentLbl;
    QDoubleSpinBox *BusCurrentSbx;
    QLabel *RinehartVoltageLbl;
    QDoubleSpinBox *RinehartVoltageSbx;
    QWidget *layoutWidget1;
    QGridLayout *WheelConnectionGridLayout;
    QLabel *WheelConnectionLbl;
    QLabel *WheelConnectionStatusImage;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QDoubleSpinBox *CommandedTorqueSbx;
    QLabel *DriveDirectionTbx;
    QLabel *commandedTorqueLbl;
    QLabel *DriveDirectionLbl;
    QLabel *InverterStatusLED;
    QLabel *InverterStatusLbl;
    QSpacerItem *horizontalSpacer_2;
    QLabel *IMDFaultLED;
    QLabel *BMSFaultLED;
    QLabel *IMDFaultLbl;
    QLabel *BMSFaultLbl;
    QLabel *readyToDriveLbl;
    QLabel *readyToDriveLED;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_11;
    QLabel *prechargeStateLbl;
    QLabel *prechargeStateTbx;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *minCellVoltageLbl;
    QDoubleSpinBox *minCellVoltageSbx;
    QLabel *maxCellVoltageLbl;
    QDoubleSpinBox *maxCellVoltageSbx;
    QLabel *averageCellVoltageLbl;
    QDoubleSpinBox *averageCellVoltageSbx;
    QLabel *averageCellTempLbl;
    QDoubleSpinBox *averageCellTempSbx;
    QDoubleSpinBox *maxCellTempSbx;
    QDoubleSpinBox *minCellTempSbx;
    QLabel *minCellTempLbl;
    QLabel *maxCellTempLbl;
    QLabel *CarImage;
    QWidget *layoutWidget3;
    QGridLayout *FRWheelGridLayout;
    QLabel *FRWheelSpeedLbl;
    QSpinBox *FRWheelSpeedSbx;
    QLabel *FRWheelHeightLbl;
    QDoubleSpinBox *FRWheelHeightSbx;
    QWidget *layoutWidget_2;
    QGridLayout *BRWheelGridLayout;
    QLabel *BRWheelSpeedLbl;
    QSpinBox *BRWheelSpeedSbx;
    QLabel *BRWheelHeightLbl;
    QDoubleSpinBox *BRWheelHeightSbx;
    QWidget *layoutWidget_3;
    QGridLayout *BLWheelGridLayout;
    QLabel *BLWheelSpeedLbl;
    QSpinBox *BLWheelSpeedSbx;
    QLabel *BLWheelHeightLbl;
    QDoubleSpinBox *BLWheelHeightSbx;
    QWidget *layoutWidget4;
    QGridLayout *FLWheelGridLayout;
    QLabel *FLWheelSpeedLbl;
    QSpinBox *FLWheelSpeedSbx;
    QLabel *FLWheelHeightLbl;
    QDoubleSpinBox *FLWheelHeightSbx;
    QWidget *layoutWidget5;
    QGridLayout *DriveModeGridLayout;
    QLabel *DriveModeLbl;
    QLineEdit *DriveModeTbx;
    QMenuBar *menubar;
    QMenu *menuOptions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1300, 800);
        MainWindow->setMinimumSize(QSize(1300, 800));
        MainWindow->setMaximumSize(QSize(1300, 800));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/bessieIcon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        Dark_Mode = new QAction(MainWindow);
        Dark_Mode->setObjectName(QString::fromUtf8("Dark_Mode"));
        Dark_Mode->setCheckable(true);
        About_Dlg = new QAction(MainWindow);
        About_Dlg->setObjectName(QString::fromUtf8("About_Dlg"));
        actionSelect_Serial_Port = new QAction(MainWindow);
        actionSelect_Serial_Port->setObjectName(QString::fromUtf8("actionSelect_Serial_Port"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MechanicalDataGroupBox = new QGroupBox(centralwidget);
        MechanicalDataGroupBox->setObjectName(QString::fromUtf8("MechanicalDataGroupBox"));
        MechanicalDataGroupBox->setGeometry(QRect(10, 10, 411, 741));
        BrakePedalImage = new QLabel(MechanicalDataGroupBox);
        BrakePedalImage->setObjectName(QString::fromUtf8("BrakePedalImage"));
        BrakePedalImage->setGeometry(QRect(50, 520, 101, 151));
        AccelPedalImage = new QLabel(MechanicalDataGroupBox);
        AccelPedalImage->setObjectName(QString::fromUtf8("AccelPedalImage"));
        AccelPedalImage->setGeometry(QRect(270, 520, 111, 151));
        BrakePedalLbl = new QLabel(MechanicalDataGroupBox);
        BrakePedalLbl->setObjectName(QString::fromUtf8("BrakePedalLbl"));
        BrakePedalLbl->setGeometry(QRect(50, 710, 62, 16));
        BrakePedalLbl->setAlignment(Qt::AlignCenter);
        AccelPedalLbl = new QLabel(MechanicalDataGroupBox);
        AccelPedalLbl->setObjectName(QString::fromUtf8("AccelPedalLbl"));
        AccelPedalLbl->setGeometry(QRect(270, 710, 81, 20));
        AccelPedalLbl->setAlignment(Qt::AlignCenter);
        BrakePedalProgressBar = new QProgressBar(MechanicalDataGroupBox);
        BrakePedalProgressBar->setObjectName(QString::fromUtf8("BrakePedalProgressBar"));
        BrakePedalProgressBar->setGeometry(QRect(10, 680, 161, 23));
        BrakePedalProgressBar->setValue(13);
        AccelPedalProgressBar = new QProgressBar(MechanicalDataGroupBox);
        AccelPedalProgressBar->setObjectName(QString::fromUtf8("AccelPedalProgressBar"));
        AccelPedalProgressBar->setGeometry(QRect(230, 680, 171, 23));
        AccelPedalProgressBar->setValue(66);
        SpeedLbl = new QLabel(MechanicalDataGroupBox);
        SpeedLbl->setObjectName(QString::fromUtf8("SpeedLbl"));
        SpeedLbl->setGeometry(QRect(160, 300, 91, 16));
        CurrentSpeedLCD = new QLCDNumber(MechanicalDataGroupBox);
        CurrentSpeedLCD->setObjectName(QString::fromUtf8("CurrentSpeedLCD"));
        CurrentSpeedLCD->setGeometry(QRect(20, 40, 381, 251));
        CurrentSpeedLCD->setSmallDecimalPoint(false);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(890, 10, 401, 741));
        BatteryImage = new QLabel(groupBox_2);
        BatteryImage->setObjectName(QString::fromUtf8("BatteryImage"));
        BatteryImage->setGeometry(QRect(70, 20, 271, 91));
        BatteryImage->setAlignment(Qt::AlignCenter);
        BatteryPrecentageProgressBar = new QProgressBar(groupBox_2);
        BatteryPrecentageProgressBar->setObjectName(QString::fromUtf8("BatteryPrecentageProgressBar"));
        BatteryPrecentageProgressBar->setGeometry(QRect(10, 120, 381, 23));
        BatteryPrecentageProgressBar->setValue(78);
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 380, 191, 101));
        PrimaryVoltageGridLayout = new QGridLayout(layoutWidget);
        PrimaryVoltageGridLayout->setObjectName(QString::fromUtf8("PrimaryVoltageGridLayout"));
        PrimaryVoltageGridLayout->setContentsMargins(0, 0, 0, 0);
        BusVoltageLbl = new QLabel(layoutWidget);
        BusVoltageLbl->setObjectName(QString::fromUtf8("BusVoltageLbl"));

        PrimaryVoltageGridLayout->addWidget(BusVoltageLbl, 0, 0, 1, 1);

        BusVoltageSbx = new QDoubleSpinBox(layoutWidget);
        BusVoltageSbx->setObjectName(QString::fromUtf8("BusVoltageSbx"));
        BusVoltageSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BusVoltageSbx->setReadOnly(true);
        BusVoltageSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        PrimaryVoltageGridLayout->addWidget(BusVoltageSbx, 0, 1, 1, 1);

        BusCurrentLbl = new QLabel(layoutWidget);
        BusCurrentLbl->setObjectName(QString::fromUtf8("BusCurrentLbl"));

        PrimaryVoltageGridLayout->addWidget(BusCurrentLbl, 1, 0, 1, 1);

        BusCurrentSbx = new QDoubleSpinBox(layoutWidget);
        BusCurrentSbx->setObjectName(QString::fromUtf8("BusCurrentSbx"));
        BusCurrentSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BusCurrentSbx->setReadOnly(true);
        BusCurrentSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        PrimaryVoltageGridLayout->addWidget(BusCurrentSbx, 1, 1, 1, 1);

        RinehartVoltageLbl = new QLabel(layoutWidget);
        RinehartVoltageLbl->setObjectName(QString::fromUtf8("RinehartVoltageLbl"));

        PrimaryVoltageGridLayout->addWidget(RinehartVoltageLbl, 2, 0, 1, 1);

        RinehartVoltageSbx = new QDoubleSpinBox(layoutWidget);
        RinehartVoltageSbx->setObjectName(QString::fromUtf8("RinehartVoltageSbx"));
        RinehartVoltageSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        RinehartVoltageSbx->setReadOnly(true);
        RinehartVoltageSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        PrimaryVoltageGridLayout->addWidget(RinehartVoltageSbx, 2, 1, 1, 1);

        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(100, 710, 212, 18));
        WheelConnectionGridLayout = new QGridLayout(layoutWidget1);
        WheelConnectionGridLayout->setObjectName(QString::fromUtf8("WheelConnectionGridLayout"));
        WheelConnectionGridLayout->setContentsMargins(0, 0, 0, 0);
        WheelConnectionLbl = new QLabel(layoutWidget1);
        WheelConnectionLbl->setObjectName(QString::fromUtf8("WheelConnectionLbl"));

        WheelConnectionGridLayout->addWidget(WheelConnectionLbl, 0, 0, 1, 1);

        WheelConnectionStatusImage = new QLabel(layoutWidget1);
        WheelConnectionStatusImage->setObjectName(QString::fromUtf8("WheelConnectionStatusImage"));

        WheelConnectionGridLayout->addWidget(WheelConnectionStatusImage, 0, 1, 1, 1);

        layoutWidget2 = new QWidget(groupBox_2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 210, 381, 104));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        CommandedTorqueSbx = new QDoubleSpinBox(layoutWidget2);
        CommandedTorqueSbx->setObjectName(QString::fromUtf8("CommandedTorqueSbx"));
        CommandedTorqueSbx->setMaximumSize(QSize(60, 16777215));
        CommandedTorqueSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        CommandedTorqueSbx->setReadOnly(true);
        CommandedTorqueSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        CommandedTorqueSbx->setDecimals(0);

        gridLayout->addWidget(CommandedTorqueSbx, 0, 6, 1, 1);

        DriveDirectionTbx = new QLabel(layoutWidget2);
        DriveDirectionTbx->setObjectName(QString::fromUtf8("DriveDirectionTbx"));

        gridLayout->addWidget(DriveDirectionTbx, 1, 6, 1, 1);

        commandedTorqueLbl = new QLabel(layoutWidget2);
        commandedTorqueLbl->setObjectName(QString::fromUtf8("commandedTorqueLbl"));

        gridLayout->addWidget(commandedTorqueLbl, 0, 5, 1, 1);

        DriveDirectionLbl = new QLabel(layoutWidget2);
        DriveDirectionLbl->setObjectName(QString::fromUtf8("DriveDirectionLbl"));

        gridLayout->addWidget(DriveDirectionLbl, 1, 5, 1, 1);

        InverterStatusLED = new QLabel(layoutWidget2);
        InverterStatusLED->setObjectName(QString::fromUtf8("InverterStatusLED"));

        gridLayout->addWidget(InverterStatusLED, 3, 2, 1, 2);

        InverterStatusLbl = new QLabel(layoutWidget2);
        InverterStatusLbl->setObjectName(QString::fromUtf8("InverterStatusLbl"));

        gridLayout->addWidget(InverterStatusLbl, 3, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        IMDFaultLED = new QLabel(layoutWidget2);
        IMDFaultLED->setObjectName(QString::fromUtf8("IMDFaultLED"));

        gridLayout->addWidget(IMDFaultLED, 1, 2, 1, 2);

        BMSFaultLED = new QLabel(layoutWidget2);
        BMSFaultLED->setObjectName(QString::fromUtf8("BMSFaultLED"));

        gridLayout->addWidget(BMSFaultLED, 2, 2, 1, 2);

        IMDFaultLbl = new QLabel(layoutWidget2);
        IMDFaultLbl->setObjectName(QString::fromUtf8("IMDFaultLbl"));

        gridLayout->addWidget(IMDFaultLbl, 1, 0, 1, 2);

        BMSFaultLbl = new QLabel(layoutWidget2);
        BMSFaultLbl->setObjectName(QString::fromUtf8("BMSFaultLbl"));

        gridLayout->addWidget(BMSFaultLbl, 2, 0, 1, 2);

        readyToDriveLbl = new QLabel(layoutWidget2);
        readyToDriveLbl->setObjectName(QString::fromUtf8("readyToDriveLbl"));

        gridLayout->addWidget(readyToDriveLbl, 0, 0, 1, 2);

        readyToDriveLED = new QLabel(layoutWidget2);
        readyToDriveLED->setObjectName(QString::fromUtf8("readyToDriveLED"));

        gridLayout->addWidget(readyToDriveLED, 0, 2, 1, 2);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 1, 4, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 2, 4, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 3, 4, 1, 1);

        prechargeStateLbl = new QLabel(layoutWidget2);
        prechargeStateLbl->setObjectName(QString::fromUtf8("prechargeStateLbl"));

        gridLayout->addWidget(prechargeStateLbl, 2, 5, 1, 1);

        prechargeStateTbx = new QLabel(layoutWidget2);
        prechargeStateTbx->setObjectName(QString::fromUtf8("prechargeStateTbx"));

        gridLayout->addWidget(prechargeStateTbx, 2, 6, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 540, 101, 16));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 350, 121, 16));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 180, 81, 16));
        widget = new QWidget(groupBox_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 570, 388, 101));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        minCellVoltageLbl = new QLabel(widget);
        minCellVoltageLbl->setObjectName(QString::fromUtf8("minCellVoltageLbl"));

        gridLayout_2->addWidget(minCellVoltageLbl, 0, 0, 1, 1);

        minCellVoltageSbx = new QDoubleSpinBox(widget);
        minCellVoltageSbx->setObjectName(QString::fromUtf8("minCellVoltageSbx"));
        minCellVoltageSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        minCellVoltageSbx->setReadOnly(true);
        minCellVoltageSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_2->addWidget(minCellVoltageSbx, 0, 1, 1, 1);

        maxCellVoltageLbl = new QLabel(widget);
        maxCellVoltageLbl->setObjectName(QString::fromUtf8("maxCellVoltageLbl"));

        gridLayout_2->addWidget(maxCellVoltageLbl, 1, 0, 1, 1);

        maxCellVoltageSbx = new QDoubleSpinBox(widget);
        maxCellVoltageSbx->setObjectName(QString::fromUtf8("maxCellVoltageSbx"));
        maxCellVoltageSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        maxCellVoltageSbx->setReadOnly(true);
        maxCellVoltageSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_2->addWidget(maxCellVoltageSbx, 1, 1, 1, 1);

        averageCellVoltageLbl = new QLabel(widget);
        averageCellVoltageLbl->setObjectName(QString::fromUtf8("averageCellVoltageLbl"));

        gridLayout_2->addWidget(averageCellVoltageLbl, 2, 0, 1, 1);

        averageCellVoltageSbx = new QDoubleSpinBox(widget);
        averageCellVoltageSbx->setObjectName(QString::fromUtf8("averageCellVoltageSbx"));
        averageCellVoltageSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        averageCellVoltageSbx->setReadOnly(true);
        averageCellVoltageSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_2->addWidget(averageCellVoltageSbx, 2, 1, 1, 1);

        averageCellTempLbl = new QLabel(widget);
        averageCellTempLbl->setObjectName(QString::fromUtf8("averageCellTempLbl"));

        gridLayout_2->addWidget(averageCellTempLbl, 2, 2, 1, 3);

        averageCellTempSbx = new QDoubleSpinBox(widget);
        averageCellTempSbx->setObjectName(QString::fromUtf8("averageCellTempSbx"));
        averageCellTempSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        averageCellTempSbx->setReadOnly(true);
        averageCellTempSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_2->addWidget(averageCellTempSbx, 2, 5, 1, 1);

        maxCellTempSbx = new QDoubleSpinBox(widget);
        maxCellTempSbx->setObjectName(QString::fromUtf8("maxCellTempSbx"));
        maxCellTempSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        maxCellTempSbx->setReadOnly(true);
        maxCellTempSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_2->addWidget(maxCellTempSbx, 1, 5, 1, 1);

        minCellTempSbx = new QDoubleSpinBox(widget);
        minCellTempSbx->setObjectName(QString::fromUtf8("minCellTempSbx"));
        minCellTempSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        minCellTempSbx->setReadOnly(true);
        minCellTempSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_2->addWidget(minCellTempSbx, 0, 5, 1, 1);

        minCellTempLbl = new QLabel(widget);
        minCellTempLbl->setObjectName(QString::fromUtf8("minCellTempLbl"));

        gridLayout_2->addWidget(minCellTempLbl, 0, 2, 1, 3);

        maxCellTempLbl = new QLabel(widget);
        maxCellTempLbl->setObjectName(QString::fromUtf8("maxCellTempLbl"));

        gridLayout_2->addWidget(maxCellTempLbl, 1, 2, 1, 3);

        CarImage = new QLabel(centralwidget);
        CarImage->setObjectName(QString::fromUtf8("CarImage"));
        CarImage->setGeometry(QRect(460, 200, 381, 451));
        CarImage->setAlignment(Qt::AlignCenter);
        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(710, 100, 161, 71));
        FRWheelGridLayout = new QGridLayout(layoutWidget3);
        FRWheelGridLayout->setObjectName(QString::fromUtf8("FRWheelGridLayout"));
        FRWheelGridLayout->setContentsMargins(0, 0, 0, 0);
        FRWheelSpeedLbl = new QLabel(layoutWidget3);
        FRWheelSpeedLbl->setObjectName(QString::fromUtf8("FRWheelSpeedLbl"));

        FRWheelGridLayout->addWidget(FRWheelSpeedLbl, 0, 0, 1, 1);

        FRWheelSpeedSbx = new QSpinBox(layoutWidget3);
        FRWheelSpeedSbx->setObjectName(QString::fromUtf8("FRWheelSpeedSbx"));
        FRWheelSpeedSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FRWheelSpeedSbx->setReadOnly(true);
        FRWheelSpeedSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        FRWheelGridLayout->addWidget(FRWheelSpeedSbx, 0, 1, 1, 1);

        FRWheelHeightLbl = new QLabel(layoutWidget3);
        FRWheelHeightLbl->setObjectName(QString::fromUtf8("FRWheelHeightLbl"));

        FRWheelGridLayout->addWidget(FRWheelHeightLbl, 1, 0, 1, 1);

        FRWheelHeightSbx = new QDoubleSpinBox(layoutWidget3);
        FRWheelHeightSbx->setObjectName(QString::fromUtf8("FRWheelHeightSbx"));
        FRWheelHeightSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FRWheelHeightSbx->setReadOnly(true);
        FRWheelHeightSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        FRWheelGridLayout->addWidget(FRWheelHeightSbx, 1, 1, 1, 1);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(700, 670, 171, 71));
        BRWheelGridLayout = new QGridLayout(layoutWidget_2);
        BRWheelGridLayout->setObjectName(QString::fromUtf8("BRWheelGridLayout"));
        BRWheelGridLayout->setContentsMargins(0, 0, 0, 0);
        BRWheelSpeedLbl = new QLabel(layoutWidget_2);
        BRWheelSpeedLbl->setObjectName(QString::fromUtf8("BRWheelSpeedLbl"));

        BRWheelGridLayout->addWidget(BRWheelSpeedLbl, 0, 0, 1, 1);

        BRWheelSpeedSbx = new QSpinBox(layoutWidget_2);
        BRWheelSpeedSbx->setObjectName(QString::fromUtf8("BRWheelSpeedSbx"));
        BRWheelSpeedSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BRWheelSpeedSbx->setReadOnly(true);
        BRWheelSpeedSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        BRWheelGridLayout->addWidget(BRWheelSpeedSbx, 0, 1, 1, 1);

        BRWheelHeightLbl = new QLabel(layoutWidget_2);
        BRWheelHeightLbl->setObjectName(QString::fromUtf8("BRWheelHeightLbl"));

        BRWheelGridLayout->addWidget(BRWheelHeightLbl, 1, 0, 1, 1);

        BRWheelHeightSbx = new QDoubleSpinBox(layoutWidget_2);
        BRWheelHeightSbx->setObjectName(QString::fromUtf8("BRWheelHeightSbx"));
        BRWheelHeightSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BRWheelHeightSbx->setReadOnly(true);
        BRWheelHeightSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        BRWheelGridLayout->addWidget(BRWheelHeightSbx, 1, 1, 1, 1);

        layoutWidget_3 = new QWidget(centralwidget);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(440, 670, 161, 71));
        BLWheelGridLayout = new QGridLayout(layoutWidget_3);
        BLWheelGridLayout->setObjectName(QString::fromUtf8("BLWheelGridLayout"));
        BLWheelGridLayout->setContentsMargins(0, 0, 0, 0);
        BLWheelSpeedLbl = new QLabel(layoutWidget_3);
        BLWheelSpeedLbl->setObjectName(QString::fromUtf8("BLWheelSpeedLbl"));

        BLWheelGridLayout->addWidget(BLWheelSpeedLbl, 0, 0, 1, 1);

        BLWheelSpeedSbx = new QSpinBox(layoutWidget_3);
        BLWheelSpeedSbx->setObjectName(QString::fromUtf8("BLWheelSpeedSbx"));
        BLWheelSpeedSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelSpeedSbx->setReadOnly(true);
        BLWheelSpeedSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        BLWheelGridLayout->addWidget(BLWheelSpeedSbx, 0, 1, 1, 1);

        BLWheelHeightLbl = new QLabel(layoutWidget_3);
        BLWheelHeightLbl->setObjectName(QString::fromUtf8("BLWheelHeightLbl"));

        BLWheelGridLayout->addWidget(BLWheelHeightLbl, 1, 0, 1, 1);

        BLWheelHeightSbx = new QDoubleSpinBox(layoutWidget_3);
        BLWheelHeightSbx->setObjectName(QString::fromUtf8("BLWheelHeightSbx"));
        BLWheelHeightSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelHeightSbx->setReadOnly(true);
        BLWheelHeightSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        BLWheelGridLayout->addWidget(BLWheelHeightSbx, 1, 1, 1, 1);

        layoutWidget4 = new QWidget(centralwidget);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(440, 100, 161, 71));
        FLWheelGridLayout = new QGridLayout(layoutWidget4);
        FLWheelGridLayout->setObjectName(QString::fromUtf8("FLWheelGridLayout"));
        FLWheelGridLayout->setContentsMargins(0, 0, 0, 0);
        FLWheelSpeedLbl = new QLabel(layoutWidget4);
        FLWheelSpeedLbl->setObjectName(QString::fromUtf8("FLWheelSpeedLbl"));

        FLWheelGridLayout->addWidget(FLWheelSpeedLbl, 0, 0, 1, 1);

        FLWheelSpeedSbx = new QSpinBox(layoutWidget4);
        FLWheelSpeedSbx->setObjectName(QString::fromUtf8("FLWheelSpeedSbx"));
        FLWheelSpeedSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FLWheelSpeedSbx->setReadOnly(true);
        FLWheelSpeedSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        FLWheelGridLayout->addWidget(FLWheelSpeedSbx, 0, 1, 1, 1);

        FLWheelHeightLbl = new QLabel(layoutWidget4);
        FLWheelHeightLbl->setObjectName(QString::fromUtf8("FLWheelHeightLbl"));

        FLWheelGridLayout->addWidget(FLWheelHeightLbl, 1, 0, 1, 1);

        FLWheelHeightSbx = new QDoubleSpinBox(layoutWidget4);
        FLWheelHeightSbx->setObjectName(QString::fromUtf8("FLWheelHeightSbx"));
        FLWheelHeightSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FLWheelHeightSbx->setReadOnly(true);
        FLWheelHeightSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        FLWheelGridLayout->addWidget(FLWheelHeightSbx, 1, 1, 1, 1);

        layoutWidget5 = new QWidget(centralwidget);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(580, 11, 144, 48));
        DriveModeGridLayout = new QGridLayout(layoutWidget5);
        DriveModeGridLayout->setObjectName(QString::fromUtf8("DriveModeGridLayout"));
        DriveModeGridLayout->setContentsMargins(0, 0, 0, 0);
        DriveModeLbl = new QLabel(layoutWidget5);
        DriveModeLbl->setObjectName(QString::fromUtf8("DriveModeLbl"));
        DriveModeLbl->setAlignment(Qt::AlignCenter);

        DriveModeGridLayout->addWidget(DriveModeLbl, 0, 0, 1, 1);

        DriveModeTbx = new QLineEdit(layoutWidget5);
        DriveModeTbx->setObjectName(QString::fromUtf8("DriveModeTbx"));
        DriveModeTbx->setAlignment(Qt::AlignCenter);
        DriveModeTbx->setReadOnly(true);

        DriveModeGridLayout->addWidget(DriveModeTbx, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1300, 21));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionSelect_Serial_Port);
        menuOptions->addAction(Dark_Mode);
        menuOptions->addAction(About_Dlg);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Dark_Mode->setText(QCoreApplication::translate("MainWindow", "Dark Mode", nullptr));
        About_Dlg->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionSelect_Serial_Port->setText(QCoreApplication::translate("MainWindow", "Select Serial Port", nullptr));
        MechanicalDataGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Mechanical Data", nullptr));
        BrakePedalImage->setText(QCoreApplication::translate("MainWindow", "Brake Pedal Image", nullptr));
        AccelPedalImage->setText(QCoreApplication::translate("MainWindow", "Accelerator Pedal Image", nullptr));
        BrakePedalLbl->setText(QCoreApplication::translate("MainWindow", "Brake", nullptr));
        AccelPedalLbl->setText(QCoreApplication::translate("MainWindow", "Accelerator", nullptr));
        SpeedLbl->setText(QCoreApplication::translate("MainWindow", "Speed (mph)", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Electrical Data", nullptr));
        BatteryImage->setText(QCoreApplication::translate("MainWindow", "Battery Image", nullptr));
        BusVoltageLbl->setText(QCoreApplication::translate("MainWindow", "Bus Voltage", nullptr));
        BusCurrentLbl->setText(QCoreApplication::translate("MainWindow", "Bus Current", nullptr));
        RinehartVoltageLbl->setText(QCoreApplication::translate("MainWindow", "RInehart Voltage", nullptr));
        WheelConnectionLbl->setText(QCoreApplication::translate("MainWindow", "Steering Wheel Connection", nullptr));
        WheelConnectionStatusImage->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
        DriveDirectionTbx->setText(QCoreApplication::translate("MainWindow", "Direction", nullptr));
        commandedTorqueLbl->setText(QCoreApplication::translate("MainWindow", "Commanded Torque:", nullptr));
        DriveDirectionLbl->setText(QCoreApplication::translate("MainWindow", "Drive Direction: ", nullptr));
        InverterStatusLED->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
        InverterStatusLbl->setText(QCoreApplication::translate("MainWindow", "Inverter Status: ", nullptr));
        IMDFaultLED->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
        BMSFaultLED->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
        IMDFaultLbl->setText(QCoreApplication::translate("MainWindow", "IMD Fault: ", nullptr));
        BMSFaultLbl->setText(QCoreApplication::translate("MainWindow", "BMS Fault:", nullptr));
        readyToDriveLbl->setText(QCoreApplication::translate("MainWindow", "Ready to Drive:", nullptr));
        readyToDriveLED->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
        prechargeStateLbl->setText(QCoreApplication::translate("MainWindow", "Precharge State", nullptr));
        prechargeStateTbx->setText(QCoreApplication::translate("MainWindow", "State", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Cell Infomation", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Pack Information", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Critical Data", nullptr));
        minCellVoltageLbl->setText(QCoreApplication::translate("MainWindow", "Min Cell Voltage", nullptr));
        maxCellVoltageLbl->setText(QCoreApplication::translate("MainWindow", "Max Cell Voltage", nullptr));
        averageCellVoltageLbl->setText(QCoreApplication::translate("MainWindow", "Average Cell Voltage", nullptr));
        averageCellTempLbl->setText(QCoreApplication::translate("MainWindow", "Average Cell Voltage", nullptr));
        minCellTempLbl->setText(QCoreApplication::translate("MainWindow", "Min Cell Temp", nullptr));
        maxCellTempLbl->setText(QCoreApplication::translate("MainWindow", "Max Cell Temp", nullptr));
        CarImage->setText(QCoreApplication::translate("MainWindow", "Image of Car", nullptr));
        FRWheelSpeedLbl->setText(QCoreApplication::translate("MainWindow", "Wheel Speed", nullptr));
        FRWheelHeightLbl->setText(QCoreApplication::translate("MainWindow", "Suspension", nullptr));
        BRWheelSpeedLbl->setText(QCoreApplication::translate("MainWindow", "Wheel Speed", nullptr));
        BRWheelHeightLbl->setText(QCoreApplication::translate("MainWindow", "Suspension", nullptr));
        BLWheelSpeedLbl->setText(QCoreApplication::translate("MainWindow", "Wheel Speed", nullptr));
        BLWheelHeightLbl->setText(QCoreApplication::translate("MainWindow", "Suspension", nullptr));
        FLWheelSpeedLbl->setText(QCoreApplication::translate("MainWindow", "Wheel Speed", nullptr));
        FLWheelHeightLbl->setText(QCoreApplication::translate("MainWindow", "Suspension", nullptr));
        DriveModeLbl->setText(QCoreApplication::translate("MainWindow", "Drive Mode", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
