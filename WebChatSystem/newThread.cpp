#include "newThread.h"
#include "CusDaoImp.h"
#include "Custom.h"
#include <QDebug>

newThread::newThread(QTcpSocket* socket, QMainWindow *parent) :
    QThread(parent),
    socket(socket)
{
}

void newThread::run(){
    QObject::connect(socket,SIGNAL(readyRead()),this,SLOT(onRead()));
}

void newThread::onRead()
{
    CusDao* cd = new CusDaoImp();
    Pack pack;
    socket->read(pack.getPack(),sizeof(Pack));
    switch(pack.type){

        case Pack::TYPE_REGIST:
            if(!cd->findCust(pack)) {
                Custom cust(pack.getName(),pack.getPswd(),500,0,"\0");  //注册时初始化用户基本信息
                cd->insertCustomer(cust);
                pack.setText("注册成功");
            } else {
                pack.setText("已被注册，注册失败");
            }
            emit sendMsg(pack);
            break;

        case Pack::TYPE_LOGIN:
            if(!cd->findCust(pack)) {
                pack.setText("该账户不存在");
            } else if(!cd->checkPwd(pack)) {
                pack.setText("密码错误");
            } else {
                pack.setText("登录成功");
            }
            qDebug() << "成功发送包";
            emit sendMsg(pack);
            break;

        case Pack::TYPE_LOGINOK:
            emit upLogin(pack.getName(),1);
            break;

        case Pack::TYPE_LOGINDOWN:
            emit upLogin(pack.getName(),0);
            break;

        case Pack::TYPE_CREATE_ROOM:
            if(!cd->checkRoom(pack)) {
                cd->insertRoom(pack.getText(),pack.getName());
                pack.setText("创建成功");
            } else {
                pack.setText("该房间已存在~");
            }
            emit sendMsg(pack);
            break;

        case Pack::TYPE_SELECT_ROOMS:
            cd->giveRooms(pack);
            emit sendMsg(pack);
            break;

        default:
            break;
    }
}
