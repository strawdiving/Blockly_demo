#include "webobject.h"
#include <QDebug>

WebObject::WebObject(QObject *parent) : QObject(parent)
{

}

void WebObject::receiveText(const QString& text)
{
    emit commandReceived(text);
}

void WebObject::sendCommand(const QString& text)
{
    emit sendText(text);
}
