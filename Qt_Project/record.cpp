#include "record.h"
#include "ui_record.h"

record::record(QWidget *parent,qint32 game_time,qint32 red_num,qint32 blue_num) :
    QWidget(parent),
    ui(new Ui::record)
{
    ui->setupUi(this);

    move(600,235);

    this->setAutoFillBackground(true);
    QPalette p;
    QPixmap pix(":/new/prefix1/picture/main_standard.png");
    p.setBrush(QPalette::Window,QBrush(pix));
    this->setPalette(p);
    this->show();

    ui->pushButton->setStyleSheet("QPushButton#pushButton{background-image: url(:/new/prefix1/picture/return_dark.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton:hover{background-image: url(:/new/prefix1/picture/return_light_new.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton:pressed{background-image: url(:/new/prefix1/picture/return_light_new.png);border:1px solid rgba(255,255,255,0);}");
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    if(blue_num==0)
        ui->blue->setStyleSheet("background-image: url(:/new/prefix1/picture/zero_new.png);");
    else if(blue_num==1)
        ui->blue->setStyleSheet("background-image: url(:/new/prefix1/picture/one_new.png);");
    else if(blue_num==2)
        ui->blue->setStyleSheet("background-image: url(:/new/prefix1/picture/two_new.png);");
    else if(blue_num==3)
        ui->blue->setStyleSheet("background-image: url(:/new/prefix1/picture/three_new.png);");
    else if(blue_num==4)
        ui->blue->setStyleSheet("background-image: url(:/new/prefix1/picture/four_new.png);");
    else if(blue_num==5)
        ui->blue->setStyleSheet("background-image: url(:/new/prefix1/picture/five.png);");
    else if(blue_num==6)
        ui->blue->setStyleSheet("background-image: url(:/new/prefix1/picture/six.png);");

    if(red_num==0)
        ui->red->setStyleSheet("background-image: url(:/new/prefix1/picture/zero_new.png);");
    else if(red_num==1)
        ui->red->setStyleSheet("background-image: url(:/new/prefix1/picture/one_new.png);");
    else if(red_num==2)
        ui->red->setStyleSheet("background-image: url(:/new/prefix1/picture/two_new.png);");
    else if(red_num==3)
        ui->red->setStyleSheet("background-image: url(:/new/prefix1/picture/three_new.png);");
    else if(red_num==4)
        ui->red->setStyleSheet("background-image: url(:/new/prefix1/picture/four_new.png);");
    else if(red_num==5)
        ui->red->setStyleSheet("background-image: url(:/new/prefix1/picture/five.png);");
    else if(red_num==6)
        ui->red->setStyleSheet("background-image: url(:/new/prefix1/picture/six.png);");

    ui->blue->show();
    ui->red->show();

    qint32 t=game_time;
    qint32 minute=t/60,second=t%60;

    if(second%10==0)
        ui->label4->setStyleSheet("background-image: url(:/new/prefix1/picture/zero_new.png);");
    else if(second%10==1)
        ui->label4->setStyleSheet("background-image: url(:/new/prefix1/picture/one_new.png);");
    else if(second%10==2)
        ui->label4->setStyleSheet("background-image: url(:/new/prefix1/picture/two_new.png);");
    else if(second%10==3)
        ui->label4->setStyleSheet("background-image: url(:/new/prefix1/picture/three_new.png);");
    else if(second%10==4)
        ui->label4->setStyleSheet("background-image: url(:/new/prefix1/picture/four_new.png);");
    else if(second%10==5)
        ui->label4->setStyleSheet("background-image: url(:/new/prefix1/picture/five.png);");
    else if(second%10==6)
        ui->label4->setStyleSheet("background-image: url(:/new/prefix1/picture/six.png);");
    else if(second%10==7)
        ui->label4->setStyleSheet("background-image: url(:/new/prefix1/picture/seven.png);");
    else if(second%10==8)
        ui->label4->setStyleSheet("background-image: url(:/new/prefix1/picture/eight.png);");
    else if(second%10==9)
        ui->label4->setStyleSheet("background-image: url(:/new/prefix1/picture/nine.png);");

    if(minute/10==0)
        ui->label1->setStyleSheet("background-image: url(:/new/prefix1/picture/zero_new.png);");
    else if(minute/10==1)
        ui->label1->setStyleSheet("background-image: url(:/new/prefix1/picture/one_new.png);");
    else if(minute/10==2)
        ui->label1->setStyleSheet("background-image: url(:/new/prefix1/picture/two_new.png);");
    else if(minute/10==3)
        ui->label1->setStyleSheet("background-image: url(:/new/prefix1/picture/three_new.png);");
    else if(minute/10==4)
        ui->label1->setStyleSheet("background-image: url(:/new/prefix1/picture/four_new.png);");
    else if(minute/10==5)
        ui->label1->setStyleSheet("background-image: url(:/new/prefix1/picture/five.png);");
    else if(minute/10==6)
        ui->label1->setStyleSheet("background-image: url(:/new/prefix1/picture/six.png);");
    else if(minute/10==7)
        ui->label1->setStyleSheet("background-image: url(:/new/prefix1/picture/seven.png);");
    else if(minute/10==8)
        ui->label1->setStyleSheet("background-image: url(:/new/prefix1/picture/eight.png);");
    else if(minute/10==9)
        ui->label1->setStyleSheet("background-image: url(:/new/prefix1/picture/nine.png);");

    if(minute%10==0)
        ui->label2->setStyleSheet("background-image: url(:/new/prefix1/picture/zero_new.png);");
    else if(minute%10==1)
        ui->label2->setStyleSheet("background-image: url(:/new/prefix1/picture/one_new.png);");
    else if(minute%10==2)
        ui->label2->setStyleSheet("background-image: url(:/new/prefix1/picture/two_new.png);");
    else if(minute%10==3)
        ui->label2->setStyleSheet("background-image: url(:/new/prefix1/picture/three_new.png);");
    else if(minute%10==4)
        ui->label2->setStyleSheet("background-image: url(:/new/prefix1/picture/four_new.png);");
    else if(minute%10==5)
        ui->label2->setStyleSheet("background-image: url(:/new/prefix1/picture/five.png);");
    else if(minute%10==6)
        ui->label2->setStyleSheet("background-image: url(:/new/prefix1/picture/six.png);");
    else if(minute%10==7)
        ui->label2->setStyleSheet("background-image: url(:/new/prefix1/picture/seven.png);");
    else if(minute%10==8)
        ui->label2->setStyleSheet("background-image: url(:/new/prefix1/picture/eight.png);");
    else if(minute%10==9)
        ui->label2->setStyleSheet("background-image: url(:/new/prefix1/picture/nine.png);");

    if(second/10==0)
        ui->label3->setStyleSheet("background-image: url(:/new/prefix1/picture/zero_new.png);");
    else if(second/10==1)
        ui->label3->setStyleSheet("background-image: url(:/new/prefix1/picture/one_new.png);");
    else if(second/10==2)
        ui->label3->setStyleSheet("background-image: url(:/new/prefix1/picture/two_new.png);");
    else if(second/10==3)
        ui->label3->setStyleSheet("background-image: url(:/new/prefix1/picture/three_new.png);");
    else if(second/10==4)
        ui->label3->setStyleSheet("background-image: url(:/new/prefix1/picture/four_new.png);");
    else if(second/10==5)
        ui->label3->setStyleSheet("background-image: url(:/new/prefix1/picture/five.png);");
    else if(second/10==6)
        ui->label3->setStyleSheet("background-image: url(:/new/prefix1/picture/six.png);");
    else if(second/10==7)
        ui->label3->setStyleSheet("background-image: url(:/new/prefix1/picture/seven.png);");
    else if(second/10==8)
        ui->label3->setStyleSheet("background-image: url(:/new/prefix1/picture/eight.png);");
    else if(second/10==9)
        ui->label3->setStyleSheet("background-image: url(:/new/prefix1/picture/nine.png);");
}

record::~record()
{
    delete ui;
}

void record::on_pushButton_clicked()
{
    this->close();
}
