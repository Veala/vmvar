TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    types.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    types.h
