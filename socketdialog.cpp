#include "socketdialog.h"
#include "ui_socketdialog.h"
#include <QMessageBox>

socketDialog::socketDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::socketDialog),
    m_tcpSocket(NULL),
    m_socketConnected(false)
{
    ui->setupUi(this);

    m_tcpSocket =  new QTcpSocket(this);
    //connect(m_tcpSocket,&QTcpSocket::disconnected,this,);
    connect(m_tcpSocket,&QTcpSocket::connected,this,&socketDialog::socketConnected);
    connect(m_tcpSocket,&QTcpSocket::disconnected,this,&socketDialog::socketDisconnected);
}

socketDialog::~socketDialog()
{
    delete ui;
}

void socketDialog::on_pushButton_Connect_clicked()
{
    ui->lineEdit_Port->setValidator(new QIntValidator(1, 65535, this));

    m_tcpSocket->abort();
    m_tcpSocket->connectToHost(ui->lineEdit_Adrress->text(),
                             ui->lineEdit_Port->text().toInt());
    timer = new QTimer();
    connect(timer,&QTimer::timeout,this,&socketDialog::reconnectSocket);
    timer->start(3000);
}

void socketDialog::on_pushButton_DisConnect_clicked()
{
    m_tcpSocket->disconnectFromHost();
}

void socketDialog::reconnectSocket(void)
{
    QMessageBox::warning(this,"Server Unconnected","Can not connect server, retry it please.",QMessageBox::Ok);
}

 void  socketDialog::socketConnected(void)
 {
    timer->stop();
    m_socketConnected = true;
    ui->pushButton_Connect->setEnabled(false);
    ui->pushButton_DisConnect->setEnabled(true);
    //qDebug()<<"socketConnected";
 }

 void  socketDialog::socketDisconnected(void)
 {
    m_socketConnected = false;
     ui->pushButton_Connect->setEnabled(true);
    ui->pushButton_DisConnect->setEnabled(false);
    //qDebug()<<"socketDisconnected";
 }

 void socketDialog::setCommand(const QString& text)
 {
     //qDebug()<<"socketDialog"<<text;
     m_command = text;
     ui->textEdit->append(text);
 }

void socketDialog::on_pushButton_Send_clicked()
{
    if(m_socketConnected) {
        m_tcpSocket->write(m_command.toLocal8Bit().data());
    }
    else {
        QMessageBox::warning(this,"Server Unconnected","You should connect TCP socket first.",QMessageBox::Ok);
    }
}
