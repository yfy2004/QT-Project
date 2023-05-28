#include "lose.h"
#include "ui_lose.h"

lose::lose(QWidget *parent,Game *father) :
    QWidget(parent),
    ui(new Ui::lose)
{
    ui->setupUi(this);
    f = father;

    this->setAutoFillBackground(true);
    QPalette p;
    QPixmap pix(":/new/prefix1/picture/lose.png");
    p.setBrush(QPalette::Window,QBrush(pix));
    this->setPalette(p);
    this->show();

    ui->pushButton->setStyleSheet("QPushButton#pushButton{background-image: url(:/new/prefix1/picture/again_dark.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton:hover{background-image: url(:/new/prefix1/picture/again_light.png);border:1px solid rgba(255,255,255,0);}QPushButton{background-image: url(:/new/prefix1/picture/again_light.png);border:1px solid rgba(255,255,255,0);}");
    ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2{background-image: url(:/new/prefix1/picture/return_dark_another.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton_2:hover{background-image: url(:/new/prefix1/picture/return_light.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton_2:pressed{background-image: url(:/new/prefix1/picture/return_light.png);border:1px solid rgba(255,255,255,0);}");
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
}

lose::~lose()
{
    delete ui;
}

void lose::on_pushButton_clicked()
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

void lose::on_pushButton_2_clicked()
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
