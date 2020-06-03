#ifndef MONK_SHA_H
#define MONK_SHA_H
#include "eudemon.h"

class MonkSha:public Eudemon{
public:
    MonkSha(int xx,int yy,int s);
    virtual void Addbuttle();                //添加光圈
    virtual int Attack(QPainter& painter); //画出子弹并攻击
    ~MonkSha();
private:
    int count=0;                        //当前光圈的数量
};
#endif // MONK_SHA_H
