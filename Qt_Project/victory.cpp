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

    if(f->blue_num==0)
        ui->blue->setStyleSheet("background-image: url(:/new/prefix1/picture/zero_new.png);");
    else if(f->blue_num==1)
        ui->blue->setStyleSheet("background-image: url(:/new/prefix1/picture/one_new.png);");
    else if(f->blue_num==2)
        ui->blue->setStyleSheet("background-image: url(:/new/prefix1/picture/two_new.png);");
    else if(f->blue_num==3)
        ui->blue->setStyleSheet("background-image: url(:/new/prefix1/picture/three_new.png);");
    else if(f->blue_num==4)
        ui->blue->setStyleSheet("background-image: url(:/new/prefix1/picture/four_new.png);");
    else if(f->blue_num==5)
        ui->blue->setStyleSheet("background-image: url(:/new/prefix1/picture/five.png);");
    else if(f->blue_num==6)
        ui->blue->setStyleSheet("background-image: url(:/new/prefix1/picture/six.png);");

    if(f->red_num==0)
        ui->red->setStyleSheet("background-image: url(:/new/prefix1/picture/zero_new.png);");
    else if(f->red_num==1)
        ui->red->setStyleSheet("background-image: url(:/new/prefix1/picture/one_new.png);");
    else if(f->red_num==2)
        ui->red->setStyleSheet("background-image: url(:/new/prefix1/picture/two_new.png);");
    else if(f->red_num==3)
        ui->red->setStyleSheet("background-image: url(:/new/prefix1/picture/three_new.png);");
    else if(f->red_num==4)
        ui->red->setStyleSheet("background-image: url(:/new/prefix1/picture/four_new.png);");
    else if(f->red_num==5)
        ui->red->setStyleSheet("background-image: url(:/new/prefix1/picture/five.png);");
    else if(f->red_num==6)
        ui->red->setStyleSheet("background-image: url(:/new/prefix1/picture/six.png);");

    ui->blue->show();
    ui->red->show();

    qint32 t=f->game_time;
    qint32 minute=t/60,second=t%60;

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

    ui->label->setStyleSheet("background-image: url(:/new/prefix1/picture/colon.png);");

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
    if(f->game_num==1){
        Game *configWindow = new Game(nullptr,2);
        configWindow->red_num=f->red_num;
        configWindow->blue_num=f->blue_num;
        configWindow->game_time=f->game_time;
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
