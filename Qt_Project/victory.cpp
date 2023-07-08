#include "victory.h"
#include "ui_victory.h"
#include <QDebug>

victory::victory(QWidget *parent,Game *father) :
    QWidget(parent),
    ui(new Ui::victory)
{
    ui->setupUi(this);
    f = father;

    this->setAutoFillBackground(true);
    QPalette p;
    QPixmap pix(":/new/prefix1/picture/victory_final_new.png");
    p.setBrush(QPalette::Window,QBrush(pix));
    this->setPalette(p);
    this->show();

    ui->pushButton->setStyleSheet("QPushButton#pushButton{background-image: url(:/new/prefix1/picture/continue_dark.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton:hover{background-image: url(:/new/prefix1/picture/continue_light.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton:pressed{background-image: url(:/new/prefix1/picture/continue_light.png);border:1px solid rgba(255,255,255,0);}");
    ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2{background-image: url(:/new/prefix1/picture/return_dark_another.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton_2:hover{background-image: url(:/new/prefix1/picture/return_light_another.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton_2:pressed{background-image: url(:/new/prefix1/picture/return_light_another.png);border:1px solid rgba(255,255,255,0);}");
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
}

victory::~victory()
{
    delete ui;
}

void victory::on_pushButton_clicked()
{
    if(f->my_game_music!=nullptr){
        f->my_game_music->stop();
        delete f->my_game_music;
        f->my_game_music=nullptr;
    }
    f->close();
    qDebug()<<f->game_num<<endl;
    if(f->game_num==1){
        Game *configWindow = new Game(nullptr,2);
        configWindow->show();
        this->close();
    }
    else{
        OurMainWindow *configWindow = new OurMainWindow;
        configWindow->show();
        this->close();
    }
}

void victory::on_pushButton_2_clicked()
{
    if(f->my_game_music!=nullptr){
        f->my_game_music->stop();
        delete f->my_game_music;
        f->my_game_music=nullptr;
    }
    f->close();
    OurMainWindow *configWindow = new OurMainWindow;
    configWindow->show();
    this->close();
}
