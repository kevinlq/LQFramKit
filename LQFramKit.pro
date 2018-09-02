TEMPLATE = subdirs

SUBDIRS += \
    $$PWD/LQ3rdparty/LQ3rdparty.pro \
    $$PWD/LQMisc/LQMisc.pro \
    $$PWD/LQInstrumentation/LQInstrumentation.pro \
    $$PWD/LQFormWidget/LQFormWidget.pro \
    $$PWD/LQChart/LQChart.pro \
    $$PWD/LQTools/LQTools.pro    \
    $$PWD/Exmaple/Exmaple.pro

CONFIG  +=ordered

