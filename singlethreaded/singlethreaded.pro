QT += core
QT -= gui

CONFIG += c++11

TARGET = singlethreaded
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../prime/release/ -lprime
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../prime/debug/ -lprime
else:unix: LIBS += -L$$OUT_PWD/../prime/ -lprime

INCLUDEPATH += $$PWD/../prime
DEPENDPATH += $$PWD/../prime

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../prime/release/libprime.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../prime/debug/libprime.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../prime/release/prime.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../prime/debug/prime.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../prime/libprime.a
