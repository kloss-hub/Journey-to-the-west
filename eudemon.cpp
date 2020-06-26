#include "eudemon.h"
Eudemon::Eudemon(int xx,int yy,int s,QString i):Object (xx,yy,i)
{
    size=s;
}

int Eudemon::GetRange() const //获取射程
{
    return range;
}

void Eudemon::SetTargetEvil(Evil* e)//设置当前目标妖怪
{
    target_evil=e;
}

int Eudemon::GetSize() const//返回大小
{
    return size;
}

int Eudemon::GetUpgradeCost() const//返回升级所需费用
{
    return upgradecost;
}

void Eudemon::Upgrade()//升级,上限为3
{
    if(level<3){
        upgradecost+=10;
        size+=8;
        power+=2;
        range+=8;
        level+=1;
        bulletnum-=1;
        BulletQ.clear();
    }
}
