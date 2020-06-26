# include"pigsy.h"

Pigsy::Pigsy(int xx,int yy,int s):Eudemon (xx,yy,s,":/images/pig1.png")
{
    range=100;
    power=2;
    upgradecost=20;
    bulletnum=6;
}

void Pigsy::Addbuttle()//添加子弹
{
    if(target_evil&&target_evil->GetHealth()>0){
        if(BulletQ.size()<bulletnum)
            BulletQ.append((new Object(0,0,":/images/bullet2.png")));
    }
    else {
        BulletQ.clear();
    }
}

int Pigsy::Attack(QPainter &painter,bool pause)//攻击函数
{
    if(target_evil&&target_evil->GetHealth()>0){
        Changeimag(":/images/pig2.png");
        int to_evilx=(target_evil->GetX()-x)/bulletnum;
        int to_evily=(target_evil->GetY()-y)/bulletnum;//到达目标怪物的距离
        for(int i=0;i<BulletQ.size();i++){
            BulletQ.at(i)->SetX(x+size/2+to_evilx*(i+1));
            BulletQ.at(i)->SetY(y+size/2+to_evily*(i+1));
            BulletQ.at(i)->draw(painter,size/5,size/5);
        }
        if(BulletQ.size()==bulletnum&&!pause){
            target_evil->GetSlow();//有足够多的子弹，被打到,减速
            target_evil->BeHurt(power);//同时扣血
        }

    }
    else{
        Changeimag(":/images/pig1.png");
    }
    return 0;
}

Pigsy::~Pigsy()
{
    for(int i=0;i<BulletQ.size();i++){
        free(BulletQ.at(i));
    }
}
