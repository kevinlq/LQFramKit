#-------------------------------------------------
#
# Project created by QtCreator 2017-03-21T22:49:34
#
#-------------------------------------------------
#对常见的仪器仪表进行封装(比如仪表盘……)
QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LQInstrumentation
TEMPLATE = lib

DEFINES += LQINSTRUMENTATION_LIBRARY


include ($$PWD/lqinstrumentation_src.pri)
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
    UI_DIR =  $$target_path/ui
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
    UI_DIR =  $$target_path/ui
    OBJECTS_DIR = $$target_path/obj
}
