#-------------------------------------------------
#
# Project created by QtCreator 2017-03-21T23:01:24
#
#-------------------------------------------------
#常见的图表类控件集合(各种折线图，条形图，饼图……)
include($$PWD/../LQGlobal.pri)
QT       -= gui

TARGET = LQChart$${FILE_POSTFIX}
TEMPLATE = lib

DEFINES += LQCHART_LIBRARY

include ($$PWD/lqchart_src.pri)

INCLUDEPATH +=$$PWD/inc

