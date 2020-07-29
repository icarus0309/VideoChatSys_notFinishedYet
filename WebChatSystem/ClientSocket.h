#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>

class ClientSocket : public QObject
{
    Q_OBJECT
public:
    explicit ClientSocket(QTcpSocket* socket, QObject *parent = nullptr);
private:
    QTcpSocket* socket;
signals:
    void sigWrite(QTcpSocket* socket,const char* data,int len);             //这里要改
public slots:
    void onReadyRead();

};

#endif // CLIENTSOCKET_H
