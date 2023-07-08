#include "ourmainwindow.h"
#include "ui_ourmainwindow.h"

OurMainWindow::OurMainWindow(QWidget *parent,qint32 time,qint32 red,qint32 blue) :
    QMainWindow(parent),
    ui(new Ui::OurMainWindow),
    game_time(time),
    red_num(red),
    blue_num(blue)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    ui->pushButton_6->setEnabled(false);
    ui->pushButton_6->setVisible(0);

    QMediaPlaylist *my_list = new QMediaPlaylist();
    my_list->addMedia(QUrl("qrc:/new/prefix1/picture/MenuMusic.mp3"));
    my_list->setCurrentIndex(0);
    my_list->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    my_BGM=new QMediaPlayer(this);
    my_BGM->setPlaylist(my_list);
    my_BGM->setVolume(50);
    my_BGM->play();
}

OurMainWindow::~OurMainWindow()
{
    delete ui;
}

void OurMainWindow::on_pushButton_clicked()
{
    Game *configWindow = new Game;
    configWindow->show();
    this->close();
}

void OurMainWindow::on_pushButton_pressed()
{
    ui->pushButton->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/picture/start_new.png);}");
    my_BGM->stop();
    if(my_BGM!=nullptr){
        delete my_BGM;
        my_BGM=nullptr;
    }
}

void OurMainWindow::on_pushButton_5_clicked()
{
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_5->setVisible(0);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_6->setVisible(1);
    my_BGM->pause();
}

void OurMainWindow::on_pushButton_6_clicked()
{
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_6->setVisible(0);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_5->setVisible(1);
    my_BGM->play();
}

void OurMainWindow::on_pushButton_4_clicked()
{
    help_platform *configWindow = new help_platform;
    configWindow->show();
}

void OurMainWindow::on_pushButton_3_clicked()
{
    my_BGM->stop();
    if(my_BGM!=nullptr){
        delete my_BGM;
        my_BGM=nullptr;
    }
    this->close();
}

void OurMainWindow::on_pushButton_2_clicked()
{
    record *configWindow = new record(nullptr,game_time,red_num,blue_num);
    configWindow->show();
}
