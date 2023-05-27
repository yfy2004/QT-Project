#include "help_platform.h"
#include "ui_help_platform.h"

help_platform::help_platform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::help_platform)
{
    ui->setupUi(this);

    move(600,235);

    this->setAutoFillBackground(true);
    QPalette p;
    QPixmap pix(":/new/prefix1/picture/help_platform.png");
    p.setBrush(QPalette::Window,QBrush(pix));
    this->setPalette(p);
    this->show();

    ui->pushButton->setStyleSheet("QPushButton#pushButton{background:transparent;border:1px solid rgba(255,255,255,0);}QPushButton#pushButton:hover{background-image: url(:/new/prefix1/picture/help_return_hovering.png);border:1px solid rgba(255,255,255,0);}QPushButton#pushButton:pressed{background-image: url(:/new/prefix1/picture/help_return_hovering.png);border:1px solid rgba(255,255,255,0);}");
}

help_platform::~help_platform()
{
    delete ui;
}

void help_platform::on_pushButton_clicked()
{
    this->close();
}
