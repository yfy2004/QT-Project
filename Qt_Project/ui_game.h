/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QPushButton *musicon;
    QPushButton *musicoff;
    QPushButton *setting;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QStringLiteral("Game"));
        Game->resize(1512, 1134);
        Game->setMinimumSize(QSize(1512, 1134));
        Game->setMaximumSize(QSize(1512, 1134));
        musicon = new QPushButton(Game);
        musicon->setObjectName(QStringLiteral("musicon"));
        musicon->setGeometry(QRect(1444, 7, 45, 38));
        musicon->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/picture/music_on.png);\n"
"border:1px solid rgba(255,255,255,0);\n"
""));
        musicon->setFlat(true);
        musicoff = new QPushButton(Game);
        musicoff->setObjectName(QStringLiteral("musicoff"));
        musicoff->setGeometry(QRect(1445, 7, 24, 38));
        musicoff->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/music_off.png);border:1px solid rgba(255,255,255,0);"));
        musicoff->setFlat(true);
        setting = new QPushButton(Game);
        setting->setObjectName(QStringLiteral("setting"));
        setting->setGeometry(QRect(706, 1076, 100, 58));
        setting->setStyleSheet(QStringLiteral("QPushButton#setting{background-image: url(:/new/prefix1/picture/setting_dark.png);border:1px solid rgba(255,255,255,0);}QPushButton#setting:hover{background-image: url(:/new/prefix1/picture/setting_light.png);border:1px solid rgba(255,255,255,0);}QPushButton#setting:pressed{background-image: url(:/new/prefix1/picture/setting_light.png);border:1px solid rgba(255,255,255,0);}"));
        setting->setFlat(true);
        label = new QLabel(Game);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(651, 0, 210, 76));
        label->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/timer.png);"));
        label_2 = new QLabel(Game);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(675, 0, 35, 55));
        label_2->setStyleSheet(QStringLiteral("background:transparent;"));
        label_3 = new QLabel(Game);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(710, 0, 35, 55));
        label_3->setStyleSheet(QStringLiteral("background:transparent;"));
        label_4 = new QLabel(Game);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(765, 0, 35, 55));
        label_4->setStyleSheet(QStringLiteral("background:transparent;"));
        label_5 = new QLabel(Game);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(800, 0, 35, 55));
        label_5->setStyleSheet(QStringLiteral("background:transparent;"));

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QWidget *Game)
    {
        Game->setWindowTitle(QApplication::translate("Game", "Form", nullptr));
        musicon->setText(QString());
        musicoff->setText(QString());
        setting->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
