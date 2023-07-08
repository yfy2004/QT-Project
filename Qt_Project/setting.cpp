#include "setting.h"
#include "ui_setting.h"

setting::setting(QWidget *parent,Game *father) :
    QWidget(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);
    f = father;

    this->setAutoFillBackground(true);
    QPalette p;
    QPixmap pix(":/new/prefix1/picture/setting_back.png");
    p.setBrush(QPalette::Window,QBrush(pix));
    this->setPalette(p);
    this->show();

    ui->pushButton->setStyleSheet("QPushButton#pushButton{background-image: url(:/new/prefix1/picture/return_dark_another.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton:hover{background-image: url(:/new/prefix1/picture/return_light_another.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton:pressed{background-image: url(:/new/prefix1/picture/return_light_another.png);border:1px solid rgba(255,255,255,0);}");
    ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2{background-image: url(:/new/prefix1/picture/continue_dark.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton_2:hover{background-image: url(:/new/prefix1/picture/continue_light.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton_2:pressed{background-image: url(:/new/prefix1/picture/continue_light.png);border:1px solid rgba(255,255,255,0);}");
    ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3{background-image: url(:/new/prefix1/picture/again_dark.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton_3:hover{background-image: url(:/new/prefix1/picture/again_light.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton_3:pressed{background-image: url(:/new/prefix1/picture/again_light.png);border:1px solid rgba(255,255,255,0);}");
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
}

setting::~setting()
{
    delete ui;
}

void setting::on_pushButton_2_clicked()
{
    this->close();
    f->timer->start();
    f->ui->setting->setEnabled(true);
}

void setting::on_pushButton_3_clicked()
{
    if(f->my_game_music!=nullptr){
        f->my_game_music->stop();
        delete f->my_game_music;
        f->my_game_music=nullptr;
    }
    f->close();
    Game *configWindow = new Game;
    configWindow->show();
    this->close();
}

void setting::on_pushButton_clicked()
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
