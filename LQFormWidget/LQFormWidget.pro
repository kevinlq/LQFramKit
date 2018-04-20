#-------------------------------------------------
#
# Project created by QtCreator 2017-03-21T22:59:40
#
#-------------------------------------------------
#常见界面控件的封装(比如可移动窗体、各种自定义类型的消息框、各种弹窗等)
QT       -= gui
QT       +=xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LQFormWidget
TEMPLATE = lib

CONFIG  +=C++11

DEFINES += LQFORMWIDGET_LIBRARY
DEFINES +=DEBUG_OUT

include ($$PWD/lqformwidget_src.pri)
INCLUDEPATH +=$$PWD/inc \
              $$PWD/messageWidget

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

RESOURCES += \
    image.qrc
