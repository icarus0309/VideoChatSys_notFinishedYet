#include "DBHelper.h"

#include <QDebug>

DBHelper* DBHelper::instance = 0;

DBHelper* DBHelper::getInstance(){
    if(0==instance){
        instance = new DBHelper();
    }
    return instance;
}

DBHelper::DBHelper()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
}

void DBHelper::createConn(){
    db.setHostName("localHost");
    db.setPort(3306);
    db.setUserName("root");
    db.setPassword("season97");
    db.setDatabaseName("new_wzy");
    if(db.open()==false){
        qDebug() << "open failed";
    }
}

void DBHelper::destroyConn(){
    db.close();
    db.removeDatabase("new_wzy");
}

