#-------------------------------------------------
#
# Project created by QtCreator 2016-03-21T21:33:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QStickyButton
TEMPLATE = app

INCLUDEPATH += source ui

SOURCES += source/src/main.cpp \
    source/src/MainWindow.cpp \
    source/src/QStickyButton.cpp

HEADERS  += source/MainWindow.h \
    source/QStickyButton.h

FORMS    += ui/MainWindow.ui \
    ui/QStickyButton.ui

RESOURCES += \
    QStickyButton.qrc
