#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , socket(new QTcpSocket(this))  // 初始化 socket
{
    ui->setupUi(this);

    // 在构造函数中连接信号
    connect(ui->connectButton, &QPushButton::clicked, this, &Widget::connect_click);
    connect(socket, &QTcpSocket::connected, this, &Widget::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &Widget::onDisconnected);
    qDebug()<< "构造函数被调用";
}

Widget::~Widget()
{
    delete ui;
    delete socket;
    delete c;
}

void Widget::connect_click()
{
    // 获取IP地址和端口号
    QString IP = ui->ipLineEdit->text();
    QString port = ui->portLineEdit->text();

    // 连接服务器
    socket->connectToHost(QHostAddress(IP), port.toShort());
}

void Widget::onConnected()
{
    QMessageBox::information(this, "连接提示", "连接服务器成功");
    qDebug() << "连接成功";

    this->hide();
    //堆空间创建
    c = new Chat(socket);
    c->show();
}

void Widget::onDisconnected()
{
    QMessageBox::information(this, "连接提示", "连接服务器断开");
}
