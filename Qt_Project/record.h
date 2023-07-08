#ifndef RECORD_H
#define RECORD_H

#include <QWidget>

namespace Ui {
class record;
}

class record : public QWidget
{
    Q_OBJECT

public:
    explicit record(QWidget *parent = nullptr,qint32 game_time=0,qint32 red_num=0,qint32 blue_num=0);
    ~record();

private slots:
    void on_pushButton_clicked();

private:
    Ui::record *ui;
};

#endif // RECORD_H
