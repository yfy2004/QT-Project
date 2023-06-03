#ifndef GAME_H
#define GAME_H
#include "setting.h"
#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>
#include <QMessageBox>
#include <QMultimedia>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <setting.h>
#include <ui_setting.h>
#include <QTimer>
#include <QTime>

namespace Ui {
class Game;
//class Ice;
}

class setting;
class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();
    QMediaPlayer *my_game_music=nullptr;
    QTimer *timer=nullptr;
    QTime time;

private slots:


    void on_musicon_clicked();

    void on_musicoff_clicked();

    void on_setting_clicked();

    void update();

public:
    Ui::Game *ui;

};
/*
class Ice : public QDialog
{
    Q_OBJECT

public:
    explicit Ice(QWidget *parent = 0);
    ~Ice();

protected:

    void paintEvent(QPaintEvent *event);

    void keyPressEvent(QKeyEvent *event);

public:
    Ui::Ice *ui;
};*/

#endif // GAME_H
