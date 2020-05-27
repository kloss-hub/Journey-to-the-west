#ifndef EUDEMON_H
#define EUDEMON_H
#include <QString>
#include "evil.h"
#include "object.h"
class Eudemon: public Object
{
public:
    int GetRange() const;  //获取射程
    void SetTargetEvil(Evil*); //设置当前目标妖怪
    void InitBullet();             //新建子弹
    void MoveBullet();             //子弹移动
    void Upgrade();            //升级
//    void Addpower(int);       //设置防御塔攻击力
//    void AddSize(int);        //炮塔变大
//    void AddRange();              //增加攻击范围
protected:
    int price;//购买价格
    int range;//射程
    Evil* target_evil=nullptr;//攻击的目标妖怪
    int power;//攻击威力
    int bullsize;//子弹大小
    int speed;//子弹速度
};

#endif // EUDEMON_H
