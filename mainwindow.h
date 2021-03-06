#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QTimer>
#include "evil.h"
#include "eudemon.h"
#include "point.h"
#include "marquee.h"
#include"monkey_king.h"
#include"pigsy.h"
#include"monk_sha.h"
#include"gnome.h"
#include <QMediaPlayer>
#include<QMediaPlaylist>
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
     void InitBullet();             //产生子弹
private:
    Ui::MainWindow *ui;
    bool pause=false;               //暂停
    int level;                      //关卡
    int size;                       //界面大小
    int blocksize;                  //块大小
    int money=150;                  //金币
    int Map[10][15];                //地图
    int evil_count=0;               //妖怪数量
    int life=100;                   //唐僧的剩余生命
    int evil_init_speed=2000;       //怪物产生速度/ms
    bool inselect=false;            //是否在选择
    int difficulty=0;               //游戏难度，随着守护者的建造和升级而增加
    Marquee *M;
    QMediaPlayer * player;
    QVector <Evil *> Evilvec;           //存放妖怪的数组
    QVector <Eudemon *> Eudemonvec;     //存放守护者的数组
    QVector<Point *> path;              //移动路径
    void paintEvent(QPaintEvent *);     //绘图事件
    void mousePressEvent(QMouseEvent *);//鼠标点击事件
    void DrawMap(QPainter&);            //画地图函数
    void Drawlife(QPainter&,int x,int y);
    int hurt(Evil *);                   //判断怪物是否伤害到唐僧
    void DrawEudemon(QPainter&);
    void DrawEvil(QPainter&);           //画出怪物
};
#endif // MAINWINDOW_H

