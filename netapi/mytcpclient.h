#ifndef QTCPCLIENT_H
#define QTCPCLIENT_H

#include <QObject>
#include"tcpnet.h"

class MyTcpClient : public QObject,public ITcpMediator
{
    Q_OBJECT
public:
    explicit MyTcpClient(QObject *parent = 0);
    ~MyTcpClient();
signals:
    void SIG_ReadyData( char* szbuf , int nLen );
public slots:
    bool InitNetWork(char* szBufIP , unsigned short port);
    void UnInitNetWork();
    int SendData(char* szbuf,int nLen);
    int ConnectToServer( char* szBufIP);
    void DealData(char* szbuf , int nLen);
public:
    TCPNet *m_pTcp;

};

#endif // QTCPCLIENT_H
