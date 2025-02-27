#include "widget.h"
#include "ui_widget.h"
#include "mythread.h"
#include "myserver.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    myServer *server = new myServer(this);
//    server = new QTcpServer;

    server->listen(QHostAddress::AnyIPv4, 8000);
    qDebug() << "myThread is running in thread:" << QThread::currentThreadId();

    //客户端发起连接，server发出信号
    connect(server, SIGNAL(sig_sendsd(qintptr)), this, SLOT(slot_recv_sd(qintptr)));
}

Widget::~Widget()
{
    delete ui;
//    delete server;
}
void Widget::slot_recv_sd(qintptr sd)
{
    qDebug() << "myThread is running in thread:" << sd;
    myThread *t = new myThread(sd);
    t->start();
//    ui->ipLineEdit->setText(socket->peerAddress().toString());
//    ui->portLineEdit->setText(QString::number(socket->peerPort()));
    connect(t, &myThread::sendToWidget, this, &Widget::threadSlotSend);


}





void Widget::newClientInformtion()
{
    //获取信号的发出者
    QTcpSocket *socket = (QTcpSocket *)sender();
    ui->lineEdit->setText(QString::fromUtf8(socket->readAll()));
}

void Widget::threadSlotSend(QByteArray ba)
{
    qDebug() << "myThread is running in thread:" << ba;
    ui->lineEdit->setText(QString::fromUtf8(ba));
}

