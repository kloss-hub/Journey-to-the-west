#ifndef PIGSY_H
#define PIGSY_H
#include "eudemon.h"
#include "bullet.h"

class Pigsy:public Eudemon{
public:
    Pigsy(int xx,int yy,int s);
    virtual void Addbuttle();
    virtual void Attack(QPainter& painter);   //画出子弹并攻击
    ~Pigsy();
private:
    QVector<Bullet *> BulletQ;
};
#endif // PIGSY_H
