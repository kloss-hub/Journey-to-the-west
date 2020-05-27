#ifndef EUDEMON_H
#define EUDEMON_H
#include <QString>
#include "evil.h"
#include "object.h"
class Eudemon: public Object
{
public:
    Eudemon(int xx,int yy,int s,QString i);//构造函数
    int GetRange() const;  //获取射程
    void SetTargetEvil(Evil*); //设置当前目标妖怪
    Evil* GetTargetEvil();
    void InitBullet();             //新建子弹
    void MoveBullet();             //子弹移动
    void Upgrade();            //升级
    int GetSize();//返回大小
    int GetUpgradeCost();//返回升级需要花费的金钱
//    virtual void Addbuttle()=0;//添加子弹
    virtual void Attack(QPainter& painter)=0;   //画出子弹并攻击
    virtual ~Eudemon(){}//析构函数也需要是虚函数
protected:
    int level=1;
    int range;//射程
    int size;
    Evil* target_evil=nullptr;//攻击的目标妖怪
    int power;//攻击威力
    int upgradecost;//升级花费
};

#endif // EUDEMON_H
