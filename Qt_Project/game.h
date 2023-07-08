#ifndef GAME_H
#define GAME_H
#include "setting.h"
#include "lose.h"
#include "victory.h"
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
#include <lose.h>
#include <ui_lose.h>
#include <victory.h>
#include <ui_victory.h>
#include <QTimer>
#include <QTime>
#include <QPointF>

namespace Ui {
class Game;
}

class setting;
class lose;
class victory;
class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr, qint32 num=1);
    ~Game();
    QMediaPlayer *my_game_music=nullptr;
    QTimer *timer=nullptr;
    QTimer *timer_ice=nullptr;
    QTimer *timer_fire=nullptr;
    QTimer *timer_animation=nullptr;
    QTime time;

private slots:


    void on_musicon_clicked();

    void on_musicoff_clicked();

    void on_setting_clicked();

    void update();

    void keyPressEvent(QKeyEvent *event);

    void keyReleaseEvent(QKeyEvent *event);

    void ice_update();

    void ice_update2();

    void fire_update();

    void fire_update2();

    void animation_update();

    void game_lose();

    void game_victory();

public:
    Ui::Game *ui;

public:
    qint32 game_num;
    qint32 blue_num;
    qint32 red_num;
    qint32 game_time;
    qreal ice_vx;
    qreal ice_vy;
    qreal fire_vx;
    qreal fire_vy;
    bool ice_is_falling;
    bool fire_is_falling;
    bool wPressed=false;
    bool aPressed=false;
    bool dPressed=false;
    bool upPressed=false;
    bool leftPressed=false;
    bool rightPressed=false;
    qint32 ice_cnt;
    qint32 fire_cnt;
    bool blue[7],red[7];
    bool buttonPressed;
};

#endif // GAME_H
