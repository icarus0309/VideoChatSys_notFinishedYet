#ifndef CUSTOM_H
#define CUSTOM_H

#include <QString>

class Custom
{
    QString name;
    QString pwd;
    int money;
    int islogin;
    QString room;
public:
    Custom();
    Custom(QString name,QString pwd,float money,int islogin,QString room);

    void setName(QString name){this->name = name;}
    void setPwd(QString pwd){this->pwd = pwd;}
    void setMoney(int money){this->money = money;}
    void setIslogin(int islogin){this->islogin = islogin;}
    void setRoom(QString room){this->room = room;}

    QString getName()const;
    QString getPwd()const;
    int getMoney()const;
    int getIslogin()const;
    QString getRoom()const;
};

#endif // CUSTOM_H
