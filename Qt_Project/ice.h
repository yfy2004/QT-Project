#ifndef ICE_H
#define ICE_H

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>
#include <QMessageBox>

namespace Ui {
class Ice;
}

class Ice : public QWidget
{
    Q_OBJECT

public:
    explicit Ice(QWidget *parent = 0);
    ~Ice();

protected:

    void paintEvent(QPaintEvent *event);

    void keyPressEvent(QKeyEvent *event);

public:
    Ui::Ice *ui;
};

#endif
