// Dominic Gasperini
// ARDAN

// includes
#include <QApplication>
#include "GUI/MainWindow.h"

/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    // init application
    QApplication a(argc, argv);

    // init main window
    MainWindow w;

    w.show();
    return a.exec();
}
