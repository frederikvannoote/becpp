#-------------------------------------------------
#
# Project created by QtCreator 2017-11-03T20:07:15
#
#-------------------------------------------------

QT       -= gui

TARGET = prime
TEMPLATE = lib
CONFIG += staticlib

SOURCES += prime.cpp \
    journal.cpp

HEADERS += prime.h \
    journal.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
