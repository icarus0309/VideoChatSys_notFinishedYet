#ifndef NEWTHREAD_H
#define NEWTHREAD_H

#include <QMainWindow>
#include <QThread>
#include <QTcpSocket>
#include "Pack.h"
//#include "PackVector.h"

class newThread : public QThread
{
    Q_OBJECT
private:
    QTcpSocket* socket;
public:
    explicit newThread(QTcpSocket* socket,QMainWindow* parent = 0);
protected:
    virtual void run();
signals:
    void sendMsg(Pack);
    void upLogin(QString,int);
public slots:
    void onRead();
};

#endif // NEWTHREAD_H
