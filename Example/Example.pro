#-------------------------------------------------
#
# Project created by QtCreator 2017-3-14T09:34:59
#
#-------------------------------------------------
QT  +=core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LQFramKit
TEMPLATE = app

DEFINES +=DEBUG_OUT


SOURCES += \
    main.cpp

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

win32:{
    LIBS += -L../bin/ -lLQCustomGroupBox
}

DEPENDPATH += ../bin

# import dll file
include (../LQCustomGroupBox/lqcustomgroupbox_inc.pri)
