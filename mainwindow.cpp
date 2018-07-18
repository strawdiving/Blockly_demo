#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebEngineView>
#include <QWebChannel>
#include <QHBoxLayout>
#include <QDir>
#include <QFile>
#include <QTextStream>
QString fileSavePath = "C:\\SiasunRobot";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //webview to display html
    QWebEngineView* view = new QWebEngineView(parent);
    view->load(QUrl("qrc:/web/WebPage/playground - test.html"));

    ui->gridLayout1->addWidget(view,1,1,1,1);

    //help Qt interact with javascript
    QWebChannel* channel = new QWebChannel(this);
    m_content = new document(this);
    //register object. id "content" should be the same with the object name in js
    channel->registerObject(QStringLiteral("content"),m_content);
    // object to interact with javascript with QWebChannel

    view->page()->setWebChannel(channel);
    connect(m_content,&document::commandReceived,this,&MainWindow::receiveCommand);

    m_socketDlg = new socketDialog(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveCommand(const QString& text)
{
    m_command = text;
    qDebug()<<text;
    if(text == "stop") {
        //on_programButton_clicked();
        return;
    }

    QDir myDir(fileSavePath + "\\program");
    if(!myDir.exists()) {
        qDebug()<<"no exist";
        myDir.mkdir(myDir.absolutePath());
    }

    QString programName =myDir.absolutePath()  + "\\webCommand.txt";
    QFile programFile(programName);

    if(programFile.exists()) {
        qDebug()<<"already exist";
        programFile.resize(0);
     }
    else {
        //delete all the existing items
        //ui->programTree->clear();
}
    //write content to command file
    if (!programFile.open(QIODevice::ReadWrite | QIODevice::Truncate)) return;
    QByteArray content(text.toLocal8Bit());
    programFile.write(content);


        //show program name
      /*  QStringList pieces = programName.split("/");
        ui->programNameLabel->setText(pieces.value(pieces.size() - 1));

        QTreeWidgetItem *itm = new QTreeWidgetItem(ui->programTree);
        itm->setText(0, "Start");
        QSize size; size.setHeight(programLineHeight);
        itm->setSizeHint(0,size);

        //set warning icon
        QPixmap pixmap(":/images/node_warning.png");
        QIcon ButtonIcon(pixmap);
        itm->setIcon(0,ButtonIcon);

        ui->programTree->addTopLevelItem(itm);

        //save the program in the tree into a file
        QTextStream stream( &programFile );
        stream << ui->programTree->topLevelItem(0)->text(0) + ";" << endl;

        //clean the ancient recover files in SiasunRobot folder(old_X)
        progBackupPtr = 0;
        for(int i = 0; i < 10; i++){
            QFile file(fileSavePath + "\\old_" + QString::number(i));
            file.remove();
        }
        progBackupPtrMax = 0;

        //change the current tree index to 0 (if no element selected, it can cause qTreeWidget crash)
        ui->programTree->setCurrentIndex(ui->programTree->model()->index(0, 0));

        //save the current position to the Start node
        on_saveNodeButton_clicked();

        on_runButton_clicked();

        //save the program
        saveProgramHandler(programName);
    }
    */
}

void MainWindow::on_pushButton_clicked()
{
    m_socketDlg->setCommand(m_command);
    m_socketDlg->exec();
}
