#ifndef SETTING_H
#define SETTING_H
#include <game.h>
#include <ui_game.h>
#include <ourmainwindow.h>
#include <ui_ourmainwindow.h>
#include <QWidget>

namespace Ui {
class setting;
}

class Game;
class setting : public QWidget
{
    Q_OBJECT

public:
    explicit setting(QWidget *parent = nullptr,Game *father=nullptr);
    ~setting();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::setting *ui;
    Game *f;
};

#endif // SETTING_H
