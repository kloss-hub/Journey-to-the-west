#ifndef BULLET_H
#define BULLET_H
#include "object.h"
#include <QPainter>     //画笔
class Bullet:public Object
{
public:
    Bullet(int xx,int yy,QString i):Object(xx,yy,i){}
};

#endif // BULLET_H
