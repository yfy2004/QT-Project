#include "game.h"
#include "ui_game.h"
#include <QTimer>
#include <QTime>
#include <QKeyEvent>
#include <QDebug>
#include <QApplication>

/*extern qint32 game_num;
extern qint32 blue_num;
extern qint32 red_num;
extern qint32 game_time;

qint32 game_num;
qint32 blue_num;
qint32 red_num;
qint32 game_time;*/

Game::Game(QWidget *parent,qint32 num) :
    QWidget(parent),
    ui(new Ui::Game),
    game_num(num)
{
    ui->setupUi(this);

    this->setAutoFillBackground(true);
    QPalette p;
    if(game_num==1){
        QPixmap pix(":/new/prefix1/picture/map0.png");
        p.setBrush(QPalette::Window,QBrush(pix));
    }
    else{
        QPixmap pix(":/new/prefix1/picture/maphard_init.png");
        p.setBrush(QPalette::Window,QBrush(pix));
    }
    this->setPalette(p);
    this->show();

    this->setWindowFlags(Qt::FramelessWindowHint);

    time.setHMS(0,0,0,0);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(1000);

    QMediaPlaylist *my_list = new QMediaPlaylist();
    my_list->addMedia(QUrl("qrc:/new/prefix1/picture/LevelMusic.mp3"));
    my_list->setCurrentIndex(0);
    my_list->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    my_game_music=new QMediaPlayer(this);
    my_game_music->setPlaylist(my_list);
    my_game_music->setVolume(50);
    my_game_music->play();

    ui->setting->setStyleSheet("QPushButton#setting{background-image: url(:/new/prefix1/picture/setting_dark.png);border:1px solid rgba(255,255,255,0);}QPushButton#setting:hover{background-image: url(:/new/prefix1/picture/setting_light.png);border:1px solid rgba(255,255,255,0);}QPushButton#setting:pressed{background-image: url(:/new/prefix1/picture/setting_light.png);border:1px solid rgba(255,255,255,0);}");
    ui->setting->move(618,930);
    ui->setting->show();
    ui->musicon->setStyleSheet("background-image: url(:/new/prefix1/picture/music_on.png);border:1px solid rgba(255,255,255,0);");
    ui->musicoff->setStyleSheet("background-image: url(:/new/prefix1/picture/music_off.png);border:1px solid rgba(255,255,255,0);");
    ui->musicoff->setEnabled(false);
    ui->musicoff->setVisible(0);

    if(game_num==1){
        blue_num=0;
        red_num=0;
        game_time=0;
        blue[1]=0,blue[2]=0,blue[3]=0;
        red[1]=0,red[2]=0,red[3]=0;
        ui->blue1->setStyleSheet("background-image: url(:/new/prefix1/picture/blue diamond.png);");
        ui->blue2->setStyleSheet("background-image: url(:/new/prefix1/picture/blue diamond.png);");
        ui->blue3->setStyleSheet("background-image: url(:/new/prefix1/picture/blue diamond.png);");
        ui->red1->setStyleSheet("background-image: url(:/new/prefix1/picture/red diamond.png);");
        ui->red2->setStyleSheet("background-image: url(:/new/prefix1/picture/red diamond.png);");
        ui->red3->setStyleSheet("background-image: url(:/new/prefix1/picture/red diamond.png);");
        ui->blue1->setVisible(true);
        ui->blue2->setVisible(true);
        ui->blue3->setVisible(true);
        ui->red1->setVisible(true);
        ui->red2->setVisible(true);
        ui->red3->setVisible(true);
        ui->blue4->setVisible(false);
        ui->blue5->setVisible(false);
        ui->blue6->setVisible(false);
        ui->red4->setVisible(false);
        ui->red5->setVisible(false);
        ui->red6->setVisible(false);
        ui->button->setVisible(false);
        ui->block->setVisible(false);
    }
    else{
        blue[4]=0,blue[5]=0,blue[6]=0;
        red[4]=0,red[5]=0,red[6]=0;
        ui->blue4->setStyleSheet("background-image: url(:/new/prefix1/picture/blue diamond.png);");
        ui->blue5->setStyleSheet("background-image: url(:/new/prefix1/picture/blue diamond.png);");
        ui->blue6->setStyleSheet("background-image: url(:/new/prefix1/picture/blue diamond.png);");
        ui->red4->setStyleSheet("background-image: url(:/new/prefix1/picture/red diamond.png);");
        ui->red5->setStyleSheet("background-image: url(:/new/prefix1/picture/red diamond.png);");
        ui->red6->setStyleSheet("background-image: url(:/new/prefix1/picture/red diamond.png);");
        ui->blue1->setVisible(false);
        ui->blue2->setVisible(false);
        ui->blue3->setVisible(false);
        ui->red1->setVisible(false);
        ui->red2->setVisible(false);
        ui->red3->setVisible(false);
        ui->blue4->setVisible(true);
        ui->blue5->setVisible(true);
        ui->blue6->setVisible(true);
        ui->red4->setVisible(true);
        ui->red5->setVisible(true);
        ui->red6->setVisible(true);
        ui->button->setStyleSheet("background-image: url(:/new/prefix1/picture/button.png);");
        ui->block->setStyleSheet("background-image: url(:/new/prefix1/picture/block.png);");
        ui->button->setVisible(true);
        ui->block->setVisible(true);
        buttonPressed=false;
    }

    quint32 dt=40;

    ui->labelImg1->setStyleSheet("background-image: url(:/new/prefix1/picture/ice.png);");
    if(game_num==1)
        ui->labelImg1->move(50,738);
    else
        ui->labelImg1->move(70,112);
    ui->labelImg1->show();
    ice_vx=0;
    ice_vy=0;
    ice_is_falling=false;
    timer_ice=new QTimer(this);
    connect(timer_ice,SIGNAL(timeout()),this,SLOT(ice_update()));
    timer_ice->start(dt);

    ui->labelImg->setStyleSheet("background-image: url(:/new/prefix1/picture/fire.png);");
    if(game_num==1)
        ui->labelImg->move(50,870);
    else
        ui->labelImg->move(1170,241);
    ui->labelImg->show();
    fire_vx=0;
    fire_vy=0;
    fire_is_falling=false;
    timer_fire=new QTimer(this);
    connect(timer_fire,SIGNAL(timeout()),this,SLOT(fire_update()));
    timer_fire->start(dt);

    ice_cnt=0;
    fire_cnt=0;
    timer_animation=new QTimer(this);
    connect(timer_animation,SIGNAL(timeout()),this,SLOT(animation_update()));
    timer_animation->start(250);
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

void Game::game_lose()
{
    lose *configWindow = new lose(nullptr,this);
    configWindow->show();
}

void Game::game_victory()
{
    game_time+=time.minute()*60+time.second();
    victory *configWindow = new victory(nullptr,this);
    configWindow->show();
}

void Game::update()
{
    static quint32 time_out=0;
    time_out++;
    time=time.addSecs(1);
    quint32 minute=time.minute();
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

    if(game_num==1 && ui->labelImg1->y()>=100 && ui->labelImg1->y()<=134 && ui->labelImg1->x()>=1130 && ui->labelImg1->x()<=1180 && ui->labelImg->y()>=100 && ui->labelImg->y()<=134 && ui->labelImg->x()>=1030 && ui->labelImg->x()<=1080){
        timer->stop();
        timer_ice->stop();
        timer_fire->stop();
        timer_animation->stop();
        this->game_victory();
        return;
    }
    if(game_num==2 && ui->labelImg1->y()>=208 && ui->labelImg1->y()<=241 && ui->labelImg1->x()>=49 && ui->labelImg1->x()<=92 && ui->labelImg->y()>=79 && ui->labelImg->y()<=112 && ui->labelImg->x()>=1124 && ui->labelImg->x()<=1167){
        timer->stop();
        timer_ice->stop();
        timer_fire->stop();
        timer_animation->stop();
        this->game_victory();
        return;
    }
}

void Game::ice_update()
{
    quint32 dt=40;
    if(ice_is_falling){
        ice_vy+=280*dt/1000;
        ui->labelImg1->move(ui->labelImg1->x(),ui->labelImg1->y()+ice_vy*dt/1000);
    }
    if(aPressed || dPressed){
        ui->labelImg1->move(ui->labelImg1->x()+ice_vx*dt/1000,ui->labelImg1->y());
    }
    if(ui->labelImg1->x()<10){
        ui->labelImg1->move(10,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->x()>1230){
        ui->labelImg1->move(1230,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()<30){
        ui->labelImg1->move(ui->labelImg1->x(),30);
        ice_vy=0;
    }
    if(game_num==2){
        ice_update2();
        return;
    }
    if(ui->labelImg1->y()>870 &&(ui->labelImg1->x()>=1000 || ui->labelImg1->x()<=834)){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),870);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>=870 && ui->labelImg1->x()>=834 && ui->labelImg1->x()<=868){
        qreal t=870+(ui->labelImg1->x()-834)/2;
        if(ui->labelImg1->y()>t){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),t);
            ice_vy=ice_vx/2;
        }
        else{
            ice_is_falling=true;
        }
    }
    if(ui->labelImg1->y()>=870 && ui->labelImg1->x()>=966 && ui->labelImg1->x()<=1000){
        qreal t=870+(1000-ui->labelImg1->x())/2;
        if(ui->labelImg1->y()>t){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),t);
            ice_vy=-ice_vx/2;
        }
        else{
            ice_is_falling=true;
        }
    }
    if(ui->labelImg1->y()>887){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),887);
        ice_vy=0;
    }
    if(ui->labelImg1->x()>1130 && ui->labelImg1->y()<=870 && ui->labelImg1->y()>810){
        ui->labelImg1->move(1130,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->x()>1170 && ui->labelImg1->y()>770){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),770);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>=770 && ui->labelImg1->x()>=1130 && ui->labelImg1->x()<=1170){
        qreal t=770+(1170-ui->labelImg1->x());
        if(ui->labelImg1->y()>t){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),t);
            ice_vy=-ice_vx;
        }
        else{
            ice_is_falling=true;
        }
    }
    if(ui->labelImg1->y()>=668 && ui->labelImg1->y()<=710 && ui->labelImg1->x()>1078 && ui->labelImg1->x()<=1115){
        qreal t=668+(ui->labelImg1->x()-1078);
        if(ui->labelImg1->y()>t){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),t);
            ice_vy=ice_vx;
        }
        else{
            ice_is_falling=true;
        }
    }
    if(ui->labelImg1->y()>668 && ui->labelImg1->y()<=680 && ui->labelImg1->x()<=1078 && ui->labelImg1->x()>=605){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),668);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>=599 && ui->labelImg1->y()<=680 && ui->labelImg1->x()>536 && ui->labelImg1->x()<605){
        qreal t=599+(ui->labelImg1->x()-536);
        if(ui->labelImg1->y()>t){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),t);
            ice_vy=ice_vx;
        }
        else{
            ice_is_falling=true;
        }
    }
    if(ui->labelImg1->y()>599 && ui->labelImg1->y()<=680 && ui->labelImg1->x()<=536 && ui->labelImg1->x()>=140){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),599);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>543 && ui->labelImg1->y()<=599 && ui->labelImg1->x()<140){
        ui->labelImg1->move(140,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>538 && ui->labelImg1->y()<=680 && ui->labelImg1->x()<140 && ui->labelImg1->x()>=75){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),538);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>=500 && ui->labelImg1->y()<599 && ui->labelImg1->x()<=536 && ui->labelImg1->x()>=140){
        ice_is_falling=true;
    }
    if(ui->labelImg1->y()>489 && ui->labelImg1->y()<=538 && ui->labelImg1->x()<75){
        ui->labelImg1->move(75,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>484 && ui->labelImg1->y()<=680 && ui->labelImg1->x()<75 && ui->labelImg1->x()>=10){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),484);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>=390 && ui->labelImg1->y()<538 && ui->labelImg1->x()<140 && ui->labelImg1->x()>=75){
        ice_is_falling=true;
    }
    if(ui->labelImg1->y()>433 && ui->labelImg1->y()<=490 && ui->labelImg1->x()<=640 && ui->labelImg1->x()>=140){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),433);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>=433 && ui->labelImg1->y()<=520 && ui->labelImg1->x()>640 && ui->labelImg1->x()<=675){
        qreal t=433+(ui->labelImg1->x()-640);
        if(ui->labelImg1->y()>t){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),t);
            ice_vy=ice_vx;
        }
        else{
            ice_is_falling=true;
        }
    }
    if(ui->labelImg1->y()>468 && ui->labelImg1->y()<=520 && ui->labelImg1->x()<=1137 && ui->labelImg1->x()>=675){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),468);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>408 && ui->labelImg1->y()<=520 && ui->labelImg1->x()>1137){
        ui->labelImg1->move(1137,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>=370 && ui->labelImg1->y()<=520 && ui->labelImg1->x()>1137 && ui->labelImg1->x()<=1170){
        qreal t=370+(1170-ui->labelImg1->x());
        if(ui->labelImg1->y()>t){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),t);
            ice_vy=-ice_vx;
        }
        else{
            ice_is_falling=true;
        }
    }
    if(ui->labelImg1->y()>370 && ui->labelImg1->y()<=520 && ui->labelImg1->x()<=1230 && ui->labelImg1->x()>1170){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),370);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>299 && ui->labelImg1->y()<=360 && ui->labelImg1->x()<=1110 && ui->labelImg1->x()>=905){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),299);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>=299 && ui->labelImg1->y()<360 && ui->labelImg1->x()<=1230 && ui->labelImg1->x()>1110){
        ice_is_falling=true;
    }
    if(ui->labelImg1->y()>=233 && ui->labelImg1->y()<=299 && ui->labelImg1->x()>839 && ui->labelImg1->x()<=905){
        qreal t=233+(ui->labelImg1->x()-839);
        if(ui->labelImg1->y()>t){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),t);
            ice_vy=ice_vx;
        }
        else{
            ice_is_falling=true;
        }
    }
    if(ui->labelImg1->y()>233 && ui->labelImg1->y()<=360 && ui->labelImg1->x()<=839 && ui->labelImg1->x()>592){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),233);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>301 && ui->labelImg1->y()<=360 && ui->labelImg1->x()<=592 && ui->labelImg1->x()>=230){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),301);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>238 && ui->labelImg1->y()<=360 && ui->labelImg1->x()>592 && ui->labelImg1->x()<700){
        ui->labelImg1->move(592,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>233 && ui->labelImg1->y()<=360 && ui->labelImg1->x()<230){
        ui->labelImg1->move(230,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>=228 && ui->labelImg1->y()<301 && ui->labelImg1->x()<=592 && ui->labelImg1->x()>=510){
        ice_is_falling=true;
    }
    if(ui->labelImg1->y()>228 && ui->labelImg1->y()<=360 && ui->labelImg1->x()<230 && ui->labelImg1->x()>=174){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),228);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>=160 && ui->labelImg1->y()<301 && ui->labelImg1->x()<=330 && ui->labelImg1->x()>=230){
        ice_is_falling=true;
    }
    if(ui->labelImg1->y()>173 && ui->labelImg1->y()<=228 && ui->labelImg1->x()<174){
        ui->labelImg1->move(174,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>168 && ui->labelImg1->y()<=360 && ui->labelImg1->x()<174 && ui->labelImg1->x()>=10){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),168);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>=10 && ui->labelImg1->y()<228 && ui->labelImg1->x()<230 && ui->labelImg1->x()>=174){
        ice_is_falling=true;
    }
    if(ui->labelImg1->y()>=67 && ui->labelImg1->y()<=105 && ui->labelImg1->x()>=260 && ui->labelImg1->x()<=295){
        qreal t=67+(296-ui->labelImg1->x());
        if(ui->labelImg1->y()>t){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),t);
            ice_vy=-ice_vx;
        }
        else{
            ice_is_falling=true;
        }
    }
    if(ui->labelImg1->y()>67 && ui->labelImg1->y()<=130 && ui->labelImg1->x()<370 && ui->labelImg1->x()>295){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),67);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>=67 && ui->labelImg1->y()<=100 && ui->labelImg1->x()>=370 && ui->labelImg1->x()<403){
        qreal t=67+(ui->labelImg1->x()-370);
        if(ui->labelImg1->y()>t){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),t);
            ice_vy=ice_vx;
        }
        else{
            ice_is_falling=true;
        }
    }
    if(ui->labelImg1->y()>=105 && ui->labelImg1->y()<=134 && ui->labelImg1->x()<448 && ui->labelImg1->x()>400){
        ui->labelImg1->move(448,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>100 && ui->labelImg1->y()<=190 && ui->labelImg1->x()<448 && ui->labelImg1->x()>=403){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),100);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>=10 && ui->labelImg1->y()<=100 && ui->labelImg1->x()<448 && ui->labelImg1->x()>370){
        ice_is_falling=true;
    }
    if(ui->labelImg1->y()>134 && ui->labelImg1->y()<=190 && ui->labelImg1->x()<=833 && ui->labelImg1->x()>=448){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),134);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>=10 && ui->labelImg1->y()<134 && ui->labelImg1->x()<833 && ui->labelImg1->x()>=448){
        ice_is_falling=true;
    }
    if(ui->labelImg1->y()>=100 && ui->labelImg1->y()<=134 && ui->labelImg1->x()>=833 && ui->labelImg1->x()<=867){
        qreal t=100+(867-ui->labelImg1->x());
        if(ui->labelImg1->y()>t){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),t);
            ice_vy=-ice_vx;
        }
        else{
            ice_is_falling=true;
        }
    }
    if(ui->labelImg1->y()>100 && ui->labelImg1->y()<=190 && ui->labelImg1->x()<972 && ui->labelImg1->x()>867){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),100);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>=100 && ui->labelImg1->y()<=134 && ui->labelImg1->x()>=972 && ui->labelImg1->x()<=1006){
        qreal t=100+(ui->labelImg1->x()-972);
        if(ui->labelImg1->y()>t){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),t);
            ice_vy=ice_vx;
        }
        else{
            ice_is_falling=true;
        }
    }
    if(ui->labelImg1->y()>134 && ui->labelImg1->y()<=190 && ui->labelImg1->x()<=1230 && ui->labelImg1->x()>1006){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),134);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>820 && ui->labelImg1->y()<830 && ui->labelImg1->x()<410 && ui->labelImg1->x()>=10){
        ice_is_falling=true;
        ui->labelImg1->move(ui->labelImg1->x(),830);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>520 && ui->labelImg1->y()<530 && ui->labelImg1->x()<590 && ui->labelImg1->x()>132){
        ice_is_falling=true;
        ui->labelImg1->move(ui->labelImg1->x(),530);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>385 && ui->labelImg1->y()<395 && ui->labelImg1->x()<930 && ui->labelImg1->x()>=10){
        ice_is_falling=true;
        ui->labelImg1->move(ui->labelImg1->x(),395);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>420 && ui->labelImg1->y()<430 && ui->labelImg1->x()<1110 && ui->labelImg1->x()>=930){
        ice_is_falling=true;
        ui->labelImg1->move(ui->labelImg1->x(),430);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>220 && ui->labelImg1->y()<230 && ui->labelImg1->x()<=1230 && ui->labelImg1->x()>505){
        ice_is_falling=true;
        ui->labelImg1->move(ui->labelImg1->x(),230);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>282 && ui->labelImg1->y()<292 && ui->labelImg1->x()<=505 && ui->labelImg1->x()>335){
        ice_is_falling=true;
        ui->labelImg1->move(ui->labelImg1->x(),292);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>150 && ui->labelImg1->y()<160 && ui->labelImg1->x()<=335 && ui->labelImg1->x()>270){
        ice_is_falling=true;
        ui->labelImg1->move(ui->labelImg1->x(),160);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>750 && ui->labelImg1->y()<=830 && ui->labelImg1->x()<410 && ui->labelImg1->x()>400){
        ice_is_falling=true;
        ui->labelImg1->move(410,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>530 && ui->labelImg1->y()<=560 && ui->labelImg1->x()<600 && ui->labelImg1->x()>590){
        ice_is_falling=true;
        ui->labelImg1->move(590,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>440 && ui->labelImg1->y()<=530 && ui->labelImg1->x()<142 && ui->labelImg1->x()>132){
        ice_is_falling=true;
        ui->labelImg1->move(132,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>395 && ui->labelImg1->y()<=430 && ui->labelImg1->x()<940 && ui->labelImg1->x()>930){
        ice_is_falling=true;
        ui->labelImg1->move(930,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>305 && ui->labelImg1->y()<=430 && ui->labelImg1->x()<1110 && ui->labelImg1->x()>1100){
        ice_is_falling=true;
        ui->labelImg1->move(1110,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>230 && ui->labelImg1->y()<=292 && ui->labelImg1->x()<505 && ui->labelImg1->x()>495){
        ice_is_falling=true;
        ui->labelImg1->move(505,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>160 && ui->labelImg1->y()<=292 && ui->labelImg1->x()<345 && ui->labelImg1->x()>335){
        ice_is_falling=true;
        ui->labelImg1->move(335,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>738 && ui->labelImg1->y()<748 && ui->labelImg1->x()<410 && ui->labelImg1->x()>=10){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),738);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>=730 && ui->labelImg1->y()<870 && ui->labelImg1->x()<430 && ui->labelImg1->x()>=410){
        ice_is_falling=true;
    }
    if(ui->labelImg1->y()>680 && ui->labelImg1->y()<690 && ui->labelImg1->x()<=530 && ui->labelImg1->x()>=10){
        ice_is_falling=true;
        ui->labelImg1->move(ui->labelImg1->x(),690);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>690 && ui->labelImg1->y()<750 && ui->labelImg1->x()<540 && ui->labelImg1->x()>530){
        ice_is_falling=true;
        ui->labelImg1->move(530,ui->labelImg1->y());
        ice_vx=0;
    }
    ui->labelImg1->show();
    if(ui->labelImg1->y()>=845 && ui->labelImg1->y()<=887 && ui->labelImg1->x()<=940 && ui->labelImg1->x()>=905){
        if(!blue[1]){
            ui->blue1->setVisible(false);
            blue[1]=1;
            blue_num++;
        }
    }
    if(ui->labelImg1->y()>=550 && ui->labelImg1->y()<=599 && ui->labelImg1->x()<=250 && ui->labelImg1->x()>=215){
        if(!blue[2]){
            ui->blue2->setVisible(false);
            blue[2]=1;
            blue_num++;
        }
    }
    if(ui->labelImg1->y()>=35 && ui->labelImg1->y()<=100 && ui->labelImg1->x()<=780 && ui->labelImg1->x()>=745){
        if(!blue[3]){
            ui->blue3->setVisible(false);
            blue[3]=1;
            blue_num++;
        }
    }
    if(ui->labelImg1->y()>=870 && ui->labelImg1->x()<=730 && ui->labelImg1->x()>=580){
        timer->stop();
        timer_ice->stop();
        timer_fire->stop();
        timer_animation->stop();
        this->game_lose();
    }
    if(ui->labelImg1->y()>=668 && ui->labelImg1->y()<=673 && ui->labelImg1->x()<=930 && ui->labelImg1->x()>=780){
        timer->stop();
        timer_ice->stop();
        timer_fire->stop();
        timer_animation->stop();
        this->game_lose();
    }
}

void Game::ice_update2()
{
    if(ui->labelImg1->y()>866){
        timer->stop();
        timer_ice->stop();
        timer_fire->stop();
        timer_animation->stop();
        this->game_lose();
        return;
    }
    if((ui->labelImg1->y()>504 && ui->labelImg1->y()<=509 && ui->labelImg1->x()<=641 && ui->labelImg1->x()>=622) || (ui->labelImg->y()>504 && ui->labelImg->y()<=509 && ui->labelImg->x()<=641 && ui->labelImg->x()>=622)){
        buttonPressed=true;
        ui->button->setVisible(false);
        ui->block->setVisible(false);
    }
    else{
        buttonPressed=false;
        ui->button->setVisible(true);
        ui->block->setVisible(true);
    }
    if(ui->labelImg1->y()>112 && ui->labelImg1->y()<132 && ui->labelImg1->x()<221 && ui->labelImg1->x()>=10){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),112);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>112 && ui->labelImg1->y()<132 && ui->labelImg1->x()<=1230 && ui->labelImg1->x()>1041){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),112);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>=112 && ui->labelImg1->y()<=440 && ui->labelImg1->x()>=221 && ui->labelImg1->x()<=549){
        qreal t=112+(ui->labelImg1->x()-221);
        if(ui->labelImg1->y()>t && ui->labelImg1->y()<t+15){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),t);
            ice_vx/=1.414;
            ice_vy=ice_vx;
        }
        else{
            ice_is_falling=true;
        }
    }
    if(ui->labelImg1->y()>=112 && ui->labelImg1->y()<=440 && ui->labelImg1->x()>=713 && ui->labelImg1->x()<=1041){
        qreal t=112+(1041-ui->labelImg1->x());
        if(ui->labelImg1->y()>t && ui->labelImg1->y()<t+15){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),t);
            ice_vx/=1.414;
            ice_vy=-ice_vx;
        }
        else{
            ice_is_falling=true;
        }
    }
    if(ui->labelImg1->y()>509 && ui->labelImg1->y()<529 && ui->labelImg1->x()<720 && ui->labelImg1->x()>544){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),509);
        ice_vy=0;
    }
    if(!buttonPressed){
        if(ui->labelImg1->y()>573 && ui->labelImg1->y()<600 && ui->labelImg1->x()<=544 && ui->labelImg1->x()>=413){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),573);
            ice_vy=0;
        }
        if(ui->labelImg1->y()>573 && ui->labelImg1->y()<600 && ui->labelImg1->x()<=852 && ui->labelImg1->x()>=720){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),573);
            ice_vy=0;
        }
        if(ui->labelImg1->y()>639 && ui->labelImg1->y()<666 && ui->labelImg1->x()<=944 && ui->labelImg1->x()>=313){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),639);
            ice_vy=0;
        }
        if(ui->labelImg1->y()>600 && ui->labelImg1->y()<605 && ui->labelImg1->x()<=544 && ui->labelImg1->x()>415){
            ice_is_falling=true;
            ui->labelImg1->move(ui->labelImg1->x(),605);
            ice_vy=0;
        }
        if(ui->labelImg1->y()>600 && ui->labelImg1->y()<605 && ui->labelImg1->x()<850 && ui->labelImg1->x()>=720){
            ice_is_falling=true;
            ui->labelImg1->move(ui->labelImg1->x(),605);
            ice_vy=0;
        }
        if(ui->labelImg1->y()>610 && ui->labelImg1->y()<620 && ui->labelImg1->x()<720 && ui->labelImg1->x()>544){
            ice_is_falling=true;
            ui->labelImg1->move(ui->labelImg1->x(),620);
            ice_vy=0;
        }
    }
    if(ui->labelImg1->y()>514 && ui->labelImg1->y()<=573 && ui->labelImg1->x()<574 && ui->labelImg1->x()>544){
        ui->labelImg1->move(544,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>514 && ui->labelImg1->y()<=573 && ui->labelImg1->x()<720 && ui->labelImg1->x()>690){
        ui->labelImg1->move(720,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>=495 && ui->labelImg1->y()<=630 && ui->labelImg1->x()>=400 && ui->labelImg1->x()<=535){
        qreal t=400+(630-ui->labelImg1->y());
        if(ui->labelImg1->x()<t && ui->labelImg1->x()>t-15){
            ice_is_falling=true;
            ui->labelImg1->move(t,ui->labelImg1->y());
            ice_vx=0;
            ice_vy=0;
        }
    }
    if(ui->labelImg1->y()>=495 && ui->labelImg1->y()<=630 && ui->labelImg1->x()>=730 && ui->labelImg1->x()<=865){
        qreal t=730+(ui->labelImg1->y()-495);
        if(ui->labelImg1->x()>t && ui->labelImg1->x()<t+15){
            ice_is_falling=true;
            ui->labelImg1->move(t,ui->labelImg1->y());
            ice_vx=0;
            ice_vy=0;
        }
    }
    if(ui->labelImg1->y()>241 && ui->labelImg1->y()<261 && ui->labelImg1->x()<249 && ui->labelImg1->x()>=10){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),241);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>241 && ui->labelImg1->y()<261 && ui->labelImg1->x()<=1230 && ui->labelImg1->x()>1012){
        ice_is_falling=false;
        ui->labelImg1->move(ui->labelImg1->x(),241);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>=241 && ui->labelImg1->y()<=440 && ui->labelImg1->x()>=249 && ui->labelImg1->x()<=448){
        qreal t=241+(ui->labelImg1->x()-249);
        if(ui->labelImg1->y()>t && ui->labelImg1->y()<t+15){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),t);
            ice_vx/=1.414;
            ice_vy=ice_vx;
        }
        else{
            ice_is_falling=true;
        }
    }
    if(ui->labelImg1->y()>=241 && ui->labelImg1->y()<=440 && ui->labelImg1->x()>=803 && ui->labelImg1->x()<=1012){
        qreal t=241+(1012-ui->labelImg1->x());
        if(ui->labelImg1->y()>t && ui->labelImg1->y()<t+15){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),t);
            ice_vx/=1.414;
            ice_vy=-ice_vx;
        }
        else{
            ice_is_falling=true;
        }
    }
    if(ui->labelImg1->y()>=470 && ui->labelImg1->y()<=573 && ui->labelImg1->x()>=398 && ui->labelImg1->x()<=501){
        qreal t=470+(501-ui->labelImg1->x());
        if(ui->labelImg1->y()>t && ui->labelImg1->y()<t+15){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),t);
            ice_vx/=1.414;
            ice_vy=-ice_vx;
        }
        else{
            ice_is_falling=true;
        }
    }
    if(ui->labelImg1->y()>=470 && ui->labelImg1->y()<=573 && ui->labelImg1->x()>=760 && ui->labelImg1->x()<=863){
        qreal t=470+(ui->labelImg1->x()-760);
        if(ui->labelImg1->y()>t && ui->labelImg1->y()<t+15){
            ice_is_falling=false;
            ui->labelImg1->move(ui->labelImg1->x(),t);
            ice_vx/=1.414;
            ice_vy=ice_vx;
        }
        else{
            ice_is_falling=true;
        }
    }
    if(ui->labelImg1->y()>=495 && ui->labelImg1->y()<=630 && ui->labelImg1->x()>=300 && ui->labelImg1->x()<=435){
        qreal t=300+(630-ui->labelImg1->y());
        if(ui->labelImg1->x()<t && ui->labelImg1->x()>t-15){
            ice_is_falling=true;
            ui->labelImg1->move(t,ui->labelImg1->y());
            ice_vx=0;
            ice_vy=0;
        }
    }
    if(ui->labelImg1->y()>=495 && ui->labelImg1->y()<=630 && ui->labelImg1->x()>=830 && ui->labelImg1->x()<=965){
        qreal t=830+(ui->labelImg1->y()-495);
        if(ui->labelImg1->x()>t && ui->labelImg1->x()<t+15){
            ice_is_falling=true;
            ui->labelImg1->move(t,ui->labelImg1->y());
            ice_vx=0;
            ice_vy=0;
        }
    }
    if(ui->labelImg1->y()>=165 && ui->labelImg1->y()<=465 && ui->labelImg1->x()>=220 && ui->labelImg1->x()<=520){
        qreal t=220+(ui->labelImg1->y()-165);
        if(ui->labelImg1->x()>t && ui->labelImg1->x()<t+15){
            ice_is_falling=true;
            ui->labelImg1->move(t,ui->labelImg1->y());
            ice_vx=0;
            ice_vy=0;
        }
    }
    if(ui->labelImg1->y()>=165 && ui->labelImg1->y()<=465 && ui->labelImg1->x()>=750 && ui->labelImg1->x()<=1050){
        qreal t=750+(465-ui->labelImg1->y());
        if(ui->labelImg1->x()<t && ui->labelImg1->x()>t-15){
            ice_is_falling=true;
            ui->labelImg1->move(t,ui->labelImg1->y());
            ice_vx=0;
            ice_vy=0;
        }
    }
    if(ui->labelImg1->y()>155 && ui->labelImg1->y()<165 && ui->labelImg1->x()<=226 && ui->labelImg1->x()>=10){
        ice_is_falling=true;
        ui->labelImg1->move(ui->labelImg1->x(),165);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>155 && ui->labelImg1->y()<165 && ui->labelImg1->x()<=1230 && ui->labelImg1->x()>=1036){
        ice_is_falling=true;
        ui->labelImg1->move(ui->labelImg1->x(),165);
        ice_vy=0;
    }
    if(ui->labelImg1->y()>590 && ui->labelImg1->y()<610 && ui->labelImg1->x()<403 && ui->labelImg1->x()>398){
        ui->labelImg1->move(400,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>590 && ui->labelImg1->y()<610 && ui->labelImg1->x()<800 && ui->labelImg1->x()>795){
        ui->labelImg1->move(800,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>450 && ui->labelImg1->y()<490 && ui->labelImg1->x()<525 && ui->labelImg1->x()>505){
        qreal t;
        if(ui->labelImg1->x()<515)
            t=505;
        else
            t=525;
        ui->labelImg1->move(t,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>450 && ui->labelImg1->y()<490 && ui->labelImg1->x()<750 && ui->labelImg1->x()>730){
        qreal t;
        if(ui->labelImg1->x()<740)
            t=730;
        else
            t=750;
        ui->labelImg1->move(t,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>450 && ui->labelImg1->y()<490 && ui->labelImg1->x()<425 && ui->labelImg1->x()>405){
        qreal t;
        if(ui->labelImg1->x()<415)
            t=405;
        else
            t=425;
        ui->labelImg1->move(t,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>450 && ui->labelImg1->y()<490 && ui->labelImg1->x()<850 && ui->labelImg1->x()>830){
        qreal t;
        if(ui->labelImg1->x()<840)
            t=830;
        else
            t=850;
        ui->labelImg1->move(t,ui->labelImg1->y());
        ice_vx=0;
    }
    if(ui->labelImg1->y()>=509 && ui->labelImg1->y()<573 && ui->labelImg1->x()>534 && ui->labelImg1->x()<=544){
        ice_is_falling=true;
    }
    if(ui->labelImg1->y()>=509 && ui->labelImg1->y()<573 && ui->labelImg1->x()>=720 && ui->labelImg1->x()<730){
        ice_is_falling=true;
    }
    if(ui->labelImg1->y()>=440 && ui->labelImg1->y()<445 && ui->labelImg1->x()>=549 && ui->labelImg1->x()<554){
        ice_is_falling=true;
    }
    if(ui->labelImg1->y()>=440 && ui->labelImg1->y()<445 && ui->labelImg1->x()>708 && ui->labelImg1->x()<=713){
        ice_is_falling=true;
    }
    if(ui->labelImg1->y()>=440 && ui->labelImg1->y()<445 && ui->labelImg1->x()>=449 && ui->labelImg1->x()<454){
        ice_is_falling=true;
    }
    if(ui->labelImg1->y()>=440 && ui->labelImg1->y()<445 && ui->labelImg1->x()>808 && ui->labelImg1->x()<=813){
        ice_is_falling=true;
    }
    if(buttonPressed && ui->labelImg1->y()>=573){
        ice_is_falling=true;
    }
    if(ui->labelImg1->y()>=480 && ui->labelImg1->y()<=509 && ui->labelImg1->x()<=600 && ui->labelImg1->x()>=565){
        if(!blue[4]){
            ui->blue4->setVisible(false);
            blue[4]=1;
            blue_num++;
        }
    }
    if(ui->labelImg1->y()>=210 && ui->labelImg1->y()<=241 && ui->labelImg1->x()<=180 && ui->labelImg1->x()>=145){
        if(!blue[5]){
            ui->blue5->setVisible(false);
            blue[5]=1;
            blue_num++;
        }
    }
    if(ui->labelImg1->y()>=600 && ui->labelImg1->y()<=639 && ui->labelImg1->x()<=520 && ui->labelImg1->x()>=485){
        if(!blue[6]){
            ui->blue6->setVisible(false);
            blue[6]=1;
            blue_num++;
        }
    }
}

void Game::fire_update()
{
    quint32 dt=40;
    if(fire_is_falling){
        fire_vy+=280*dt/1000;
        ui->labelImg->move(ui->labelImg->x(),ui->labelImg->y()+fire_vy*dt/1000);
    }
    if(leftPressed || rightPressed){
        ui->labelImg->move(ui->labelImg->x()+fire_vx*dt/1000,ui->labelImg->y());
    }
    if(ui->labelImg->x()<10){
        ui->labelImg->move(10,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->x()>1230){
        ui->labelImg->move(1230,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()<30){
        ui->labelImg->move(ui->labelImg->x(),30);
        fire_vy=0;
    }
    if(game_num==2){
        fire_update2();
        return;
    }
    if(ui->labelImg->y()>870 &&(ui->labelImg->x()>=734 || ui->labelImg->x()<=576)){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),870);
        fire_vy=0;
    }
    if(ui->labelImg->y()>=870 && ui->labelImg->x()>=576 && ui->labelImg->x()<=610){
        qreal t=870+(ui->labelImg->x()-576)/2;
        if(ui->labelImg->y()>t){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),t);
            fire_vy=fire_vx/2;
        }
        else{
            fire_is_falling=true;
        }
    }
    if(ui->labelImg->y()>=870 && ui->labelImg->x()>=700 && ui->labelImg->x()<=734){
        qreal t=870+(734-ui->labelImg->x())/2;
        if(ui->labelImg->y()>t){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),t);
            fire_vy=-fire_vx/2;
        }
        else{
            fire_is_falling=true;
        }
    }
    if(ui->labelImg->y()>887){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),887);
        fire_vy=0;
    }
    if(ui->labelImg->x()>1130 && ui->labelImg->y()<=870 && ui->labelImg->y()>810){
        ui->labelImg->move(1130,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->x()>1170 && ui->labelImg->y()>770){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),770);
        fire_vy=0;
    }
    if(ui->labelImg->y()>=770 && ui->labelImg->x()>=1130 && ui->labelImg->x()<=1170){
        qreal t=770+(1170-ui->labelImg->x());
        if(ui->labelImg->y()>t){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),t);
            fire_vy=-fire_vx;
        }
        else{
            fire_is_falling=true;
        }
    }
    if(ui->labelImg->y()>=668 && ui->labelImg->y()<=710 && ui->labelImg->x()>1078 && ui->labelImg->x()<=1115){
        qreal t=668+(ui->labelImg->x()-1078);
        if(ui->labelImg->y()>t){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),t);
            fire_vy=fire_vx;
        }
        else{
            fire_is_falling=true;
        }
    }
    if(ui->labelImg->y()>668 && ui->labelImg->y()<=710 && ui->labelImg->x()<=1078 && ui->labelImg->x()>=605){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),668);
        fire_vy=0;
    }
    if(ui->labelImg->y()>=599 && ui->labelImg->y()<=710 && ui->labelImg->x()>536 && ui->labelImg->x()<605){
        qreal t=599+(ui->labelImg->x()-536);
        if(ui->labelImg->y()>t){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),t);
            fire_vy=fire_vx;
        }
        else{
            fire_is_falling=true;
        }
    }
    if(ui->labelImg->y()>599 && ui->labelImg->y()<=710 && ui->labelImg->x()<=536 && ui->labelImg->x()>=140){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),599);
        fire_vy=0;
    }
    if(ui->labelImg->y()>543 && ui->labelImg->y()<=599 && ui->labelImg->x()<140){
        ui->labelImg->move(140,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>538 && ui->labelImg->y()<=710 && ui->labelImg->x()<140 && ui->labelImg->x()>=75){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),538);
        fire_vy=0;
    }
    if(ui->labelImg->y()>=500 && ui->labelImg->y()<599 && ui->labelImg->x()<=536 && ui->labelImg->x()>=140){
        fire_is_falling=true;
    }
    if(ui->labelImg->y()>489 && ui->labelImg->y()<=538 && ui->labelImg->x()<75){
        ui->labelImg->move(75,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>484 && ui->labelImg->y()<=710 && ui->labelImg->x()<75 && ui->labelImg->x()>=10){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),484);
        fire_vy=0;
    }
    if(ui->labelImg->y()>=390 && ui->labelImg->y()<538 && ui->labelImg->x()<140 && ui->labelImg->x()>=75){
        fire_is_falling=true;
    }
    if(ui->labelImg->y()>433 && ui->labelImg->y()<=490 && ui->labelImg->x()<=640 && ui->labelImg->x()>=140){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),433);
        fire_vy=0;
    }
    if(ui->labelImg->y()>=433 && ui->labelImg->y()<=520 && ui->labelImg->x()>640 && ui->labelImg->x()<=675){
        qreal t=433+(ui->labelImg->x()-640);
        if(ui->labelImg->y()>t){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),t);
            fire_vy=fire_vx;
        }
        else{
            fire_is_falling=true;
        }
    }
    if(ui->labelImg->y()>468 && ui->labelImg->y()<=520 && ui->labelImg->x()<=1137 && ui->labelImg->x()>=675){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),468);
        fire_vy=0;
    }
    if(ui->labelImg->y()>408 && ui->labelImg->y()<=520 && ui->labelImg->x()>1137){
        ui->labelImg->move(1137,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>=370 && ui->labelImg->y()<=520 && ui->labelImg->x()>1137 && ui->labelImg->x()<=1170){
        qreal t=370+(1170-ui->labelImg->x());
        if(ui->labelImg->y()>t){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),t);
            fire_vy=-fire_vx;
        }
        else{
            fire_is_falling=true;
        }
    }
    if(ui->labelImg->y()>370 && ui->labelImg->y()<=520 && ui->labelImg->x()<=1230 && ui->labelImg->x()>1170){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),370);
        fire_vy=0;
    }
    if(ui->labelImg->y()>299 && ui->labelImg->y()<=360 && ui->labelImg->x()<=1110 && ui->labelImg->x()>=905){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),299);
        fire_vy=0;
    }
    if(ui->labelImg->y()>=299 && ui->labelImg->y()<360 && ui->labelImg->x()<=1230 && ui->labelImg->x()>1110){
        fire_is_falling=true;
    }
    if(ui->labelImg->y()>=233 && ui->labelImg->y()<=299 && ui->labelImg->x()>839 && ui->labelImg->x()<=905){
        qreal t=233+(ui->labelImg->x()-839);
        if(ui->labelImg->y()>t){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),t);
            fire_vy=fire_vx;
        }
        else{
            fire_is_falling=true;
        }
    }
    if(ui->labelImg->y()>233 && ui->labelImg->y()<=360 && ui->labelImg->x()<=839 && ui->labelImg->x()>592){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),233);
        fire_vy=0;
    }
    if(ui->labelImg->y()>301 && ui->labelImg->y()<=360 && ui->labelImg->x()<=592 && ui->labelImg->x()>=230){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),301);
        fire_vy=0;
    }
    if(ui->labelImg->y()>238 && ui->labelImg->y()<=360 && ui->labelImg->x()>592 && ui->labelImg->x()<700){
        ui->labelImg->move(592,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>233 && ui->labelImg->y()<=360 && ui->labelImg->x()<230){
        ui->labelImg->move(230,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>=228 && ui->labelImg->y()<301 && ui->labelImg->x()<=592 && ui->labelImg->x()>=510){
        fire_is_falling=true;
    }
    if(ui->labelImg->y()>228 && ui->labelImg->y()<=360 && ui->labelImg->x()<230 && ui->labelImg->x()>=174){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),228);
        fire_vy=0;
    }
    if(ui->labelImg->y()>=160 && ui->labelImg->y()<301 && ui->labelImg->x()<=330 && ui->labelImg->x()>=230){
        fire_is_falling=true;
    }
    if(ui->labelImg->y()>173 && ui->labelImg->y()<=228 && ui->labelImg->x()<174){
        ui->labelImg->move(174,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>168 && ui->labelImg->y()<=360 && ui->labelImg->x()<174 && ui->labelImg->x()>=10){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),168);
        fire_vy=0;
    }
    if(ui->labelImg->y()>=10 && ui->labelImg->y()<228 && ui->labelImg->x()<230 && ui->labelImg->x()>=174){
        fire_is_falling=true;
    }
    if(ui->labelImg->y()>=67 && ui->labelImg->y()<=105 && ui->labelImg->x()>=260 && ui->labelImg->x()<=295){
        qreal t=67+(296-ui->labelImg->x());
        if(ui->labelImg->y()>t){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),t);
            fire_vy=-fire_vx;
        }
        else{
            fire_is_falling=true;
        }
    }
    if(ui->labelImg->y()>67 && ui->labelImg->y()<=130 && ui->labelImg->x()<370 && ui->labelImg->x()>295){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),67);
        fire_vy=0;
    }
    if(ui->labelImg->y()>=67 && ui->labelImg->y()<=100 && ui->labelImg->x()>=370 && ui->labelImg->x()<403){
        qreal t=67+(ui->labelImg->x()-370);
        if(ui->labelImg->y()>t){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),t);
            fire_vy=fire_vx;
        }
        else{
            fire_is_falling=true;
        }
    }
    if(ui->labelImg->y()>=105 && ui->labelImg->y()<=134 && ui->labelImg->x()<448 && ui->labelImg->x()>400){
        ui->labelImg->move(448,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>100 && ui->labelImg->y()<=190 && ui->labelImg->x()<448 && ui->labelImg->x()>=403){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),100);
        fire_vy=0;
    }
    if(ui->labelImg->y()>=10 && ui->labelImg->y()<=100 && ui->labelImg->x()<448 && ui->labelImg->x()>370){
        fire_is_falling=true;
    }
    if(ui->labelImg->y()>134 && ui->labelImg->y()<=190 && ui->labelImg->x()<=833 && ui->labelImg->x()>=448){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),134);
        fire_vy=0;
    }
    if(ui->labelImg->y()>=10 && ui->labelImg->y()<134 && ui->labelImg->x()<833 && ui->labelImg->x()>=448){
        fire_is_falling=true;
    }
    if(ui->labelImg->y()>=100 && ui->labelImg->y()<=134 && ui->labelImg->x()>=833 && ui->labelImg->x()<=867){
        qreal t=100+(867-ui->labelImg->x());
        if(ui->labelImg->y()>t){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),t);
            fire_vy=-fire_vx;
        }
        else{
            fire_is_falling=true;
        }
    }
    if(ui->labelImg->y()>100 && ui->labelImg->y()<=190 && ui->labelImg->x()<972 && ui->labelImg->x()>867){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),100);
        fire_vy=0;
    }
    if(ui->labelImg->y()>=100 && ui->labelImg->y()<=134 && ui->labelImg->x()>=972 && ui->labelImg->x()<=1006){
        qreal t=100+(ui->labelImg->x()-972);
        if(ui->labelImg->y()>t){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),t);
            fire_vy=fire_vx;
        }
        else{
            fire_is_falling=true;
        }
    }
    if(ui->labelImg->y()>134 && ui->labelImg->y()<=190 && ui->labelImg->x()<=1230 && ui->labelImg->x()>1006){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),134);
        fire_vy=0;
    }
    if(ui->labelImg->y()>820 && ui->labelImg->y()<830 && ui->labelImg->x()<410 && ui->labelImg->x()>=10){
        fire_is_falling=true;
        ui->labelImg->move(ui->labelImg->x(),830);
        fire_vy=0;
    }
    if(ui->labelImg->y()>520 && ui->labelImg->y()<530 && ui->labelImg->x()<590 && ui->labelImg->x()>132){
        fire_is_falling=true;
        ui->labelImg->move(ui->labelImg->x(),530);
        fire_vy=0;
    }
    if(ui->labelImg->y()>385 && ui->labelImg->y()<395 && ui->labelImg->x()<930 && ui->labelImg->x()>=10){
        fire_is_falling=true;
        ui->labelImg->move(ui->labelImg->x(),395);
        fire_vy=0;
    }
    if(ui->labelImg->y()>420 && ui->labelImg->y()<430 && ui->labelImg->x()<1110 && ui->labelImg->x()>=930){
        fire_is_falling=true;
        ui->labelImg->move(ui->labelImg->x(),430);
        fire_vy=0;
    }
    if(ui->labelImg->y()>220 && ui->labelImg->y()<230 && ui->labelImg->x()<=1230 && ui->labelImg->x()>505){
        fire_is_falling=true;
        ui->labelImg->move(ui->labelImg->x(),230);
        fire_vy=0;
    }
    if(ui->labelImg->y()>282 && ui->labelImg->y()<292 && ui->labelImg->x()<=505 && ui->labelImg->x()>335){
        fire_is_falling=true;
        ui->labelImg->move(ui->labelImg->x(),292);
        fire_vy=0;
    }
    if(ui->labelImg->y()>150 && ui->labelImg->y()<160 && ui->labelImg->x()<=335 && ui->labelImg->x()>270){
        fire_is_falling=true;
        ui->labelImg->move(ui->labelImg->x(),160);
        fire_vy=0;
    }
    if(ui->labelImg->y()>750 && ui->labelImg->y()<=830 && ui->labelImg->x()<410 && ui->labelImg->x()>400){
        fire_is_falling=true;
        ui->labelImg->move(410,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>530 && ui->labelImg->y()<=560 && ui->labelImg->x()<600 && ui->labelImg->x()>590){
        fire_is_falling=true;
        ui->labelImg->move(590,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>440 && ui->labelImg->y()<=530 && ui->labelImg->x()<142 && ui->labelImg->x()>132){
        fire_is_falling=true;
        ui->labelImg->move(132,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>395 && ui->labelImg->y()<=430 && ui->labelImg->x()<940 && ui->labelImg->x()>930){
        fire_is_falling=true;
        ui->labelImg->move(930,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>305 && ui->labelImg->y()<=430 && ui->labelImg->x()<1110 && ui->labelImg->x()>1100){
        fire_is_falling=true;
        ui->labelImg->move(1110,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>230 && ui->labelImg->y()<=292 && ui->labelImg->x()<505 && ui->labelImg->x()>495){
        fire_is_falling=true;
        ui->labelImg->move(505,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>160 && ui->labelImg->y()<=292 && ui->labelImg->x()<345 && ui->labelImg->x()>335){
        fire_is_falling=true;
        ui->labelImg->move(335,ui->labelImg->y());
        fire_vx=0;
    }
    ui->labelImg->show();
    if(ui->labelImg->y()>=845 && ui->labelImg->y()<=887 && ui->labelImg->x()<=670 && ui->labelImg->x()>=635){
        if(!red[1]){
            red[1]=1;
            ui->red1->setVisible(false);
            red_num++;
        }
    }
    if(ui->labelImg->y()>=550 && ui->labelImg->y()<=599 && ui->labelImg->x()<=410 && ui->labelImg->x()>=375){
        if(!red[2]){
            red[2]=1;
            ui->red2->setVisible(false);
            red_num++;
        }
    }
    if(ui->labelImg->y()>=35 && ui->labelImg->y()<=100 && ui->labelImg->x()<=620 && ui->labelImg->x()>=585){
        if(!red[3]){
            red[3]=1;
            ui->red3->setVisible(false);
            red_num++;
        }
    }
    if(ui->labelImg->y()>=870 && ui->labelImg->x()<=995 && ui->labelImg->x()>=845){
        timer->stop();
        timer_ice->stop();
        timer_fire->stop();
        timer_animation->stop();
        this->game_lose();
    }
    if(ui->labelImg->y()>=668 && ui->labelImg->y()<=673 && ui->labelImg->x()<=930 && ui->labelImg->x()>=780){
        timer->stop();
        timer_ice->stop();
        timer_fire->stop();
        timer_animation->stop();
        this->game_lose();
    }
}

void Game::fire_update2()
{
    if(ui->labelImg->y()>866){
        timer->stop();
        timer_ice->stop();
        timer_fire->stop();
        timer_animation->stop();
        this->game_lose();
        return;
    }
    if((ui->labelImg1->y()>504 && ui->labelImg1->y()<=509 && ui->labelImg1->x()<=641 && ui->labelImg1->x()>=622) || (ui->labelImg->y()>504 && ui->labelImg->y()<=509 && ui->labelImg->x()<=641 && ui->labelImg->x()>=622)){
        buttonPressed=true;
        ui->button->setVisible(false);
        ui->block->setVisible(false);
    }
    else{
        buttonPressed=false;
        ui->button->setVisible(true);
        ui->block->setVisible(true);
    }
    if(ui->labelImg->y()>112 && ui->labelImg->y()<132 && ui->labelImg->x()<221 && ui->labelImg->x()>=10){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),112);
        fire_vy=0;
    }
    if(ui->labelImg->y()>112 && ui->labelImg->y()<132 && ui->labelImg->x()<=1230 && ui->labelImg->x()>1041){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),112);
        fire_vy=0;
    }
    if(ui->labelImg->y()>=112 && ui->labelImg->y()<=440 && ui->labelImg->x()>=221 && ui->labelImg->x()<=549){
        qreal t=112+(ui->labelImg->x()-221);
        if(ui->labelImg->y()>t && ui->labelImg->y()<t+15){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),t);
            fire_vx/=1.414;
            fire_vy=fire_vx;
        }
        else{
            fire_is_falling=true;
        }
    }
    if(ui->labelImg->y()>=112 && ui->labelImg->y()<=440 && ui->labelImg->x()>=713 && ui->labelImg->x()<=1041){
        qreal t=112+(1041-ui->labelImg->x());
        if(ui->labelImg->y()>t && ui->labelImg->y()<t+15){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),t);
            fire_vx/=1.414;
            fire_vy=-fire_vx;
        }
        else{
            fire_is_falling=true;
        }
    }
    if(ui->labelImg->y()>509 && ui->labelImg->y()<529 && ui->labelImg->x()<720 && ui->labelImg->x()>544){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),509);
        fire_vy=0;
    }
    if(!buttonPressed){
        if(ui->labelImg->y()>573 && ui->labelImg->y()<600 && ui->labelImg->x()<=544 && ui->labelImg->x()>=413){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),573);
            fire_vy=0;
        }
        if(ui->labelImg->y()>573 && ui->labelImg->y()<600 && ui->labelImg->x()<=852 && ui->labelImg->x()>=720){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),573);
            fire_vy=0;
        }
        if(ui->labelImg->y()>639 && ui->labelImg->y()<666 && ui->labelImg->x()<=944 && ui->labelImg->x()>=313){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),639);
            fire_vy=0;
        }
        if(ui->labelImg->y()>600 && ui->labelImg->y()<605 && ui->labelImg->x()<=544 && ui->labelImg->x()>415){
            fire_is_falling=true;
            ui->labelImg->move(ui->labelImg->x(),605);
            fire_vy=0;
        }
        if(ui->labelImg->y()>600 && ui->labelImg->y()<605 && ui->labelImg->x()<850 && ui->labelImg->x()>=720){
            fire_is_falling=true;
            ui->labelImg->move(ui->labelImg->x(),605);
            fire_vy=0;
        }
        if(ui->labelImg->y()>610 && ui->labelImg->y()<620 && ui->labelImg->x()<720 && ui->labelImg->x()>544){
            fire_is_falling=true;
            ui->labelImg->move(ui->labelImg->x(),620);
            fire_vy=0;
        }
    }
    if(ui->labelImg->y()>514 && ui->labelImg->y()<=573 && ui->labelImg->x()<574 && ui->labelImg->x()>544){
        ui->labelImg->move(544,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>514 && ui->labelImg->y()<=573 && ui->labelImg->x()<720 && ui->labelImg->x()>690){
        ui->labelImg->move(720,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>=495 && ui->labelImg->y()<=630 && ui->labelImg->x()>=400 && ui->labelImg->x()<=535){
        qreal t=400+(630-ui->labelImg->y());
        if(ui->labelImg->x()<t && ui->labelImg->x()>t-15){
            fire_is_falling=true;
            ui->labelImg->move(t,ui->labelImg->y());
            fire_vx=0;
            fire_vy=0;
        }
    }
    if(ui->labelImg->y()>=495 && ui->labelImg->y()<=630 && ui->labelImg->x()>=730 && ui->labelImg->x()<=865){
        qreal t=730+(ui->labelImg->y()-495);
        if(ui->labelImg->x()>t && ui->labelImg->x()<t+15){
            fire_is_falling=true;
            ui->labelImg->move(t,ui->labelImg->y());
            fire_vx=0;
            fire_vy=0;
        }
    }
    if(ui->labelImg->y()>241 && ui->labelImg->y()<261 && ui->labelImg->x()<249 && ui->labelImg->x()>=10){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),241);
        fire_vy=0;
    }
    if(ui->labelImg->y()>241 && ui->labelImg->y()<261 && ui->labelImg->x()<=1230 && ui->labelImg->x()>1012){
        fire_is_falling=false;
        ui->labelImg->move(ui->labelImg->x(),241);
        fire_vy=0;
    }
    if(ui->labelImg->y()>=241 && ui->labelImg->y()<=440 && ui->labelImg->x()>=249 && ui->labelImg->x()<=448){
        qreal t=241+(ui->labelImg->x()-249);
        if(ui->labelImg->y()>t && ui->labelImg->y()<t+15){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),t);
            fire_vx/=1.414;
            fire_vy=fire_vx;
        }
        else{
            fire_is_falling=true;
        }
    }
    if(ui->labelImg->y()>=241 && ui->labelImg->y()<=440 && ui->labelImg->x()>=803 && ui->labelImg->x()<=1012){
        qreal t=241+(1012-ui->labelImg->x());
        if(ui->labelImg->y()>t && ui->labelImg->y()<t+15){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),t);
            fire_vx/=1.414;
            fire_vy=-fire_vx;
        }
        else{
            fire_is_falling=true;
        }
    }
    if(ui->labelImg->y()>=470 && ui->labelImg->y()<=573 && ui->labelImg->x()>=398 && ui->labelImg->x()<=501){
        qreal t=470+(501-ui->labelImg->x());
        if(ui->labelImg->y()>t && ui->labelImg->y()<t+15){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),t);
            fire_vx/=1.414;
            fire_vy=-fire_vx;
        }
        else{
            fire_is_falling=true;
        }
    }
    if(ui->labelImg->y()>=470 && ui->labelImg->y()<=573 && ui->labelImg->x()>=760 && ui->labelImg->x()<=863){
        qreal t=470+(ui->labelImg->x()-760);
        if(ui->labelImg->y()>t && ui->labelImg->y()<t+15){
            fire_is_falling=false;
            ui->labelImg->move(ui->labelImg->x(),t);
            fire_vx/=1.414;
            fire_vy=fire_vx;
        }
        else{
            fire_is_falling=true;
        }
    }
    if(ui->labelImg->y()>=495 && ui->labelImg->y()<=630 && ui->labelImg->x()>=300 && ui->labelImg->x()<=435){
        qreal t=300+(630-ui->labelImg->y());
        if(ui->labelImg->x()<t && ui->labelImg->x()>t-15){
            fire_is_falling=true;
            ui->labelImg->move(t,ui->labelImg->y());
            fire_vx=0;
            fire_vy=0;
        }
    }
    if(ui->labelImg->y()>=495 && ui->labelImg->y()<=630 && ui->labelImg->x()>=830 && ui->labelImg->x()<=965){
        qreal t=830+(ui->labelImg->y()-495);
        if(ui->labelImg->x()>t && ui->labelImg->x()<t+15){
            fire_is_falling=true;
            ui->labelImg->move(t,ui->labelImg->y());
            fire_vx=0;
            fire_vy=0;
        }
    }
    if(ui->labelImg->y()>=165 && ui->labelImg->y()<=465 && ui->labelImg->x()>=220 && ui->labelImg->x()<=520){
        qreal t=220+(ui->labelImg->y()-165);
        if(ui->labelImg->x()>t && ui->labelImg->x()<t+15){
            fire_is_falling=true;
            ui->labelImg->move(t,ui->labelImg->y());
            fire_vx=0;
            fire_vy=0;
        }
    }
    if(ui->labelImg->y()>=165 && ui->labelImg->y()<=465 && ui->labelImg->x()>=750 && ui->labelImg->x()<=1050){
        qreal t=750+(465-ui->labelImg->y());
        if(ui->labelImg->x()<t && ui->labelImg->x()>t-15){
            fire_is_falling=true;
            ui->labelImg->move(t,ui->labelImg->y());
            fire_vx=0;
            fire_vy=0;
        }
    }
    if(ui->labelImg->y()>155 && ui->labelImg->y()<165 && ui->labelImg->x()<=226 && ui->labelImg->x()>=10){
        fire_is_falling=true;
        ui->labelImg->move(ui->labelImg->x(),165);
        fire_vy=0;
    }
    if(ui->labelImg->y()>155 && ui->labelImg->y()<165 && ui->labelImg->x()<=1230 && ui->labelImg->x()>=1036){
        fire_is_falling=true;
        ui->labelImg->move(ui->labelImg->x(),165);
        fire_vy=0;
    }
    if(ui->labelImg->y()>590 && ui->labelImg->y()<610 && ui->labelImg->x()<403 && ui->labelImg->x()>398){
        ui->labelImg->move(400,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>590 && ui->labelImg->y()<610 && ui->labelImg->x()<800 && ui->labelImg->x()>795){
        ui->labelImg->move(800,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>450 && ui->labelImg->y()<490 && ui->labelImg->x()<525 && ui->labelImg->x()>505){
        qreal t;
        if(ui->labelImg->x()<515)
            t=505;
        else
            t=525;
        ui->labelImg->move(t,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>450 && ui->labelImg->y()<490 && ui->labelImg->x()<750 && ui->labelImg->x()>730){
        qreal t;
        if(ui->labelImg->x()<740)
            t=730;
        else
            t=750;
        ui->labelImg->move(t,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>450 && ui->labelImg->y()<490 && ui->labelImg->x()<425 && ui->labelImg->x()>405){
        qreal t;
        if(ui->labelImg->x()<415)
            t=405;
        else
            t=425;
        ui->labelImg->move(t,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>450 && ui->labelImg->y()<490 && ui->labelImg->x()<850 && ui->labelImg->x()>830){
        qreal t;
        if(ui->labelImg->x()<840)
            t=830;
        else
            t=850;
        ui->labelImg->move(t,ui->labelImg->y());
        fire_vx=0;
    }
    if(ui->labelImg->y()>=509 && ui->labelImg->y()<573 && ui->labelImg->x()>534 && ui->labelImg->x()<=544){
        fire_is_falling=true;
    }
    if(ui->labelImg->y()>=509 && ui->labelImg->y()<573 && ui->labelImg->x()>=720 && ui->labelImg->x()<730){
        fire_is_falling=true;
    }
    if(ui->labelImg->y()>=440 && ui->labelImg->y()<445 && ui->labelImg->x()>=549 && ui->labelImg->x()<554){
        fire_is_falling=true;
    }
    if(ui->labelImg->y()>=440 && ui->labelImg->y()<445 && ui->labelImg->x()>708 && ui->labelImg->x()<=713){
        fire_is_falling=true;
    }
    if(ui->labelImg->y()>=440 && ui->labelImg->y()<445 && ui->labelImg->x()>=449 && ui->labelImg->x()<454){
        fire_is_falling=true;
    }
    if(ui->labelImg->y()>=440 && ui->labelImg->y()<445 && ui->labelImg->x()>808 && ui->labelImg->x()<=813){
        fire_is_falling=true;
    }
    if(buttonPressed && ui->labelImg->y()>=573){
        fire_is_falling=true;
    }
    if(ui->labelImg->y()>=480 && ui->labelImg->y()<=509 && ui->labelImg->x()<=700 && ui->labelImg->x()>=665){
        if(!red[4]){
            red[4]=1;
            ui->red4->setVisible(false);
            red_num++;
        }
    }
    if(ui->labelImg->y()>=70 && ui->labelImg->y()<=112 && ui->labelImg->x()<=1090 && ui->labelImg->x()>=1055){
        if(!red[5]){
            red[5]=1;
            ui->red5->setVisible(false);
            red_num++;
        }
    }
    if(ui->labelImg->y()>=600 && ui->labelImg->y()<=639 && ui->labelImg->x()<=780 && ui->labelImg->x()>=745){
        if(!red[6]){
            red[6]=1;
            ui->red6->setVisible(false);
            red_num++;
        }
    }
}

void Game::animation_update()
{
    if(ice_is_falling){
        ui->labelImg1->setStyleSheet("background-image: url(:/new/prefix1/picture/ice_jump.png);");
        ice_cnt=0;
    }
    else if(!aPressed && !dPressed){
        ui->labelImg1->setStyleSheet("background-image: url(:/new/prefix1/picture/ice.png);");
        ice_cnt=0;
    }
    else if(aPressed){
        ice_cnt+=1;
        if(ice_cnt%4==1)
            ui->labelImg1->setStyleSheet("background-image: url(:/new/prefix1/picture/ice_left1.png);");
        else if(ice_cnt%4==2)
            ui->labelImg1->setStyleSheet("background-image: url(:/new/prefix1/picture/ice_left2.png);");
        else if(ice_cnt%4==3)
            ui->labelImg1->setStyleSheet("background-image: url(:/new/prefix1/picture/ice_left3.png);");
        else
            ui->labelImg1->setStyleSheet("background-image: url(:/new/prefix1/picture/ice_left4.png);");
    }
    else if(dPressed){
        ice_cnt+=1;
        if(ice_cnt%4==1)
            ui->labelImg1->setStyleSheet("background-image: url(:/new/prefix1/picture/ice_right1.png);");
        else if(ice_cnt%4==2)
            ui->labelImg1->setStyleSheet("background-image: url(:/new/prefix1/picture/ice_right2.png);");
        else if(ice_cnt%4==3)
            ui->labelImg1->setStyleSheet("background-image: url(:/new/prefix1/picture/ice_right3.png);");
        else
            ui->labelImg1->setStyleSheet("background-image: url(:/new/prefix1/picture/ice_right4.png);");
    }

    if(fire_is_falling){
        ui->labelImg->setStyleSheet("background-image: url(:/new/prefix1/picture/fire_jump.png);");
        fire_cnt=0;
    }
    else if(!leftPressed && !rightPressed){
        ui->labelImg->setStyleSheet("background-image: url(:/new/prefix1/picture/fire.png);");
        fire_cnt=0;
    }
    else if(leftPressed){
        fire_cnt+=1;
        if(fire_cnt%4==1)
            ui->labelImg->setStyleSheet("background-image: url(:/new/prefix1/picture/fire_left1.png);");
        else if(fire_cnt%4==2)
            ui->labelImg->setStyleSheet("background-image: url(:/new/prefix1/picture/fire_left2.png);");
        else if(fire_cnt%4==3)
            ui->labelImg->setStyleSheet("background-image: url(:/new/prefix1/picture/fire_left3.png);");
        else
            ui->labelImg->setStyleSheet("background-image: url(:/new/prefix1/picture/fire_left4.png);");
    }
    else if(rightPressed){
        fire_cnt+=1;
        if(fire_cnt%4==1)
            ui->labelImg->setStyleSheet("background-image: url(:/new/prefix1/picture/fire_right1.png);");
        else if(fire_cnt%4==2)
            ui->labelImg->setStyleSheet("background-image: url(:/new/prefix1/picture/fire_right2.png);");
        else if(fire_cnt%4==3)
            ui->labelImg->setStyleSheet("background-image: url(:/new/prefix1/picture/fire_right3.png);");
        else
            ui->labelImg->setStyleSheet("background-image: url(:/new/prefix1/picture/fire_right4.png);");
    }

    ui->labelImg1->show();
    ui->labelImg->show();
}

void Game::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_A){
        aPressed=true;
        ice_vx=-140;
    }
    if(event->key()==Qt::Key_D){
        dPressed=true;
        ice_vx=140;
    }
    if(event->key()==Qt::Key_W){
        wPressed=true;
        if(!ice_is_falling){
            ice_vy=-200;
            ice_is_falling=true;
        }
    }

    if(event->key()==Qt::Key_Left){
        leftPressed=true;
        fire_vx=-140;
    }
    if(event->key()==Qt::Key_Right){
        rightPressed=true;
        fire_vx=140;
    }
    if(event->key()==Qt::Key_Up){
        upPressed=true;
        if(!fire_is_falling){
            fire_vy=-200;
            fire_is_falling=true;
        }
    }

    QWidget::keyPressEvent(event);
}

void Game::keyReleaseEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_A){
        aPressed=false;
        ice_vx=0;
    }
    if(event->key()==Qt::Key_D){
        dPressed=false;
        ice_vx=0;
    }
    if(event->key()==Qt::Key_W){
        wPressed=false;
    }

    if(event->key()==Qt::Key_Left){
        leftPressed=false;
        fire_vx=0;
    }
    if(event->key()==Qt::Key_Right){
        rightPressed=false;
        fire_vx=0;
    }
    if(event->key()==Qt::Key_Up){
        upPressed=false;
    }

    QWidget::keyPressEvent(event);
}
