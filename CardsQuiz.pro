TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    icardoperation.cpp \
    cardlist.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    card.h \
    helper.h \
    icardoperation.h \
    cardlist.h

