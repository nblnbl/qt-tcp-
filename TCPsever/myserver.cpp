#include "myserver.h"

myServer::myServer(QObject *parent) : QTcpServer(parent)
{
}

void myServer::incomingConnection(qintptr socketDescriptor)
{
    emit sig_sendsd(socketDescriptor);  // 发射自定义信号
}

myServer::~myServer()
{

}
