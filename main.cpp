#include "mainwindow.h"
#include "begingame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Begingame b;
    b.show();
    return a.exec();
}
