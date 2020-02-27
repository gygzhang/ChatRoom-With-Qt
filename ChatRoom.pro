#-------------------------------------------------
#
# Project created by QtCreator 2015-08-19T17:49:47
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChatRoom
TEMPLATE = app

CONFIG+=c++11

SOURCES += main.cpp\
        widget.cpp \
    chat_face.cpp \
    myQlable.cpp \
    login.cpp

HEADERS  += widget.h \
    chat_face.h \
    myQlable.h \
    login.h

FORMS    += widget.ui \
    chat_face.ui \
    login.ui



RESOURCES += \
    image_resouce.qrc
