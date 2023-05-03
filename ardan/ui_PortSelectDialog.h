/********************************************************************************
** Form generated from reading UI file 'PortSelectDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTSELECTDIALOG_H
#define UI_PORTSELECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PortSelectDialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;
    QLabel *selectPortLbl;
    QPushButton *refreshButton;

    void setupUi(QDialog *PortSelectDialog)
    {
        if (PortSelectDialog->objectName().isEmpty())
            PortSelectDialog->setObjectName(QString::fromUtf8("PortSelectDialog"));
        PortSelectDialog->resize(400, 130);
        PortSelectDialog->setMinimumSize(QSize(400, 130));
        PortSelectDialog->setMaximumSize(QSize(400, 130));
        buttonBox = new QDialogButtonBox(PortSelectDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(220, 90, 171, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox = new QComboBox(PortSelectDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(60, 50, 271, 31));
        selectPortLbl = new QLabel(PortSelectDialog);
        selectPortLbl->setObjectName(QString::fromUtf8("selectPortLbl"));
        selectPortLbl->setGeometry(QRect(130, 20, 131, 16));
        refreshButton = new QPushButton(PortSelectDialog);
        refreshButton->setObjectName(QString::fromUtf8("refreshButton"));
        refreshButton->setGeometry(QRect(10, 100, 91, 24));

        retranslateUi(PortSelectDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, PortSelectDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, PortSelectDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(PortSelectDialog);
    } // setupUi

    void retranslateUi(QDialog *PortSelectDialog)
    {
        PortSelectDialog->setWindowTitle(QCoreApplication::translate("PortSelectDialog", "Dialog", nullptr));
        selectPortLbl->setText(QCoreApplication::translate("PortSelectDialog", "Select a Serial Port:", nullptr));
        refreshButton->setText(QCoreApplication::translate("PortSelectDialog", "Refesh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PortSelectDialog: public Ui_PortSelectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTSELECTDIALOG_H
