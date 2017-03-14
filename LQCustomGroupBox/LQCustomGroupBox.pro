#-------------------------------------------------
#
# Project created by QtCreator 2017-03-14T22:47:02
#
#-------------------------------------------------

QT       += widgets

QT       -= gui

TARGET = LQCustomGroupBox
TEMPLATE = lib

DEFINES += LQCUSTOMGROUPBOX_LIBRARY

SOURCES += lqcustomgroupbox.cpp

HEADERS += lqcustomgroupbox.h\
        lqcustomgroupbox_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
