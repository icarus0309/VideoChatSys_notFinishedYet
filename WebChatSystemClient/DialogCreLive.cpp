#include "DialogCreLive.h"
#include "ui_dialogcrelive.h"

DialogCreLive::DialogCreLive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCreLive)
{
    ui->setupUi(this);
}

DialogCreLive::~DialogCreLive()
{
    delete ui;
}

void DialogCreLive::on_buttonBox_accepted()
{
    QString s = ui->le_show->text();            //将文本框中的房间名字写给客户端发送给服务器
    emit sendCre(s);
}

void DialogCreLive::on_buttonBox_rejected()
{

}
