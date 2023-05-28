#include "game.h"
#include "ui_game.h"
#include <QTimer>
#include <QTime>

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    time.setHMS(0,0,0,0);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(1000);

    my_game_music=new QMediaPlayer(this);
    my_game_music->setMedia(QUrl("qrc:/new/prefix1/picture/LevelMusic.mp3"));
    my_game_music->setVolume(50);
    my_game_music->play();

    ui->setting->setStyleSheet("QPushButton#setting{background-image: url(:/new/prefix1/picture/setting_dark.png);border:1px solid rgba(255,255,255,0);}QPushButton#setting:hover{background-image: url(:/new/prefix1/picture/setting_light.png);border:1px solid rgba(255,255,255,0);}QPushButton#setting:pressed{background-image: url(:/new/prefix1/picture/setting_light.png);border:1px solid rgba(255,255,255,0);}");
    ui->musicon->setStyleSheet("background-image: url(:/new/prefix1/picture/music_on.png);border:1px solid rgba(255,255,255,0);");
    ui->musicoff->setStyleSheet("background-image: url(:/new/prefix1/picture/music_off.png);border:1px solid rgba(255,255,255,0);");
    ui->musicoff->setEnabled(false);
    ui->musicoff->setVisible(0);
}

Game::~Game()
{
    delete ui;
}


void Game::on_musicon_clicked()
{
    ui->musicon->setEnabled(false);
    ui->musicon->setVisible(0);
    ui->musicoff->setEnabled(true);
    ui->musicoff->setVisible(1);
    my_game_music->pause();
}

void Game::on_musicoff_clicked()
{
    ui->musicoff->setEnabled(false);
    ui->musicoff->setVisible(0);
    ui->musicon->setEnabled(true);
    ui->musicon->setVisible(1);
    my_game_music->play();
}

void Game::on_setting_clicked()
{
    setting *configWindow=new setting(nullptr,this);
    configWindow->show();
    timer->stop();
    ui->setting->setEnabled(false);
}

void Game::update()
{
    static quint32 time_out=0;
    time_out++;
    time=time.addSecs(1);
    quint32 minute = time.minute();
    quint32 second=time.second();

    if(second%10==0)
        ui->label_5->setStyleSheet("background-image: url(:/new/prefix1/picture/zero_new.png);");
    else if(second%10==1)
        ui->label_5->setStyleSheet("background-image: url(:/new/prefix1/picture/one_new.png);");
    else if(second%10==2)
        ui->label_5->setStyleSheet("background-image: url(:/new/prefix1/picture/two_new.png);");
    else if(second%10==3)
        ui->label_5->setStyleSheet("background-image: url(:/new/prefix1/picture/three_new.png);");
    else if(second%10==4)
        ui->label_5->setStyleSheet("background-image: url(:/new/prefix1/picture/four_new.png);");
    else if(second%10==5)
        ui->label_5->setStyleSheet("background-image: url(:/new/prefix1/picture/five.png);");
    else if(second%10==6)
        ui->label_5->setStyleSheet("background-image: url(:/new/prefix1/picture/six.png);");
    else if(second%10==7)
        ui->label_5->setStyleSheet("background-image: url(:/new/prefix1/picture/seven.png);");
    else if(second%10==8)
        ui->label_5->setStyleSheet("background-image: url(:/new/prefix1/picture/eight.png);");
    else if(second%10==9)
        ui->label_5->setStyleSheet("background-image: url(:/new/prefix1/picture/nine.png);");

    if(minute/10==0)
        ui->label_2->setStyleSheet("background-image: url(:/new/prefix1/picture/zero_new.png);");
    else if(minute/10==1)
        ui->label_2->setStyleSheet("background-image: url(:/new/prefix1/picture/one_new.png);");
    else if(minute/10==2)
        ui->label_2->setStyleSheet("background-image: url(:/new/prefix1/picture/two_new.png);");
    else if(minute/10==3)
        ui->label_2->setStyleSheet("background-image: url(:/new/prefix1/picture/three_new.png);");
    else if(minute/10==4)
        ui->label_2->setStyleSheet("background-image: url(:/new/prefix1/picture/four_new.png);");
    else if(minute/10==5)
        ui->label_2->setStyleSheet("background-image: url(:/new/prefix1/picture/five.png);");
    else if(minute/10==6)
        ui->label_2->setStyleSheet("background-image: url(:/new/prefix1/picture/six.png);");
    else if(minute/10==7)
        ui->label_2->setStyleSheet("background-image: url(:/new/prefix1/picture/seven.png);");
    else if(minute/10==8)
        ui->label_2->setStyleSheet("background-image: url(:/new/prefix1/picture/eight.png);");
    else if(minute/10==9)
        ui->label_2->setStyleSheet("background-image: url(:/new/prefix1/picture/nine.png);");

    if(minute%10==0)
        ui->label_3->setStyleSheet("background-image: url(:/new/prefix1/picture/zero_new.png);");
    else if(minute%10==1)
        ui->label_3->setStyleSheet("background-image: url(:/new/prefix1/picture/one_new.png);");
    else if(minute%10==2)
        ui->label_3->setStyleSheet("background-image: url(:/new/prefix1/picture/two_new.png);");
    else if(minute%10==3)
        ui->label_3->setStyleSheet("background-image: url(:/new/prefix1/picture/three_new.png);");
    else if(minute%10==4)
        ui->label_3->setStyleSheet("background-image: url(:/new/prefix1/picture/four_new.png);");
    else if(minute%10==5)
        ui->label_3->setStyleSheet("background-image: url(:/new/prefix1/picture/five.png);");
    else if(minute%10==6)
        ui->label_3->setStyleSheet("background-image: url(:/new/prefix1/picture/six.png);");
    else if(minute%10==7)
        ui->label_3->setStyleSheet("background-image: url(:/new/prefix1/picture/seven.png);");
    else if(minute%10==8)
        ui->label_3->setStyleSheet("background-image: url(:/new/prefix1/picture/eight.png);");
    else if(minute%10==9)
        ui->label_3->setStyleSheet("background-image: url(:/new/prefix1/picture/nine.png);");

    if(second/10==0)
        ui->label_4->setStyleSheet("background-image: url(:/new/prefix1/picture/zero_new.png);");
    else if(second/10==1)
        ui->label_4->setStyleSheet("background-image: url(:/new/prefix1/picture/one_new.png);");
    else if(second/10==2)
        ui->label_4->setStyleSheet("background-image: url(:/new/prefix1/picture/two_new.png);");
    else if(second/10==3)
        ui->label_4->setStyleSheet("background-image: url(:/new/prefix1/picture/three_new.png);");
    else if(second/10==4)
        ui->label_4->setStyleSheet("background-image: url(:/new/prefix1/picture/four_new.png);");
    else if(second/10==5)
        ui->label_4->setStyleSheet("background-image: url(:/new/prefix1/picture/five.png);");
    else if(second/10==6)
        ui->label_4->setStyleSheet("background-image: url(:/new/prefix1/picture/six.png);");
    else if(second/10==7)
        ui->label_4->setStyleSheet("background-image: url(:/new/prefix1/picture/seven.png);");
    else if(second/10==8)
        ui->label_4->setStyleSheet("background-image: url(:/new/prefix1/picture/eight.png);");
    else if(second/10==9)
        ui->label_4->setStyleSheet("background-image: url(:/new/prefix1/picture/nine.png);");
}

