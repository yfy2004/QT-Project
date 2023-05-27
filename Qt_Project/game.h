#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QMultimedia>
#include <QMediaPlayer>

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

private:
    Ui::Game *ui;
    QMediaPlayer *my_game_music=nullptr;
};

#endif // GAME_H
