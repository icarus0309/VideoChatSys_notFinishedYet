#include "HomeThread.h"
#include "Pack.h"
#include "ChatRoom.h"
#include <QMessageBox>

HomeThread::HomeThread(QTcpSocket* socket,QWidget* parent):
    QThread(parent),
    socket(socket)
{
}

void HomeThread::run()
{
    QObject::connect(socket,SIGNAL(readyRead()),this,SLOT(onRead()));
}

void HomeThread::onRead()
{
    qDebug() << "我方已经成功接收到信息";
    QByteArray bytearry;
    bytearry.resize(socket->bytesAvailable());                  //这三行都是读取出服务器发来的包
    bytearry = socket->readAll();

    const  Pack* ppack = (const Pack*)(bytearry.data());
    QString text = ppack->getText();
    QMessageBox msgBox;                                         //创建对话框
    msgBox.setSizeIncrement(200,150);
    msgBox.setText(text);

    if(ppack->type == Pack::TYPE_REGIST) {
        msgBox.setWindowTitle("Regist");                                //显示注册信息弹窗
        msgBox.exec();
    } else if(ppack->type == Pack::TYPE_LOGIN) {
        msgBox.setWindowTitle("Login");                                 //显示登录信息弹窗
        msgBox.exec();
        if(text == "登录成功") {
            emit login_ok();
        }
    }

}
