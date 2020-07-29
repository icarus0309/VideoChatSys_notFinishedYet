#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include "newThread.h"
#include "ClientSocket.h"
#include "Pack.h"
#include "DBHelper.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btn_listen_clicked();
    void on_btn_selectall_clicked();
    void onNewConnection();
    void onSigWrite(Pack);
    void on_btn_selectrooms_clicked();
    void upDBLogin(QString,int);

private:
    Ui::MainWindow *ui;
    QTcpServer* server;
    QTcpSocket* socket;
    QVector<QTcpSocket*> v_soc;
    newThread* thread;

};
#endif // MAINWINDOW_H
