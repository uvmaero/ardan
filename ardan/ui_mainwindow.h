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
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
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
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *BrakePedalImage;
    QLabel *AccelPedalImage;
    QLabel *label_13;
    QLabel *label_14;
    QProgressBar *progressBar;
    QProgressBar *progressBar_2;
    QLabel *label_29;
    QDial *dial;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QLabel *BatteryImage;
    QProgressBar *progressBar_3;
    QWidget *widget;
    QGridLayout *gridLayout_5;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_5;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_6;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_7;
    QWidget *widget1;
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
    QWidget *widget2;
    QGridLayout *gridLayout_7;
    QLabel *label_30;
    QLabel *WheelConnectionStatusImage;
    QLabel *CarImage;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QSpinBox *spinBox_2;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_2;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QSpinBox *spinBox_3;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_3;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout_4;
    QLabel *label_8;
    QSpinBox *spinBox_4;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_10;
    QLineEdit *lineEdit;
    QWidget *widget3;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1300, 800);
        MainWindow->setMinimumSize(QSize(1300, 800));
        MainWindow->setMaximumSize(QSize(1300, 800));
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
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(50, 710, 62, 16));
        label_13->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(270, 710, 81, 20));
        label_14->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 680, 161, 23));
        progressBar->setValue(13);
        progressBar_2 = new QProgressBar(groupBox);
        progressBar_2->setObjectName(QString::fromUtf8("progressBar_2"));
        progressBar_2->setGeometry(QRect(230, 680, 171, 23));
        progressBar_2->setValue(66);
        label_29 = new QLabel(groupBox);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(160, 230, 91, 16));
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
        progressBar_3 = new QProgressBar(groupBox_2);
        progressBar_3->setObjectName(QString::fromUtf8("progressBar_3"));
        progressBar_3->setGeometry(QRect(10, 120, 381, 23));
        progressBar_3->setValue(78);
        widget = new QWidget(groupBox_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(110, 420, 191, 101));
        gridLayout_5 = new QGridLayout(widget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        doubleSpinBox_5 = new QDoubleSpinBox(widget);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));
        doubleSpinBox_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_5->setReadOnly(true);
        doubleSpinBox_5->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_5->addWidget(doubleSpinBox_5, 0, 1, 1, 1);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_5->addWidget(label_11, 1, 0, 1, 1);

        doubleSpinBox_6 = new QDoubleSpinBox(widget);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));
        doubleSpinBox_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_6->setReadOnly(true);
        doubleSpinBox_6->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_5->addWidget(doubleSpinBox_6, 1, 1, 1, 1);

        label_12 = new QLabel(widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_5->addWidget(label_12, 2, 0, 1, 1);

        doubleSpinBox_7 = new QDoubleSpinBox(widget);
        doubleSpinBox_7->setObjectName(QString::fromUtf8("doubleSpinBox_7"));
        doubleSpinBox_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_7->setReadOnly(true);
        doubleSpinBox_7->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_5->addWidget(doubleSpinBox_7, 2, 1, 1, 1);

        widget1 = new QWidget(groupBox_2);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(10, 190, 381, 211));
        gridLayout_6 = new QGridLayout(widget1);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_22 = new QLabel(widget1);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_6->addWidget(label_22, 6, 0, 1, 2);

        doubleSpinBox_8 = new QDoubleSpinBox(widget1);
        doubleSpinBox_8->setObjectName(QString::fromUtf8("doubleSpinBox_8"));
        doubleSpinBox_8->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_8->setReadOnly(true);
        doubleSpinBox_8->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_8, 1, 2, 1, 1);

        label_25 = new QLabel(widget1);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_6->addWidget(label_25, 1, 4, 1, 1);

        label_26 = new QLabel(widget1);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_6->addWidget(label_26, 2, 4, 1, 1);

        label_28 = new QLabel(widget1);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_6->addWidget(label_28, 5, 4, 1, 1);

        label_19 = new QLabel(widget1);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_6->addWidget(label_19, 3, 0, 1, 2);

        label_20 = new QLabel(widget1);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_6->addWidget(label_20, 4, 0, 1, 2);

        label_24 = new QLabel(widget1);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_6->addWidget(label_24, 6, 4, 1, 1);

        doubleSpinBox_13 = new QDoubleSpinBox(widget1);
        doubleSpinBox_13->setObjectName(QString::fromUtf8("doubleSpinBox_13"));
        doubleSpinBox_13->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_13->setReadOnly(true);
        doubleSpinBox_13->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_13, 6, 2, 1, 1);

        doubleSpinBox_11 = new QDoubleSpinBox(widget1);
        doubleSpinBox_11->setObjectName(QString::fromUtf8("doubleSpinBox_11"));
        doubleSpinBox_11->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_11->setReadOnly(true);
        doubleSpinBox_11->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_11, 4, 2, 1, 1);

        label_27 = new QLabel(widget1);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_6->addWidget(label_27, 4, 4, 1, 1);

        doubleSpinBox_16 = new QDoubleSpinBox(widget1);
        doubleSpinBox_16->setObjectName(QString::fromUtf8("doubleSpinBox_16"));
        doubleSpinBox_16->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_16->setReadOnly(true);
        doubleSpinBox_16->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_16, 5, 5, 1, 1);

        doubleSpinBox_18 = new QDoubleSpinBox(widget1);
        doubleSpinBox_18->setObjectName(QString::fromUtf8("doubleSpinBox_18"));
        doubleSpinBox_18->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_18->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_18->setReadOnly(true);
        doubleSpinBox_18->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_18, 6, 5, 1, 1);

        doubleSpinBox_14 = new QDoubleSpinBox(widget1);
        doubleSpinBox_14->setObjectName(QString::fromUtf8("doubleSpinBox_14"));
        doubleSpinBox_14->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_14->setReadOnly(true);
        doubleSpinBox_14->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_14, 1, 5, 1, 1);

        label_21 = new QLabel(widget1);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_6->addWidget(label_21, 5, 0, 1, 2);

        doubleSpinBox_10 = new QDoubleSpinBox(widget1);
        doubleSpinBox_10->setObjectName(QString::fromUtf8("doubleSpinBox_10"));
        doubleSpinBox_10->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_10->setReadOnly(true);
        doubleSpinBox_10->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_10, 3, 2, 1, 1);

        doubleSpinBox_15 = new QDoubleSpinBox(widget1);
        doubleSpinBox_15->setObjectName(QString::fromUtf8("doubleSpinBox_15"));
        doubleSpinBox_15->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_15->setReadOnly(true);
        doubleSpinBox_15->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_15, 2, 5, 1, 1);

        doubleSpinBox_17 = new QDoubleSpinBox(widget1);
        doubleSpinBox_17->setObjectName(QString::fromUtf8("doubleSpinBox_17"));
        doubleSpinBox_17->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_17->setReadOnly(true);
        doubleSpinBox_17->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_17, 3, 5, 1, 1);

        doubleSpinBox_19 = new QDoubleSpinBox(widget1);
        doubleSpinBox_19->setObjectName(QString::fromUtf8("doubleSpinBox_19"));
        doubleSpinBox_19->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_19->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_19->setReadOnly(true);
        doubleSpinBox_19->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_19, 4, 5, 1, 1);

        label_23 = new QLabel(widget1);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_6->addWidget(label_23, 3, 4, 1, 1);

        label_18 = new QLabel(widget1);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_6->addWidget(label_18, 2, 0, 1, 2);

        label_17 = new QLabel(widget1);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_6->addWidget(label_17, 1, 0, 1, 2);

        doubleSpinBox_9 = new QDoubleSpinBox(widget1);
        doubleSpinBox_9->setObjectName(QString::fromUtf8("doubleSpinBox_9"));
        doubleSpinBox_9->setMaximumSize(QSize(60, 16777215));
        doubleSpinBox_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_9->setReadOnly(true);
        doubleSpinBox_9->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_6->addWidget(doubleSpinBox_9, 2, 2, 1, 1);

        doubleSpinBox_12 = new QDoubleSpinBox(widget1);
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

        label_15 = new QLabel(widget1);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_6->addWidget(label_15, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 0, 3, 1, 1);

        label_16 = new QLabel(widget1);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_6->addWidget(label_16, 0, 4, 1, 2);

        widget2 = new QWidget(groupBox_2);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(100, 550, 212, 18));
        gridLayout_7 = new QGridLayout(widget2);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        label_30 = new QLabel(widget2);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout_7->addWidget(label_30, 0, 0, 1, 1);

        WheelConnectionStatusImage = new QLabel(widget2);
        WheelConnectionStatusImage->setObjectName(QString::fromUtf8("WheelConnectionStatusImage"));

        gridLayout_7->addWidget(WheelConnectionStatusImage, 0, 1, 1, 1);

        CarImage = new QLabel(centralwidget);
        CarImage->setObjectName(QString::fromUtf8("CarImage"));
        CarImage->setGeometry(QRect(460, 200, 381, 451));
        CarImage->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(710, 100, 161, 71));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        spinBox_2 = new QSpinBox(layoutWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_2->setReadOnly(true);
        spinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_2->addWidget(spinBox_2, 0, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_2->setReadOnly(true);
        doubleSpinBox_2->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_2->addWidget(doubleSpinBox_2, 1, 1, 1, 1);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(700, 670, 171, 71));
        gridLayout_3 = new QGridLayout(layoutWidget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        spinBox_3 = new QSpinBox(layoutWidget_2);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_3->setReadOnly(true);
        spinBox_3->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_3->addWidget(spinBox_3, 0, 1, 1, 1);

        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 1, 0, 1, 1);

        doubleSpinBox_3 = new QDoubleSpinBox(layoutWidget_2);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_3->setReadOnly(true);
        doubleSpinBox_3->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_3->addWidget(doubleSpinBox_3, 1, 1, 1, 1);

        layoutWidget_3 = new QWidget(centralwidget);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(440, 670, 161, 71));
        gridLayout_4 = new QGridLayout(layoutWidget_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_4->addWidget(label_8, 0, 0, 1, 1);

        spinBox_4 = new QSpinBox(layoutWidget_3);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox_4->setReadOnly(true);
        spinBox_4->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_4->addWidget(spinBox_4, 0, 1, 1, 1);

        label_9 = new QLabel(layoutWidget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 1, 0, 1, 1);

        doubleSpinBox_4 = new QDoubleSpinBox(layoutWidget_3);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox_4->setReadOnly(true);
        doubleSpinBox_4->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout_4->addWidget(doubleSpinBox_4, 1, 1, 1, 1);

        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(620, 10, 81, 16));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(570, 30, 181, 31));
        widget3 = new QWidget(centralwidget);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(440, 100, 161, 71));
        gridLayout = new QGridLayout(widget3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        spinBox = new QSpinBox(widget3);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox->setReadOnly(true);
        spinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(spinBox, 0, 1, 1, 1);

        label_3 = new QLabel(widget3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(widget3);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        doubleSpinBox->setReadOnly(true);
        doubleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(doubleSpinBox, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1300, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Mechanical", nullptr));
        BrakePedalImage->setText(QCoreApplication::translate("MainWindow", "Brake Pedal Image", nullptr));
        AccelPedalImage->setText(QCoreApplication::translate("MainWindow", "Accelerator Pedal Image", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Brake", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Accelerator", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Speed (mph)", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Electrical", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Faults", nullptr));
        BatteryImage->setText(QCoreApplication::translate("MainWindow", "Battery Image", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Bus Voltage", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Bus Current", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "RInehart Voltage", nullptr));
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
        label_30->setText(QCoreApplication::translate("MainWindow", "Steering Wheel Connection", nullptr));
        WheelConnectionStatusImage->setText(QCoreApplication::translate("MainWindow", "LED", nullptr));
        CarImage->setText(QCoreApplication::translate("MainWindow", "Image of Car", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Wheel Speed", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Suspension", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Wheel Speed", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Suspension", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Wheel Speed", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Suspension", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Drive Mode", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Wheel Speed", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Suspension", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
