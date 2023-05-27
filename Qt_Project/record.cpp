#include "record.h"
#include "ui_record.h"

record::record(QWidget *parent) :
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
}

record::~record()
{
    delete ui;
}

void record::on_pushButton_clicked()
{
    this->close();
}
