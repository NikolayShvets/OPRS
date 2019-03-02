TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tvector.cpp \
    tmatrix.cpp \
    tquaternion.cpp \
    white_noise.cpp \
    math_model.cpp \
    custom.cpp \
    integrator.cpp

HEADERS += \
    tvector.h \
    tmatrix.h \
    tquaternion.h \
    white_noise.h \
    math_model.h \
    custom.h \
    integrator.h
