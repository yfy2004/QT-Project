/********************************************************************************
** Form generated from reading UI file 'lose.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOSE_H
#define UI_LOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lose
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *lose)
    {
        if (lose->objectName().isEmpty())
            lose->setObjectName(QStringLiteral("lose"));
        lose->resize(740, 769);
        lose->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/lose.png);"));
        pushButton = new QPushButton(lose);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 520, 330, 100));
        pushButton->setStyleSheet(QStringLiteral("QPushButton#pushButton{background-image: url(:/new/prefix1/picture/again_dark.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton:hover{background-image: url(:/new/prefix1/picture/again_light.png);border:1px solid rgba(255,255,255,0);}QPushButton{background-image: url(:/new/prefix1/picture/again_light.png);border:1px solid rgba(255,255,255,0);}"));
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(lose);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 390, 265, 92));
        pushButton_2->setStyleSheet(QStringLiteral("QPushButton#pushButton_2{background-image: url(:/new/prefix1/picture/return_dark_another.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton_2:hover{background-image: url(:/new/prefix1/picture/return_light.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton_2:pressed{background-image: url(:/new/prefix1/picture/return_light.png);border:1px solid rgba(255,255,255,0);}"));
        pushButton_2->setFlat(true);

        retranslateUi(lose);

        QMetaObject::connectSlotsByName(lose);
    } // setupUi

    void retranslateUi(QWidget *lose)
    {
        lose->setWindowTitle(QApplication::translate("lose", "Form", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class lose: public Ui_lose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOSE_H
