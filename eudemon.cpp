#include "eudemon.h"
Eudemon::Eudemon(int xx,int yy,int s,QString i):Object (xx,yy,i)
{
    size=s;
}
int Eudemon::GetRange() const
{
    return range;
}  //获取射程
void Eudemon::SetTargetEvil(Evil* e)
{
    target_evil=e;
} //设置当前目标妖怪
int Eudemon::GetSize(){
    return size;
}
int Eudemon::GetUpgradeCost(){
    return upgradecost;
}
void Eudemon::InitBullet(){

}             //新建子弹
void Eudemon::MoveBullet(){

}             //子弹移动
void Eudemon::Upgrade(){
    if(level<3){
        size+=10;
        power+=3;
        range+=20;
        level+=1;
    }
}            //升级,上限为3
