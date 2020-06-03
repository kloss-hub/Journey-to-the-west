#ifndef MONKEY_KING_H
#define MONKEY_KING_H
#include "eudemon.h"
#include "bullet.h"
class MonkeyKing:public Eudemon{
public:
    MonkeyKing(int xx,int yy,int s);
    virtual void Addbuttle();//添加子弹
    virtual int Attack(QPainter& painter);   //画出子弹并攻击
    ~MonkeyKing();
private:

};

#endif // MONKEY_KING_H
