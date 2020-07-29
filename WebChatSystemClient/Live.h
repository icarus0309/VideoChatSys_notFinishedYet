#ifndef LIVE_H
#define LIVE_H

#include <QMainWindow>
#include <vector>
#include <iostream>
#include "string.h"
using namespace std;

namespace Ui {
class Live;
}

class Live : public QMainWindow
{
    Q_OBJECT

public:
    explicit Live(QWidget *parent = nullptr);
    ~Live();

    QString getName()const{return QString::fromLocal8Bit(live_name);}   //注意这里的getName是指Live

    void setName(QString name)
    {
        char* str = name.toLocal8Bit().data();
        strcpy(this->live_name,str);
    }

    void closeEvent( QCloseEvent * event );

signals:
    void closeLiveroom();

private slots:
    //void on_btn_exit_clicked();

private:
    Ui::Live *ui;
    char live_name[20];                     //先不加房主试试看
    vector<QString> live_passenger;         //这两个参数先就这么放着
};

#endif // LIVE_H
