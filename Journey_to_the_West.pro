#-------------------------------------------------
#
# Project created by QtCreator 2020-05-15T15:32:15
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Journey_to_the_West
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    evil.cpp \
    point.cpp \
    eudemon.cpp \
    object.cpp \
    marquee.cpp \
    monke_king.cpp \
    pigsy.cpp \
    monk_sha.cpp \
    gnome.cpp \
    begingame.cpp \
    endwindow.cpp

HEADERS += \
        mainwindow.h \
    evil.h \
    eudemon.h \
    point.h \
    marquee.h \
    object.h \
    monkey_king.h \
    pigsy.h \
    monk_sha.h \
    gnome.h \
    begingame.h \
    endwindow.h

FORMS += \
        mainwindow.ui \
    begingame.ui \
    endwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    media.qrc
