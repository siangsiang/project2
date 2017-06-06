#-------------------------------------------------
#
# Project created by QtCreator 2017-06-04T00:48:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project22
TEMPLATE = app


SOURCES += main.cpp \
    Bullet.cpp \
    Game.cpp \
    Tower.cpp \
    Enemy.cpp

HEADERS  += \
    Bullet.h \
    Tower.h \
    Game.h \
    Enemy.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
