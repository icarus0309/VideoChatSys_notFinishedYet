/********************************************************************************
** Form generated from reading UI file 'dialogcrelive.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCRELIVE_H
#define UI_DIALOGCRELIVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogCreLive
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *le_show;

    void setupUi(QDialog *DialogCreLive)
    {
        if (DialogCreLive->objectName().isEmpty())
            DialogCreLive->setObjectName(QStringLiteral("DialogCreLive"));
        DialogCreLive->resize(320, 203);
        buttonBox = new QDialogButtonBox(DialogCreLive);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(0, 110, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DialogCreLive);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 50, 131, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\347\220\245\347\217\200"));
        font.setPointSize(12);
        label->setFont(font);
        le_show = new QLineEdit(DialogCreLive);
        le_show->setObjectName(QStringLiteral("le_show"));
        le_show->setGeometry(QRect(150, 50, 151, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Times New Roman"));
        font1.setPointSize(12);
        le_show->setFont(font1);

        retranslateUi(DialogCreLive);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogCreLive, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogCreLive, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogCreLive);
    } // setupUi

    void retranslateUi(QDialog *DialogCreLive)
    {
        DialogCreLive->setWindowTitle(QApplication::translate("DialogCreLive", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DialogCreLive", "\350\257\267\350\276\223\345\205\245\346\210\277\351\227\264\345\220\215\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogCreLive: public Ui_DialogCreLive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCRELIVE_H
