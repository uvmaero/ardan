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
#include <QtWidgets/QHBoxLayout>
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
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
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
    QWidget *packCurrentPlot;
    QWidget *packCurrentPlot_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QWidget *accelPlot;
    QHBoxLayout *horizontalLayout;
    QLabel *AccelPedalLbl;
    QProgressBar *AccelPedalProgressBar;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_5;
    QWidget *brakePlot;
    QHBoxLayout *horizontalLayout_2;
    QLabel *BrakePedalLbl;
    QProgressBar *BrakePedalProgressBar;
    QWidget *widget2;
    QGridLayout *gridLayout;
    QLineEdit *DriveModeTbx;
    QDoubleSpinBox *CommandedTorqueSbx;
    QLabel *BMSFaultLED;
    QSpacerItem *horizontalSpacer_11;
    QLabel *IMDFaultLED;
    QLabel *InverterStatusLbl;
    QLabel *DriveDirectionLbl;
    QLabel *commandedTorqueLbl;
    QLabel *readyToDriveLED;
    QLabel *IMDFaultLbl;
    QLabel *DriveDirectionTbx;
    QLabel *prechargeStateTbx;
    QLabel *prechargeStateLbl;
    QLabel *DriveModeLbl;
    QLabel *readyToDriveLbl;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_10;
    QLabel *InverterStatusLED;
    QLabel *BMSFaultLbl;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_2;
    QLabel *BatteryImage;
    QProgressBar *BatteryPrecentageProgressBar;
    QWidget *widget4;
    QVBoxLayout *verticalLayout_6;
    QWidget *speedPlot;
    QHBoxLayout *horizontalLayout_3;
    QLabel *currentSpeedLbl;
    QLabel *currentSpeedDataLbl;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QLabel *cellInfoLbl;
    QGridLayout *gridLayout_2;
    QLabel *minCellVoltageLbl;
    QDoubleSpinBox *minCellTempSbx;
    QLabel *maxCellVoltageLbl;
    QLabel *maxCellTempLbl;
    QLabel *minCellTempLbl;
    QDoubleSpinBox *maxCellVoltageSbx;
    QDoubleSpinBox *minCellVoltageSbx;
    QDoubleSpinBox *maxCellTempSbx;
    QWidget *widget5;
    QGridLayout *gridLayout_3;
    QGridLayout *FLWheelGridLayout;
    QLabel *FLWheelSpeedLbl;
    QSpinBox *FLWheelSpeedSbx;
    QLabel *FLWheelHeightLbl;
    QDoubleSpinBox *FLWheelHeightSbx;
    QGridLayout *BLWheelGridLayout;
    QLabel *BLWheelSpeedLbl;
    QSpinBox *BLWheelSpeedSbx;
    QLabel *BLWheelHeightLbl;
    QDoubleSpinBox *BLWheelHeightSbx;
    QGridLayout *BRWheelGridLayout;
    QLabel *BRWheelSpeedLbl;
    QSpinBox *BRWheelSpeedSbx;
    QLabel *BRWheelHeightLbl;
    QDoubleSpinBox *BRWheelHeightSbx;
    QGridLayout *FRWheelGridLayout;
    QLabel *FRWheelSpeedLbl;
    QSpinBox *FRWheelSpeedSbx;
    QDoubleSpinBox *FRWheelHeightSbx;
    QLabel *FRWheelHeightLbl;
    QMenuBar *menubar;
    QMenu *menuOptions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1714, 1180);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setMaximumSize(QSize(9999, 9999));
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
        MechanicalDataGroupBox->setGeometry(QRect(10, 0, 1111, 1121));
        spinBox = new QSpinBox(MechanicalDataGroupBox);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(10, 760, 101, 20));
        spinBox->setMaximum(255);
        spinBox_2 = new QSpinBox(MechanicalDataGroupBox);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(530, 760, 91, 20));
        spinBox_2->setMaximum(255);
        layoutWidget = new QWidget(MechanicalDataGroupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(700, 820, 331, 121));
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

        packCurrentPlot = new QWidget(MechanicalDataGroupBox);
        packCurrentPlot->setObjectName("packCurrentPlot");
        packCurrentPlot->setGeometry(QRect(670, 960, 400, 150));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(packCurrentPlot->sizePolicy().hasHeightForWidth());
        packCurrentPlot->setSizePolicy(sizePolicy1);
        packCurrentPlot->setMinimumSize(QSize(400, 150));
        packCurrentPlot->setMaximumSize(QSize(400, 150));
        packCurrentPlot_2 = new QWidget(MechanicalDataGroupBox);
        packCurrentPlot_2->setObjectName("packCurrentPlot_2");
        packCurrentPlot_2->setGeometry(QRect(670, 580, 400, 150));
        sizePolicy1.setHeightForWidth(packCurrentPlot_2->sizePolicy().hasHeightForWidth());
        packCurrentPlot_2->setSizePolicy(sizePolicy1);
        packCurrentPlot_2->setMinimumSize(QSize(400, 150));
        packCurrentPlot_2->setMaximumSize(QSize(400, 150));
        widget = new QWidget(MechanicalDataGroupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 420, 611, 336));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        accelPlot = new QWidget(widget);
        accelPlot->setObjectName("accelPlot");
        sizePolicy1.setHeightForWidth(accelPlot->sizePolicy().hasHeightForWidth());
        accelPlot->setSizePolicy(sizePolicy1);
        accelPlot->setMinimumSize(QSize(600, 300));
        accelPlot->setMaximumSize(QSize(600, 300));

        verticalLayout_4->addWidget(accelPlot);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        AccelPedalLbl = new QLabel(widget);
        AccelPedalLbl->setObjectName("AccelPedalLbl");
        AccelPedalLbl->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(AccelPedalLbl);

        AccelPedalProgressBar = new QProgressBar(widget);
        AccelPedalProgressBar->setObjectName("AccelPedalProgressBar");
        AccelPedalProgressBar->setValue(66);

        horizontalLayout->addWidget(AccelPedalProgressBar);


        verticalLayout_4->addLayout(horizontalLayout);

        widget1 = new QWidget(MechanicalDataGroupBox);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(10, 780, 611, 336));
        verticalLayout_5 = new QVBoxLayout(widget1);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        brakePlot = new QWidget(widget1);
        brakePlot->setObjectName("brakePlot");
        sizePolicy1.setHeightForWidth(brakePlot->sizePolicy().hasHeightForWidth());
        brakePlot->setSizePolicy(sizePolicy1);
        brakePlot->setMinimumSize(QSize(600, 300));
        brakePlot->setMaximumSize(QSize(600, 300));

        verticalLayout_5->addWidget(brakePlot);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        BrakePedalLbl = new QLabel(widget1);
        BrakePedalLbl->setObjectName("BrakePedalLbl");
        BrakePedalLbl->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(BrakePedalLbl);

        BrakePedalProgressBar = new QProgressBar(widget1);
        BrakePedalProgressBar->setObjectName("BrakePedalProgressBar");
        BrakePedalProgressBar->setValue(13);

        horizontalLayout_2->addWidget(BrakePedalProgressBar);


        verticalLayout_5->addLayout(horizontalLayout_2);

        widget2 = new QWidget(MechanicalDataGroupBox);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(670, 130, 442, 201));
        gridLayout = new QGridLayout(widget2);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        DriveModeTbx = new QLineEdit(widget2);
        DriveModeTbx->setObjectName("DriveModeTbx");
        DriveModeTbx->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        DriveModeTbx->setReadOnly(true);

        gridLayout->addWidget(DriveModeTbx, 4, 4, 1, 1);

        CommandedTorqueSbx = new QDoubleSpinBox(widget2);
        CommandedTorqueSbx->setObjectName("CommandedTorqueSbx");
        CommandedTorqueSbx->setMaximumSize(QSize(60, 16777215));
        CommandedTorqueSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        CommandedTorqueSbx->setReadOnly(true);
        CommandedTorqueSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        CommandedTorqueSbx->setDecimals(0);
        CommandedTorqueSbx->setMaximum(250.000000000000000);

        gridLayout->addWidget(CommandedTorqueSbx, 1, 4, 1, 1);

        BMSFaultLED = new QLabel(widget2);
        BMSFaultLED->setObjectName("BMSFaultLED");
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(BMSFaultLED->sizePolicy().hasHeightForWidth());
        BMSFaultLED->setSizePolicy(sizePolicy2);
        BMSFaultLED->setMinimumSize(QSize(0, 30));
        BMSFaultLED->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(BMSFaultLED, 3, 1, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 4, 2, 1, 1);

        IMDFaultLED = new QLabel(widget2);
        IMDFaultLED->setObjectName("IMDFaultLED");
        sizePolicy2.setHeightForWidth(IMDFaultLED->sizePolicy().hasHeightForWidth());
        IMDFaultLED->setSizePolicy(sizePolicy2);
        IMDFaultLED->setMinimumSize(QSize(0, 30));
        IMDFaultLED->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(IMDFaultLED, 2, 1, 1, 1);

        InverterStatusLbl = new QLabel(widget2);
        InverterStatusLbl->setObjectName("InverterStatusLbl");

        gridLayout->addWidget(InverterStatusLbl, 4, 0, 1, 1);

        DriveDirectionLbl = new QLabel(widget2);
        DriveDirectionLbl->setObjectName("DriveDirectionLbl");

        gridLayout->addWidget(DriveDirectionLbl, 2, 3, 1, 1);

        commandedTorqueLbl = new QLabel(widget2);
        commandedTorqueLbl->setObjectName("commandedTorqueLbl");

        gridLayout->addWidget(commandedTorqueLbl, 1, 3, 1, 1);

        readyToDriveLED = new QLabel(widget2);
        readyToDriveLED->setObjectName("readyToDriveLED");
        sizePolicy2.setHeightForWidth(readyToDriveLED->sizePolicy().hasHeightForWidth());
        readyToDriveLED->setSizePolicy(sizePolicy2);
        readyToDriveLED->setMinimumSize(QSize(0, 30));
        readyToDriveLED->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(readyToDriveLED, 1, 1, 1, 1);

        IMDFaultLbl = new QLabel(widget2);
        IMDFaultLbl->setObjectName("IMDFaultLbl");

        gridLayout->addWidget(IMDFaultLbl, 2, 0, 1, 1);

        DriveDirectionTbx = new QLabel(widget2);
        DriveDirectionTbx->setObjectName("DriveDirectionTbx");

        gridLayout->addWidget(DriveDirectionTbx, 2, 4, 1, 1);

        prechargeStateTbx = new QLabel(widget2);
        prechargeStateTbx->setObjectName("prechargeStateTbx");

        gridLayout->addWidget(prechargeStateTbx, 3, 4, 1, 1);

        prechargeStateLbl = new QLabel(widget2);
        prechargeStateLbl->setObjectName("prechargeStateLbl");

        gridLayout->addWidget(prechargeStateLbl, 3, 3, 1, 1);

        DriveModeLbl = new QLabel(widget2);
        DriveModeLbl->setObjectName("DriveModeLbl");
        DriveModeLbl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(DriveModeLbl, 4, 3, 1, 1);

        readyToDriveLbl = new QLabel(widget2);
        readyToDriveLbl->setObjectName("readyToDriveLbl");

        gridLayout->addWidget(readyToDriveLbl, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 3, 2, 1, 1);

        InverterStatusLED = new QLabel(widget2);
        InverterStatusLED->setObjectName("InverterStatusLED");
        InverterStatusLED->setEnabled(true);
        sizePolicy2.setHeightForWidth(InverterStatusLED->sizePolicy().hasHeightForWidth());
        InverterStatusLED->setSizePolicy(sizePolicy2);
        InverterStatusLED->setMinimumSize(QSize(0, 30));
        InverterStatusLED->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(InverterStatusLED, 4, 1, 1, 1);

        BMSFaultLbl = new QLabel(widget2);
        BMSFaultLbl->setObjectName("BMSFaultLbl");

        gridLayout->addWidget(BMSFaultLbl, 3, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 2, 2, 1, 1);

        label_3 = new QLabel(widget2);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 4, 1, 1);

        widget3 = new QWidget(MechanicalDataGroupBox);
        widget3->setObjectName("widget3");
        widget3->setGeometry(QRect(670, 420, 431, 141));
        verticalLayout_2 = new QVBoxLayout(widget3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        BatteryImage = new QLabel(widget3);
        BatteryImage->setObjectName("BatteryImage");
        sizePolicy1.setHeightForWidth(BatteryImage->sizePolicy().hasHeightForWidth());
        BatteryImage->setSizePolicy(sizePolicy1);
        BatteryImage->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(BatteryImage);

        BatteryPrecentageProgressBar = new QProgressBar(widget3);
        BatteryPrecentageProgressBar->setObjectName("BatteryPrecentageProgressBar");
        BatteryPrecentageProgressBar->setValue(78);

        verticalLayout_2->addWidget(BatteryPrecentageProgressBar);

        widget4 = new QWidget(MechanicalDataGroupBox);
        widget4->setObjectName("widget4");
        widget4->setGeometry(QRect(10, 30, 611, 371));
        verticalLayout_6 = new QVBoxLayout(widget4);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        speedPlot = new QWidget(widget4);
        speedPlot->setObjectName("speedPlot");
        sizePolicy1.setHeightForWidth(speedPlot->sizePolicy().hasHeightForWidth());
        speedPlot->setSizePolicy(sizePolicy1);
        speedPlot->setMinimumSize(QSize(600, 300));
        speedPlot->setMaximumSize(QSize(600, 300));

        verticalLayout_6->addWidget(speedPlot);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        currentSpeedLbl = new QLabel(widget4);
        currentSpeedLbl->setObjectName("currentSpeedLbl");

        horizontalLayout_3->addWidget(currentSpeedLbl);

        currentSpeedDataLbl = new QLabel(widget4);
        currentSpeedDataLbl->setObjectName("currentSpeedDataLbl");

        horizontalLayout_3->addWidget(currentSpeedDataLbl);


        verticalLayout_6->addLayout(horizontalLayout_3);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(1280, 10, 401, 611));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 490, 390, 110));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        cellInfoLbl = new QLabel(layoutWidget1);
        cellInfoLbl->setObjectName("cellInfoLbl");
        cellInfoLbl->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(cellInfoLbl);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        minCellVoltageLbl = new QLabel(layoutWidget1);
        minCellVoltageLbl->setObjectName("minCellVoltageLbl");

        gridLayout_2->addWidget(minCellVoltageLbl, 0, 0, 1, 1);

        minCellTempSbx = new QDoubleSpinBox(layoutWidget1);
        minCellTempSbx->setObjectName("minCellTempSbx");
        minCellTempSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        minCellTempSbx->setReadOnly(true);
        minCellTempSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_2->addWidget(minCellTempSbx, 0, 4, 1, 1);

        maxCellVoltageLbl = new QLabel(layoutWidget1);
        maxCellVoltageLbl->setObjectName("maxCellVoltageLbl");

        gridLayout_2->addWidget(maxCellVoltageLbl, 1, 0, 1, 1);

        maxCellTempLbl = new QLabel(layoutWidget1);
        maxCellTempLbl->setObjectName("maxCellTempLbl");

        gridLayout_2->addWidget(maxCellTempLbl, 1, 2, 1, 2);

        minCellTempLbl = new QLabel(layoutWidget1);
        minCellTempLbl->setObjectName("minCellTempLbl");

        gridLayout_2->addWidget(minCellTempLbl, 0, 2, 1, 2);

        maxCellVoltageSbx = new QDoubleSpinBox(layoutWidget1);
        maxCellVoltageSbx->setObjectName("maxCellVoltageSbx");
        maxCellVoltageSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        maxCellVoltageSbx->setReadOnly(true);
        maxCellVoltageSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        maxCellVoltageSbx->setDecimals(3);

        gridLayout_2->addWidget(maxCellVoltageSbx, 1, 1, 1, 1);

        minCellVoltageSbx = new QDoubleSpinBox(layoutWidget1);
        minCellVoltageSbx->setObjectName("minCellVoltageSbx");
        minCellVoltageSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        minCellVoltageSbx->setReadOnly(true);
        minCellVoltageSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        minCellVoltageSbx->setDecimals(3);

        gridLayout_2->addWidget(minCellVoltageSbx, 0, 1, 1, 1);

        maxCellTempSbx = new QDoubleSpinBox(layoutWidget1);
        maxCellTempSbx->setObjectName("maxCellTempSbx");
        maxCellTempSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        maxCellTempSbx->setReadOnly(true);
        maxCellTempSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_2->addWidget(maxCellTempSbx, 1, 4, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        widget5 = new QWidget(centralwidget);
        widget5->setObjectName("widget5");
        widget5->setGeometry(QRect(1170, 630, 511, 331));
        gridLayout_3 = new QGridLayout(widget5);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        FLWheelGridLayout = new QGridLayout();
        FLWheelGridLayout->setObjectName("FLWheelGridLayout");
        FLWheelSpeedLbl = new QLabel(widget5);
        FLWheelSpeedLbl->setObjectName("FLWheelSpeedLbl");

        FLWheelGridLayout->addWidget(FLWheelSpeedLbl, 0, 0, 1, 1);

        FLWheelSpeedSbx = new QSpinBox(widget5);
        FLWheelSpeedSbx->setObjectName("FLWheelSpeedSbx");
        FLWheelSpeedSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FLWheelSpeedSbx->setReadOnly(true);
        FLWheelSpeedSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        FLWheelSpeedSbx->setMaximum(1000);

        FLWheelGridLayout->addWidget(FLWheelSpeedSbx, 0, 1, 1, 1);

        FLWheelHeightLbl = new QLabel(widget5);
        FLWheelHeightLbl->setObjectName("FLWheelHeightLbl");

        FLWheelGridLayout->addWidget(FLWheelHeightLbl, 1, 0, 1, 1);

        FLWheelHeightSbx = new QDoubleSpinBox(widget5);
        FLWheelHeightSbx->setObjectName("FLWheelHeightSbx");
        FLWheelHeightSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FLWheelHeightSbx->setReadOnly(true);
        FLWheelHeightSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        FLWheelGridLayout->addWidget(FLWheelHeightSbx, 1, 1, 1, 1);


        gridLayout_3->addLayout(FLWheelGridLayout, 0, 0, 1, 1);

        BLWheelGridLayout = new QGridLayout();
        BLWheelGridLayout->setObjectName("BLWheelGridLayout");
        BLWheelSpeedLbl = new QLabel(widget5);
        BLWheelSpeedLbl->setObjectName("BLWheelSpeedLbl");

        BLWheelGridLayout->addWidget(BLWheelSpeedLbl, 0, 0, 1, 1);

        BLWheelSpeedSbx = new QSpinBox(widget5);
        BLWheelSpeedSbx->setObjectName("BLWheelSpeedSbx");
        BLWheelSpeedSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelSpeedSbx->setReadOnly(true);
        BLWheelSpeedSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLWheelSpeedSbx->setMaximum(1000);

        BLWheelGridLayout->addWidget(BLWheelSpeedSbx, 0, 1, 1, 1);

        BLWheelHeightLbl = new QLabel(widget5);
        BLWheelHeightLbl->setObjectName("BLWheelHeightLbl");

        BLWheelGridLayout->addWidget(BLWheelHeightLbl, 1, 0, 1, 1);

        BLWheelHeightSbx = new QDoubleSpinBox(widget5);
        BLWheelHeightSbx->setObjectName("BLWheelHeightSbx");
        BLWheelHeightSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelHeightSbx->setReadOnly(true);
        BLWheelHeightSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        BLWheelGridLayout->addWidget(BLWheelHeightSbx, 1, 1, 1, 1);


        gridLayout_3->addLayout(BLWheelGridLayout, 1, 0, 1, 1);

        BRWheelGridLayout = new QGridLayout();
        BRWheelGridLayout->setObjectName("BRWheelGridLayout");
        BRWheelSpeedLbl = new QLabel(widget5);
        BRWheelSpeedLbl->setObjectName("BRWheelSpeedLbl");

        BRWheelGridLayout->addWidget(BRWheelSpeedLbl, 0, 0, 1, 1);

        BRWheelSpeedSbx = new QSpinBox(widget5);
        BRWheelSpeedSbx->setObjectName("BRWheelSpeedSbx");
        BRWheelSpeedSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BRWheelSpeedSbx->setReadOnly(true);
        BRWheelSpeedSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BRWheelSpeedSbx->setMaximum(1000);

        BRWheelGridLayout->addWidget(BRWheelSpeedSbx, 0, 1, 1, 1);

        BRWheelHeightLbl = new QLabel(widget5);
        BRWheelHeightLbl->setObjectName("BRWheelHeightLbl");

        BRWheelGridLayout->addWidget(BRWheelHeightLbl, 1, 0, 1, 1);

        BRWheelHeightSbx = new QDoubleSpinBox(widget5);
        BRWheelHeightSbx->setObjectName("BRWheelHeightSbx");
        BRWheelHeightSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BRWheelHeightSbx->setReadOnly(true);
        BRWheelHeightSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        BRWheelGridLayout->addWidget(BRWheelHeightSbx, 1, 1, 1, 1);


        gridLayout_3->addLayout(BRWheelGridLayout, 1, 1, 1, 1);

        FRWheelGridLayout = new QGridLayout();
        FRWheelGridLayout->setObjectName("FRWheelGridLayout");
        FRWheelSpeedLbl = new QLabel(widget5);
        FRWheelSpeedLbl->setObjectName("FRWheelSpeedLbl");

        FRWheelGridLayout->addWidget(FRWheelSpeedLbl, 0, 0, 1, 1);

        FRWheelSpeedSbx = new QSpinBox(widget5);
        FRWheelSpeedSbx->setObjectName("FRWheelSpeedSbx");
        FRWheelSpeedSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FRWheelSpeedSbx->setReadOnly(true);
        FRWheelSpeedSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        FRWheelSpeedSbx->setMaximum(1000);

        FRWheelGridLayout->addWidget(FRWheelSpeedSbx, 0, 1, 1, 1);

        FRWheelHeightSbx = new QDoubleSpinBox(widget5);
        FRWheelHeightSbx->setObjectName("FRWheelHeightSbx");
        FRWheelHeightSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FRWheelHeightSbx->setReadOnly(true);
        FRWheelHeightSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        FRWheelGridLayout->addWidget(FRWheelHeightSbx, 1, 1, 1, 1);

        FRWheelHeightLbl = new QLabel(widget5);
        FRWheelHeightLbl->setObjectName("FRWheelHeightLbl");

        FRWheelGridLayout->addWidget(FRWheelHeightLbl, 1, 0, 1, 1);


        gridLayout_3->addLayout(FRWheelGridLayout, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1714, 23));
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
        MechanicalDataGroupBox->setTitle(QCoreApplication::translate("MainWindow", "Tractive Data", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Pack Information", nullptr));
        BusVoltageLbl->setText(QCoreApplication::translate("MainWindow", "Bus Voltage", nullptr));
        BusCurrentLbl->setText(QCoreApplication::translate("MainWindow", "Bus Current", nullptr));
        RinehartVoltageLbl->setText(QCoreApplication::translate("MainWindow", "RInehart Voltage", nullptr));
        AccelPedalLbl->setText(QCoreApplication::translate("MainWindow", "Accelerator: ", nullptr));
        BrakePedalLbl->setText(QCoreApplication::translate("MainWindow", "Brake:", nullptr));
        BMSFaultLED->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
        IMDFaultLED->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
        InverterStatusLbl->setText(QCoreApplication::translate("MainWindow", "Inverter Status: ", nullptr));
        DriveDirectionLbl->setText(QCoreApplication::translate("MainWindow", "Drive Direction: ", nullptr));
        commandedTorqueLbl->setText(QCoreApplication::translate("MainWindow", "Commanded Torque:", nullptr));
        readyToDriveLED->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
        IMDFaultLbl->setText(QCoreApplication::translate("MainWindow", "IMD Fault: ", nullptr));
        DriveDirectionTbx->setText(QCoreApplication::translate("MainWindow", "Direction", nullptr));
        prechargeStateTbx->setText(QCoreApplication::translate("MainWindow", "State", nullptr));
        prechargeStateLbl->setText(QCoreApplication::translate("MainWindow", "Precharge State", nullptr));
        DriveModeLbl->setText(QCoreApplication::translate("MainWindow", "Drive Mode", nullptr));
        readyToDriveLbl->setText(QCoreApplication::translate("MainWindow", "Ready to Drive:", nullptr));
        InverterStatusLED->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
        BMSFaultLbl->setText(QCoreApplication::translate("MainWindow", "BMS Fault:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Critical Data", nullptr));
        BatteryImage->setText(QCoreApplication::translate("MainWindow", "Battery Image", nullptr));
        currentSpeedLbl->setText(QCoreApplication::translate("MainWindow", "Current Speed (mph):", nullptr));
        currentSpeedDataLbl->setText(QCoreApplication::translate("MainWindow", "current speed", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Electrical Data", nullptr));
        cellInfoLbl->setText(QCoreApplication::translate("MainWindow", "Cell Infomation", nullptr));
        minCellVoltageLbl->setText(QCoreApplication::translate("MainWindow", "Min Cell Voltage", nullptr));
        maxCellVoltageLbl->setText(QCoreApplication::translate("MainWindow", "Max Cell Voltage", nullptr));
        maxCellTempLbl->setText(QCoreApplication::translate("MainWindow", "Max Cell Temp", nullptr));
        minCellTempLbl->setText(QCoreApplication::translate("MainWindow", "Min Cell Temp", nullptr));
        FLWheelSpeedLbl->setText(QCoreApplication::translate("MainWindow", "Wheel Speed", nullptr));
        FLWheelHeightLbl->setText(QCoreApplication::translate("MainWindow", "Suspension", nullptr));
        BLWheelSpeedLbl->setText(QCoreApplication::translate("MainWindow", "Wheel Speed", nullptr));
        BLWheelHeightLbl->setText(QCoreApplication::translate("MainWindow", "Suspension", nullptr));
        BRWheelSpeedLbl->setText(QCoreApplication::translate("MainWindow", "Wheel Speed", nullptr));
        BRWheelHeightLbl->setText(QCoreApplication::translate("MainWindow", "Suspension", nullptr));
        FRWheelSpeedLbl->setText(QCoreApplication::translate("MainWindow", "Wheel Speed", nullptr));
        FRWheelHeightLbl->setText(QCoreApplication::translate("MainWindow", "Suspension", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
