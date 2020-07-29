#ifndef DBHELPER_H
#define DBHELPER_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class DBHelper
{
    static DBHelper* instance;
    DBHelper();
public:
    QSqlDatabase db;
    static DBHelper* getInstance();
    void createConn();
    void destroyConn();
    void insertCostom(const QString&id, const QString& name, const QString& pwd, const QString& money);
    void insertRoom(const QString& id,const QString& name, const QString& master);

};

#endif // DBHELPER_H
