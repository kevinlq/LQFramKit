#-------------------------------------------------
#
# Project created by QtCreator 2017-03-21T22:59:40
#
#-------------------------------------------------
#常见界面控件的封装(比如可移动窗体、各种自定义类型的消息框、各种弹窗等)
include($$PWD/../LQGlobal.pri)
QT       -= gui
QT       +=xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LQFormWidget$${FILE_POSTFIX}

TEMPLATE = lib

CONFIG  +=C++11

DEFINES += LQFORMWIDGET_LIBRARY
DEFINES +=DEBUG_OUT

INCLUDEPATH +=$$PWD/inc \
              $$PWD/messageWidget


SOURCES += \
    $$PWD/src/lqformwidget.cpp \
    $$PWD/src/searchlineedit.cpp \
    $$PWD/src/gradientcombobox.cpp \
    $$PWD/src/cmysplashscreen.cpp \
    $$PWD/src/nbaseswitchbutton.cpp \
    $$PWD/src/msgboxbase.cpp \
    $$PWD/src/messageWidget/messagetitle.cpp \
    $$PWD/src/messageWidget/messagewidget.cpp \
    $$PWD/src/lqstartwidget.cpp \
    $$PWD/src/drawprogressbar/drawprogressbar.cpp \
    $$PWD/src/ipaddresswidget.cpp \
    $$PWD/src/msgNotify/notify.cpp \
    $$PWD/src/msgNotify/notifymanager.cpp \
    $$PWD/src/navlistview.cpp \
    $$PWD/src/tabWidget/customtabstyle.cpp \
    $$PWD/src/tabWidget/mytabwidget.cpp \
    $$PWD/src/tolerancebar.cpp

HEADERS += \
    StdMain.h \
    inc/LQFormWidgetInc.h \
    inc/LQFormWidgetIncLib.h \
    $$PWD/inc/lqformwidget_global.h \
    $$PWD/inc/lqformwidget.h \
    $$PWD/inc/searchlineedit.h \
    $$PWD/inc/gradientcombobox.h \
    $$PWD/inc/cmysplashscreen.h \
    $$PWD/inc/nbaseswitchbutton.h \
    $$PWD/inc/msgboxbase.h \
    $$PWD/inc/messageWidget/messagetitle.h \
    $$PWD/inc/messageWidget/messagewidget.h \
    $$PWD/inc/lqstartwidget.h \
    $$PWD/inc/drawprogressbar/drawprogressbar.h \
    $$PWD/inc/ipaddresswidget.h \
    $$PWD/inc/msgNotify/notifymanager.h \
    $$PWD/inc/msgNotify/notify.h \
    $$PWD/inc/navlistview.h \
    $$PWD/inc/tabWidget/customtabstyle.h \
    $$PWD/inc/tabWidget/mytabwidget.h \
    $$PWD/inc/tolerancebar.h



RESOURCES += \
    ../LQRes/FormWidgetimage.qrc
