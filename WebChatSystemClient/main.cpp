#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.setQuitOnLastWindowClosed(false);
    MainWindow w;

    w.setWindowTitle("狍子聊天室");
    w.show();
    return a.exec();
}
