#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CusDaoImp.h"
#include "SocketManager.h"
#include "newThread.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = new QTcpServer(this);

    SocketManager* sm = SocketManager::getInstance();

    QObject::connect(sm, SIGNAL(sigWrite(QString, QTcpSocket*)),this,SLOT(onSigWrite(QString, QTcpSocket*)));

    QObject::connect(server, SIGNAL(newConnection()),this, SLOT(onNewConnection()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_listen_clicked()
{
    if(server->isListening()){
        ui->te_show_1->append("already listening...");
        return;
    }
    if(server->listen(QHostAddress("127.0.0.1"),8888)){
        ui->te_show_1->append("listen success");
    }else{
        ui->te_show_1->append("listen failed");
    }
}

/*有新的套接字接入*/
void MainWindow::onNewConnection()
{
    ui->te_show_1->append("someone connected");
    socket = new QTcpSocket(this);
    socket = server->nextPendingConnection();
    qDebug() << "此时连接上来的套接字：" <<socket;
    ClientSocket* cs = new ClientSocket(socket);

    SocketManager* sm = SocketManager::getInstance();
    sm->addSocket(socket);

    thread = new newThread(socket,this);

    QObject::connect(socket,SIGNAL(disconnected()),cs,SLOT(deleteLater()));

    QObject::connect(socket,SIGNAL(disconnected()),thread,SLOT(quit()));

    QObject::connect(thread,SIGNAL(sendMsg(Pack)),this,SLOT(onSigWrite(Pack)));

    QObject::connect(thread,SIGNAL(upLogin(QString,int)),this,SLOT(upDBLogin(QString,int)));

    thread->start();
}

/*将包发回给客户端*/
void MainWindow::onSigWrite(Pack pack)
{
    //qDebug() << pack.getName() << "正在返回信息：" << pack.getText();
    socket->write(pack.getPack(),sizeof(Pack));         //写pack给客户端
}

/*显示本地所有用户的信息--镜像：显示所有聊天房间的方法属于客户端*/
void MainWindow::on_btn_selectall_clicked()
{
    ui->te_show_2->clear();
    ui->te_show_2->append("账户名\t密码\t余额\t在线状态");

    CusDao* cd = new CusDaoImp();
    vector<Custom> custs = cd->selectAllCustomers();
    for(auto& it: custs) {
        QString ret;
        ret += it.getName();
        ret += "\t";
        ret += it.getPwd();
        ret += "\t";
        ret += QString::number(it.getMoney());
        ret += "\t";
        ret += QString::number(it.getIslogin());
        ui->te_show_2->append(ret);
    }
}

/*更新登录状态*/
void MainWindow::upDBLogin(QString name,int islogin)
{
    qDebug() << name+"登录/下线了";
    DBHelper* helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query;
    query.prepare("update customs set cust_islogin=:islogin where cust_name=:name;");
    query.bindValue(":islogin",islogin);
    query.bindValue(":name",name);
    query.exec();
    helper->destroyConn();
}



void MainWindow::on_btn_selectrooms_clicked()
{
     ui->te_show_3->clear();
     ui->te_show_3->append("房间名\t房主\t人数");

     DBHelper* helper = DBHelper::getInstance();
     helper->createConn();
     QSqlQuery query;
     query.exec("select room_name,room_master,room_pnum from rooms;");
     while(query.next()){
         QString ret;
         ret += query.value(0).toString();
         ret += "\t";
         ret += query.value(1).toString();
         ret += "\t";
         ret += QString::number(query.value(2).toInt());
         ui->te_show_3->append(ret);
     }
     helper->destroyConn();
}
