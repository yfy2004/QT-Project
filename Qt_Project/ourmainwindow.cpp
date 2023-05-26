#include "ourmainwindow.h"
#include "ui_ourmainwindow.h"

OurMainWindow::OurMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OurMainWindow)
{
    ui->setupUi(this);

    ui->pushButton_6->setEnabled(false);
    ui->pushButton_6->setVisible(0);
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
}

void OurMainWindow::on_pushButton_5_clicked()
{
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_5->setVisible(0);
    ui->pushButton_6->setEnabled(true);
    ui->pushButton_6->setVisible(1);
}

void OurMainWindow::on_pushButton_6_clicked()
{
    ui->pushButton_6->setEnabled(false);
    ui->pushButton_6->setVisible(0);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_5->setVisible(1);
}
