// Dominic Gasperini
// ARDAN

#ifndef PORTSELECTDIALOG_H
#define PORTSELECTDIALOG_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>

namespace Ui {
class PortSelectDialog;
}

/**
 * @brief The PortSelectDialog class
 */
class PortSelectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PortSelectDialog(QWidget *parent = nullptr);
    ~PortSelectDialog();

private:
    // UI
    Ui::PortSelectDialog *ui;

    // functions
    void RefreshPorts();

signals:
    void sPortSelected(QString portName);

private slots:
    void on_refreshButton_clicked();
    void on_buttonBox_accepted();
};

#endif // PORTSELECTDIALOG_H
