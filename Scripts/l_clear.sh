#!/bin/sh
#FileName:clear.sh
#Function:Remove the middle of the generated files in this project
#Version:V0.1
#Author:liqi
#Data:2017-03-17

CURRPATH=$PWD

rm -rf ../AISApp/Makefile.Debug
rm -rf ../AISApp/Makefile.Release
rm -rf ../AISApp/Makefile
rm -rf ../AISApp/*.o
rm -rf ../AISApp/moc_*
rm -rf ../AISApp/ui_*

rm -rf ../buile_
rm -rf ../Makefile
rm -rf ../*.pro.user
rm -rf ../bin/*.so.*

rm -rf ../LQAisInputModule/*.Debug
rm -rf ../LQAisInputModule/*.Release
rm -rf ../LQAisInputModule/Makefile
rm -rf ../LQAisInputModule/debug
rm -rf ../LQAisInputModule/release

rm -rf ../LQAisParser/*.Debug
rm -rf ../LQAisParser/*.Release
rm -rf ../LQAisParser/Makefile
rm -rf ../LQAisParser/debug
rm -rf ../LQAisParser/release

rm -rf ../LQBaiduMapLoadModule/*.Debug
rm -rf ../LQBaiduMapLoadModule/*.Release
rm -rf ../LQBaiduMapLoadModule/Makefile
rm -rf ../LQBaiduMapLoadModule/debug
rm -rf ../LQBaiduMapLoadModule/release

rm -rf ../LQDatabaseModule/*.Debug
rm -rf ../LQDatabaseModule/*.Release
rm -rf ../LQDatabaseModule/Makefile
rm -rf ../LQDatabaseModule/debug
rm -rf ../LQDatabaseModule/release

rm -rf ../LQModleAnalysModule/*.Debug
rm -rf ../LQModleAnalysModule/*.Release
rm -rf ../LQModleAnalysModule/Makefile
rm -rf ../LQModleAnalysModule/debug
rm -rf ../LQModleAnalysModule/release
