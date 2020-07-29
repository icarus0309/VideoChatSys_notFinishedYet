#ifndef CUSDAO_H
#define CUSDAO_H

#include "Custom.h"
#include "Pack.h"
#include <vector>
using namespace std;

class CusDao
{
public:
    CusDao();
    virtual ~CusDao();
    virtual void insertCustomer(const Custom&) = 0;
    virtual void insertRoom(const QString&,const QString&) = 0;
    virtual vector<Custom> selectAllCustomers() = 0;
    virtual bool findCust(Pack&) = 0;
    virtual bool checkPwd(Pack&) = 0;
    virtual bool checkRoom(Pack&) =0;
    virtual void giveRooms(Pack&) =0;
};

#endif // CUSDAO_H
