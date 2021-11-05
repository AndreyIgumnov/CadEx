TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../CurvesLib
LIBS += -L../CurvesLib/lib -lCurvesLib

SOURCES += \
        main.cpp
