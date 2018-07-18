#ifndef SOCKETDIALOG_H
#define SOCKETDIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <QTimer>

namespace Ui {
class socketDialog;
}

class socketDialog : public QDialog
{
    Q_OBJECT

public:
    explicit socketDialog(QWidget *parent = 0);
    ~socketDialog();

    void setCommand(const QString& text);

public slots:
    void socketConnected(void);
    void socketDisconnected(void);

private slots:
    void on_pushButton_Connect_clicked();
    void on_pushButton_DisConnect_clicked();
    void on_pushButton_Send_clicked();

    void reconnectSocket(void);

private:
    Ui::socketDialog *ui;
    QTcpSocket* m_tcpSocket;
    bool m_socketConnected;
    QString m_command;
    QTimer* timer;
};

#endif // SOCKETDIALOG_H
