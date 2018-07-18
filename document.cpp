#include "document.h"
#include <QDebug>

document::document(QObject *parent) : QObject(parent)
{

}

void document::receiveText(const QString& text)
{
    //qDebug()<<text;
    emit commandReceived(text);
}
