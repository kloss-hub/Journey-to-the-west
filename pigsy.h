#ifndef PIGSY_H
#define PIGSY_H
#include "eudemon.h"
class Pigsy:public Eudemon{
public:
    Pigsy(int xx,int yy,int s);
    virtual void Addbuttle();
    virtual int Attack(QPainter& painter);   //画出子弹并攻击
    ~Pigsy();
private:
};
#endif // PIGSY_H
