#-------------------------------------------------
#
# Project created by QtCreator 2017-11-02T12:46:56
#
#-------------------------------------------------

QT       += core gui multimedia sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testTask
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    gamewindow.cpp \
    subject.cpp \
    subjectwidget.cpp \
    tablewidget.cpp \
    inventorycell.cpp \
    inventory.cpp \
    subjectapple.cpp \
    subjectfactory.cpp \
    database.cpp \
    subjectmapper.cpp \
    inventorycellmapper.cpp \
    inventorymapper.cpp

HEADERS += \
        mainwindow.h \
    gamewindow.h \
    subject.h \
    subjectwidget.h \
    tablewidget.h \
    inventorycell.h \
    inventory.h \
    subjectapple.h \
    subjectfactory.h \
    database.h \
    subjectmapper.h \
    inventorycellmapper.h \
    inventorymapper.h

FORMS += \
        mainwindow.ui \
    gamewindow.ui

RESOURCES += \
    resources.qrc

DISTFILES +=
