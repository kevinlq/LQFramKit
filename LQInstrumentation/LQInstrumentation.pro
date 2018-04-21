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


include ($$PWD/lqinstrumentation_src.pri)
INCLUDEPATH +=$$PWD/inc
