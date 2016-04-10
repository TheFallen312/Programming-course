#-------------------------------------------------
#
# Project created by QtCreator 2016-02-29T20:22:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Graphics
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    intercepted.cpp \
    interceptor.cpp \
    aag.cpp

HEADERS  += mainwindow.h \
    intercepted.h \
    interceptor.h \
    aag.h

FORMS    += mainwindow.ui
