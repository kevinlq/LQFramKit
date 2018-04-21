#-------------------------------------------------
#
# Project created by QtCreator 2017-03-21T22:47:02
#
#-------------------------------------------------
include($$PWD/../LQGlobal.pri)
include($$PWD/../LQ_LibForAdditions.pri)

QT       += gui core widgets xml sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LQFramKit
TEMPLATE = app

DEFINES +=DEBUG_OUT



include($$PWD/demo/demo.pri)

INCLUDEPATH +=$$PWD/../LQTools/inc
INCLUDEPATH +=$$PWD/../LQInstrumentation/inc
INCLUDEPATH +=$$PWD/../LQFormWidget/inc
INCLUDEPATH +=$$PWD/../LQFormWidget/inc/tabWidget
INCLUDEPATH +=$$PWD/../LQFormWidget/inc/drawprogressbar
INCLUDEPATH +=$$PWD/../LQFormWidget/inc/messageWidget
INCLUDEPATH +=$$PWD/../LQFormWidget/inc/msgNotify
INCLUDEPATH +=$$PWD/../LQChart/inc
INCLUDEPATH +=$$PWD/demo



DEPENDPATH  +=$$PWD/../LQ3rdparty/QZXing/QZXing
DEPENDPATH  +=$$PWD/../LQTools
DEPENDPATH  +=$$PWD/../LQInstrumentation
DEPENDPATH  +=$$PWD/../LQFormWidget
DEPENDPATH  +=$$PWD/../LQChart

SOURCES += \
    main.cpp \
    examplewidget.cpp



FORMS += \
    examplewidget.ui

HEADERS += \
    examplewidget.h

RESOURCES += \
    ../LQRes/ExampleImage.qrc

LIBS += -L$${DIR_DEPEND_DEST} -lLQTools$${FILE_POSTFIX}
LIBS += -L$${DIR_DEPEND_DEST} -lLQChart$${FILE_POSTFIX}
LIBS += -L$${DIR_DEPEND_DEST} -lLQFormWidget$${FILE_POSTFIX}
LIBS += -L$${DIR_DEPEND_DEST} -lLQInstrumentation$${FILE_POSTFIX}
LIBS += -L$${DIR_DEPEND_QZXING_DEST} -lQZxing$${FILE_POSTFIX}
