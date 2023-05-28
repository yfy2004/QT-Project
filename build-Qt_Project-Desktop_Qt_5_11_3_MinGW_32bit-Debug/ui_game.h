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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QPushButton *musicon;
    QPushButton *musicoff;

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

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QWidget *Game)
    {
        Game->setWindowTitle(QApplication::translate("Game", "Form", nullptr));
        musicon->setText(QString());
        musicoff->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
