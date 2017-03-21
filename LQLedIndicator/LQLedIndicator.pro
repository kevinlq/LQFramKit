#-------------------------------------------------
#
# Project created by QtCreator 2017-03-21T18:00:39
#
#-------------------------------------------------

TARGET = LQLedIndicator
TEMPLATE = lib

DEFINES += LQLEDINDICATOR_LIBRARY

SOURCES += lqledindicator.cpp

HEADERS += lqledindicator.h\
        lqledindicator_global.h

include($$PWD/lqgauge_src.pri)
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
