#ifndef EVIL_H
#define EVIL_H
#include <QVector>
#include <QString>
#include "point.h"
#include "object.h"
class Evil:public Object
{
public:
    Evil(int h,int r,QString i,QVector<Point*> p,int speed);//构造函数
    void move();//移动函数
    void BeHurt(int h);//被扣血
    int GetHealth() const;  //获取生命值
    int GetHurt() const;    //获取伤害值
    int GetReward() const; //获取价格
protected:
    QVector<Point *> Path;          //大体路径
    int health=100;                  //妖怪的生命值
    int hurt;                   //妖怪的杀伤力
    int reward;              //杀死后能获得的金钱
    int speed=10;         //移动速度
};

#endif // EVIL_H
