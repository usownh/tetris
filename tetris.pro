#-------------------------------------------------
#
# Project created by QtCreator 2014-10-11T15:14:47
#
#-------------------------------------------------

QT       += core gui
QT += widgets
TARGET = tetris
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    cube.cpp \
    tetrisscene.cpp \
    item.cpp

HEADERS  += mainwindow.h \
    cube.h \
    tetrisscene.h \
    item.h

FORMS    += mainwindow.ui
