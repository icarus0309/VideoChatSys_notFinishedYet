#ifndef HOMETHREAD_H
#define HOMETHREAD_H

#include <QThread>
#include <QMainWindow>
#include <QTcpSocket>

class HomeThread : public QThread
{
    Q_OBJECT
public:
    explicit HomeThread(QTcpSocket* socket,QWidget* parent = 0);
private:
    void run();
    QTcpSocket* socket;
signals:
    void login_ok();
    void sign_down();
private slots:
    void onRead();
};

#endif // HOMETHREAD_H
