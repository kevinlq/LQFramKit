#-------------------------------------------------
#
# Project created by QtCreator 2017-03-21T22:47:02
#
#-------------------------------------------------

QT       += gui core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LQFramKit
TEMPLATE = app

DEFINES +=DEBUG_OUT

SOURCES += \
    main.cpp \
    examplewidget.cpp

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
    LIBS += -L../bin/ -lLQInstrumentation\
    -lLQFormWidget
}
DEPENDPATH += ../bin

# import dll file
include(../LQInstrumentation/lqinstrumentation_inc.pri)
include(../LQFormWidget/lqformwidget_inc.pri)

FORMS += \
    examplewidget.ui

HEADERS += \
    examplewidget.h
