/********************************************************************************
** Form generated from reading UI file 'victory.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VICTORY_H
#define UI_VICTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_victory
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *victory)
    {
        if (victory->objectName().isEmpty())
            victory->setObjectName(QStringLiteral("victory"));
        victory->resize(735, 756);
        victory->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/victory_final_new.png);"));
        pushButton = new QPushButton(victory);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(230, 580, 265, 92));
        pushButton->setStyleSheet(QLatin1String("QPushButton#pushButton{background-image: url(:/new/prefix1/picture/continue_dark.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton:hover{background-image: url(:/new/prefix1/picture/continue_light.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton:pressed{background-image: url(:/new/prefix1/picture/continue_light.png);border:1px solid rgba(255,255,255,0);}\n"
"\n"
"\n"
""));
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(victory);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 480, 265, 92));
        pushButton_2->setStyleSheet(QStringLiteral("QPushButton#pushButton_2{background-image: url(:/new/prefix1/picture/return_dark_another.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton_2:hover{background-image: url(:/new/prefix1/picture/return_light_another.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton_2:pressed{background-image: url(:/new/prefix1/picture/return_light_another.png);border:1px solid rgba(255,255,255,0);}"));
        pushButton_2->setFlat(true);

        retranslateUi(victory);

        QMetaObject::connectSlotsByName(victory);
    } // setupUi

    void retranslateUi(QWidget *victory)
    {
        victory->setWindowTitle(QApplication::translate("victory", "Form", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class victory: public Ui_victory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VICTORY_H
