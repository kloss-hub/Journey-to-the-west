#include "eudemon.h"
int Eudemon::GetRange() const
{
    return range;
}  //获取射程
void Eudemon::SetTargetEvil(Evil* e)
{
    target_evil=e;
} //设置当前目标妖怪
void Eudemon::InitBullet(){

}             //新建子弹
void Eudemon::MoveBullet(){

}             //子弹移动
void Eudemon::Upgrade(){

}            //升级
