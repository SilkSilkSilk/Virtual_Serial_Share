#-------------------------------------------------
#
# Project created by QtCreator 2018-09-29T16:53:09
#
#-------------------------------------------------

QT       += core gui
QT       += serialport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Virtual_Serial_Share
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    host_send.cpp \
    serial_base.cpp \
    slave_recv.cpp \
    listwidget.cpp \
    list_ip_port.cpp \
    my_scrollarea.cpp

HEADERS += \
        mainwindow.h \
    host_send.h \
    serial_base.h \
    slave_recv.h \
    listwidget.h \
    list_ip_port.h \
    my_scrollarea.h

FORMS += \
        mainwindow.ui \
    host_send.ui \
    serial_base.ui \
    slave_recv.ui \
    list_ip_port.ui
