QT       += network
LIBS += -lpthread libwsock32 libws2_32
LIBS += -lpthread libMswsock libMswsock

HEADERS += \
    $$PWD/tcpnet.h \
    $$PWD/mytcpclient.h

SOURCES += \
    $$PWD/tcpnet.cpp \
    $$PWD/mytcpclient.cpp
