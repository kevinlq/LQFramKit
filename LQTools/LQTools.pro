#-------------------------------------------------
#
# Project created by QtCreator 2017-03-21T23:02:13
#
#-------------------------------------------------
#辅助工具类集合(常见的工具，比如二维码、验证码、串口通信、TCP/UDP通信……)
include($$PWD/../LQGlobal.pri)

QT       -= gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#greaterThan(QT_VERSION, 4.7): QT += declarative
greaterThan(QT_VERSION, 5.0): QT += quick

TARGET = LQTools$${FILE_POSTFIX}
TEMPLATE = lib

DEFINES += LQTOOLS_LIBRARY

INCLUDEPATH +=$$PWD/inc

SOURCES += \
    src/perfmon.cpp \
    src/LQimagehandler.cpp \
    src/cruler.cpp

HEADERS += \
    inc/LQToolsIncLib.h \
    inc/LQToolsInc.h \
    inc/lqtools_global.h \
    inc/perfmon.h \
    inc/LQimagehandler.h \
    inc/cruler.h

win32:{
    LIBS+=-L .. -lGdi32
}


