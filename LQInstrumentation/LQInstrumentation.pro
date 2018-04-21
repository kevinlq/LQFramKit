#-------------------------------------------------
#
# Project created by QtCreator 2017-03-21T22:49:34
#
#-------------------------------------------------
#对常见的仪器仪表进行封装(比如仪表盘……)
include($$PWD/../LQGlobal.pri)

QT  += gui
QT  +=core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LQInstrumentation$${FILE_POSTFIX}
TEMPLATE = lib

DEFINES += LQINSTRUMENTATION_LIBRARY


#include ($$PWD/lqinstrumentation_src.pri)
INCLUDEPATH +=$$PWD/inc


SOURCES += \
#    $$PWD/src/lqinstrumentation.cpp \
    $$PWD/src/qgauge.cpp \
    $$PWD/src/qgaugedrawfunctions.cpp \
    $$PWD/src/qmeter.cpp \
    $$PWD/src/qmeterdrawfunctions.cpp \
    $$PWD/src/qcgaugewidget.cpp \
    $$PWD/src/compasswidget.cpp \
    $$PWD/src/attitudemeter.cpp \
    $$PWD/src/speedgaugewidget.cpp \
    $$PWD/src/airspeedgaugewidget.cpp \
    $$PWD/src/QRoundProgressBar.cpp \
    $$PWD/src/colorprogressbar.cpp \
    $$PWD/src/myspeedwatch.cpp \
    $$PWD/src/lwaveupprogress.cpp

HEADERS += \
    StdMain.h \
    inc/LQInstrumenttationInc.h \
    inc/LQInstrumenttationIncLib.h \
    $$PWD/inc/lqinstrumentation_global.h \
#    $$PWD/inc/lqinstrumentation.h \
    $$PWD/inc/qgauge.h \
    $$PWD/inc/qmeter.h \
    $$PWD/inc/qcgaugewidget.h \
    $$PWD/inc/compasswidget.h \
    $$PWD/inc/attitudemeter.h \
    $$PWD/inc/speedgaugewidget.h \
    $$PWD/inc/airspeedgaugewidget.h \
    $$PWD/inc/QRoundProgressBar.h \
    $$PWD/inc/colorprogressbar.h \
    $$PWD/inc/myspeedwatch.h \
    $$PWD/inc/lwaveupprogress.h
