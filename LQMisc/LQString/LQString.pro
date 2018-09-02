#-------------------------------------------------
#
# Project created by QtCreator 2018-09-02 22:19:19
#
#-------------------------------------------------


# add include pri file 
include($$PWD/../LQMisc.pri)
QT	 +=core

TEMPLATE	 =lib
DEFINES	 +=LQSTRING_LIBRARY
TARGET	 =LQString$${FILE_POSTFIX}


INCLUDEPATH	 +=$$PWD/../../LQInclude/IncludeGlobal
INCLUDEPATH	 +=$$PWD/../IncludeMisc
INCLUDEPATH	 +=$$PWD/../IncludeMisc/LQString

SOURCES	 +=\
    Global/GlobalVar.cpp \
    LQStringUtil.cpp

HEADERS	 +=\
    StdMain.h \
    Global/GlobalVar.h \
    Global/GlobalStruct.h \
    Global/GlobalInclude.h \
    Global/GlobalDef.h \
    ../IncludeMisc/LQString/LQString_Export.h \
    ../IncludeMisc/LQString/LQStringInc.h \
    ../IncludeMisc/LQString/LQStringIncLib.h \
    ../IncludeMisc/LQString/LQStringUtil.h

