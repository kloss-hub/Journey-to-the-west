#ifndef MARQUEE_H
#define MARQUEE_H
#include "object.h"
#include <QPainter>     //画笔
class Marquee:public Object
{
public:
    Marquee(int xx,int yy,QString i,QString s1,QString s2,QString s3,QString s4);
    void draw(QPainter &painter,int blocksize);//重载函数
private:
    //4个选项的路径
    QString sel1;
    QString sel2;
    QString sel3;
    QString sel4;
};

#endif // MARQUEE_H
