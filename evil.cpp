#include "evil.h"
Evil::Evil(int h,int r,QString i,QVector<Point *> p,int s):Object (p.at(0)->GetX(),p.at(0)->GetY(),i)
{
    hurt=h;
    reward=r;
    Path=p;
    speed=s;
}
void Evil::BeHurt(int h){
    health-=h;
}
void Evil::move()
{
    Point *p1=nullptr;
    Point *p2=nullptr;
    for(int i=0;i<Path.size()-1;i++){
        p1=Path.at(i);
        p2=Path.at(i+1);
        if(((x-p1->GetX())*(x-p2->GetX()))<=0&&((y-p1->GetY())*(y-p2->GetY()))<=0)
            if((x!=p2->GetX()||y!=p2->GetY()))//非端点
                break;//找到所在路径(不包含终点)
    }
    //往下一个端点走
    if(x>p2->GetX()){
        x-=speed;
    }
    if(x<p2->GetX()){
        x+=speed;
    }
    if(y>p2->GetY()){
        y-=speed;
    }
    if(y<p2->GetY()){
        y+=speed;
    }
}
int Evil::GetHurt() const
{
    return hurt;
}
int Evil::GetHealth() const
{
    return health;
}
int Evil::GetReward() const
{
    return reward;
}
