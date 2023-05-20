#include "ourmainwindow.h"
#include "ui_ourmainwindow.h"

OurMainWindow::OurMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OurMainWindow)
{
    ui->setupUi(this);
}

OurMainWindow::~OurMainWindow()
{
    delete ui;
}
