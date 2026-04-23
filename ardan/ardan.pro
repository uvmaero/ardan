QT       += core gui
QT	 += serialport
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

UI_DIR = $$PWD

SOURCES += \
    GUI/AboutDlg.cpp \
    Data/DataLogger.cpp \
    Data/ExecutiveData.cpp \
    Data/GpioData.cpp \
    Data/TwaiData.cpp \
    Interface/DataManager.cpp \
    GUI/MainWindow.cpp \
    GUI/PortSelectDialog.cpp \
    main.cpp

HEADERS += \
    GUI/AboutDlg.h \
    Data/DataLogger.h \
    Data/ExecutiveData.h \
    Data/GpioData.h \
    Data/TwaiData.h \
    Interface/DataManager.h \
    GUI/MainWindow.h \
    GUI/PortSelectDialog.h

FORMS += \
    GUI/AboutDlg.ui \
    GUI/MainWindow.ui \
    GUI/PortSelectDialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
