#include "begingame.h"
#include "ui_begingame.h"
#include "mainwindow.h"
Begingame::Begingame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Begingame)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
//    player->setMedia(QUrl::fromLocalFile(":/sounds/bgm1.mp3"));
    player->setMedia(QUrl("qrc:/sounds/bbgm.mp3"));
    player->setVolume(50);
    player->play();

}

void Begingame::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), QPixmap(":/images/beginbg.jpg"));
}

Begingame::~Begingame()
{
    delete ui;
}

void Begingame::on_pushButton_clicked()
{
        int size=900;
        MainWindow* w=new MainWindow(size,2);
        w->setFixedSize(size,size/15*10);
        w->setWindowTitle("                 西天取经！");//设置标题和界面大小
        w->show();
        this->close();
        player->stop();
}

void Begingame::on_pushButton_2_clicked()
{
    int size=900;
    MainWindow* w=new MainWindow(size,1);
    w->setFixedSize(size,size/15*10);
    w->setWindowTitle("                 西天取经！");//设置标题和界面大小
    w->show();
    this->close();
    player->stop();
}
