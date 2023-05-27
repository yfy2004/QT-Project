#ifndef VICTORY_H
#define VICTORY_H

#include <QWidget>
#include <game.h>
#include <ui_game.h>
#include <ourmainwindow.h>
#include <ui_ourmainwindow.h>

namespace Ui {
class victory;
}

class victory : public QWidget
{
    Q_OBJECT

public:
    explicit victory(QWidget *parent = nullptr,Game *father = nullptr);
    ~victory();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::victory *ui;
    Game *f;
};

#endif // VICTORY_H
