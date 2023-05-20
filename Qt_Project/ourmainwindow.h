#ifndef OURMAINWINDOW_H
#define OURMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class OurMainWindow;
}

class OurMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OurMainWindow(QWidget *parent = nullptr);
    ~OurMainWindow();

private:
    Ui::OurMainWindow *ui;
};

#endif // OURMAINWINDOW_H
