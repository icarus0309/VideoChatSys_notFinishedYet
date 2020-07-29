#include "Custom.h"

Custom::Custom()
{
}

Custom::Custom(QString name,QString pwd,float money,int islogin,QString room):
        name(name),pwd(pwd),money(money),islogin(islogin),room(room)
{
}

QString Custom::getName()const
{
    return name;
}

QString Custom::getPwd()const
{
    return pwd;
}

int Custom::getMoney()const
{
    return money;
}

int Custom::getIslogin()const
{
    return islogin;
}

QString Custom::getRoom()const
{
    return room;
}
