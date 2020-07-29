#ifndef CHATROOM_H
#define CHATROOM_H

#include <QMainWindow>
#include "Pack.h"
#include "Live.h"
#include "DialogCreLive.h"

namespace Ui {
class ChatRoom;
}

class ChatRoom : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChatRoom( QString cust_name,Live* live,QWidget *parent = nullptr);
    void closeEvent( QCloseEvent * event );
    void allowedCreate();
    ~ChatRoom();

private:
    Ui::ChatRoom *ui;
    Live* live;
    QString cust_name;
    const Pack* ppack;
    QTcpSocket* cm_socket;
signals:
    void sign_out();
    void closeChatroom();               //关闭当前对象
    void sendAskInfo(const QString&);   //
    void showRooms();                   //发出查询现有房间的请求
public slots:
    void loginedInRoom(const Pack*);
    void askTcpCreate(const QString&);
    void updateRooms(map<QString,QString>& );

private slots:
    void onRead();                      //服务器发来消息
    void on_btn_exit_clicked();
    void on_btn_cre_r_clicked();

    void on_btn_show_r_clicked();
    void showAgain();                       //重新显示
    void createRoomLive(const QString&);    //创建房间
    void selectRoomLive();                  //显示所有房间
};

#endif // CHATROOM_H
