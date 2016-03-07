#-------------------------------------------------
#
# Project created by QtCreator 2016-02-15T14:58:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CS076_GUI
TEMPLATE = app


SOURCES +=\
    ZorkUL_GUI.cpp \
    Room.cpp \
    Item.cpp \
    Character.cpp \
    ZorkUL.cpp \
    Characterdisplay.cpp \
    Control.cpp \
    Map.cpp \
    Question.cpp \
    MainWindow.cpp

HEADERS  += \
    Room.h \
    Item.h \
    Character.h \
    ZorkUL.h \
    Characterdisplay.h \
    Control.h \
    Map.h \
    Question.h \
    MainWindow.h

FORMS    += mainwindow.ui \
    map.ui \
    characterdisplay.ui \
    control.ui

RESOURCES += \
    images.qrc \
    styleSheets.qrc \
    newImages.qrc

OTHER_FILES += \
    img/control.jpg \
    img/char9.jpg \
    img/char8.jpg \
    img/char7.jpeg \
    img/char6.jpg \
    img/char5.jpg \
    img/char4.jpg \
    img/char3.jpg \
    img/char2.jpg \
    img/char1.jpg \
    img/AI.jpg
