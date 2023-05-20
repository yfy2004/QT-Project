#include "ourmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OurMainWindow w;
    w.show();

    return a.exec();
}
