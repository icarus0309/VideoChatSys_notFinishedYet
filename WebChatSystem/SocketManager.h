#ifndef SOCKETMANAGER_H
#define SOCKETMANAGER_H

#include <QObject>
#include <QTcpSocket>
#include <vector>
#include "Pack.h"

using namespace std;
class SocketManager : public QObject
{
    Q_OBJECT
private:
    explicit SocketManager(QObject *parent = nullptr);
    static SocketManager* instance;
    vector<QTcpSocket*> sockets;
public:
    static SocketManager* getInstance();
    void addSocket(QTcpSocket* socket);
    void sendDataToAll(Pack&, int len);
signals:
    void sigWrite(QTcpSocket* socket, Pack&, int len);
};

#endif // SOCKETMANAGER_H
