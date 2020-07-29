#include "ChatRoom.h"
#include "ui_ChatRoom.h"
#include <QDebug>
#include <QCloseEvent>
#include <QHostAddress>
#include <QMessageBox>


ChatRoom::ChatRoom( QString cust_name, Live* live, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChatRoom),
    live(live),
    cust_name(cust_name)
{
    ui->setupUi(this);
    cm_socket = new QTcpSocket(this);

    QObject::connect(cm_socket,SIGNAL(readyRead()),this,SLOT(onRead()));

    cm_socket->connectToHost(QHostAddress("127.0.0.1"),8888);
}

ChatRoom::~ChatRoom()
{
    delete ui;
}

void ChatRoom::loginedInRoom(const Pack* ppack)
{
    ui->tb_name->append(ppack->getName());                  //将账户名显示在第二界面
    ui->tb_money->append(tr("%1").arg(ppack->getMoney()));  //将余额显示在第二界面
}

void ChatRoom::on_btn_exit_clicked()
{
    this->deleteLater();                                    //退出时销毁当前窗口
    emit sign_out();
    emit closeChatroom();                                   //发送信号让第一界面显现
    cm_socket->disconnectFromHost();
}

void ChatRoom::on_btn_cre_r_clicked()
{
    DialogCreLive* dlog = new DialogCreLive(this);          //对话框没有父类无法显示
    QObject::connect(dlog,SIGNAL(sendCre(const QString&)),this,SLOT(askTcpCreate(const QString&)));
    dlog->exec();
}

void ChatRoom::askTcpCreate(const QString& room_name)
{
    Pack pack;
    pack.type = Pack::TYPE_CREATE_ROOM;                     //注意登陆成功后不要清空ui里的name，在这里用就很方便

    pack.setText(room_name);                                //将房间名放入text
    pack.setName(cust_name);                                //初始化发送信息
    pack.setLogin(1);                                       //防止重复登录
    cm_socket->write(pack.getPack(),sizeof(pack));          //传送至服务器
}


void ChatRoom::on_btn_show_r_clicked()
{
    emit showRooms();
}


void ChatRoom::updateRooms(map<QString,QString>& v_rooms)
{
    /*
    for(QString & i:v_rooms) {
        ui->list_show->addItem(i);
    }
    */
}

void ChatRoom::closeEvent( QCloseEvent * event )
{
    this->deleteLater();                                    //退出时销毁当前窗口
    emit sign_out();
    emit closeChatroom();
    cm_socket->disconnectFromHost();
    event->accept();
}


void ChatRoom::showAgain()
{
    qDebug() << "卧槽";
    this->show();
}


/*查询房间槽*/
void ChatRoom::selectRoomLive()
{
    Pack pack;
    pack.type = Pack::TYPE_SELECT_ROOMS;                                //这个功能只需要从服务器读取信息，因此不需要对过多成员赋值
    cm_socket->write(pack.getPack(),sizeof(pack));                      //传送至服务器
}

/*读取到服务器发来的信息*/
void ChatRoom::onRead()
{
    //qDebug() << "我猜该不会是发到这里来了吧？";
    QByteArray bytearry;
    bytearry.resize(cm_socket->bytesAvailable());                       //这三行都是读取出服务器发来的包
    bytearry= cm_socket->readAll();

    const  Pack* ppack = (const Pack*)(bytearry.data());
    QString text = ppack->getText();
    QMessageBox msgBox;                                                 //创建对话框
    msgBox.setSizeIncrement(200,150);
    msgBox.setText(text);

    switch(ppack->type){
    case Pack::TYPE_CREATE_ROOM:
        msgBox.setWindowTitle("CREATE");                                //显示创建弹窗
        msgBox.exec();
        if(ppack->getText()=="创建成功") {
            this->hide();
            live = new Live;
            QObject::connect(live,SIGNAL(closeLiveroom()),this,SLOT(showAgain()));
            live->show();
        }
        break;
    default:
        break;
    }
}

