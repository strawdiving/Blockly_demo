#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QObject>

class document : public QObject
{
    Q_OBJECT
public:
    explicit document(QObject *parent = 0);

signals:
    void commandReceived(const QString& text);

public slots:
    void receiveText(const QString& text);

private:
    QString receive_text;
};

#endif // DOCUMENT_H
