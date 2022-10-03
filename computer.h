#ifndef COMPUTER_H
#define COMPUTER_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QDebug>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

class Computer
{
public:
    Computer();
    Computer(QByteArray &json);
    ~Computer();
    void Printf();
private:
    QJsonDocument JsonDocument;
    QByteArray JsonData;
    QString Name;
    QString CPUName;
    QString GPUName;
    QString MainBoardName;
};

#endif // COMPUTER_H
