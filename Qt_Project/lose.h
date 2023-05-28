#ifndef LOSE_H
#define LOSE_H

#include <QWidget>
#include <game.h>
#include <ui_game.h>
#include <ourmainwindow.h>
#include <ui_ourmainwindow.h>

namespace Ui {
class lose;
}
class Game;
class lose : public QWidget
{
    Q_OBJECT

public:
    explicit lose(QWidget *parent = nullptr,Game *father = nullptr);
    ~lose();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::lose *ui;
    Game *f;
};

#endif // LOSE_H
