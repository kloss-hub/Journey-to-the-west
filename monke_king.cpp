#include"monkey_king.h"
#include <math.h>
MonkeyKing::MonkeyKing(int xx,int yy,int s):Eudemon (xx,yy,s,":/images/swk.PNG")
{
    range=150;
    power=6;
    upgradecost=30;
    bulletnum=8;
}

void MonkeyKing::Addbuttle()//添加子弹
{
    if(target_evil){
        if(BulletQ.size()<bulletnum)
            BulletQ.append((new Object(0,0,":/images/bullet1.PNG")));
    }
    else {
        BulletQ.clear();
    }
}

int MonkeyKing::Attack(QPainter &painter)//攻击函数
{
    if(target_evil&&target_evil->GetHealth()>0){
        int to_evilx=(target_evil->GetX()-x)/bulletnum;
        int to_evily=(target_evil->GetY()-y)/bulletnum;//到达目标怪物的距离
        for(int i=0;i<BulletQ.size();i++){
            BulletQ.at(i)->SetX(x+size/2+to_evilx*(i+1));
            BulletQ.at(i)->SetY(y+size/2+to_evily*(i+1));
            BulletQ.at(i)->draw(painter,size/5,size/5);
        }
        if(BulletQ.size()==bulletnum)
             target_evil->BeHurt(power);//有十个子弹，被打到
    }
    return 0;
}

MonkeyKing::~MonkeyKing(){
    for(int i=0;i<BulletQ.size();i++){
        free(BulletQ.at(i));
    }
}
