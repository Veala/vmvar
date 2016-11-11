TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    N2Types.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    N2Types.h
