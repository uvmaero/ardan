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
    QGroupBox *groupBox_3;
    QWidget *widget;
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
    QLineEdit *prechargeStateTbx;
    QLabel *prechargeStateLbl;
    QLineEdit *driveDirectionTbx;
    QLabel *DriveModeLbl;
    QLabel *readyToDriveLbl;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_10;
    QLabel *InverterStatusLED;
    QLabel *BMSFaultLbl;
    QSpacerItem *horizontalSpacer_9;
    QLabel *vircoreEnableLbl;
    QLabel *vicoreFaultLbl;
    QSpacerItem *horizontalSpacer_12;
    QLabel *vicoreEnableLED;
    QLabel *vicoreFaultLED;
    QGroupBox *groupBox_4;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_6;
    QWidget *speedPlot;
    QHBoxLayout *horizontalLayout_3;
    QLabel *currentSpeedLbl;
    QLabel *currentSpeedDataLbl;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_4;
    QWidget *accelPlot;
    QHBoxLayout *horizontalLayout;
    QLabel *AccelPedalLbl;
    QProgressBar *AccelPedalProgressBar;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_5;
    QWidget *brakePlot;
    QHBoxLayout *horizontalLayout_2;
    QLabel *BrakePedalLbl;
    QProgressBar *BrakePedalProgressBar;
    QGroupBox *groupBox_5;
    QWidget *widget4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *packInformationLbl;
    QGridLayout *PrimaryVoltageGridLayout;
    QLabel *BusCurrentLbl;
    QLabel *RinehartVoltageLbl;
    QDoubleSpinBox *RinehartVoltageSbx;
    QLabel *BusVoltageLbl;
    QDoubleSpinBox *BusCurrentSbx;
    QDoubleSpinBox *BusVoltageSbx;
    QWidget *packCurrentPlot;
    QWidget *widget5;
    QVBoxLayout *verticalLayout_7;
    QWidget *packVoltagePlot;
    QHBoxLayout *horizontalLayout_4;
    QLabel *batteryPercentageLbl;
    QProgressBar *BatteryPrecentageProgressBar;
    QWidget *widget6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *steeringDeflectionLbl;
    QLabel *steeringDeflectionLblImage;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
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
    QGroupBox *groupBox;
    QWidget *widget7;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QGridLayout *FLWheelGridLayout;
    QLabel *FLWheelSpeedLbl;
    QLabel *label_6;
    QSpinBox *FLWheelSpeedSbx;
    QDoubleSpinBox *FLWheelHeightSbx;
    QDoubleSpinBox *FLWheelHeightSbx_2;
    QLabel *FLWheelHeightLbl;
    QLabel *label_7;
    QDoubleSpinBox *FLWheelHeightSbx_4;
    QLabel *label_14;
    QDoubleSpinBox *BLWheelHeightSbx_3;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout_5;
    QLabel *label_3;
    QGridLayout *BLWheelGridLayout;
    QLabel *BLWheelSpeedLbl;
    QLabel *label_9;
    QLabel *label_10;
    QDoubleSpinBox *FLWheelHeightSbx_7;
    QSpinBox *BLWheelSpeedSbx;
    QDoubleSpinBox *BLWheelHeightSbx;
    QLabel *BLWheelHeightLbl;
    QDoubleSpinBox *FLWheelHeightSbx_6;
    QDoubleSpinBox *BLWheelHeightSbx_5;
    QLabel *label_16;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_4;
    QLabel *label_2;
    QGridLayout *FRWheelGridLayout;
    QLabel *label_5;
    QLabel *FRWheelSpeedLbl;
    QLabel *label_15;
    QDoubleSpinBox *FLWheelHeightSbx_5;
    QSpinBox *FRWheelSpeedSbx;
    QDoubleSpinBox *FRWheelHeightSbx;
    QLabel *label_8;
    QDoubleSpinBox *FLWheelHeightSbx_3;
    QLabel *FRWheelHeightLbl;
    QDoubleSpinBox *BLWheelHeightSbx_4;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_6;
    QGridLayout *gridLayout_6;
    QLabel *label_4;
    QGridLayout *BRWheelGridLayout;
    QLabel *label_12;
    QDoubleSpinBox *BRWheelHeightSbx;
    QDoubleSpinBox *FLWheelHeightSbx_8;
    QSpinBox *BRWheelSpeedSbx;
    QLabel *BRWheelSpeedLbl;
    QLabel *BRWheelHeightLbl;
    QLabel *label_11;
    QDoubleSpinBox *FLWheelHeightSbx_9;
    QLabel *label_13;
    QDoubleSpinBox *BLWheelHeightSbx_2;
    QGroupBox *groupBox_6;
    QWidget *widget8;
    QGridLayout *gridLayout_10;
    QLabel *label_25;
    QDoubleSpinBox *BLWheelHeightSbx_14;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_29;
    QLabel *label_32;
    QLabel *label_26;
    QDoubleSpinBox *BLWheelHeightSbx_15;
    QLabel *label_30;
    QLabel *label_33;
    QLabel *label_27;
    QDoubleSpinBox *BLWheelHeightSbx_16;
    QLabel *label_31;
    QLabel *label_34;
    QLabel *label_28;
    QDoubleSpinBox *BLWheelHeightSbx_17;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_16;
    QGroupBox *groupBox_7;
    QWidget *widget9;
    QGridLayout *gridLayout_8;
    QLabel *fansActiveLbl;
    QLabel *fansActiveLED;
    QLabel *label_17;
    QDoubleSpinBox *BLWheelHeightSbx_6;
    QLabel *label_18;
    QDoubleSpinBox *BLWheelHeightSbx_7;
    QGroupBox *groupBox_8;
    QWidget *widget10;
    QGridLayout *gridLayout_9;
    QDoubleSpinBox *BLWheelHeightSbx_10;
    QLabel *label_20;
    QDoubleSpinBox *BLWheelHeightSbx_11;
    QLabel *label_24;
    QDoubleSpinBox *BLWheelHeightSbx_13;
    QLabel *label_23;
    QLabel *label_21;
    QDoubleSpinBox *BLWheelHeightSbx_8;
    QDoubleSpinBox *BLWheelHeightSbx_12;
    QLabel *label_19;
    QLabel *label_22;
    QDoubleSpinBox *BLWheelHeightSbx_9;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QMenuBar *menubar;
    QMenu *menuOptions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1712, 1197);
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
        MechanicalDataGroupBox->setGeometry(QRect(10, 0, 1161, 1151));
        groupBox_3 = new QGroupBox(MechanicalDataGroupBox);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(670, 30, 481, 281));
        widget = new QWidget(groupBox_3);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 30, 461, 241));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        DriveModeTbx = new QLineEdit(widget);
        DriveModeTbx->setObjectName("DriveModeTbx");
        DriveModeTbx->setMaximumSize(QSize(130, 16777215));
        DriveModeTbx->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        DriveModeTbx->setReadOnly(true);

        gridLayout->addWidget(DriveModeTbx, 3, 4, 1, 1);

        CommandedTorqueSbx = new QDoubleSpinBox(widget);
        CommandedTorqueSbx->setObjectName("CommandedTorqueSbx");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CommandedTorqueSbx->sizePolicy().hasHeightForWidth());
        CommandedTorqueSbx->setSizePolicy(sizePolicy1);
        CommandedTorqueSbx->setMaximumSize(QSize(130, 16777215));
        CommandedTorqueSbx->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        CommandedTorqueSbx->setReadOnly(true);
        CommandedTorqueSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        CommandedTorqueSbx->setDecimals(0);
        CommandedTorqueSbx->setMaximum(250.000000000000000);

        gridLayout->addWidget(CommandedTorqueSbx, 0, 4, 1, 1);

        BMSFaultLED = new QLabel(widget);
        BMSFaultLED->setObjectName("BMSFaultLED");
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(BMSFaultLED->sizePolicy().hasHeightForWidth());
        BMSFaultLED->setSizePolicy(sizePolicy2);
        BMSFaultLED->setMinimumSize(QSize(0, 30));
        BMSFaultLED->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(BMSFaultLED, 2, 1, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 3, 2, 1, 1);

        IMDFaultLED = new QLabel(widget);
        IMDFaultLED->setObjectName("IMDFaultLED");
        sizePolicy2.setHeightForWidth(IMDFaultLED->sizePolicy().hasHeightForWidth());
        IMDFaultLED->setSizePolicy(sizePolicy2);
        IMDFaultLED->setMinimumSize(QSize(0, 30));
        IMDFaultLED->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(IMDFaultLED, 1, 1, 1, 1);

        InverterStatusLbl = new QLabel(widget);
        InverterStatusLbl->setObjectName("InverterStatusLbl");

        gridLayout->addWidget(InverterStatusLbl, 3, 0, 1, 1);

        DriveDirectionLbl = new QLabel(widget);
        DriveDirectionLbl->setObjectName("DriveDirectionLbl");

        gridLayout->addWidget(DriveDirectionLbl, 1, 3, 1, 1);

        commandedTorqueLbl = new QLabel(widget);
        commandedTorqueLbl->setObjectName("commandedTorqueLbl");

        gridLayout->addWidget(commandedTorqueLbl, 0, 3, 1, 1);

        readyToDriveLED = new QLabel(widget);
        readyToDriveLED->setObjectName("readyToDriveLED");
        sizePolicy2.setHeightForWidth(readyToDriveLED->sizePolicy().hasHeightForWidth());
        readyToDriveLED->setSizePolicy(sizePolicy2);
        readyToDriveLED->setMinimumSize(QSize(0, 30));
        readyToDriveLED->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(readyToDriveLED, 0, 1, 1, 1);

        IMDFaultLbl = new QLabel(widget);
        IMDFaultLbl->setObjectName("IMDFaultLbl");

        gridLayout->addWidget(IMDFaultLbl, 1, 0, 1, 1);

        prechargeStateTbx = new QLineEdit(widget);
        prechargeStateTbx->setObjectName("prechargeStateTbx");
        prechargeStateTbx->setMaximumSize(QSize(130, 16777215));
        prechargeStateTbx->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        prechargeStateTbx->setReadOnly(true);

        gridLayout->addWidget(prechargeStateTbx, 2, 4, 1, 1);

        prechargeStateLbl = new QLabel(widget);
        prechargeStateLbl->setObjectName("prechargeStateLbl");

        gridLayout->addWidget(prechargeStateLbl, 2, 3, 1, 1);

        driveDirectionTbx = new QLineEdit(widget);
        driveDirectionTbx->setObjectName("driveDirectionTbx");
        driveDirectionTbx->setMaximumSize(QSize(130, 16777215));
        driveDirectionTbx->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        driveDirectionTbx->setReadOnly(true);

        gridLayout->addWidget(driveDirectionTbx, 1, 4, 1, 1);

        DriveModeLbl = new QLabel(widget);
        DriveModeLbl->setObjectName("DriveModeLbl");
        DriveModeLbl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(DriveModeLbl, 3, 3, 1, 1);

        readyToDriveLbl = new QLabel(widget);
        readyToDriveLbl->setObjectName("readyToDriveLbl");

        gridLayout->addWidget(readyToDriveLbl, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 2, 2, 1, 1);

        InverterStatusLED = new QLabel(widget);
        InverterStatusLED->setObjectName("InverterStatusLED");
        InverterStatusLED->setEnabled(true);
        sizePolicy2.setHeightForWidth(InverterStatusLED->sizePolicy().hasHeightForWidth());
        InverterStatusLED->setSizePolicy(sizePolicy2);
        InverterStatusLED->setMinimumSize(QSize(0, 30));
        InverterStatusLED->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(InverterStatusLED, 3, 1, 1, 1);

        BMSFaultLbl = new QLabel(widget);
        BMSFaultLbl->setObjectName("BMSFaultLbl");

        gridLayout->addWidget(BMSFaultLbl, 2, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 1, 2, 1, 1);

        vircoreEnableLbl = new QLabel(widget);
        vircoreEnableLbl->setObjectName("vircoreEnableLbl");

        gridLayout->addWidget(vircoreEnableLbl, 4, 0, 1, 1);

        vicoreFaultLbl = new QLabel(widget);
        vicoreFaultLbl->setObjectName("vicoreFaultLbl");

        gridLayout->addWidget(vicoreFaultLbl, 4, 3, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 4, 2, 1, 1);

        vicoreEnableLED = new QLabel(widget);
        vicoreEnableLED->setObjectName("vicoreEnableLED");
        vicoreEnableLED->setEnabled(true);
        sizePolicy2.setHeightForWidth(vicoreEnableLED->sizePolicy().hasHeightForWidth());
        vicoreEnableLED->setSizePolicy(sizePolicy2);
        vicoreEnableLED->setMinimumSize(QSize(0, 30));
        vicoreEnableLED->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(vicoreEnableLED, 4, 1, 1, 1);

        vicoreFaultLED = new QLabel(widget);
        vicoreFaultLED->setObjectName("vicoreFaultLED");
        vicoreFaultLED->setEnabled(true);
        sizePolicy2.setHeightForWidth(vicoreFaultLED->sizePolicy().hasHeightForWidth());
        vicoreFaultLED->setSizePolicy(sizePolicy2);
        vicoreFaultLED->setMinimumSize(QSize(0, 30));
        vicoreFaultLED->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(vicoreFaultLED, 4, 4, 1, 1);

        groupBox_4 = new QGroupBox(MechanicalDataGroupBox);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(10, 30, 641, 1111));
        widget1 = new QWidget(groupBox_4);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(10, 30, 611, 361));
        verticalLayout_6 = new QVBoxLayout(widget1);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        speedPlot = new QWidget(widget1);
        speedPlot->setObjectName("speedPlot");
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(speedPlot->sizePolicy().hasHeightForWidth());
        speedPlot->setSizePolicy(sizePolicy3);
        speedPlot->setMinimumSize(QSize(600, 300));
        speedPlot->setMaximumSize(QSize(600, 300));

        verticalLayout_6->addWidget(speedPlot);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        currentSpeedLbl = new QLabel(widget1);
        currentSpeedLbl->setObjectName("currentSpeedLbl");
        currentSpeedLbl->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(currentSpeedLbl);

        currentSpeedDataLbl = new QLabel(widget1);
        currentSpeedDataLbl->setObjectName("currentSpeedDataLbl");
        currentSpeedDataLbl->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(currentSpeedDataLbl);


        verticalLayout_6->addLayout(horizontalLayout_3);

        widget2 = new QWidget(groupBox_4);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(10, 410, 611, 336));
        verticalLayout_4 = new QVBoxLayout(widget2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        accelPlot = new QWidget(widget2);
        accelPlot->setObjectName("accelPlot");
        sizePolicy3.setHeightForWidth(accelPlot->sizePolicy().hasHeightForWidth());
        accelPlot->setSizePolicy(sizePolicy3);
        accelPlot->setMinimumSize(QSize(600, 300));
        accelPlot->setMaximumSize(QSize(600, 300));

        verticalLayout_4->addWidget(accelPlot);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        AccelPedalLbl = new QLabel(widget2);
        AccelPedalLbl->setObjectName("AccelPedalLbl");
        AccelPedalLbl->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(AccelPedalLbl);

        AccelPedalProgressBar = new QProgressBar(widget2);
        AccelPedalProgressBar->setObjectName("AccelPedalProgressBar");
        AccelPedalProgressBar->setValue(66);

        horizontalLayout->addWidget(AccelPedalProgressBar);


        verticalLayout_4->addLayout(horizontalLayout);

        widget3 = new QWidget(groupBox_4);
        widget3->setObjectName("widget3");
        widget3->setGeometry(QRect(10, 760, 611, 336));
        verticalLayout_5 = new QVBoxLayout(widget3);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        brakePlot = new QWidget(widget3);
        brakePlot->setObjectName("brakePlot");
        sizePolicy3.setHeightForWidth(brakePlot->sizePolicy().hasHeightForWidth());
        brakePlot->setSizePolicy(sizePolicy3);
        brakePlot->setMinimumSize(QSize(600, 300));
        brakePlot->setMaximumSize(QSize(600, 300));

        verticalLayout_5->addWidget(brakePlot);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        BrakePedalLbl = new QLabel(widget3);
        BrakePedalLbl->setObjectName("BrakePedalLbl");
        BrakePedalLbl->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(BrakePedalLbl);

        BrakePedalProgressBar = new QProgressBar(widget3);
        BrakePedalProgressBar->setObjectName("BrakePedalProgressBar");
        BrakePedalProgressBar->setValue(13);

        horizontalLayout_2->addWidget(BrakePedalProgressBar);


        verticalLayout_5->addLayout(horizontalLayout_2);

        groupBox_5 = new QGroupBox(MechanicalDataGroupBox);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(670, 320, 471, 821));
        widget4 = new QWidget(groupBox_5);
        widget4->setObjectName("widget4");
        widget4->setGeometry(QRect(10, 30, 452, 379));
        verticalLayout_2 = new QVBoxLayout(widget4);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        packInformationLbl = new QLabel(widget4);
        packInformationLbl->setObjectName("packInformationLbl");
        packInformationLbl->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(packInformationLbl);

        PrimaryVoltageGridLayout = new QGridLayout();
        PrimaryVoltageGridLayout->setObjectName("PrimaryVoltageGridLayout");
        BusCurrentLbl = new QLabel(widget4);
        BusCurrentLbl->setObjectName("BusCurrentLbl");

        PrimaryVoltageGridLayout->addWidget(BusCurrentLbl, 1, 0, 1, 1);

        RinehartVoltageLbl = new QLabel(widget4);
        RinehartVoltageLbl->setObjectName("RinehartVoltageLbl");

        PrimaryVoltageGridLayout->addWidget(RinehartVoltageLbl, 2, 0, 1, 1);

        RinehartVoltageSbx = new QDoubleSpinBox(widget4);
        RinehartVoltageSbx->setObjectName("RinehartVoltageSbx");
        RinehartVoltageSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        RinehartVoltageSbx->setReadOnly(true);
        RinehartVoltageSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        RinehartVoltageSbx->setMaximum(1000.000000000000000);

        PrimaryVoltageGridLayout->addWidget(RinehartVoltageSbx, 2, 1, 1, 1);

        BusVoltageLbl = new QLabel(widget4);
        BusVoltageLbl->setObjectName("BusVoltageLbl");

        PrimaryVoltageGridLayout->addWidget(BusVoltageLbl, 0, 0, 1, 1);

        BusCurrentSbx = new QDoubleSpinBox(widget4);
        BusCurrentSbx->setObjectName("BusCurrentSbx");
        BusCurrentSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BusCurrentSbx->setReadOnly(true);
        BusCurrentSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BusCurrentSbx->setMaximum(1000.000000000000000);

        PrimaryVoltageGridLayout->addWidget(BusCurrentSbx, 1, 1, 1, 1);

        BusVoltageSbx = new QDoubleSpinBox(widget4);
        BusVoltageSbx->setObjectName("BusVoltageSbx");
        BusVoltageSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BusVoltageSbx->setReadOnly(true);
        BusVoltageSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BusVoltageSbx->setMaximum(1000.000000000000000);

        PrimaryVoltageGridLayout->addWidget(BusVoltageSbx, 0, 1, 1, 1);


        verticalLayout->addLayout(PrimaryVoltageGridLayout);


        verticalLayout_2->addLayout(verticalLayout);

        packCurrentPlot = new QWidget(widget4);
        packCurrentPlot->setObjectName("packCurrentPlot");
        sizePolicy3.setHeightForWidth(packCurrentPlot->sizePolicy().hasHeightForWidth());
        packCurrentPlot->setSizePolicy(sizePolicy3);
        packCurrentPlot->setMinimumSize(QSize(450, 250));
        packCurrentPlot->setMaximumSize(QSize(450, 250));

        verticalLayout_2->addWidget(packCurrentPlot);

        widget5 = new QWidget(groupBox_5);
        widget5->setObjectName("widget5");
        widget5->setGeometry(QRect(10, 420, 452, 286));
        verticalLayout_7 = new QVBoxLayout(widget5);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        packVoltagePlot = new QWidget(widget5);
        packVoltagePlot->setObjectName("packVoltagePlot");
        sizePolicy3.setHeightForWidth(packVoltagePlot->sizePolicy().hasHeightForWidth());
        packVoltagePlot->setSizePolicy(sizePolicy3);
        packVoltagePlot->setMinimumSize(QSize(450, 250));
        packVoltagePlot->setMaximumSize(QSize(450, 250));

        verticalLayout_7->addWidget(packVoltagePlot);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        batteryPercentageLbl = new QLabel(widget5);
        batteryPercentageLbl->setObjectName("batteryPercentageLbl");
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(batteryPercentageLbl->sizePolicy().hasHeightForWidth());
        batteryPercentageLbl->setSizePolicy(sizePolicy4);
        batteryPercentageLbl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(batteryPercentageLbl);

        BatteryPrecentageProgressBar = new QProgressBar(widget5);
        BatteryPrecentageProgressBar->setObjectName("BatteryPrecentageProgressBar");
        BatteryPrecentageProgressBar->setValue(78);

        horizontalLayout_4->addWidget(BatteryPrecentageProgressBar);


        verticalLayout_7->addLayout(horizontalLayout_4);

        widget6 = new QWidget(groupBox_5);
        widget6->setObjectName("widget6");
        widget6->setGeometry(QRect(10, 710, 451, 101));
        horizontalLayout_5 = new QHBoxLayout(widget6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        steeringDeflectionLbl = new QLabel(widget6);
        steeringDeflectionLbl->setObjectName("steeringDeflectionLbl");

        horizontalLayout_5->addWidget(steeringDeflectionLbl);

        steeringDeflectionLblImage = new QLabel(widget6);
        steeringDeflectionLblImage->setObjectName("steeringDeflectionLblImage");
        steeringDeflectionLblImage->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(steeringDeflectionLblImage);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(1180, 0, 511, 1151));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(60, 1030, 390, 110));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        cellInfoLbl = new QLabel(layoutWidget);
        cellInfoLbl->setObjectName("cellInfoLbl");
        cellInfoLbl->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(cellInfoLbl);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        minCellVoltageLbl = new QLabel(layoutWidget);
        minCellVoltageLbl->setObjectName("minCellVoltageLbl");

        gridLayout_2->addWidget(minCellVoltageLbl, 0, 0, 1, 1);

        minCellTempSbx = new QDoubleSpinBox(layoutWidget);
        minCellTempSbx->setObjectName("minCellTempSbx");
        minCellTempSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        minCellTempSbx->setReadOnly(true);
        minCellTempSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_2->addWidget(minCellTempSbx, 0, 4, 1, 1);

        maxCellVoltageLbl = new QLabel(layoutWidget);
        maxCellVoltageLbl->setObjectName("maxCellVoltageLbl");

        gridLayout_2->addWidget(maxCellVoltageLbl, 1, 0, 1, 1);

        maxCellTempLbl = new QLabel(layoutWidget);
        maxCellTempLbl->setObjectName("maxCellTempLbl");

        gridLayout_2->addWidget(maxCellTempLbl, 1, 2, 1, 2);

        minCellTempLbl = new QLabel(layoutWidget);
        minCellTempLbl->setObjectName("minCellTempLbl");

        gridLayout_2->addWidget(minCellTempLbl, 0, 2, 1, 2);

        maxCellVoltageSbx = new QDoubleSpinBox(layoutWidget);
        maxCellVoltageSbx->setObjectName("maxCellVoltageSbx");
        maxCellVoltageSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        maxCellVoltageSbx->setReadOnly(true);
        maxCellVoltageSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        maxCellVoltageSbx->setDecimals(3);

        gridLayout_2->addWidget(maxCellVoltageSbx, 1, 1, 1, 1);

        minCellVoltageSbx = new QDoubleSpinBox(layoutWidget);
        minCellVoltageSbx->setObjectName("minCellVoltageSbx");
        minCellVoltageSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        minCellVoltageSbx->setReadOnly(true);
        minCellVoltageSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        minCellVoltageSbx->setDecimals(3);

        gridLayout_2->addWidget(minCellVoltageSbx, 0, 1, 1, 1);

        maxCellTempSbx = new QDoubleSpinBox(layoutWidget);
        maxCellTempSbx->setObjectName("maxCellTempSbx");
        maxCellTempSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        maxCellTempSbx->setReadOnly(true);
        maxCellTempSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_2->addWidget(maxCellTempSbx, 1, 4, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 30, 491, 451));
        widget7 = new QWidget(groupBox);
        widget7->setObjectName("widget7");
        widget7->setGeometry(QRect(10, 30, 472, 412));
        gridLayout_7 = new QGridLayout(widget7);
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        label = new QLabel(widget7);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        FLWheelGridLayout = new QGridLayout();
        FLWheelGridLayout->setObjectName("FLWheelGridLayout");
        FLWheelSpeedLbl = new QLabel(widget7);
        FLWheelSpeedLbl->setObjectName("FLWheelSpeedLbl");

        FLWheelGridLayout->addWidget(FLWheelSpeedLbl, 0, 0, 1, 1);

        label_6 = new QLabel(widget7);
        label_6->setObjectName("label_6");

        FLWheelGridLayout->addWidget(label_6, 2, 0, 1, 1);

        FLWheelSpeedSbx = new QSpinBox(widget7);
        FLWheelSpeedSbx->setObjectName("FLWheelSpeedSbx");
        sizePolicy1.setHeightForWidth(FLWheelSpeedSbx->sizePolicy().hasHeightForWidth());
        FLWheelSpeedSbx->setSizePolicy(sizePolicy1);
        FLWheelSpeedSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FLWheelSpeedSbx->setReadOnly(true);
        FLWheelSpeedSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        FLWheelSpeedSbx->setMaximum(9999);

        FLWheelGridLayout->addWidget(FLWheelSpeedSbx, 0, 1, 1, 1);

        FLWheelHeightSbx = new QDoubleSpinBox(widget7);
        FLWheelHeightSbx->setObjectName("FLWheelHeightSbx");
        sizePolicy1.setHeightForWidth(FLWheelHeightSbx->sizePolicy().hasHeightForWidth());
        FLWheelHeightSbx->setSizePolicy(sizePolicy1);
        FLWheelHeightSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FLWheelHeightSbx->setReadOnly(true);
        FLWheelHeightSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        FLWheelHeightSbx->setMaximum(99.000000000000000);

        FLWheelGridLayout->addWidget(FLWheelHeightSbx, 1, 1, 1, 1);

        FLWheelHeightSbx_2 = new QDoubleSpinBox(widget7);
        FLWheelHeightSbx_2->setObjectName("FLWheelHeightSbx_2");
        FLWheelHeightSbx_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FLWheelHeightSbx_2->setReadOnly(true);
        FLWheelHeightSbx_2->setButtonSymbols(QAbstractSpinBox::NoButtons);

        FLWheelGridLayout->addWidget(FLWheelHeightSbx_2, 2, 1, 1, 1);

        FLWheelHeightLbl = new QLabel(widget7);
        FLWheelHeightLbl->setObjectName("FLWheelHeightLbl");

        FLWheelGridLayout->addWidget(FLWheelHeightLbl, 1, 0, 1, 1);

        label_7 = new QLabel(widget7);
        label_7->setObjectName("label_7");

        FLWheelGridLayout->addWidget(label_7, 3, 0, 1, 1);

        FLWheelHeightSbx_4 = new QDoubleSpinBox(widget7);
        FLWheelHeightSbx_4->setObjectName("FLWheelHeightSbx_4");
        FLWheelHeightSbx_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FLWheelHeightSbx_4->setReadOnly(true);
        FLWheelHeightSbx_4->setButtonSymbols(QAbstractSpinBox::NoButtons);

        FLWheelGridLayout->addWidget(FLWheelHeightSbx_4, 3, 1, 1, 1);

        label_14 = new QLabel(widget7);
        label_14->setObjectName("label_14");

        FLWheelGridLayout->addWidget(label_14, 5, 0, 1, 1);

        BLWheelHeightSbx_3 = new QDoubleSpinBox(widget7);
        BLWheelHeightSbx_3->setObjectName("BLWheelHeightSbx_3");
        sizePolicy1.setHeightForWidth(BLWheelHeightSbx_3->sizePolicy().hasHeightForWidth());
        BLWheelHeightSbx_3->setSizePolicy(sizePolicy1);
        BLWheelHeightSbx_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelHeightSbx_3->setReadOnly(true);
        BLWheelHeightSbx_3->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLWheelHeightSbx_3->setMaximum(99.000000000000000);

        FLWheelGridLayout->addWidget(BLWheelHeightSbx_3, 5, 1, 1, 1);


        gridLayout_3->addLayout(FLWheelGridLayout, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_3, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_3, 1, 2, 3, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer_2, 1, 1, 3, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName("gridLayout_5");
        label_3 = new QLabel(widget7);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_3, 0, 0, 1, 1);

        BLWheelGridLayout = new QGridLayout();
        BLWheelGridLayout->setObjectName("BLWheelGridLayout");
        BLWheelSpeedLbl = new QLabel(widget7);
        BLWheelSpeedLbl->setObjectName("BLWheelSpeedLbl");

        BLWheelGridLayout->addWidget(BLWheelSpeedLbl, 0, 0, 1, 1);

        label_9 = new QLabel(widget7);
        label_9->setObjectName("label_9");

        BLWheelGridLayout->addWidget(label_9, 3, 0, 1, 1);

        label_10 = new QLabel(widget7);
        label_10->setObjectName("label_10");

        BLWheelGridLayout->addWidget(label_10, 4, 0, 1, 1);

        FLWheelHeightSbx_7 = new QDoubleSpinBox(widget7);
        FLWheelHeightSbx_7->setObjectName("FLWheelHeightSbx_7");
        FLWheelHeightSbx_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FLWheelHeightSbx_7->setReadOnly(true);
        FLWheelHeightSbx_7->setButtonSymbols(QAbstractSpinBox::NoButtons);

        BLWheelGridLayout->addWidget(FLWheelHeightSbx_7, 4, 1, 1, 1);

        BLWheelSpeedSbx = new QSpinBox(widget7);
        BLWheelSpeedSbx->setObjectName("BLWheelSpeedSbx");
        sizePolicy1.setHeightForWidth(BLWheelSpeedSbx->sizePolicy().hasHeightForWidth());
        BLWheelSpeedSbx->setSizePolicy(sizePolicy1);
        BLWheelSpeedSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelSpeedSbx->setReadOnly(true);
        BLWheelSpeedSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLWheelSpeedSbx->setMaximum(9999);

        BLWheelGridLayout->addWidget(BLWheelSpeedSbx, 0, 1, 1, 1);

        BLWheelHeightSbx = new QDoubleSpinBox(widget7);
        BLWheelHeightSbx->setObjectName("BLWheelHeightSbx");
        sizePolicy1.setHeightForWidth(BLWheelHeightSbx->sizePolicy().hasHeightForWidth());
        BLWheelHeightSbx->setSizePolicy(sizePolicy1);
        BLWheelHeightSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelHeightSbx->setReadOnly(true);
        BLWheelHeightSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLWheelHeightSbx->setMaximum(99.000000000000000);

        BLWheelGridLayout->addWidget(BLWheelHeightSbx, 1, 1, 1, 1);

        BLWheelHeightLbl = new QLabel(widget7);
        BLWheelHeightLbl->setObjectName("BLWheelHeightLbl");

        BLWheelGridLayout->addWidget(BLWheelHeightLbl, 1, 0, 1, 1);

        FLWheelHeightSbx_6 = new QDoubleSpinBox(widget7);
        FLWheelHeightSbx_6->setObjectName("FLWheelHeightSbx_6");
        FLWheelHeightSbx_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FLWheelHeightSbx_6->setReadOnly(true);
        FLWheelHeightSbx_6->setButtonSymbols(QAbstractSpinBox::NoButtons);

        BLWheelGridLayout->addWidget(FLWheelHeightSbx_6, 3, 1, 1, 1);

        BLWheelHeightSbx_5 = new QDoubleSpinBox(widget7);
        BLWheelHeightSbx_5->setObjectName("BLWheelHeightSbx_5");
        sizePolicy1.setHeightForWidth(BLWheelHeightSbx_5->sizePolicy().hasHeightForWidth());
        BLWheelHeightSbx_5->setSizePolicy(sizePolicy1);
        BLWheelHeightSbx_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelHeightSbx_5->setReadOnly(true);
        BLWheelHeightSbx_5->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLWheelHeightSbx_5->setMaximum(99.000000000000000);

        BLWheelGridLayout->addWidget(BLWheelHeightSbx_5, 5, 1, 1, 1);

        label_16 = new QLabel(widget7);
        label_16->setObjectName("label_16");

        BLWheelGridLayout->addWidget(label_16, 5, 0, 1, 1);


        gridLayout_5->addLayout(BLWheelGridLayout, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_5, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_7->addItem(verticalSpacer, 1, 0, 3, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        label_2 = new QLabel(widget7);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);

        FRWheelGridLayout = new QGridLayout();
        FRWheelGridLayout->setObjectName("FRWheelGridLayout");
        label_5 = new QLabel(widget7);
        label_5->setObjectName("label_5");

        FRWheelGridLayout->addWidget(label_5, 2, 0, 1, 1);

        FRWheelSpeedLbl = new QLabel(widget7);
        FRWheelSpeedLbl->setObjectName("FRWheelSpeedLbl");

        FRWheelGridLayout->addWidget(FRWheelSpeedLbl, 0, 0, 1, 1);

        label_15 = new QLabel(widget7);
        label_15->setObjectName("label_15");

        FRWheelGridLayout->addWidget(label_15, 5, 0, 1, 1);

        FLWheelHeightSbx_5 = new QDoubleSpinBox(widget7);
        FLWheelHeightSbx_5->setObjectName("FLWheelHeightSbx_5");
        FLWheelHeightSbx_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FLWheelHeightSbx_5->setReadOnly(true);
        FLWheelHeightSbx_5->setButtonSymbols(QAbstractSpinBox::NoButtons);

        FRWheelGridLayout->addWidget(FLWheelHeightSbx_5, 3, 1, 1, 1);

        FRWheelSpeedSbx = new QSpinBox(widget7);
        FRWheelSpeedSbx->setObjectName("FRWheelSpeedSbx");
        sizePolicy1.setHeightForWidth(FRWheelSpeedSbx->sizePolicy().hasHeightForWidth());
        FRWheelSpeedSbx->setSizePolicy(sizePolicy1);
        FRWheelSpeedSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FRWheelSpeedSbx->setReadOnly(true);
        FRWheelSpeedSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        FRWheelSpeedSbx->setMaximum(9999);

        FRWheelGridLayout->addWidget(FRWheelSpeedSbx, 0, 1, 1, 1);

        FRWheelHeightSbx = new QDoubleSpinBox(widget7);
        FRWheelHeightSbx->setObjectName("FRWheelHeightSbx");
        sizePolicy1.setHeightForWidth(FRWheelHeightSbx->sizePolicy().hasHeightForWidth());
        FRWheelHeightSbx->setSizePolicy(sizePolicy1);
        FRWheelHeightSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FRWheelHeightSbx->setReadOnly(true);
        FRWheelHeightSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        FRWheelHeightSbx->setMaximum(99.000000000000000);

        FRWheelGridLayout->addWidget(FRWheelHeightSbx, 1, 1, 1, 1);

        label_8 = new QLabel(widget7);
        label_8->setObjectName("label_8");

        FRWheelGridLayout->addWidget(label_8, 3, 0, 1, 1);

        FLWheelHeightSbx_3 = new QDoubleSpinBox(widget7);
        FLWheelHeightSbx_3->setObjectName("FLWheelHeightSbx_3");
        FLWheelHeightSbx_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FLWheelHeightSbx_3->setReadOnly(true);
        FLWheelHeightSbx_3->setButtonSymbols(QAbstractSpinBox::NoButtons);

        FRWheelGridLayout->addWidget(FLWheelHeightSbx_3, 2, 1, 1, 1);

        FRWheelHeightLbl = new QLabel(widget7);
        FRWheelHeightLbl->setObjectName("FRWheelHeightLbl");

        FRWheelGridLayout->addWidget(FRWheelHeightLbl, 1, 0, 1, 1);

        BLWheelHeightSbx_4 = new QDoubleSpinBox(widget7);
        BLWheelHeightSbx_4->setObjectName("BLWheelHeightSbx_4");
        sizePolicy1.setHeightForWidth(BLWheelHeightSbx_4->sizePolicy().hasHeightForWidth());
        BLWheelHeightSbx_4->setSizePolicy(sizePolicy1);
        BLWheelHeightSbx_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelHeightSbx_4->setReadOnly(true);
        BLWheelHeightSbx_4->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLWheelHeightSbx_4->setMaximum(99.000000000000000);

        FRWheelGridLayout->addWidget(BLWheelHeightSbx_4, 5, 1, 1, 1);


        gridLayout_4->addLayout(FRWheelGridLayout, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_4, 0, 2, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_7, 4, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_6, 0, 1, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName("gridLayout_6");
        label_4 = new QLabel(widget7);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_4, 0, 0, 1, 1);

        BRWheelGridLayout = new QGridLayout();
        BRWheelGridLayout->setObjectName("BRWheelGridLayout");
        label_12 = new QLabel(widget7);
        label_12->setObjectName("label_12");

        BRWheelGridLayout->addWidget(label_12, 2, 0, 1, 1);

        BRWheelHeightSbx = new QDoubleSpinBox(widget7);
        BRWheelHeightSbx->setObjectName("BRWheelHeightSbx");
        sizePolicy1.setHeightForWidth(BRWheelHeightSbx->sizePolicy().hasHeightForWidth());
        BRWheelHeightSbx->setSizePolicy(sizePolicy1);
        BRWheelHeightSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BRWheelHeightSbx->setReadOnly(true);
        BRWheelHeightSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BRWheelHeightSbx->setMaximum(99.000000000000000);

        BRWheelGridLayout->addWidget(BRWheelHeightSbx, 1, 1, 1, 1);

        FLWheelHeightSbx_8 = new QDoubleSpinBox(widget7);
        FLWheelHeightSbx_8->setObjectName("FLWheelHeightSbx_8");
        FLWheelHeightSbx_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FLWheelHeightSbx_8->setReadOnly(true);
        FLWheelHeightSbx_8->setButtonSymbols(QAbstractSpinBox::NoButtons);

        BRWheelGridLayout->addWidget(FLWheelHeightSbx_8, 2, 1, 1, 1);

        BRWheelSpeedSbx = new QSpinBox(widget7);
        BRWheelSpeedSbx->setObjectName("BRWheelSpeedSbx");
        sizePolicy1.setHeightForWidth(BRWheelSpeedSbx->sizePolicy().hasHeightForWidth());
        BRWheelSpeedSbx->setSizePolicy(sizePolicy1);
        BRWheelSpeedSbx->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BRWheelSpeedSbx->setReadOnly(true);
        BRWheelSpeedSbx->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BRWheelSpeedSbx->setMaximum(9999);

        BRWheelGridLayout->addWidget(BRWheelSpeedSbx, 0, 1, 1, 1);

        BRWheelSpeedLbl = new QLabel(widget7);
        BRWheelSpeedLbl->setObjectName("BRWheelSpeedLbl");

        BRWheelGridLayout->addWidget(BRWheelSpeedLbl, 0, 0, 1, 1);

        BRWheelHeightLbl = new QLabel(widget7);
        BRWheelHeightLbl->setObjectName("BRWheelHeightLbl");

        BRWheelGridLayout->addWidget(BRWheelHeightLbl, 1, 0, 1, 1);

        label_11 = new QLabel(widget7);
        label_11->setObjectName("label_11");

        BRWheelGridLayout->addWidget(label_11, 4, 0, 1, 1);

        FLWheelHeightSbx_9 = new QDoubleSpinBox(widget7);
        FLWheelHeightSbx_9->setObjectName("FLWheelHeightSbx_9");
        FLWheelHeightSbx_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FLWheelHeightSbx_9->setReadOnly(true);
        FLWheelHeightSbx_9->setButtonSymbols(QAbstractSpinBox::NoButtons);

        BRWheelGridLayout->addWidget(FLWheelHeightSbx_9, 4, 1, 1, 1);

        label_13 = new QLabel(widget7);
        label_13->setObjectName("label_13");

        BRWheelGridLayout->addWidget(label_13, 5, 0, 1, 1);

        BLWheelHeightSbx_2 = new QDoubleSpinBox(widget7);
        BLWheelHeightSbx_2->setObjectName("BLWheelHeightSbx_2");
        sizePolicy1.setHeightForWidth(BLWheelHeightSbx_2->sizePolicy().hasHeightForWidth());
        BLWheelHeightSbx_2->setSizePolicy(sizePolicy1);
        BLWheelHeightSbx_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelHeightSbx_2->setReadOnly(true);
        BLWheelHeightSbx_2->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLWheelHeightSbx_2->setMaximum(99.000000000000000);

        BRWheelGridLayout->addWidget(BLWheelHeightSbx_2, 5, 1, 1, 1);


        gridLayout_6->addLayout(BRWheelGridLayout, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 4, 2, 1, 1);

        groupBox_6 = new QGroupBox(groupBox_2);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(10, 670, 491, 171));
        widget8 = new QWidget(groupBox_6);
        widget8->setObjectName("widget8");
        widget8->setGeometry(QRect(10, 30, 471, 128));
        gridLayout_10 = new QGridLayout(widget8);
        gridLayout_10->setObjectName("gridLayout_10");
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        label_25 = new QLabel(widget8);
        label_25->setObjectName("label_25");

        gridLayout_10->addWidget(label_25, 0, 0, 1, 1);

        BLWheelHeightSbx_14 = new QDoubleSpinBox(widget8);
        BLWheelHeightSbx_14->setObjectName("BLWheelHeightSbx_14");
        sizePolicy1.setHeightForWidth(BLWheelHeightSbx_14->sizePolicy().hasHeightForWidth());
        BLWheelHeightSbx_14->setSizePolicy(sizePolicy1);
        BLWheelHeightSbx_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelHeightSbx_14->setReadOnly(true);
        BLWheelHeightSbx_14->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLWheelHeightSbx_14->setMaximum(200.000000000000000);

        gridLayout_10->addWidget(BLWheelHeightSbx_14, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_5, 0, 2, 2, 1);

        label_29 = new QLabel(widget8);
        label_29->setObjectName("label_29");

        gridLayout_10->addWidget(label_29, 0, 3, 1, 1);

        label_32 = new QLabel(widget8);
        label_32->setObjectName("label_32");

        gridLayout_10->addWidget(label_32, 0, 4, 1, 1);

        label_26 = new QLabel(widget8);
        label_26->setObjectName("label_26");

        gridLayout_10->addWidget(label_26, 1, 0, 2, 1);

        BLWheelHeightSbx_15 = new QDoubleSpinBox(widget8);
        BLWheelHeightSbx_15->setObjectName("BLWheelHeightSbx_15");
        sizePolicy1.setHeightForWidth(BLWheelHeightSbx_15->sizePolicy().hasHeightForWidth());
        BLWheelHeightSbx_15->setSizePolicy(sizePolicy1);
        BLWheelHeightSbx_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelHeightSbx_15->setReadOnly(true);
        BLWheelHeightSbx_15->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLWheelHeightSbx_15->setMaximum(200.000000000000000);

        gridLayout_10->addWidget(BLWheelHeightSbx_15, 1, 1, 2, 1);

        label_30 = new QLabel(widget8);
        label_30->setObjectName("label_30");

        gridLayout_10->addWidget(label_30, 2, 3, 1, 1);

        label_33 = new QLabel(widget8);
        label_33->setObjectName("label_33");

        gridLayout_10->addWidget(label_33, 2, 4, 1, 1);

        label_27 = new QLabel(widget8);
        label_27->setObjectName("label_27");

        gridLayout_10->addWidget(label_27, 3, 0, 1, 1);

        BLWheelHeightSbx_16 = new QDoubleSpinBox(widget8);
        BLWheelHeightSbx_16->setObjectName("BLWheelHeightSbx_16");
        sizePolicy1.setHeightForWidth(BLWheelHeightSbx_16->sizePolicy().hasHeightForWidth());
        BLWheelHeightSbx_16->setSizePolicy(sizePolicy1);
        BLWheelHeightSbx_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelHeightSbx_16->setReadOnly(true);
        BLWheelHeightSbx_16->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLWheelHeightSbx_16->setMaximum(200.000000000000000);

        gridLayout_10->addWidget(BLWheelHeightSbx_16, 3, 1, 1, 1);

        label_31 = new QLabel(widget8);
        label_31->setObjectName("label_31");

        gridLayout_10->addWidget(label_31, 3, 3, 1, 1);

        label_34 = new QLabel(widget8);
        label_34->setObjectName("label_34");

        gridLayout_10->addWidget(label_34, 3, 4, 1, 1);

        label_28 = new QLabel(widget8);
        label_28->setObjectName("label_28");

        gridLayout_10->addWidget(label_28, 4, 0, 1, 1);

        BLWheelHeightSbx_17 = new QDoubleSpinBox(widget8);
        BLWheelHeightSbx_17->setObjectName("BLWheelHeightSbx_17");
        sizePolicy1.setHeightForWidth(BLWheelHeightSbx_17->sizePolicy().hasHeightForWidth());
        BLWheelHeightSbx_17->setSizePolicy(sizePolicy1);
        BLWheelHeightSbx_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelHeightSbx_17->setReadOnly(true);
        BLWheelHeightSbx_17->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLWheelHeightSbx_17->setMaximum(200.000000000000000);

        gridLayout_10->addWidget(BLWheelHeightSbx_17, 4, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_8, 2, 2, 1, 1);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_13, 3, 2, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_14, 4, 2, 1, 1);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_15, 4, 3, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_16, 4, 4, 1, 1);

        groupBox_7 = new QGroupBox(groupBox_2);
        groupBox_7->setObjectName("groupBox_7");
        groupBox_7->setGeometry(QRect(110, 850, 261, 161));
        widget9 = new QWidget(groupBox_7);
        widget9->setObjectName("widget9");
        widget9->setGeometry(QRect(10, 30, 241, 121));
        gridLayout_8 = new QGridLayout(widget9);
        gridLayout_8->setObjectName("gridLayout_8");
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        fansActiveLbl = new QLabel(widget9);
        fansActiveLbl->setObjectName("fansActiveLbl");

        gridLayout_8->addWidget(fansActiveLbl, 0, 0, 1, 1);

        fansActiveLED = new QLabel(widget9);
        fansActiveLED->setObjectName("fansActiveLED");
        fansActiveLED->setEnabled(true);
        sizePolicy2.setHeightForWidth(fansActiveLED->sizePolicy().hasHeightForWidth());
        fansActiveLED->setSizePolicy(sizePolicy2);
        fansActiveLED->setMinimumSize(QSize(0, 30));
        fansActiveLED->setMaximumSize(QSize(16777215, 30));
        fansActiveLED->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(fansActiveLED, 0, 1, 1, 1);

        label_17 = new QLabel(widget9);
        label_17->setObjectName("label_17");

        gridLayout_8->addWidget(label_17, 1, 0, 1, 1);

        BLWheelHeightSbx_6 = new QDoubleSpinBox(widget9);
        BLWheelHeightSbx_6->setObjectName("BLWheelHeightSbx_6");
        sizePolicy1.setHeightForWidth(BLWheelHeightSbx_6->sizePolicy().hasHeightForWidth());
        BLWheelHeightSbx_6->setSizePolicy(sizePolicy1);
        BLWheelHeightSbx_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelHeightSbx_6->setReadOnly(true);
        BLWheelHeightSbx_6->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLWheelHeightSbx_6->setMaximum(200.000000000000000);

        gridLayout_8->addWidget(BLWheelHeightSbx_6, 1, 1, 1, 1);

        label_18 = new QLabel(widget9);
        label_18->setObjectName("label_18");

        gridLayout_8->addWidget(label_18, 2, 0, 1, 1);

        BLWheelHeightSbx_7 = new QDoubleSpinBox(widget9);
        BLWheelHeightSbx_7->setObjectName("BLWheelHeightSbx_7");
        sizePolicy1.setHeightForWidth(BLWheelHeightSbx_7->sizePolicy().hasHeightForWidth());
        BLWheelHeightSbx_7->setSizePolicy(sizePolicy1);
        BLWheelHeightSbx_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelHeightSbx_7->setReadOnly(true);
        BLWheelHeightSbx_7->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLWheelHeightSbx_7->setMaximum(200.000000000000000);

        gridLayout_8->addWidget(BLWheelHeightSbx_7, 2, 1, 1, 1);

        groupBox_8 = new QGroupBox(groupBox_2);
        groupBox_8->setObjectName("groupBox_8");
        groupBox_8->setGeometry(QRect(10, 490, 491, 171));
        widget10 = new QWidget(groupBox_8);
        widget10->setObjectName("widget10");
        widget10->setGeometry(QRect(10, 30, 471, 131));
        gridLayout_9 = new QGridLayout(widget10);
        gridLayout_9->setObjectName("gridLayout_9");
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        BLWheelHeightSbx_10 = new QDoubleSpinBox(widget10);
        BLWheelHeightSbx_10->setObjectName("BLWheelHeightSbx_10");
        sizePolicy1.setHeightForWidth(BLWheelHeightSbx_10->sizePolicy().hasHeightForWidth());
        BLWheelHeightSbx_10->setSizePolicy(sizePolicy1);
        BLWheelHeightSbx_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelHeightSbx_10->setReadOnly(true);
        BLWheelHeightSbx_10->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLWheelHeightSbx_10->setMaximum(200.000000000000000);

        gridLayout_9->addWidget(BLWheelHeightSbx_10, 2, 1, 1, 1);

        label_20 = new QLabel(widget10);
        label_20->setObjectName("label_20");

        gridLayout_9->addWidget(label_20, 1, 0, 1, 1);

        BLWheelHeightSbx_11 = new QDoubleSpinBox(widget10);
        BLWheelHeightSbx_11->setObjectName("BLWheelHeightSbx_11");
        sizePolicy1.setHeightForWidth(BLWheelHeightSbx_11->sizePolicy().hasHeightForWidth());
        BLWheelHeightSbx_11->setSizePolicy(sizePolicy1);
        BLWheelHeightSbx_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelHeightSbx_11->setReadOnly(true);
        BLWheelHeightSbx_11->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLWheelHeightSbx_11->setMaximum(200.000000000000000);

        gridLayout_9->addWidget(BLWheelHeightSbx_11, 0, 4, 1, 1);

        label_24 = new QLabel(widget10);
        label_24->setObjectName("label_24");

        gridLayout_9->addWidget(label_24, 2, 3, 1, 1);

        BLWheelHeightSbx_13 = new QDoubleSpinBox(widget10);
        BLWheelHeightSbx_13->setObjectName("BLWheelHeightSbx_13");
        sizePolicy1.setHeightForWidth(BLWheelHeightSbx_13->sizePolicy().hasHeightForWidth());
        BLWheelHeightSbx_13->setSizePolicy(sizePolicy1);
        BLWheelHeightSbx_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelHeightSbx_13->setReadOnly(true);
        BLWheelHeightSbx_13->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLWheelHeightSbx_13->setMaximum(200.000000000000000);

        gridLayout_9->addWidget(BLWheelHeightSbx_13, 2, 4, 1, 1);

        label_23 = new QLabel(widget10);
        label_23->setObjectName("label_23");

        gridLayout_9->addWidget(label_23, 1, 3, 1, 1);

        label_21 = new QLabel(widget10);
        label_21->setObjectName("label_21");

        gridLayout_9->addWidget(label_21, 2, 0, 1, 1);

        BLWheelHeightSbx_8 = new QDoubleSpinBox(widget10);
        BLWheelHeightSbx_8->setObjectName("BLWheelHeightSbx_8");
        sizePolicy1.setHeightForWidth(BLWheelHeightSbx_8->sizePolicy().hasHeightForWidth());
        BLWheelHeightSbx_8->setSizePolicy(sizePolicy1);
        BLWheelHeightSbx_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelHeightSbx_8->setReadOnly(true);
        BLWheelHeightSbx_8->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLWheelHeightSbx_8->setMaximum(200.000000000000000);

        gridLayout_9->addWidget(BLWheelHeightSbx_8, 0, 1, 1, 1);

        BLWheelHeightSbx_12 = new QDoubleSpinBox(widget10);
        BLWheelHeightSbx_12->setObjectName("BLWheelHeightSbx_12");
        sizePolicy1.setHeightForWidth(BLWheelHeightSbx_12->sizePolicy().hasHeightForWidth());
        BLWheelHeightSbx_12->setSizePolicy(sizePolicy1);
        BLWheelHeightSbx_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelHeightSbx_12->setReadOnly(true);
        BLWheelHeightSbx_12->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLWheelHeightSbx_12->setMaximum(200.000000000000000);

        gridLayout_9->addWidget(BLWheelHeightSbx_12, 1, 4, 1, 1);

        label_19 = new QLabel(widget10);
        label_19->setObjectName("label_19");

        gridLayout_9->addWidget(label_19, 0, 0, 1, 1);

        label_22 = new QLabel(widget10);
        label_22->setObjectName("label_22");

        gridLayout_9->addWidget(label_22, 0, 3, 1, 1);

        BLWheelHeightSbx_9 = new QDoubleSpinBox(widget10);
        BLWheelHeightSbx_9->setObjectName("BLWheelHeightSbx_9");
        sizePolicy1.setHeightForWidth(BLWheelHeightSbx_9->sizePolicy().hasHeightForWidth());
        BLWheelHeightSbx_9->setSizePolicy(sizePolicy1);
        BLWheelHeightSbx_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BLWheelHeightSbx_9->setReadOnly(true);
        BLWheelHeightSbx_9->setButtonSymbols(QAbstractSpinBox::NoButtons);
        BLWheelHeightSbx_9->setMaximum(200.000000000000000);

        gridLayout_9->addWidget(BLWheelHeightSbx_9, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_3, 2, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_9->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1712, 23));
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
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Critical Data", nullptr));
        BMSFaultLED->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
        IMDFaultLED->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
        InverterStatusLbl->setText(QCoreApplication::translate("MainWindow", "Inverter Status: ", nullptr));
        DriveDirectionLbl->setText(QCoreApplication::translate("MainWindow", "Drive Direction: ", nullptr));
        commandedTorqueLbl->setText(QCoreApplication::translate("MainWindow", "Commanded Torque:", nullptr));
        readyToDriveLED->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
        IMDFaultLbl->setText(QCoreApplication::translate("MainWindow", "IMD Fault: ", nullptr));
        prechargeStateLbl->setText(QCoreApplication::translate("MainWindow", "Precharge State:", nullptr));
        DriveModeLbl->setText(QCoreApplication::translate("MainWindow", "Drive Mode:", nullptr));
        readyToDriveLbl->setText(QCoreApplication::translate("MainWindow", "Ready to Drive:", nullptr));
        InverterStatusLED->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
        BMSFaultLbl->setText(QCoreApplication::translate("MainWindow", "BMS Fault:", nullptr));
        vircoreEnableLbl->setText(QCoreApplication::translate("MainWindow", "Vicore Enable: ", nullptr));
        vicoreFaultLbl->setText(QCoreApplication::translate("MainWindow", "Vicore Fault: ", nullptr));
        vicoreEnableLED->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
        vicoreFaultLED->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Speed Data", nullptr));
        currentSpeedLbl->setText(QCoreApplication::translate("MainWindow", "Current Speed (MPH):", nullptr));
        currentSpeedDataLbl->setText(QCoreApplication::translate("MainWindow", "current speed", nullptr));
        AccelPedalLbl->setText(QCoreApplication::translate("MainWindow", "Accelerator: ", nullptr));
        BrakePedalLbl->setText(QCoreApplication::translate("MainWindow", "Brake:", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Electrical Data", nullptr));
        packInformationLbl->setText(QCoreApplication::translate("MainWindow", "Pack Information", nullptr));
        BusCurrentLbl->setText(QCoreApplication::translate("MainWindow", "Bus Current", nullptr));
        RinehartVoltageLbl->setText(QCoreApplication::translate("MainWindow", "RInehart Voltage", nullptr));
        BusVoltageLbl->setText(QCoreApplication::translate("MainWindow", "Bus Voltage", nullptr));
        batteryPercentageLbl->setText(QCoreApplication::translate("MainWindow", "Battery %: ", nullptr));
        steeringDeflectionLbl->setText(QCoreApplication::translate("MainWindow", "Steering Deflection:", nullptr));
        steeringDeflectionLblImage->setText(QCoreApplication::translate("MainWindow", "steering wheel image", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Telemetry Data", nullptr));
        cellInfoLbl->setText(QCoreApplication::translate("MainWindow", "Cell Infomation", nullptr));
        minCellVoltageLbl->setText(QCoreApplication::translate("MainWindow", "Min Cell Voltage", nullptr));
        maxCellVoltageLbl->setText(QCoreApplication::translate("MainWindow", "Max Cell Voltage", nullptr));
        maxCellTempLbl->setText(QCoreApplication::translate("MainWindow", "Max Cell Temp", nullptr));
        minCellTempLbl->setText(QCoreApplication::translate("MainWindow", "Min Cell Temp", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Wheel Data", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Front Left", nullptr));
        FLWheelSpeedLbl->setText(QCoreApplication::translate("MainWindow", "Wheel Speed (RPM):", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Strain 1:", nullptr));
        FLWheelHeightLbl->setText(QCoreApplication::translate("MainWindow", "Damper Deflection:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Strain 2:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Tire Temp (C): ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Rear Left", nullptr));
        BLWheelSpeedLbl->setText(QCoreApplication::translate("MainWindow", "Wheel Speed (RPM):", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Strain 1:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Strain 2:", nullptr));
        BLWheelHeightLbl->setText(QCoreApplication::translate("MainWindow", "Damper Deflection:", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Tire Temp (C): ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Front Right", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Strain 1:", nullptr));
        FRWheelSpeedLbl->setText(QCoreApplication::translate("MainWindow", "Wheel Speed (RPM):", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Tire Temp (C): ", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Strain 2:", nullptr));
        FRWheelHeightLbl->setText(QCoreApplication::translate("MainWindow", "Damper Defection:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Rear Right", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Strain 2:", nullptr));
        BRWheelSpeedLbl->setText(QCoreApplication::translate("MainWindow", "Wheel Speed (RPM):", nullptr));
        BRWheelHeightLbl->setText(QCoreApplication::translate("MainWindow", "Damper Deflection:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Strain 1:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Tire Temp (C): ", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "GPS Data", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Longittude: ", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Year: ", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "gpsYear", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Latitude:", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Month:", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "gpsMonth", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Altitude: ", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "Day: ", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "gpsDay", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Speed: ", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "Cooling Data", nullptr));
        fansActiveLbl->setText(QCoreApplication::translate("MainWindow", "Fans Active:", nullptr));
        fansActiveLED->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Coolant Temp In (C): ", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Coolant Temp Out (C): ", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "IMU Data", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Y Accleration (Gs): ", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Z Gyro (degs):", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Y Gyro (degs) :", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Z Accleration (Gs): ", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "X Accleration:  (Gs)", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "X Gyro (degs):", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
