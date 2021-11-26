#include "mytcpclient.h"
#include <QDebug>

MyTcpClient::MyTcpClient(QObject *parent) : QObject(parent)
{
    m_pTcp = new TCPNet(this);
}

MyTcpClient::~MyTcpClient()
{
    m_pTcp->UnInitNetWork();
}

bool MyTcpClient::InitNetWork(char* szBufIP , unsigned short port)
{
    return m_pTcp->InitNetWork(szBufIP,port);
}



void MyTcpClient::UnInitNetWork()
{
    m_pTcp->UnInitNetWork();
}

int MyTcpClient::SendData(char* szbuf,int nLen)
{
    return m_pTcp->SendData(szbuf,nLen);
}

int MyTcpClient::ConnectToServer( char* szBufIP)
{
    return m_pTcp->ConnectToServer(szBufIP);
}


void MyTcpClient::DealData(char* szbuf , int nLen)
{
    qDebug()<<"DealData";
    emit SIG_ReadyData(szbuf,nLen);
}


