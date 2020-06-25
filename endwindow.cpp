#include "endwindow.h"
#include "ui_endwindow.h"
#include "begingame.h"
EndWindow::EndWindow(int s,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EndWindow)
{
    ui->setupUi(this);
    status=s;
}

void EndWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if(status==0)
        painter.drawPixmap(rect(), QPixmap(":/images/game_over.jpg"));
    if(status==1)
        painter.drawPixmap(rect(), QPixmap(":/images/win.JPG"));
}

EndWindow::~EndWindow()
{
    delete ui;
}

void EndWindow::on_pushButton_2_clicked()
{
    Begingame *b=new Begingame();
    b->show();
    this->close();
}

void EndWindow::on_pushButton_3_clicked()
{
    exit(0);
}
