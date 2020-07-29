#include "Live.h"
#include "ui_live.h"
#include <QCloseEvent>

Live::Live(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Live)
{
    ui->setupUi(this);
}

Live::~Live()
{
    delete ui;
}


void Live::closeEvent( QCloseEvent * event )
{
    this->close();                      //退出时销毁当前窗口
    this->deleteLater();
    emit closeLiveroom();               //发送信号让第一界面显现
    event->accept();
}

