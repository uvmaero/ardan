/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
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
#include <QtWidgets/QVBoxLayout>
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
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QGridLayout *PrimaryVoltageGridLayout;
    QLabel *BusVoltageLbl;
    QDoubleSpinBox *BusVoltageSbx;
    QLabel *BusCurrentLbl;
    QDoubleSpinBox *BusCurrentSbx;
    QLabel *RinehartVoltageLbl;
    QDoubleSpinBox *RinehartVoltageSbx;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
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
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QGridLayout *gridLayout_2;
    QLabel *minCellVoltageLbl;
    QDoubleSpinBox *minCellTempSbx;
    QLabel *maxCellVoltageLbl;
    QLabel *maxCellTempLbl;
    QLabel *minCellTempLbl;
    QDoubleSpinBox *maxCellVoltageSbx;
    QDoubleSpinBox *minCellVoltageSbx;
    QDoubleSpinBox *maxCellTempSbx;
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
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1300, 670);
        MainWindow->setMinimumSize(QSize(1300, 670));
        MainWindow->setMaximumSize(QSize(1300, 670));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/bessieIcon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        Dark_Mode = new QAction(MainWindow);
        Dark_Mode->setObjectName("Dark_Mode");
        Dark_Mode->setCheckable(true);
        About_Dlg = new QAction(MainWindow);
        About_Dlg->setObjectName("About_Dlg");
        actionSelect_Serial_Port = new QAction(MainWindow);
        actionSelect_Serial_Port->setObjectName("actionSelect_Serial_Port");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MechanicalDataGroupBox = new QGroupBox(centralwidget);
        MechanicalDataGroupBox->setObjectName("MechanicalDataGroupBox");
        MechanicalDataGroupBox->setGeometry(QRect(10, 10, 411, 611));
        BrakePedalImage = new QLabel(MechanicalDataGroupBox);
        BrakePedalImage->setObjectName("BrakePedalImage");
        BrakePedalImage->setGeometry(QRect(50, 380, 101, 151));
        AccelPedalImage = new QLabel(MechanicalDataGroupBox);
        AccelPedalImage->setObjectName("AccelPedalImage");
        AccelPedalImage->setGeometry(QRect(270, 380, 111, 151));
        BrakePedalLbl = new QLabel(MechanicalDataGroupBox);
        BrakePedalLbl->setObjectName("BrakePedalLbl");
        BrakePedalLbl->setGeometry(QRect(60, 580, 62, 16));
        BrakePedalLbl->setAlignment(Qt::AlignCenter);
        AccelPedalLbl = new QLabel(MechanicalDataGroupBox);
        AccelPedalLbl->setObjectName("AccelPedalLbl");
        AccelPedalLbl->setGeometry(QRect(270, 580, 81, 20));
        AccelPedalLbl->setAlignment(Qt::AlignCenter);
        BrakePedalProgressBar = new QProgressBar(MechanicalDataGroupBox);
        BrakePedalProgressBar->setObjectName("BrakePedalProgressBar");
        BrakePedalProgressBar->setGeometry(QRect(10, 540, 161, 23));
        BrakePedalProgressBar->setValue(13);
        AccelPedalProgressBar = new QProgressBar(MechanicalDataGroupBox);
        AccelPedalProgressBar->setObjectName("AccelPedalProgressBar");
        AccelPedalProgressBar->setGeometry(QRect(230, 540, 171, 23));
        AccelPedalProgressBar->setValue(66);
        SpeedLbl = new QLabel(MechanicalDataGroupBox);
        SpeedLbl->setObjectName("SpeedLbl");
        SpeedLbl->setGeometry(QRect(160, 200, 91, 16));
        CurrentSpeedLCD = new QLCDNumber(MechanicalDataGroupBox);
        CurrentSpeedLCD->setObjectName("CurrentSpeedLCD");
        CurrentSpeedLCD->setGeometry(QRect(20, 40, 381, 151));
        CurrentSpeedLCD->setSmallDecimalPoint(false);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(890, 10, 401, 611));
        BatteryImage = new QLabel(groupBox_2);
        BatteryImage->setObjectName("BatteryImage");
        BatteryImage->setGeometry(QRect(70, 20, 271, 91));
        BatteryImage->setAlignment(Qt::AlignCenter);
        BatteryPrecentageProgressBar = new QProgressBar(groupBox_2);
        BatteryPrecentageProgressBar->setObjectName("BatteryPrecentageProgressBar");
        BatteryPrecentageProgressBar->setGeometry(QRect(10, 120, 381, 23));
        BatteryPrecentageProgressBar->setValue(78);
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(100, 330, 191, 121));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        PrimaryVoltageGridLayout = new QGridLayout();
        PrimaryVoltageGridLayout->setObjectName("PrimaryVoltageGridLayout");
        BusVoltageLbl = new QLabel(layoutWidget);
        BusVoltageLbl->setObjectName("BusVoltageLbl");

        PrimaryVoltageGridLayout->addWidget(BusVoltageLbl, 0, 0, 1, 1);

        BusVoltageSbx = new QDoubleSpinBox(layoutWidget);
        BusVoltageSbx->setObjectName("BusVoltageSbx");
        BusVoltageSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BusVoltageSbx->setReadOnly(true);
        BusVoltageSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BusVoltageSbx->setMaximum(1000.000000000000000);

        PrimaryVoltageGridLayout->addWidget(BusVoltageSbx, 0, 1, 1, 1);

        BusCurrentLbl = new QLabel(layoutWidget);
        BusCurrentLbl->setObjectName("BusCurrentLbl");

        PrimaryVoltageGridLayout->addWidget(BusCurrentLbl, 1, 0, 1, 1);

        BusCurrentSbx = new QDoubleSpinBox(layoutWidget);
        BusCurrentSbx->setObjectName("BusCurrentSbx");
        BusCurrentSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BusCurrentSbx->setReadOnly(true);
        BusCurrentSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BusCurrentSbx->setMaximum(1000.000000000000000);

        PrimaryVoltageGridLayout->addWidget(BusCurrentSbx, 1, 1, 1, 1);

        RinehartVoltageLbl = new QLabel(layoutWidget);
        RinehartVoltageLbl->setObjectName("RinehartVoltageLbl");

        PrimaryVoltageGridLayout->addWidget(RinehartVoltageLbl, 2, 0, 1, 1);

        RinehartVoltageSbx = new QDoubleSpinBox(layoutWidget);
        RinehartVoltageSbx->setObjectName("RinehartVoltageSbx");
        RinehartVoltageSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        RinehartVoltageSbx->setReadOnly(true);
        RinehartVoltageSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        RinehartVoltageSbx->setMaximum(1000.000000000000000);

        PrimaryVoltageGridLayout->addWidget(RinehartVoltageSbx, 2, 1, 1, 1);


        verticalLayout->addLayout(PrimaryVoltageGridLayout);

        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 170, 381, 133));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        CommandedTorqueSbx = new QDoubleSpinBox(layoutWidget1);
        CommandedTorqueSbx->setObjectName("CommandedTorqueSbx");
        CommandedTorqueSbx->setMaximumSize(QSize(60, 16777215));
        CommandedTorqueSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        CommandedTorqueSbx->setReadOnly(true);
        CommandedTorqueSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        CommandedTorqueSbx->setDecimals(0);
        CommandedTorqueSbx->setMaximum(250.000000000000000);

        gridLayout->addWidget(CommandedTorqueSbx, 0, 6, 1, 1);

        DriveDirectionTbx = new QLabel(layoutWidget1);
        DriveDirectionTbx->setObjectName("DriveDirectionTbx");

        gridLayout->addWidget(DriveDirectionTbx, 1, 6, 1, 1);

        commandedTorqueLbl = new QLabel(layoutWidget1);
        commandedTorqueLbl->setObjectName("commandedTorqueLbl");

        gridLayout->addWidget(commandedTorqueLbl, 0, 5, 1, 1);

        DriveDirectionLbl = new QLabel(layoutWidget1);
        DriveDirectionLbl->setObjectName("DriveDirectionLbl");

        gridLayout->addWidget(DriveDirectionLbl, 1, 5, 1, 1);

        InverterStatusLED = new QLabel(layoutWidget1);
        InverterStatusLED->setObjectName("InverterStatusLED");

        gridLayout->addWidget(InverterStatusLED, 3, 2, 1, 2);

        InverterStatusLbl = new QLabel(layoutWidget1);
        InverterStatusLbl->setObjectName("InverterStatusLbl");

        gridLayout->addWidget(InverterStatusLbl, 3, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        IMDFaultLED = new QLabel(layoutWidget1);
        IMDFaultLED->setObjectName("IMDFaultLED");

        gridLayout->addWidget(IMDFaultLED, 1, 2, 1, 2);

        BMSFaultLED = new QLabel(layoutWidget1);
        BMSFaultLED->setObjectName("BMSFaultLED");

        gridLayout->addWidget(BMSFaultLED, 2, 2, 1, 2);

        IMDFaultLbl = new QLabel(layoutWidget1);
        IMDFaultLbl->setObjectName("IMDFaultLbl");

        gridLayout->addWidget(IMDFaultLbl, 1, 0, 1, 2);

        BMSFaultLbl = new QLabel(layoutWidget1);
        BMSFaultLbl->setObjectName("BMSFaultLbl");

        gridLayout->addWidget(BMSFaultLbl, 2, 0, 1, 2);

        readyToDriveLbl = new QLabel(layoutWidget1);
        readyToDriveLbl->setObjectName("readyToDriveLbl");

        gridLayout->addWidget(readyToDriveLbl, 0, 0, 1, 2);

        readyToDriveLED = new QLabel(layoutWidget1);
        readyToDriveLED->setObjectName("readyToDriveLED");

        gridLayout->addWidget(readyToDriveLED, 0, 2, 1, 2);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 1, 4, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 2, 4, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 3, 4, 1, 1);

        prechargeStateLbl = new QLabel(layoutWidget1);
        prechargeStateLbl->setObjectName("prechargeStateLbl");

        gridLayout->addWidget(prechargeStateLbl, 2, 5, 1, 1);

        prechargeStateTbx = new QLabel(layoutWidget1);
        prechargeStateTbx->setObjectName("prechargeStateTbx");

        gridLayout->addWidget(prechargeStateTbx, 2, 6, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        layoutWidget2 = new QWidget(groupBox_2);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(10, 490, 390, 110));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        minCellVoltageLbl = new QLabel(layoutWidget2);
        minCellVoltageLbl->setObjectName("minCellVoltageLbl");

        gridLayout_2->addWidget(minCellVoltageLbl, 0, 0, 1, 1);

        minCellTempSbx = new QDoubleSpinBox(layoutWidget2);
        minCellTempSbx->setObjectName("minCellTempSbx");
        minCellTempSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        minCellTempSbx->setReadOnly(true);
        minCellTempSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_2->addWidget(minCellTempSbx, 0, 4, 1, 1);

        maxCellVoltageLbl = new QLabel(layoutWidget2);
        maxCellVoltageLbl->setObjectName("maxCellVoltageLbl");

        gridLayout_2->addWidget(maxCellVoltageLbl, 1, 0, 1, 1);

        maxCellTempLbl = new QLabel(layoutWidget2);
        maxCellTempLbl->setObjectName("maxCellTempLbl");

        gridLayout_2->addWidget(maxCellTempLbl, 1, 2, 1, 2);

        minCellTempLbl = new QLabel(layoutWidget2);
        minCellTempLbl->setObjectName("minCellTempLbl");

        gridLayout_2->addWidget(minCellTempLbl, 0, 2, 1, 2);

        maxCellVoltageSbx = new QDoubleSpinBox(layoutWidget2);
        maxCellVoltageSbx->setObjectName("maxCellVoltageSbx");
        maxCellVoltageSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        maxCellVoltageSbx->setReadOnly(true);
        maxCellVoltageSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        maxCellVoltageSbx->setDecimals(3);

        gridLayout_2->addWidget(maxCellVoltageSbx, 1, 1, 1, 1);

        minCellVoltageSbx = new QDoubleSpinBox(layoutWidget2);
        minCellVoltageSbx->setObjectName("minCellVoltageSbx");
        minCellVoltageSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        minCellVoltageSbx->setReadOnly(true);
        minCellVoltageSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        minCellVoltageSbx->setDecimals(3);

        gridLayout_2->addWidget(minCellVoltageSbx, 0, 1, 1, 1);

        maxCellTempSbx = new QDoubleSpinBox(layoutWidget2);
        maxCellTempSbx->setObjectName("maxCellTempSbx");
        maxCellTempSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        maxCellTempSbx->setReadOnly(true);
        maxCellTempSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_2->addWidget(maxCellTempSbx, 1, 4, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        CarImage = new QLabel(centralwidget);
        CarImage->setObjectName("CarImage");
        CarImage->setGeometry(QRect(480, 180, 351, 351));
        CarImage->setAlignment(Qt::AlignCenter);
        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(710, 100, 161, 71));
        FRWheelGridLayout = new QGridLayout(layoutWidget3);
        FRWheelGridLayout->setObjectName("FRWheelGridLayout");
        FRWheelGridLayout->setContentsMargins(0, 0, 0, 0);
        FRWheelSpeedLbl = new QLabel(layoutWidget3);
        FRWheelSpeedLbl->setObjectName("FRWheelSpeedLbl");

        FRWheelGridLayout->addWidget(FRWheelSpeedLbl, 0, 0, 1, 1);

        FRWheelSpeedSbx = new QSpinBox(layoutWidget3);
        FRWheelSpeedSbx->setObjectName("FRWheelSpeedSbx");
        FRWheelSpeedSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FRWheelSpeedSbx->setReadOnly(true);
        FRWheelSpeedSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        FRWheelSpeedSbx->setMaximum(1000);

        FRWheelGridLayout->addWidget(FRWheelSpeedSbx, 0, 1, 1, 1);

        FRWheelHeightLbl = new QLabel(layoutWidget3);
        FRWheelHeightLbl->setObjectName("FRWheelHeightLbl");

        FRWheelGridLayout->addWidget(FRWheelHeightLbl, 1, 0, 1, 1);

        FRWheelHeightSbx = new QDoubleSpinBox(layoutWidget3);
        FRWheelHeightSbx->setObjectName("FRWheelHeightSbx");
        FRWheelHeightSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FRWheelHeightSbx->setReadOnly(true);
        FRWheelHeightSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        FRWheelGridLayout->addWidget(FRWheelHeightSbx, 1, 1, 1, 1);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName("layoutWidget_2");
        layoutWidget_2->setGeometry(QRect(700, 540, 171, 71));
        BRWheelGridLayout = new QGridLayout(layoutWidget_2);
        BRWheelGridLayout->setObjectName("BRWheelGridLayout");
        BRWheelGridLayout->setContentsMargins(0, 0, 0, 0);
        BRWheelSpeedLbl = new QLabel(layoutWidget_2);
        BRWheelSpeedLbl->setObjectName("BRWheelSpeedLbl");

        BRWheelGridLayout->addWidget(BRWheelSpeedLbl, 0, 0, 1, 1);

        BRWheelSpeedSbx = new QSpinBox(layoutWidget_2);
        BRWheelSpeedSbx->setObjectName("BRWheelSpeedSbx");
        BRWheelSpeedSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BRWheelSpeedSbx->setReadOnly(true);
        BRWheelSpeedSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BRWheelSpeedSbx->setMaximum(1000);

        BRWheelGridLayout->addWidget(BRWheelSpeedSbx, 0, 1, 1, 1);

        BRWheelHeightLbl = new QLabel(layoutWidget_2);
        BRWheelHeightLbl->setObjectName("BRWheelHeightLbl");

        BRWheelGridLayout->addWidget(BRWheelHeightLbl, 1, 0, 1, 1);

        BRWheelHeightSbx = new QDoubleSpinBox(layoutWidget_2);
        BRWheelHeightSbx->setObjectName("BRWheelHeightSbx");
        BRWheelHeightSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BRWheelHeightSbx->setReadOnly(true);
        BRWheelHeightSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        BRWheelGridLayout->addWidget(BRWheelHeightSbx, 1, 1, 1, 1);

        layoutWidget_3 = new QWidget(centralwidget);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(440, 540, 161, 71));
        BLWheelGridLayout = new QGridLayout(layoutWidget_3);
        BLWheelGridLayout->setObjectName("BLWheelGridLayout");
        BLWheelGridLayout->setContentsMargins(0, 0, 0, 0);
        BLWheelSpeedLbl = new QLabel(layoutWidget_3);
        BLWheelSpeedLbl->setObjectName("BLWheelSpeedLbl");

        BLWheelGridLayout->addWidget(BLWheelSpeedLbl, 0, 0, 1, 1);

        BLWheelSpeedSbx = new QSpinBox(layoutWidget_3);
        BLWheelSpeedSbx->setObjectName("BLWheelSpeedSbx");
        BLWheelSpeedSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelSpeedSbx->setReadOnly(true);
        BLWheelSpeedSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLWheelSpeedSbx->setMaximum(1000);

        BLWheelGridLayout->addWidget(BLWheelSpeedSbx, 0, 1, 1, 1);

        BLWheelHeightLbl = new QLabel(layoutWidget_3);
        BLWheelHeightLbl->setObjectName("BLWheelHeightLbl");

        BLWheelGridLayout->addWidget(BLWheelHeightLbl, 1, 0, 1, 1);

        BLWheelHeightSbx = new QDoubleSpinBox(layoutWidget_3);
        BLWheelHeightSbx->setObjectName("BLWheelHeightSbx");
        BLWheelHeightSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelHeightSbx->setReadOnly(true);
        BLWheelHeightSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        BLWheelGridLayout->addWidget(BLWheelHeightSbx, 1, 1, 1, 1);

        layoutWidget4 = new QWidget(centralwidget);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(440, 100, 161, 71));
        FLWheelGridLayout = new QGridLayout(layoutWidget4);
        FLWheelGridLayout->setObjectName("FLWheelGridLayout");
        FLWheelGridLayout->setContentsMargins(0, 0, 0, 0);
        FLWheelSpeedLbl = new QLabel(layoutWidget4);
        FLWheelSpeedLbl->setObjectName("FLWheelSpeedLbl");

        FLWheelGridLayout->addWidget(FLWheelSpeedLbl, 0, 0, 1, 1);

        FLWheelSpeedSbx = new QSpinBox(layoutWidget4);
        FLWheelSpeedSbx->setObjectName("FLWheelSpeedSbx");
        FLWheelSpeedSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FLWheelSpeedSbx->setReadOnly(true);
        FLWheelSpeedSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        FLWheelSpeedSbx->setMaximum(1000);

        FLWheelGridLayout->addWidget(FLWheelSpeedSbx, 0, 1, 1, 1);

        FLWheelHeightLbl = new QLabel(layoutWidget4);
        FLWheelHeightLbl->setObjectName("FLWheelHeightLbl");

        FLWheelGridLayout->addWidget(FLWheelHeightLbl, 1, 0, 1, 1);

        FLWheelHeightSbx = new QDoubleSpinBox(layoutWidget4);
        FLWheelHeightSbx->setObjectName("FLWheelHeightSbx");
        FLWheelHeightSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FLWheelHeightSbx->setReadOnly(true);
        FLWheelHeightSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        FLWheelGridLayout->addWidget(FLWheelHeightSbx, 1, 1, 1, 1);

        layoutWidget5 = new QWidget(centralwidget);
        layoutWidget5->setObjectName("layoutWidget5");
        layoutWidget5->setGeometry(QRect(580, 11, 144, 52));
        DriveModeGridLayout = new QGridLayout(layoutWidget5);
        DriveModeGridLayout->setObjectName("DriveModeGridLayout");
        DriveModeGridLayout->setContentsMargins(0, 0, 0, 0);
        DriveModeLbl = new QLabel(layoutWidget5);
        DriveModeLbl->setObjectName("DriveModeLbl");
        DriveModeLbl->setAlignment(Qt::AlignCenter);

        DriveModeGridLayout->addWidget(DriveModeLbl, 0, 0, 1, 1);

        DriveModeTbx = new QLineEdit(layoutWidget5);
        DriveModeTbx->setObjectName("DriveModeTbx");
        DriveModeTbx->setAlignment(Qt::AlignCenter);
        DriveModeTbx->setReadOnly(true);

        DriveModeGridLayout->addWidget(DriveModeTbx, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1300, 23));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName("menuOptions");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
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
        label_2->setText(QCoreApplication::translate("MainWindow", "Pack Information", nullptr));
        BusVoltageLbl->setText(QCoreApplication::translate("MainWindow", "Bus Voltage", nullptr));
        BusCurrentLbl->setText(QCoreApplication::translate("MainWindow", "Bus Current", nullptr));
        RinehartVoltageLbl->setText(QCoreApplication::translate("MainWindow", "RInehart Voltage", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Critical Data", nullptr));
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
        minCellVoltageLbl->setText(QCoreApplication::translate("MainWindow", "Min Cell Voltage", nullptr));
        maxCellVoltageLbl->setText(QCoreApplication::translate("MainWindow", "Max Cell Voltage", nullptr));
        maxCellTempLbl->setText(QCoreApplication::translate("MainWindow", "Max Cell Temp", nullptr));
        minCellTempLbl->setText(QCoreApplication::translate("MainWindow", "Min Cell Temp", nullptr));
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
