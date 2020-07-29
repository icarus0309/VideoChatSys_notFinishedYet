/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn_listen;
    QPushButton *btn_selectall;
    QPushButton *btn_selectrooms;
    QTextBrowser *te_show_1;
    QTextBrowser *te_show_3;
    QTextBrowser *te_show_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        btn_listen = new QPushButton(centralwidget);
        btn_listen->setObjectName(QStringLiteral("btn_listen"));
        btn_listen->setGeometry(QRect(90, 40, 141, 23));
        btn_selectall = new QPushButton(centralwidget);
        btn_selectall->setObjectName(QStringLiteral("btn_selectall"));
        btn_selectall->setGeometry(QRect(290, 40, 91, 23));
        btn_selectrooms = new QPushButton(centralwidget);
        btn_selectrooms->setObjectName(QStringLiteral("btn_selectrooms"));
        btn_selectrooms->setGeometry(QRect(290, 290, 91, 23));
        te_show_1 = new QTextBrowser(centralwidget);
        te_show_1->setObjectName(QStringLiteral("te_show_1"));
        te_show_1->setGeometry(QRect(80, 70, 161, 371));
        te_show_3 = new QTextBrowser(centralwidget);
        te_show_3->setObjectName(QStringLiteral("te_show_3"));
        te_show_3->setGeometry(QRect(290, 320, 461, 121));
        te_show_2 = new QTextBrowser(centralwidget);
        te_show_2->setObjectName(QStringLiteral("te_show_2"));
        te_show_2->setGeometry(QRect(290, 70, 461, 191));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        btn_listen->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
        btn_selectall->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272/\345\210\267\346\226\260\347\224\250\346\210\267", Q_NULLPTR));
        btn_selectrooms->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272/\345\210\267\346\226\260\346\210\277\351\227\264", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
