#include "computer.h"

Computer::Computer()
{

}

Computer::Computer(QByteArray &json)
{
    QJsonParseError JsonParseError;
    QByteArray json_ = json.mid(json.indexOf("{"));
    JsonDocument = QJsonDocument::fromJson(json_, &JsonParseError);
    if (JsonParseError.error == QJsonParseError::NoError)
    {
        qDebug() << "Computer parse json success!";
    }
    else
    {
        qDebug() << "Computer parse json error!" + JsonParseError.errorString();
        return;
    }
}

void Computer::Printf()
{
    qDebug() << Name;
    qDebug() << CPUName;
    qDebug() << GPUName;
    qDebug() << MainBoardName;
}
