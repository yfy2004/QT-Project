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
}

record::~record()
{
    delete ui;
}
