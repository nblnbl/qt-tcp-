#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QDebug>
#include <chat.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void onConnected();
    void onDisconnected();

private slots:
    void connect_click();

private:
    Ui::Widget *ui;
    QTcpSocket *socket;
    Chat *c;
};
#endif // WIDGET_H
