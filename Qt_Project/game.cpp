#include "game.h"
#include "ui_game.h"

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);

    my_game_music=new QMediaPlayer(this);
    my_game_music->setMedia(QUrl::fromLocalFile("C:/Users/JinYihan/Documents/GitHub/QT-Project/Qt_Project/picture/LevelMusic.mp3"));
    my_game_music->setVolume(50);
    my_game_music->play();
}

Game::~Game()
{
    delete ui;
}
