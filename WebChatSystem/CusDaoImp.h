#ifndef CUSDAOIMP_H
#define CUSDAOIMP_H

#include "CusDao.h"
#include "Pack.h"
#include <iostream>

class CusDaoImp : public CusDao
{
public:
    CusDaoImp();
    void insertCustomer(const Custom&);
    void insertRoom(const QString&,const QString&);
    vector<Custom> selectAllCustomers();
    bool findCust(Pack&);
    bool checkPwd(Pack&);
    bool checkRoom(Pack&);
    void giveRooms(Pack&);
};

#endif // CUSDAOIMP_H
