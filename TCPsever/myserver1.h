#ifndef MYSERVER1_H
#define MYSERVER1_H

#include <QObject>
#include <QWidget>
#include <QTcpServer>

class myServer1 : public QTcpServer
{
    Q_OBJECT
public:
    explicit myServer1(QObject *parent = nullptr);

signals:

};

#endif // MYSERVER1_H
