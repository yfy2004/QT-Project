#ifndef HELP_PLATFORM_H
#define HELP_PLATFORM_H

#include <QWidget>

namespace Ui {
class help_platform;
}

class help_platform : public QWidget
{
    Q_OBJECT

public:
    explicit help_platform(QWidget *parent = nullptr);
    ~help_platform();

private slots:
    void on_pushButton_clicked();

private:
    Ui::help_platform *ui;
};

#endif // HELP_PLATFORM_H
