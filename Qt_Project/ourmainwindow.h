#pragma execution_character_set("utf-8")
#ifndef OURMAINWINDOW_H
#define OURMAINWINDOW_H

#include <QMainWindow>
#include <QMultimedia>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <game.h>
#include <ui_game.h>

namespace Ui {
class OurMainWindow;
}

class OurMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OurMainWindow(QWidget *parent = nullptr);
    ~OurMainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_pressed();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::OurMainWindow *ui;
};

#endif // OURMAINWINDOW_H
