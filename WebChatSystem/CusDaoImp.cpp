#include "CusDaoImp.h"
#include "DBHelper.h"
#include <QVariant>     //这是啥。。。好神奇的功能
#include <QDebug>
#include <vector>

using namespace std;

CusDaoImp::CusDaoImp()
{
}

void CusDaoImp::insertCustomer(const Custom& custom)
{
    DBHelper* helper = DBHelper::getInstance();
    helper->createConn();                           //打开本地的数据库
    QSqlQuery query;
    query.prepare("insert into customs(cust_name,cust_pwd,cust_money,cust_islogin,cust_room) values(:cust_name,:cust_pwd,:cust_money,0,:cust_room);");
    query.bindValue(":cust_name" , custom.getName() );
    query.bindValue(":cust_pwd"  , custom.getPwd()  );
    query.bindValue(":cust_money", custom.getMoney());
    query.bindValue(":cust_room",  custom.getRoom() );
    bool ret = query.exec();
    if(!ret){
        const QSqlError& error = query.lastError();
        qDebug() << error.text();
    }
    helper->destroyConn();
}


void CusDaoImp::insertRoom(const QString& name,const QString& master)
{
    DBHelper* helper = DBHelper::getInstance();
    helper->createConn();                           //打开本地的数据库
    QSqlQuery query;
    query.prepare("insert into rooms(room_name,room_master,room_pnum) values(:room_name,:room_master,1);");
    query.bindValue(":room_name" , name   );
    query.bindValue(":room_master", master );
    bool ret = query.exec();
    if(!ret){
        const QSqlError& error = query.lastError();
        qDebug() << error.text();
    }
    helper->destroyConn();
}


vector<Custom> CusDaoImp::selectAllCustomers()
{
    DBHelper* helper = DBHelper::getInstance();
    vector<Custom> cus;
    helper->createConn();
    QSqlQuery query;
    query.exec("select cust_name,cust_pwd,cust_money,cust_islogin,cust_room from customs;");
    while(query.next()){
        QString name = query.value(0).toString();
        QString pwd  = query.value(1).toString();
        float money  = query.value(2).toInt();
        int islogin = query.value(3).toInt();
        QString room = query.value(4).toString();
        Custom cust(name,pwd,money,islogin,room);
        cus.push_back(cust);
    }
    helper->destroyConn();
    return cus;
}


bool CusDaoImp::findCust(Pack& pack)
{
    DBHelper* helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query;
    query.exec("select cust_name from customs;");
    while(query.next()) {
        QString name = query.value(0).toString();
        if(name == pack.getName()) {
            return true;
        }
    }
    helper->destroyConn();
    return false;
}

bool CusDaoImp::checkPwd(Pack& pack)
{
    DBHelper* helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query;
    query.prepare("select cust_pwd,cust_money from customs where cust_name=:name;");
    query.bindValue(":name",pack.getName());
    qDebug()<<"正在检查 "<<pack.getName()<<" 的密码是否正确";
    query.exec();
    QString pwd;                                                            //将密码和余额作为需要读取的常量
    int money;
    if(query.next()){
        pwd = query.value(0).toString();
        money = query.value(1).toInt();
    }
    helper->destroyConn();
    if(pwd == pack.getPswd()){
        pack.setMoney(money);
        return true;
    }
    return false;
}


bool CusDaoImp::checkRoom(Pack& pack)
{
    DBHelper* helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query;
    query.exec("select room_name from rooms;");
    while(query.next()) {
        QString name = query.value(0).toString();
        if(name == pack.getText()) {                    //用text[]来存储房间名字
            return true;
        }
    }
    helper->destroyConn();
    return false;
}



/*将所有的现存房间存入pack*/
void CusDaoImp::giveRooms(Pack& pack)
{
    map<QString,QString> v_rooms;
    DBHelper* helper = DBHelper::getInstance();
    helper->createConn();
    QSqlQuery query;
    query.exec("select room_name,room_master from rooms;");
    while(query.next()) {
        QString r_name = query.value(0).toString();
        QString m_name = query.value(1).toString();
        v_rooms.insert(pair<QString,QString>(r_name,m_name));
    }
    pack.setRooms(v_rooms);
    helper->destroyConn();
}
