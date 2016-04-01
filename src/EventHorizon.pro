#-------------------------------------------------
#
# Project created by QtCreator 2016-03-26T20:30:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EventHorizon
TEMPLATE = app


SOURCES += ZorkUL_GUI.cpp \
    ZorkUL.cpp \
    Room.cpp \
    Question.cpp \
    Map.cpp \
    MainWindow.cpp \
    MainCharacter.cpp \
    Item.cpp \
    Control.cpp \
    Characterdisplay.cpp \
    Character.cpp \
    Challenger.cpp

HEADERS  += ZorkUL.h \
    Room.h \
    Question.h \
    Map.h \
    MainWindow.h \
    MainCharacter.h \
    Item.h \
    Control.h \
    Characterdisplay.h \
    Character.h \
    Challenger.h

FORMS    += \
    map.ui \
    control.ui \
    characterdisplay.ui \
    mainwindow.ui \


RESOURCES += \
    styleSheets.qrc \
    newImages.qrc \
    images.qrc

OTHER_FILES += \
    EventHorizon.pro.user
