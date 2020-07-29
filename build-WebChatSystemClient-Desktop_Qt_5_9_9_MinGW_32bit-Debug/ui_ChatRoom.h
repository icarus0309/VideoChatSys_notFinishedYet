/********************************************************************************
** Form generated from reading UI file 'ChatRoom.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATROOM_H
#define UI_CHATROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatRoom
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *btn_show_r;
    QLabel *label_3;
    QLabel *label_5;
    QPushButton *btn_cre_r;
    QPushButton *btn_exit;
    QPushButton *btn_set;
    QTextBrowser *tb_name;
    QTextBrowser *tb_money;
    QListWidget *list_show;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChatRoom)
    {
        if (ChatRoom->objectName().isEmpty())
            ChatRoom->setObjectName(QStringLiteral("ChatRoom"));
        ChatRoom->resize(560, 405);
        centralwidget = new QWidget(ChatRoom);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 60, 81, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(14);
        font.setItalic(false);
        label->setFont(font);
        btn_show_r = new QPushButton(centralwidget);
        btn_show_r->setObjectName(QStringLiteral("btn_show_r"));
        btn_show_r->setGeometry(QRect(180, 60, 75, 23));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        btn_show_r->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(300, 150, 71, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(11);
        label_3->setFont(font2);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(300, 190, 71, 41));
        label_5->setFont(font2);
        btn_cre_r = new QPushButton(centralwidget);
        btn_cre_r->setObjectName(QStringLiteral("btn_cre_r"));
        btn_cre_r->setGeometry(QRect(340, 60, 131, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font3.setPointSize(12);
        btn_cre_r->setFont(font3);
        btn_exit = new QPushButton(centralwidget);
        btn_exit->setObjectName(QStringLiteral("btn_exit"));
        btn_exit->setGeometry(QRect(410, 310, 75, 23));
        btn_exit->setFont(font1);
        btn_set = new QPushButton(centralwidget);
        btn_set->setObjectName(QStringLiteral("btn_set"));
        btn_set->setGeometry(QRect(320, 310, 75, 21));
        btn_set->setFont(font1);
        tb_name = new QTextBrowser(centralwidget);
        tb_name->setObjectName(QStringLiteral("tb_name"));
        tb_name->setGeometry(QRect(380, 150, 121, 31));
        tb_name->setFrameShape(QFrame::NoFrame);
        tb_name->setFrameShadow(QFrame::Plain);
        tb_money = new QTextBrowser(centralwidget);
        tb_money->setObjectName(QStringLiteral("tb_money"));
        tb_money->setGeometry(QRect(380, 190, 121, 31));
        tb_money->setFrameShape(QFrame::NoFrame);
        tb_money->setFrameShadow(QFrame::Plain);
        list_show = new QListWidget(centralwidget);
        list_show->setObjectName(QStringLiteral("list_show"));
        list_show->setGeometry(QRect(60, 100, 211, 241));
        ChatRoom->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ChatRoom);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ChatRoom->setStatusBar(statusbar);

        retranslateUi(ChatRoom);

        QMetaObject::connectSlotsByName(ChatRoom);
    } // setupUi

    void retranslateUi(QMainWindow *ChatRoom)
    {
        ChatRoom->setWindowTitle(QApplication::translate("ChatRoom", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("ChatRoom", "\346\210\277\351\227\264\345\210\227\350\241\250", Q_NULLPTR));
        btn_show_r->setText(QApplication::translate("ChatRoom", "\345\210\267\346\226\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("ChatRoom", "\346\210\221\347\232\204\346\230\265\347\247\260:", Q_NULLPTR));
        label_5->setText(QApplication::translate("ChatRoom", "\345\211\251\344\275\231\351\207\221\345\270\201:", Q_NULLPTR));
        btn_cre_r->setText(QApplication::translate("ChatRoom", "\345\210\233\345\273\272\346\210\221\347\232\204\346\210\277\351\227\264", Q_NULLPTR));
        btn_exit->setText(QApplication::translate("ChatRoom", "\351\200\200\345\207\272", Q_NULLPTR));
        btn_set->setText(QApplication::translate("ChatRoom", "\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChatRoom: public Ui_ChatRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATROOM_H
