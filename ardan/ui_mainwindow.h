/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
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
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *BrakePedalImage;
    QLabel *AccelPedalImage;
    QLabel *BrakePedalLbl;
    QLabel *AccelPedalLbl;
    QProgressBar *BrakePedalProgressBar;
    QProgressBar *AccelPedalProgressBar;
    QLabel *SpeedLbl;
    QDial *dial;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
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
    QGridLayout *gridLayout_6;
    QLabel *label_22;
    QDoubleSpinBox *doubleSpinBox_8;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_28;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_24;
    QDoubleSpinBox *doubleSpinBox_13;
    QDoubleSpinBox *doubleSpinBox_11;
    QLabel *label_27;
    QDoubleSpinBox *doubleSpinBox_16;
    QDoubleSpinBox *doubleSpinBox_18;
    QDoubleSpinBox *doubleSpinBox_14;
    QLabel *label_21;
    QDoubleSpinBox *doubleSpinBox_10;
    QDoubleSpinBox *doubleSpinBox_15;
    QDoubleSpinBox *doubleSpinBox_17;
    QDoubleSpinBox *doubleSpinBox_19;
    QLabel *label_23;
    QLabel *label_18;
    QLabel *label_17;
    QDoubleSpinBox *doubleSpinBox_9;
    QDoubleSpinBox *doubleSpinBox_12;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer;
    QLabel *label_16;
    QWidget *layoutWidget2;
    QGridLayout *WheelConnectionGridLayout;
    QLabel *WheelConnectionLbl;
    QLabel *WheelConnectionStatusImage;
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
        Dark_Mode = new QAction(MainWindow);
        Dark_Mode->setObjectName(QString::fromUtf8("Dark_Mode"));
        Dark_Mode->setCheckable(true);
        About_Dlg = new QAction(MainWindow);
        About_Dlg->setObjectName(QString::fromUtf8("About_Dlg"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 411, 741));
        BrakePedalImage = new QLabel(groupBox);
        BrakePedalImage->setObjectName(QString::fromUtf8("BrakePedalImage"));
        BrakePedalImage->setGeometry(QRect(50, 520, 101, 151));
        AccelPedalImage = new QLabel(groupBox);
        AccelPedalImage->setObjectName(QString::fromUtf8("AccelPedalImage"));
        AccelPedalImage->setGeometry(QRect(270, 520, 111, 151));
        BrakePedalLbl = new QLabel(groupBox);
        BrakePedalLbl->setObjectName(QString::fromUtf8("BrakePedalLbl"));
        BrakePedalLbl->setGeometry(QRect(50, 710, 62, 16));
        BrakePedalLbl->setAlignment(Qt::AlignCenter);
        AccelPedalLbl = new QLabel(groupBox);
        AccelPedalLbl->setObjectName(QString::fromUtf8("AccelPedalLbl"));
        AccelPedalLbl->setGeometry(QRect(270, 710, 81, 20));
        AccelPedalLbl->setAlignment(Qt::AlignCenter);
        BrakePedalProgressBar = new QProgressBar(groupBox);
        BrakePedalProgressBar->setObjectName(QString::fromUtf8("BrakePedalProgressBar"));
        BrakePedalProgressBar->setGeometry(QRect(10, 680, 161, 23));
        BrakePedalProgressBar->setValue(13);
        AccelPedalProgressBar = new QProgressBar(groupBox);
        AccelPedalProgressBar->setObjectName(QString::fromUtf8("AccelPedalProgressBar"));
        AccelPedalProgressBar->setGeometry(QRect(230, 680, 171, 23));
        AccelPedalProgressBar->setValue(66);
        SpeedLbl = new QLabel(groupBox);
        SpeedLbl->setObjectName(QString::fromUtf8("SpeedLbl"));
        SpeedLbl->setGeometry(QRect(160, 230, 91, 16));
        dial = new QDial(groupBox);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setGeometry(QRect(120, 70, 161, 141));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(890, 10, 401, 741));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 580, 381, 151));
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
        layoutWidget->setGeometry(QRect(110, 420, 191, 101));
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
        layoutWidget1->setGeometry(QRect(10, 190, 381, 211));
        gridLayout_6 = new QGridLayout(layoutWidget1);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_22 = new QLabel(layoutWidget1);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_6->addWidget(label_22, 6, 0, 1, 2);

        doubleSpinBox_8 = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_8->setObjectName(QString::fromUtf8("doubleSpinBox_8"));
        doubleSpinBox_8->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_8->setReadOnly(true);
        doubleSpinBox_8->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_8, 1, 2, 1, 1);

        label_25 = new QLabel(layoutWidget1);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_6->addWidget(label_25, 1, 4, 1, 1);

        label_26 = new QLabel(layoutWidget1);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_6->addWidget(label_26, 2, 4, 1, 1);

        label_28 = new QLabel(layoutWidget1);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_6->addWidget(label_28, 5, 4, 1, 1);

        label_19 = new QLabel(layoutWidget1);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_6->addWidget(label_19, 3, 0, 1, 2);

        label_20 = new QLabel(layoutWidget1);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_6->addWidget(label_20, 4, 0, 1, 2);

        label_24 = new QLabel(layoutWidget1);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_6->addWidget(label_24, 6, 4, 1, 1);

        doubleSpinBox_13 = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_13->setObjectName(QString::fromUtf8("doubleSpinBox_13"));
        doubleSpinBox_13->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_13->setReadOnly(true);
        doubleSpinBox_13->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_13, 6, 2, 1, 1);

        doubleSpinBox_11 = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_11->setObjectName(QString::fromUtf8("doubleSpinBox_11"));
        doubleSpinBox_11->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_11->setReadOnly(true);
        doubleSpinBox_11->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_11, 4, 2, 1, 1);

        label_27 = new QLabel(layoutWidget1);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_6->addWidget(label_27, 4, 4, 1, 1);

        doubleSpinBox_16 = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_16->setObjectName(QString::fromUtf8("doubleSpinBox_16"));
        doubleSpinBox_16->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_16->setReadOnly(true);
        doubleSpinBox_16->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_16, 5, 5, 1, 1);

        doubleSpinBox_18 = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_18->setObjectName(QString::fromUtf8("doubleSpinBox_18"));
        doubleSpinBox_18->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_18->setReadOnly(true);
        doubleSpinBox_18->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_18, 6, 5, 1, 1);

        doubleSpinBox_14 = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_14->setObjectName(QString::fromUtf8("doubleSpinBox_14"));
        doubleSpinBox_14->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_14->setReadOnly(true);
        doubleSpinBox_14->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_14, 1, 5, 1, 1);

        label_21 = new QLabel(layoutWidget1);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_6->addWidget(label_21, 5, 0, 1, 2);

        doubleSpinBox_10 = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_10->setObjectName(QString::fromUtf8("doubleSpinBox_10"));
        doubleSpinBox_10->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_10->setReadOnly(true);
        doubleSpinBox_10->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_10, 3, 2, 1, 1);

        doubleSpinBox_15 = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_15->setObjectName(QString::fromUtf8("doubleSpinBox_15"));
        doubleSpinBox_15->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_15->setReadOnly(true);
        doubleSpinBox_15->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_15, 2, 5, 1, 1);

        doubleSpinBox_17 = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_17->setObjectName(QString::fromUtf8("doubleSpinBox_17"));
        doubleSpinBox_17->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_17->setReadOnly(true);
        doubleSpinBox_17->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_17, 3, 5, 1, 1);

        doubleSpinBox_19 = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_19->setObjectName(QString::fromUtf8("doubleSpinBox_19"));
        doubleSpinBox_19->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_19->setReadOnly(true);
        doubleSpinBox_19->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_19, 4, 5, 1, 1);

        label_23 = new QLabel(layoutWidget1);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_6->addWidget(label_23, 3, 4, 1, 1);

        label_18 = new QLabel(layoutWidget1);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_6->addWidget(label_18, 2, 0, 1, 2);

        label_17 = new QLabel(layoutWidget1);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_6->addWidget(label_17, 1, 0, 1, 2);

        doubleSpinBox_9 = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_9->setObjectName(QString::fromUtf8("doubleSpinBox_9"));
        doubleSpinBox_9->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_9->setReadOnly(true);
        doubleSpinBox_9->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_9, 2, 2, 1, 1);

        doubleSpinBox_12 = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox_12->setObjectName(QString::fromUtf8("doubleSpinBox_12"));
        doubleSpinBox_12->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_12->setReadOnly(true);
        doubleSpinBox_12->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_12, 5, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_3, 1, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_4, 2, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_5, 3, 3, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_6, 4, 3, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_7, 5, 3, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_8, 6, 3, 1, 1);

        label_15 = new QLabel(layoutWidget1);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_6->addWidget(label_15, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 0, 3, 1, 1);

        label_16 = new QLabel(layoutWidget1);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_6->addWidget(label_16, 0, 4, 1, 2);

        layoutWidget2 = new QWidget(groupBox_2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(100, 550, 212, 18));
        WheelConnectionGridLayout = new QGridLayout(layoutWidget2);
        WheelConnectionGridLayout->setObjectName(QString::fromUtf8("WheelConnectionGridLayout"));
        WheelConnectionGridLayout->setContentsMargins(0, 0, 0, 0);
        WheelConnectionLbl = new QLabel(layoutWidget2);
        WheelConnectionLbl->setObjectName(QString::fromUtf8("WheelConnectionLbl"));

        WheelConnectionGridLayout->addWidget(WheelConnectionLbl, 0, 0, 1, 1);

        WheelConnectionStatusImage = new QLabel(layoutWidget2);
        WheelConnectionStatusImage->setObjectName(QString::fromUtf8("WheelConnectionStatusImage"));

        WheelConnectionGridLayout->addWidget(WheelConnectionStatusImage, 0, 1, 1, 1);

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
        layoutWidget5->setGeometry(QRect(571, 11, 144, 47));
        DriveModeGridLayout = new QGridLayout(layoutWidget5);
        DriveModeGridLayout->setObjectName(QString::fromUtf8("DriveModeGridLayout"));
        DriveModeGridLayout->setContentsMargins(0, 0, 0, 0);
        DriveModeLbl = new QLabel(layoutWidget5);
        DriveModeLbl->setObjectName(QString::fromUtf8("DriveModeLbl"));
        DriveModeLbl->setAlignment(Qt::AlignCenter);

        DriveModeGridLayout->addWidget(DriveModeLbl, 0, 0, 1, 1);

        DriveModeTbx = new QLineEdit(layoutWidget5);
        DriveModeTbx->setObjectName(QString::fromUtf8("DriveModeTbx"));

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
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Mechanical Data", nullptr));
        BrakePedalImage->setText(QCoreApplication::translate("MainWindow", "Brake Pedal Image", nullptr));
        AccelPedalImage->setText(QCoreApplication::translate("MainWindow", "Accelerator Pedal Image", nullptr));
        BrakePedalLbl->setText(QCoreApplication::translate("MainWindow", "Brake", nullptr));
        AccelPedalLbl->setText(QCoreApplication::translate("MainWindow", "Accelerator", nullptr));
        SpeedLbl->setText(QCoreApplication::translate("MainWindow", "Speed (mph)", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Electrical Data", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Faults", nullptr));
        BatteryImage->setText(QCoreApplication::translate("MainWindow", "Battery Image", nullptr));
        BusVoltageLbl->setText(QCoreApplication::translate("MainWindow", "Bus Voltage", nullptr));
        BusCurrentLbl->setText(QCoreApplication::translate("MainWindow", "Bus Current", nullptr));
        RinehartVoltageLbl->setText(QCoreApplication::translate("MainWindow", "RInehart Voltage", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Averge Temp", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Average Voltage", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Max Cell Voltage", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "Min Cell Temp", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Min Cell Voltage", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Max Cell Temp", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Averge Temp", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Max Cell Temp", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Min Cell Temp", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Min Cell Voltage", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Max Cell Voltage", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Average Voltage", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Pack 1", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Pack 2", nullptr));
        WheelConnectionLbl->setText(QCoreApplication::translate("MainWindow", "Steering Wheel Connection", nullptr));
        WheelConnectionStatusImage->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
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
