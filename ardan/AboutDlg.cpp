// Dominic Gasperini
// ardan - about dialog

// includes
#include "AboutDlg.h"
#include "ui_AboutDlg.h"

// defines
#define CPP_VERSION     17


// About Dialog Class
/**
 * @brief AboutDlg::AboutDlg
 * @param parent
 */
AboutDlg::AboutDlg(QWidget *parent) : QDialog(parent), ui(new Ui::AboutDlg)
{
    // Setup UI
    ui->setupUi(this);
    this->setWindowTitle("About");
    ui->ardanLogoLbl->setPixmap(QPixmap(":/icons/lockbox.png").scaledToWidth(ui->lockboxLogoLbl->width()));
    ui->qtLogoLbl->setPixmap(QPixmap(":/icons/qt_logo.png").scaledToWidth(ui->qtLogoLbl->width()));

    // Fill in text boxes with information
    ui->cppVersionNumLbl->setText(QString::number(CPP_VERSION));
    ui->qtVersionNumLbl->setText(getQtVersion());
}


/**
 * @brief AboutDlg::~AboutDlg
 */
AboutDlg::~AboutDlg()
{
    delete ui;
}

// Setters & Getters
QString AboutDlg::getQtVersion() {
    QString major = QString::number(QT_VERSION_MAJOR);
    QString minor = QString::number(QT_VERSION_MINOR);

    return (major + "." + minor);
}


/**
 * @brief AboutDlg::on_exitBtn_clicked
 */
void AboutDlg::on_exitBtn_clicked()
{
    this->hide();
}


/**
 * @brief AboutDlg::on_lockboxTitleBtn_clicked
 */
void AboutDlg::on_ardanTitleBtn_clicked()
{
    QDesktopServices::openUrl(QUrl("https://shattereddisk.github.io/rickroll/rickroll.mp4", QUrl::TolerantMode));
}
