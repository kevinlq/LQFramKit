#-------------------------------------------------
#
# Project created by QtCreator 2017-03-21T23:01:24
#
#-------------------------------------------------
#常见的图表类控件集合(各种折线图，条形图，饼图……)
QT       -= gui

TARGET = LQChart
TEMPLATE = lib

DEFINES += LQCHART_LIBRARY

include ($$PWD/lqchart_src.pri)
INCLUDEPATH +=$$PWD/inc

win32{
    CONFIG  += debug_and_release
    CONFIG(release,debug|release){
        target_path = ../build_/release
    }else{
        target_path = ../build_/debug
    }
    DESTDIR =../bin
    MOC_DIR = $$target_path/moc
    RCC_DIR = $$target_path/rcc
    OBJECTS_DIR = $$target_path/obj
}

unix {
    CONFIG  += debug_and_release
    CONFIG(release,debug|release){
        target_path = ../build_/release
    }else{
        target_path = ../build_/debug
    }
    DESTDIR =../bin
    MOC_DIR = $$target_path/moc
    RCC_DIR = $$target_path/rcc
    OBJECTS_DIR = $$target_path/obj
}
