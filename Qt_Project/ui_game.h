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
    QLabel *labelImg;
    QLabel *labelImg1;
    QLabel *blue1;
    QLabel *blue2;
    QLabel *blue3;
    QLabel *red1;
    QLabel *red2;
    QLabel *red3;
    QLabel *button;
    QLabel *block;
    QLabel *blue4;
    QLabel *blue5;
    QLabel *blue6;
    QLabel *red4;
    QLabel *red5;
    QLabel *red6;

    void setupUi(QWidget *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QStringLiteral("Game"));
        Game->resize(1336, 1000);
        Game->setMinimumSize(QSize(1336, 1000));
        Game->setMaximumSize(QSize(1336, 1000));
        Game->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/maphard_init.png);"));
        musicon = new QPushButton(Game);
        musicon->setObjectName(QStringLiteral("musicon"));
        musicon->setGeometry(QRect(1268, 18, 45, 38));
        musicon->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/picture/music_on.png);\n"
"border:1px solid rgba(255,255,255,0);\n"
""));
        musicon->setFlat(true);
        musicoff = new QPushButton(Game);
        musicoff->setObjectName(QStringLiteral("musicoff"));
        musicoff->setGeometry(QRect(1268, 17, 24, 38));
        musicoff->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/music_off.png);border:1px solid rgba(255,255,255,0);"));
        musicoff->setFlat(true);
        setting = new QPushButton(Game);
        setting->setObjectName(QStringLiteral("setting"));
        setting->setGeometry(QRect(618, 930, 101, 71));
        setting->setStyleSheet(QStringLiteral("QPushButton#setting{background-image: url(:/new/prefix1/picture/setting_dark.png);border:1px solid rgba(255,255,255,0);}QPushButton#setting:hover{background-image: url(:/new/prefix1/picture/setting_light.png);border:1px solid rgba(255,255,255,0);}QPushButton#setting:pressed{background-image: url(:/new/prefix1/picture/setting_light.png);border:1px solid rgba(255,255,255,0);}"));
        setting->setFlat(true);
        label = new QLabel(Game);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(563, 0, 210, 76));
        label->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/timer.png);"));
        label_2 = new QLabel(Game);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(587, 0, 35, 55));
        label_2->setStyleSheet(QStringLiteral("background:transparent;"));
        label_3 = new QLabel(Game);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(622, 0, 35, 55));
        label_3->setStyleSheet(QStringLiteral("background:transparent;"));
        label_4 = new QLabel(Game);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(677, 0, 35, 55));
        label_4->setStyleSheet(QStringLiteral("background:transparent;"));
        label_5 = new QLabel(Game);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(712, 0, 35, 55));
        label_5->setStyleSheet(QStringLiteral("background:transparent;"));
        labelImg = new QLabel(Game);
        labelImg->setObjectName(QStringLiteral("labelImg"));
        labelImg->setGeometry(QRect(425, 650, 101, 91));
        labelImg->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/fire.png);"));
        labelImg1 = new QLabel(Game);
        labelImg1->setObjectName(QStringLiteral("labelImg1"));
        labelImg1->setGeometry(QRect(780, 639, 101, 91));
        labelImg1->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/ice.png);"));
        blue1 = new QLabel(Game);
        blue1->setObjectName(QStringLiteral("blue1"));
        blue1->setGeometry(QRect(920, 880, 101, 101));
        blue1->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/blue diamond.png);"));
        blue2 = new QLabel(Game);
        blue2->setObjectName(QStringLiteral("blue2"));
        blue2->setGeometry(QRect(230, 580, 101, 101));
        blue2->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/blue diamond.png);"));
        blue3 = new QLabel(Game);
        blue3->setObjectName(QStringLiteral("blue3"));
        blue3->setGeometry(QRect(760, 70, 101, 101));
        blue3->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/blue diamond.png);"));
        red1 = new QLabel(Game);
        red1->setObjectName(QStringLiteral("red1"));
        red1->setGeometry(QRect(650, 880, 101, 101));
        red1->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/red diamond.png);"));
        red2 = new QLabel(Game);
        red2->setObjectName(QStringLiteral("red2"));
        red2->setGeometry(QRect(390, 580, 101, 101));
        red2->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/red diamond.png);"));
        red3 = new QLabel(Game);
        red3->setObjectName(QStringLiteral("red3"));
        red3->setGeometry(QRect(600, 70, 101, 101));
        red3->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/red diamond.png);"));
        button = new QLabel(Game);
        button->setObjectName(QStringLiteral("button"));
        button->setGeometry(QRect(0, 0, 1336, 1000));
        button->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/button.png);"));
        block = new QLabel(Game);
        block->setObjectName(QStringLiteral("block"));
        block->setGeometry(QRect(0, 0, 1336, 1000));
        block->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/block.png);"));
        blue4 = new QLabel(Game);
        blue4->setObjectName(QStringLiteral("blue4"));
        blue4->setGeometry(QRect(580, 510, 101, 101));
        blue4->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/blue diamond.png);"));
        blue5 = new QLabel(Game);
        blue5->setObjectName(QStringLiteral("blue5"));
        blue5->setGeometry(QRect(160, 240, 101, 101));
        blue5->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/blue diamond.png);"));
        blue6 = new QLabel(Game);
        blue6->setObjectName(QStringLiteral("blue6"));
        blue6->setGeometry(QRect(500, 635, 101, 101));
        blue6->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/blue diamond.png);"));
        red4 = new QLabel(Game);
        red4->setObjectName(QStringLiteral("red4"));
        red4->setGeometry(QRect(680, 510, 101, 101));
        red4->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/red diamond.png);"));
        red5 = new QLabel(Game);
        red5->setObjectName(QStringLiteral("red5"));
        red5->setGeometry(QRect(1070, 105, 101, 101));
        red5->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/red diamond.png);"));
        red6 = new QLabel(Game);
        red6->setObjectName(QStringLiteral("red6"));
        red6->setGeometry(QRect(760, 635, 101, 101));
        red6->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/picture/red diamond.png);"));
        button->raise();
        block->raise();
        musicon->raise();
        musicoff->raise();
        setting->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        labelImg->raise();
        labelImg1->raise();
        blue1->raise();
        blue2->raise();
        blue3->raise();
        red1->raise();
        red2->raise();
        red3->raise();
        blue4->raise();
        blue5->raise();
        blue6->raise();
        red4->raise();
        red5->raise();
        red6->raise();

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
        labelImg->setText(QString());
        labelImg1->setText(QString());
        blue1->setText(QString());
        blue2->setText(QString());
        blue3->setText(QString());
        red1->setText(QString());
        red2->setText(QString());
        red3->setText(QString());
        button->setText(QString());
        block->setText(QString());
        blue4->setText(QString());
        blue5->setText(QString());
        blue6->setText(QString());
        red4->setText(QString());
        red5->setText(QString());
        red6->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
