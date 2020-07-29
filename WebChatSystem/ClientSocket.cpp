#include "ClientSocket.h"
#include <QDebug>
#include "SocketManager.h"

ClientSocket::ClientSocket(QTcpSocket* socket, QObject *parent) :
    QObject(parent),socket(socket)
{
    QObject::connect(socket,SIGNAL(readyRead()),
                     this,SLOT(onReadyRead()));
}

void ClientSocket::onReadyRead()
{

}
