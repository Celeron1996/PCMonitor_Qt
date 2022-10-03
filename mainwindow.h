#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <iostream>
#include <QTcpServer>
#include <QTcpSocket>
#include "computer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    /* qt tcp socket */
    QTcpSocket *tcpSocket;
    /* data json */
    QByteArray json;
    /* computer info */
    Computer *computer;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool ParseJson(QByteArray json);

private slots:
    void on_pushButton_connect_clicked();

    /* 已连接 */
    void connected();

    /* 已断开连接 */
    void disconnected();

    /* 接收到消息 */
    void receiveMessages();

    /* 连接状态改变槽函数 */
    void socketStateChange(QAbstractSocket::SocketState);

    void on_pushButton_send_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
