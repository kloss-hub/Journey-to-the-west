#ifndef GNOME_H
#define GNOME_H
#include "eudemon.h"

class Gnome:public Eudemon{
public:
    Gnome(int xx,int yy,int s);
    virtual void Addbuttle();
    virtual int Attack(QPainter& painter,bool pause);  //画出子弹并攻击
    ~Gnome();
private:
    int count=0;                        //计数
};
#endif // GNOME_H
