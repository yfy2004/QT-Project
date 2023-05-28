#ifndef GAME_H
#define GAME_H
#include "setting.h"
#include <QWidget>
#include <QMultimedia>
#include <QMediaPlayer>
#include <setting.h>
#include <ui_setting.h>
#include <QTimer>
#include <QTime>

namespace Ui {
class Game;
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

private:
    Ui::Game *ui;

};

#endif // GAME_H
