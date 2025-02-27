#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>


class myServer:public QTcpServer
{

    Q_OBJECT
public:
    explicit myServer(QObject *parent = nullptr);
protected:
    void incomingConnection(qintptr socketDescriptor)override;//重写父类中的保护虚函数


    ~myServer();
signals:
    void sig_sendsd(qintptr descriptor);
};

#endif // MYSERVER_H
