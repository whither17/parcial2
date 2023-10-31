TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    juego.cpp \
    main.cpp \
    ficha.cpp \
    player.cpp \
    tablero.cpp

HEADERS += \
    ficha.h \
    juego.h \
    macros.h \
    player.h \
    tablero.h
