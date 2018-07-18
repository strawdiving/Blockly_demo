#-------------------------------------------------
#
# Project created by QtCreator 2017-08-23T16:42:07
#
#-------------------------------------------------

QT       += core gui webenginewidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    document.cpp \
    socketdialog.cpp

HEADERS  += mainwindow.h \
    document.h \
    socketdialog.h

FORMS    += mainwindow.ui \
    socketdialog.ui

RESOURCES += \
    web.qrc
