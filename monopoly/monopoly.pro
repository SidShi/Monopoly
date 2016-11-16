#-------------------------------------------------
#
# Project created by QtCreator 2016-11-13T23:14:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = monopoly
TEMPLATE = app


SOURCES += main.cpp\
        monopoly.cpp \
    gameslot.cpp \
    player.cpp \
    chance.cpp

HEADERS  += monopoly.h \
    gameslot.h \
    player.h \
    chance.h

FORMS    += monopoly.ui \
    gameslot.ui \
    player.ui \
    chance.ui
