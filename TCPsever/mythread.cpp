#include "mythread.h"

myThread::myThread(qintptr sd)
{
    this->sd = sd;
}



void myThread::run()
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(sd);
//    qDebug() << "myThread is running in thread:" << QThread::currentThreadId();
//    connect(socket, SIGNAL(readyRead()), this, SLOT(clientInfo()));
    connect(socket, &QTcpSocket::readyRead, this, [this](){
        qDebug() << "myThread is running in thread:" << QThread::currentThreadId();
        QByteArray ba = socket->readAll();
        emit sendToWidget(ba);

    });
    exec();
}

void myThread::clientInfo()
{

    QByteArray ba = socket->readAll();
    emit sendToWidget(ba);

}
