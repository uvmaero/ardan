// Dominic Gasperini
// ARDAN

// includes
#include "PortSelectDialog.h"
#include "ui_PortSelectDialog.h"


/**
 * @brief PortSelectDialog::PortSelectDialog
 * @param parent
 */
PortSelectDialog::PortSelectDialog(QWidget *parent) : QDialog(parent), ui(new Ui::PortSelectDialog)
{
    // setup ui
    ui->setupUi(this);
    this->setWindowTitle("Select Serial Port");

    // refresh ports list
    RefreshPorts();
}


/**
 * @brief PortSelectDialog::~PortSelectDialog
 */
PortSelectDialog::~PortSelectDialog()
{
    delete ui;
}


/**
 * @brief PortSelectDialog::RefreshPorts
 */
void PortSelectDialog::RefreshPorts()
{
    // clear out old ports
    ui->comboBox->clear();

    // get available ports
    const auto availablePorts = QSerialPortInfo::availablePorts();

    // add to combo box
    if (!availablePorts.empty()) {
        for (const QSerialPortInfo &port : availablePorts)
        {
            ui->comboBox->addItem(port.portName());
        }
    }
}


/**
 * @brief PortSelectDialog::on_refreshButton_clicked
 */
void PortSelectDialog::on_refreshButton_clicked()
{
    RefreshPorts();
}


/**
 * @brief PortSelectDialog::on_buttonBox_accepted
 */
void PortSelectDialog::on_buttonBox_accepted()
{
    // get port name
    QString portName = ui->comboBox->currentText();

    // send signal to main window
    emit sPortSelected(portName);
}
