#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <QPainter>     //画笔
#include <QMouseEvent>  //鼠标事件
#include <QTimer>
#include "evil.h"       //妖怪类
#include "eudemon.h"    //守护者类
#include "point.h"
#include "marquee.h"
#include"monkey_king.h"
#include"pigsy.h"
#include"monk_sha.h"
#include"gnome.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(int s,int l,QWidget *parent = nullptr);
    ~MainWindow();
private slots:
     void InitEvil();               //产生怪物
     void drawagin();               //重画
     void InitBullet();             //产生子弹
private:
    Ui::MainWindow *ui;
    int level;                      //关卡
    int size;                      //界面大小
    int blocksize;                //块大小
    int evil_init_speed=2000;    //怪物产生速度/ms
    bool inselect=false;        //是否在选择
    bool needselect;
    Marquee *M;
    QVector <Evil *> Evilvec;           //存放妖怪的数组
    QVector <Eudemon *> Eudemonvec;     //存放守护者的数组
    QVector<Point *> path;              //移动路径
    void paintEvent(QPaintEvent *);     //绘图事件
    void mousePressEvent(QMouseEvent *);//鼠标点击事件
    void DrawMap(QPainter&);         //画地图函数
    void Drawlife(QPainter&,int x,int y);
    int hurt(Evil *);                   //判断怪物是否伤害到唐僧
    void DrawEudemon(QPainter&);
    void DrawEvil(QPainter&);           //画出怪物
    int money=200;                      //金币
    int evil_count=0;                   //妖怪数量
    int life=100;                       //唐僧的剩余生命
};

#endif // MAINWINDOW_H

