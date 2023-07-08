#pragma execution_character_set("utf-8")
#ifndef OURMAINWINDOW_H
#define OURMAINWINDOW_H

#include <QMainWindow>
#include <QMultimedia>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <game.h>
#include <ui_game.h>
#include <help_platform.h>
#include <ui_help_platform.h>
#include <record.h>
#include <ui_record.h>
#include <victory.h>
#include <ui_victory.h>
#include <lose.h>
#include <ui_lose.h>

namespace Ui {
class OurMainWindow;
}

class OurMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OurMainWindow(QWidget *parent = nullptr,qint32 game_time=0,qint32 red_num=0,qint32 blue_num=0);
    ~OurMainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_pressed();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::OurMainWindow *ui;
    QMediaPlayer *my_BGM=nullptr;

public:
    qint32 game_time,red_num,blue_num;
};

#endif // OURMAINWINDOW_H
