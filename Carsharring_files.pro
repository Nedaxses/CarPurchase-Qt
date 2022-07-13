#-------------------------------------------------
#
# Project created by QtCreator 2022-06-19T14:35:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Carsharring_files
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    addmoney.cpp \
    mainmenu2.cpp \
    changepass.cpp \
    audi.cpp \
    newcar.cpp \
    mercedes.cpp \
    bmw.cpp

*gcc*:QMAKE_CXXFLAGS += -std=c++11

HEADERS  += mainwindow.h \
    addmoney.h \
    mainmenu2.h \
    changepass.h \
    audi.h \
    newcar.h \
    mercedes.h \
    bmw.h

FORMS    += mainwindow.ui \
    addmoney.ui \
    mainmenu2.ui \
    changepass.ui \
    audi.ui \
    newcar.ui \
    mercedes.ui \
    bmw.ui

RESOURCES += \
    src.qrc \
    qss.qrc
