#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class myThread : public QThread
{
    Q_OBJECT
public:
    explicit myThread(qintptr sd);
    void run(); //线程处理函数

signals:
    void sendToWidget(QByteArray ba);

private slots:
    void clientInfo();

private:
    qintptr sd;
    QTcpSocket *socket;

};

#endif // MYTHREAD_H
