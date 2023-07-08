#include "ourmainwindow.h"
#include <QApplication>

/*extern qint32 game_num;
extern qint32 blue_num;
extern qint32 red_num;
extern qint32 game_time;*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OurMainWindow w;
    w.show();

    return a.exec();
}
