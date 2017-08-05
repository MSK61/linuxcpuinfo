include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG += thread
QT -= gui

SOURCES +=     tst_cpuinfotest.cpp \
    cpuinfoutils.cpp
