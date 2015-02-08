#-------------------------------------------------
#
# Project created by QtCreator 2014-12-18T16:31:07
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ogonek_uchet
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    editdata.cpp \
    people.cpp \
    sponsors.cpp \
    edirsponsor.cpp \
    paysponsor.cpp \
    pay.cpp \
    humanpay.cpp

HEADERS  += mainwindow.h \
    editdata.h \
    people.h \
    sponsors.h \
    edirsponsor.h \
    paysponsor.h \
    pay.h \
    humanpay.h

FORMS    += mainwindow.ui \
    editdata.ui \
    edirsponsor.ui \
    paysponsor.ui \
    humanpay.ui
