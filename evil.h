#ifndef EVIL_H
#define EVIL_H
#include <QVector>
#include <QString>
#include "point.h"
#include "object.h"
class Evil:public Object
{
public:
    Evil(int hl,int ht,int r,QString i,QVector<Point*> p,int speed);//构造函数
    int GetHealth() const;               //获取生命值
    int GetHurt() const;                 //获取伤害值
    int GetReward() const;               //获取价格
    void move();                         //移动函数
    void BeHurt(int h);                  //被扣血
    void GetSlow();                      //被降速
    void draw(QPainter &,int w,int h);   //画出怪物（在基类函数上做相应的修改）
protected:
    int slowdown=0;
    QVector<Point *> Path; //大体路径
    int health;            //妖怪的生命值
    int hurt;              //妖怪的杀伤力
    int reward;            //杀死后能获得的金钱
    int speed;             //移动速度
};

#endif // EVIL_H
