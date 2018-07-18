#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "document.h"
#include "socketdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void receiveCommand(const QString& text);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    document *m_content;
    socketDialog* m_socketDlg;
    QString m_command;
};

#endif // MAINWINDOW_H
