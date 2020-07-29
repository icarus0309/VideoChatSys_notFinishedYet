/********************************************************************************
** Form generated from reading UI file 'live.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIVE_H
#define UI_LIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Live
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTextBrowser *te_chats;
    QTextBrowser *te_custs;
    QPushButton *btn_send;
    QTextEdit *te_send;
    QPushButton *btn_carm_on;
    QPushButton *btn_carm_close;
    QPushButton *btn_maike_on;
    QPushButton *btn_maike_close;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Live)
    {
        if (Live->objectName().isEmpty())
            Live->setObjectName(QStringLiteral("Live"));
        Live->resize(809, 484);
        centralwidget = new QWidget(Live);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(540, 30, 54, 12));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(540, 110, 54, 12));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(610, 30, 81, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 270, 54, 12));
        te_chats = new QTextBrowser(centralwidget);
        te_chats->setObjectName(QStringLiteral("te_chats"));
        te_chats->setGeometry(QRect(50, 290, 721, 91));
        te_custs = new QTextBrowser(centralwidget);
        te_custs->setObjectName(QStringLiteral("te_custs"));
        te_custs->setGeometry(QRect(600, 60, 171, 201));
        btn_send = new QPushButton(centralwidget);
        btn_send->setObjectName(QStringLiteral("btn_send"));
        btn_send->setGeometry(QRect(690, 400, 75, 23));
        te_send = new QTextEdit(centralwidget);
        te_send->setObjectName(QStringLiteral("te_send"));
        te_send->setGeometry(QRect(50, 400, 631, 31));
        btn_carm_on = new QPushButton(centralwidget);
        btn_carm_on->setObjectName(QStringLiteral("btn_carm_on"));
        btn_carm_on->setGeometry(QRect(540, 50, 41, 23));
        btn_carm_close = new QPushButton(centralwidget);
        btn_carm_close->setObjectName(QStringLiteral("btn_carm_close"));
        btn_carm_close->setGeometry(QRect(540, 80, 41, 23));
        btn_maike_on = new QPushButton(centralwidget);
        btn_maike_on->setObjectName(QStringLiteral("btn_maike_on"));
        btn_maike_on->setGeometry(QRect(540, 130, 41, 23));
        btn_maike_close = new QPushButton(centralwidget);
        btn_maike_close->setObjectName(QStringLiteral("btn_maike_close"));
        btn_maike_close->setGeometry(QRect(540, 160, 41, 23));
        Live->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Live);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Live->setStatusBar(statusbar);

        retranslateUi(Live);

        QMetaObject::connectSlotsByName(Live);
    } // setupUi

    void retranslateUi(QMainWindow *Live)
    {
        Live->setWindowTitle(QApplication::translate("Live", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("Live", "\346\221\204\345\203\217\345\244\264", Q_NULLPTR));
        label_2->setText(QApplication::translate("Live", "\351\272\246\345\205\213\351\243\216", Q_NULLPTR));
        label_3->setText(QApplication::translate("Live", "\346\210\277\351\227\264\345\206\205\347\224\250\346\210\267", Q_NULLPTR));
        label_4->setText(QApplication::translate("Live", "\350\201\212\345\244\251\350\256\260\345\275\225", Q_NULLPTR));
        btn_send->setText(QApplication::translate("Live", "\345\217\221\351\200\201", Q_NULLPTR));
        btn_carm_on->setText(QApplication::translate("Live", "\345\274\200", Q_NULLPTR));
        btn_carm_close->setText(QApplication::translate("Live", "\345\205\263", Q_NULLPTR));
        btn_maike_on->setText(QApplication::translate("Live", "\345\274\200", Q_NULLPTR));
        btn_maike_close->setText(QApplication::translate("Live", "\345\205\263", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Live: public Ui_Live {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIVE_H
