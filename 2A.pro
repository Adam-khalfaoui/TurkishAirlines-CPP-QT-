QT += core gui
QT += sql
QT += webenginewidgets
QT+= core gui charts
QT += charts
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += resources_big
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    avion.cpp \
    bagage.cpp \
    client.cpp \
    connection.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    smtp.cpp \
    vols.cpp

HEADERS += \
    arduino.h \
    avion.h \
    bagage.h \
    client.h \
    connection.h \
    login.h \
    mainwindow.h \
    smtp.h \
    vols.h

FORMS += \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
CONFIG += resources_big
RESOURCES += \
    Ressources.qrc
QMAKE_CXXFLAGS+= -std=gnu++14
target.path = $$[QT_INSTALL_EXAMPLES]/charts/donutchart
INSTALLS += target
