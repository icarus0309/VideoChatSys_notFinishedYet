#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <string.h>
#include "Pack.h"
#include "Live.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    void closeEvent( QCloseEvent * event );
    ~MainWindow();

signals:
    void sendToLogin(const Pack*);
    void giveVectorRooms(map<QString,QString>&);
    void agreeCreateLive();
    void agreeReshow();

private slots:

    void on_btn_regis_clicked();
    void on_btn_login_clicked();
    void loginSuccess(); //登录成功
    void signOut();      //退出登录
    void onError(QAbstractSocket::SocketError skerr);
    void showAgain();

private:

    Ui::MainWindow *ui;
    QTcpSocket* socket;
    QString name;
};

#endif // MAINWINDOW_H
