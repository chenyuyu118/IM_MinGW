#-------------------------------------------------
#
# Project created by QtCreator 2021-05-24T08:22:14
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IM_MinGW
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
    logindialog.cpp \
    registerdialog.cpp \
    communicatedialog.cpp \
    dialog.cpp \
    mydatabase.cpp \
    imagehelper.cpp \
    cbasechatedit.cpp \
    appimagetypehelper.cpp \
    hashcode.cpp \
    textqjsonhelper.cpp \
    filehelper.cpp \
    emotionitem.cpp \
    emotionwidget.cpp \
    emotionwindow.cpp \
    staticemotionitem.cpp \
    addfrienddialog.cpp \
    messagelistdelegate.cpp \
    messagedelegate.cpp

HEADERS += \
        mainwindow.h \
    logindialog.h \
    registerdialog.h \
    communicatedialog.h \
    dialog.h \
    mydatabase.h \
    imagehelper.h \
    cbasechatedit.h \
    appimagetypehelper.h \
    hashcode.h \
    textqjsonhelper.h \
    filehelper.h \
    emotionitem.h \
    emotionwidget.h \
    emotionwindow.h \
    staticemotionitem.h \
    addfrienddialog.h \
    package.h \
    messagelistdata.h \
    messagelistdelegate.h \
    messagedata.h \
    messagedelegate.h

FORMS += \
        mainwindow.ui \
    logindialog.ui \
    register.ui \
    dialog.ui \
    communicatedialog.ui \
    settingdialog.ui \
    addfriend.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    rsc.qrc \
    resource.qrc

DESTDIR += bin


include(./netapi/netapi.pri)
INCLUDEPATH += $$PWD/netapi
