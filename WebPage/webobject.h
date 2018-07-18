#ifndef WEBOBJECT_H
#define WEBOBJECT_H

#include <QObject>

class WebObject : public QObject
{
    Q_OBJECT
public:
    explicit WebObject(QObject *parent = 0);

signals:
    void sendText(const QString &text);
    void commandReceived(const QString& text);


public slots:
    void sendCommand(const QString &text);
    void receiveText(const QString& text);
};

#endif // WEBOBJECT_H
