#include "SocketManager.h"
#include <QDebug>
SocketManager* SocketManager::instance = 0;

SocketManager* SocketManager::getInstance()
{
    if(0==instance)
        instance = new SocketManager();
    return instance;
}


SocketManager::SocketManager(QObject *parent) : QObject(parent)
{
}


void SocketManager::addSocket(QTcpSocket* socket)
{
    sockets.push_back(socket);
}

void SocketManager::sendDataToAll(Pack& pack, int len)
{
    vector<QTcpSocket*>::iterator it;
    for(it = sockets.begin(); it!=sockets.end(); it++) {
        QTcpSocket* socket = *it;
        emit sigWrite(socket,pack,len);
    }
}
