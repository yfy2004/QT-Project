#include "ourmainwindow.h"
#include "ui_ourmainwindow.h"

OurMainWindow::OurMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OurMainWindow)
{
    ui->setupUi(this);

    ui->pushButton_6->setEnabled(false);
    ui->pushButton_6->setVisible(0);

    my_BGM=new QMediaPlayer(this);
    my_BGM->setMedia(QUrl::fromLocalFile("C:/Users/JinYihan/Documents/GitHub/QT-Project/Qt_Project/picture/MenuMusic.mp3"));
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
    victory *configWindow2 = new victory(nullptr,configWindow);
    configWindow2->show();
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
    record *configWindow = new record;
    configWindow->show();
}
