/********************************************************************************
** Form generated from reading UI file 'AboutDlg.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDLG_H
#define UI_ABOUTDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutDlg
{
public:
    QPushButton *exitBtn;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QPushButton *ardanTitleBtn;
    QGridLayout *gridLayout;
    QLabel *authorLbl;
    QLabel *label;
    QLabel *ardanLogoLbl;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *qtVersionNumLbl;
    QLabel *qtVersionLbl;
    QLabel *cppVersionLbl;
    QLabel *cppVersionNumLbl;
    QLabel *qtLogoLbl;

    void setupUi(QDialog *AboutDlg)
    {
        if (AboutDlg->objectName().isEmpty())
            AboutDlg->setObjectName("AboutDlg");
        AboutDlg->resize(270, 410);
        AboutDlg->setMinimumSize(QSize(270, 410));
        AboutDlg->setMaximumSize(QSize(270, 410));
        exitBtn = new QPushButton(AboutDlg);
        exitBtn->setObjectName("exitBtn");
        exitBtn->setGeometry(QRect(10, 360, 251, 41));
        layoutWidget = new QWidget(AboutDlg);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 251, 341));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        ardanTitleBtn = new QPushButton(layoutWidget);
        ardanTitleBtn->setObjectName("ardanTitleBtn");
        ardanTitleBtn->setStyleSheet(QString::fromUtf8("font: 700 oblique 30pt \"DejaVu Sans\";"));

        verticalLayout->addWidget(ardanTitleBtn);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        authorLbl = new QLabel(layoutWidget);
        authorLbl->setObjectName("authorLbl");
        authorLbl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(authorLbl, 0, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_3->addLayout(verticalLayout);

        ardanLogoLbl = new QLabel(layoutWidget);
        ardanLogoLbl->setObjectName("ardanLogoLbl");
        ardanLogoLbl->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(ardanLogoLbl);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        qtVersionNumLbl = new QLabel(layoutWidget);
        qtVersionNumLbl->setObjectName("qtVersionNumLbl");
        qtVersionNumLbl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(qtVersionNumLbl, 1, 1, 1, 1);

        qtVersionLbl = new QLabel(layoutWidget);
        qtVersionLbl->setObjectName("qtVersionLbl");
        qtVersionLbl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(qtVersionLbl, 1, 0, 1, 1);

        cppVersionLbl = new QLabel(layoutWidget);
        cppVersionLbl->setObjectName("cppVersionLbl");
        cppVersionLbl->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(cppVersionLbl, 0, 0, 1, 1);

        cppVersionNumLbl = new QLabel(layoutWidget);
        cppVersionNumLbl->setObjectName("cppVersionNumLbl");
        cppVersionNumLbl->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(cppVersionNumLbl, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        qtLogoLbl = new QLabel(layoutWidget);
        qtLogoLbl->setObjectName("qtLogoLbl");
        qtLogoLbl->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(qtLogoLbl);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(AboutDlg);

        QMetaObject::connectSlotsByName(AboutDlg);
    } // setupUi

    void retranslateUi(QDialog *AboutDlg)
    {
        AboutDlg->setWindowTitle(QCoreApplication::translate("AboutDlg", "Dialog", nullptr));
        exitBtn->setText(QCoreApplication::translate("AboutDlg", "Done", nullptr));
        ardanTitleBtn->setText(QCoreApplication::translate("AboutDlg", "ARDAN", nullptr));
        authorLbl->setText(QCoreApplication::translate("AboutDlg", "Author:", nullptr));
        label->setText(QCoreApplication::translate("AboutDlg", "Dominic Gasperini", nullptr));
        ardanLogoLbl->setText(QCoreApplication::translate("AboutDlg", "ARDAN Logo", nullptr));
        qtVersionNumLbl->setText(QCoreApplication::translate("AboutDlg", "QT VERSION", nullptr));
        qtVersionLbl->setText(QCoreApplication::translate("AboutDlg", "Qt Version:", nullptr));
        cppVersionLbl->setText(QCoreApplication::translate("AboutDlg", "C++ Version: ", nullptr));
        cppVersionNumLbl->setText(QCoreApplication::translate("AboutDlg", "C++ VERSION", nullptr));
        qtLogoLbl->setText(QCoreApplication::translate("AboutDlg", "Qt Logo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutDlg: public Ui_AboutDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDLG_H
