#ifndef PACK_H
#define PACK_H
#include <QString>
#include <QTcpSocket>
#include <string.h>
#include <iostream>

using namespace std;

class Pack{
private:
    char name[20];              //用户名
    char pswd[20];              //密码
    char text[200];             //写信息
    int money;                  //余额
    map<QString,QString> v_rooms;      //存放房间名和房主名
    int islogined;             //用户是否处于登录状态
    char room[20];             //用户所在房间的名字，只有登录状态为1时这个才有可能不为空
    QTcpSocket* socket;
public:
    Pack();

    enum Type{
        TYPE_REGIST,            //注册
        TYPE_LOGIN,             //登录
        TYPE_LOGINOK,           //登录成功（为了更新登录状态）
        TYPE_LOGINDOWN,         //退出登录
        TYPE_CREATE_ROOM,       //创建房间
        TYPE_SELECT_ROOMS       //查询房间
    }type;

    QString getName()const{return QString::fromLocal8Bit(name);}

    void setName(QString name){
        char* str = name.toLocal8Bit().data();
        strcpy(this->name,str);
    }

    QString getPswd()const{return QString::fromLocal8Bit(pswd);}

    void setPswd(QString pswd){
        char* str = pswd.toLocal8Bit().data();
        strcpy(this->pswd,str);
    }

    QString getText()const{return QString::fromLocal8Bit(text);}

    void setText(QString text){
        char* str = text.toLocal8Bit().data();
        strcpy(this->text,str);
    }

    int getMoney()const{return money;}

    void setMoney(int money) {
        this->money = money;
    }

    QString getRoom()const{return QString::fromLocal8Bit(room);}

    void setRoom(QString room){
        char* str = room.toLocal8Bit().data();
        strcpy(this->room,str);
    }


    map<QString,QString> getRooms()const{return v_rooms;}

    void setRooms(map<QString,QString> v){
        this->v_rooms = v;
    }

    int getLogin()const{return islogined;}

    void setLogin(int flag){
        this->islogined = flag;
    }

    QTcpSocket* getSocket(){return socket;}
    void setSocket(QTcpSocket* socket){this->socket = socket;}

    char* getPack()const{
        return (char*)this;
    }
};
#endif // PACK_H
