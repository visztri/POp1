QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kalkulator_gui
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    kalkulator.cpp

HEADERS += \
    mainwindow.h \
    kalkulator.h

FORMS += \
    mainwindow.ui