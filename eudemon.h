#ifndef EUDEMON_H
#define EUDEMON_H
#include <QString>
#include "evil.h"
#include "object.h"
class Eudemon: public Object
{
public:
    Eudemon(int xx,int yy,int s,QString i);    //构造函数
    int GetRange() const;                      //获取射程
    int GetSize() const;                       //返回大小
    int GetUpgradeCost() const;                //返回升级需要花费的金钱
    void SetTargetEvil(Evil*);                 //设置当前目标妖怪
    void Upgrade();                            //升级
    virtual void Addbuttle()=0;                //添加子弹
    virtual int Attack(QPainter& painter,bool pause)=0;   //功能函数，攻击或者返回金钱
    virtual ~Eudemon(){}                       //析构函数也需要是虚函数
protected:
    int level=1;                   //等级
    int range;                     //射程
    int size;                      //大小
    Evil* target_evil=nullptr;     //攻击的目标妖怪
    int power;                     //攻击威力
    int upgradecost;               //升级花费
    int bulletnum;                 //需要打到怪兽的子弹数
    QVector<Object *> BulletQ;     //子弹队列
};

#endif // EUDEMON_H
