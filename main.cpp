#include "mainwindow.h"
#include "begingame.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Begingame b;
    b.show();

//    int size=900;
//    MainWindow w(size);
//    w.setFixedSize(size,size/15*10);
//    w.setWindowTitle("                 西天取经！");//设置标题和界面大小
//    w.show();
    return a.exec();
}
