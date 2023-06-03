#include "ice.h"
#include "ui_ice.h"

Ice::Ice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ice)
{
    ui->setupUi(this);
    QSize size(ui->labelImg->width(),ui->labelImg->height());
    QPixmap pic(":/new/prefix1/ice.png");
    pic = pic.scaled(size,Qt::KeepAspectRatioByExpanding);
    ui->labelImg->setPixmap(pic);
}

Ice::~Ice()
{
    delete ui;
}

void Ice::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pic(":/new/prefix1/ice.png");
    painter.drawPixmap(0,0,width(),height(),pic);
}

void Ice::keyPressEvent(QKeyEvent *event)
{
    int x=ui->labelImg->x();
    int y=ui->labelImg->y();
    qDebug()<<ui->labelImg->x()<<ui->labelImg->y();//160 120
    if(event->key()==Qt::Key_W)   //向上移动
    {
        ui->labelImg->move(x,y-5);

    }else if(event->key()==Qt::Key_A)  //向下移动
    {

        ui->labelImg->move(x-5,y);

    }else if(event->key()==Qt::Key_S)  //向左移动
    {

        ui->labelImg->move(x,y+5);

    }else if(event->key()==Qt::Key_D)  //向右移动
    {

        ui->labelImg->move(x+5,y);
    }
}
