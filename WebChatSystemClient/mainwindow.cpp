#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ChatRoom.h"

#include <QHostAddress>
#include <QMessageBox>
#include <string.h>
#include <QDebug>
#include <QCloseEvent>
#include "HomeThread.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    QObject::connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onError(QAbstractSocket::SocketError)));

    //socket->connectToHost(QHostAddress("127.0.0.1"),8888);

    //创建线程收包
    HomeThread* hth = new HomeThread(socket,this);
    QObject::connect(hth,SIGNAL(login_ok()),this,SLOT(loginSuccess()));

    //自动释放线程cth
    QObject::connect(socket,SIGNAL(disconnected()),hth,SLOT(deleteLater()));
    hth->start();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete socket;
}

/*注册按钮槽*/
void MainWindow::on_btn_regis_clicked()
{
    Pack pack;
    pack.type = Pack::TYPE_REGIST;
    QString name = ui->le_name->text();
    QString pwd  = ui->le_pwd->text();

    pack.setName(name);
    pack.setPswd(pwd);

    socket->write(pack.getPack(),sizeof(pack));

}

/*登录按钮槽*/
void MainWindow::on_btn_login_clicked()
{ 
    socket->connectToHost(QHostAddress("127.0.0.1"),8888);
    Pack pack;
    pack.type = Pack::TYPE_LOGIN;
    name = ui->le_name->text();                      //从界面读取信息
    QString pwd = ui->le_pwd->text();

    pack.setName(name);                              //初始化发送信息
    pack.setPswd(pwd);
    pack.setLogin(0);
    socket->write(pack.getPack(),sizeof(pack));      //传送至服务器
    //qDebug() << "此时客户端的套接字：" << socket;      //验证一
}

/*登录成功*/
void MainWindow::loginSuccess()//login_ok
{
    Pack pack;
    QString name = ui->le_name->text();
    pack.setName(name);
    pack.type = Pack::TYPE_LOGINOK;
    socket->write(pack.getPack(),sizeof(pack));                //传送至服务器，告诉服务器该用户已经登录

    Live* live = NULL;
    ChatRoom* cr = new ChatRoom(name,live,this);               //创建登录界面
    QObject::connect(this,SIGNAL(sendToLogin(const Pack*)),cr,SLOT(loginedInRoom(const Pack*)));    //登录信号链接
    QObject::connect(cr,SIGNAL(sign_out()),this,SLOT(signOut()));              //退出登录时要更新服务器信息
    QObject::connect(cr,SIGNAL(closeChatroom()),this,SLOT(showAgain()));       //退出登录链接
    cr->setWindowTitle("狍子聊天室");
    cr->show();                                                //显示第二界面
    this->hide();                                              //隐藏当前界面
}

/*退出登录*/
void MainWindow::signOut()
{
    Pack pack;
    pack.setName(ui->le_name->text());
    pack.type = Pack::TYPE_LOGINDOWN;
    socket->write(pack.getPack(),sizeof(pack));                //传送至服务器
    qDebug() << "我方已退出登录";
}



/*链接服务器发生错误的槽*/
void MainWindow::onError(QAbstractSocket::SocketError skerr)
{
    qDebug() << skerr;
    QMessageBox::critical(this,"警告","无法连接服务器！");
}


void MainWindow::showAgain()
{
    ui->le_pwd->clear();
    this->show();
}

/*直接按下关闭按钮*/
void MainWindow::closeEvent( QCloseEvent * event )
{
   switch( QMessageBox::information( this, tr("Control View"),
            tr("确认退出程序?"),
            tr("Yes"), tr("No"),
            0, 1 ) )
    {
       case 0:
           event->accept();
           break;
       case 1:
       default:
           event->ignore();
           break;
    }
}
