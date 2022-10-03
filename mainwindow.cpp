#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket, SIGNAL(connected()),
            this, SLOT(connected()));
    connect(tcpSocket, SIGNAL(disconnected()),
            this, SLOT(disconnected()));
    connect(tcpSocket, SIGNAL(readyRead()),
            this, SLOT(receiveMessages()));
    connect(tcpSocket,
            SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,
            SLOT(socketStateChange(QAbstractSocket::SocketState)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_connect_clicked()
{
    qDebug() << "ip: " + this->ui->lineEdit_ip->text();
    qDebug() << "port: " + this->ui->lineEdit_port->text();
    /* 如果连接状态还没有连接 */
    if (tcpSocket->state() != tcpSocket->ConnectedState) {
        /* 指定IP地址和端口连接 */
        tcpSocket->connectToHost(this->ui->lineEdit_ip->text(),
                this->ui->lineEdit_port->text().toUInt());
    }
}

void MainWindow::connected()
{
    qDebug() << "tcp connected";
    this->ui->pushButton_connect->setEnabled(false);
}

void MainWindow::disconnected()
{
    qDebug() << "tcp disconnected";
    this->ui->pushButton_connect->setEnabled(true);
}

/* 客户端接收消息 */
void MainWindow::receiveMessages()
{
    /* 读取接收到的消息 */
    QString messages = tcpSocket->readAll();
    json = messages.toUtf8();
    computer = new Computer(json);
    computer->Printf();
    this->ui->textBrowser_receive->clear();
    this->ui->textBrowser_receive->setText(messages);
    qDebug() << messages ;
}


/* 客户端状态改变 */
void MainWindow::socketStateChange(QAbstractSocket::SocketState state)
{
    switch (state) {
    case QAbstractSocket::UnconnectedState:
        qDebug("scoket状态：UnconnectedState");
        break;
    case QAbstractSocket::ConnectedState:
        qDebug("scoket状态：ConnectedState");
        break;
    case QAbstractSocket::ConnectingState:
        qDebug("scoket状态：ConnectingState");
        break;
    case QAbstractSocket::HostLookupState:
        qDebug("scoket状态：HostLookupState");
        break;
    case QAbstractSocket::ClosingState:
        qDebug("scoket状态：ClosingState");
        break;
    case QAbstractSocket::ListeningState:
        qDebug("scoket状态：ListeningState");
        break;
    case QAbstractSocket::BoundState:
        qDebug("scoket状态：BoundState");
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_send_clicked()
{
    /*
GET /data.json HTTP/1.1
Host: 192.168.2.107:8085
    */
    QString url = "GET /data.json HTTP/1.1\r\n"
                  "Host: 192.168.2.107:8085\r\n"
                  "\r\n\r\n";

    url = "GET /data.json HTTP/1.1\r\n";
    url += ("Host: " + this->ui->lineEdit_ip->text() + ':' + this->ui->lineEdit_port->text() + "\r\n");
    url += "\r\n\r\n";

    if(NULL == tcpSocket)
        return;

    if(tcpSocket->state() == tcpSocket->ConnectedState) {
        /* 发送消息 */
        //tcpSocket->write(this->ui->textEdit_send->toPlainText().toUtf8());
        tcpSocket->write(url.toUtf8());
    }
}
