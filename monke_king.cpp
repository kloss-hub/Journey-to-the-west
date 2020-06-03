#include"monkey_king.h"
#include <math.h>
MonkeyKing::MonkeyKing(int xx,int yy,int s):Eudemon (xx,yy,s,":/images/swk.PNG"){
    range=150;
    power=5;
    upgradecost=30;
    bulletnum=8;
}
void MonkeyKing::Addbuttle(){
    if(target_evil){
        if(BulletQ.size()<bulletnum)
            BulletQ.append((new Bullet(0,0,":/images/bullet1.PNG")));
    }
    else {
        BulletQ.clear();
    }
}
int MonkeyKing::Attack(QPainter &painter){
    if(target_evil&&target_evil->GetHealth()>0){
        int to_evilx=(target_evil->GetX()-x)/bulletnum;
        int to_evily=(target_evil->GetY()-y)/bulletnum;//到达目标怪物的距离
//        float rate=to_evilx?(float)to_evily/(float)to_evilx:0;//计算tan
//        for(int i=0;i<10;i++){
//            Bullet *B=new Bullet(x+size/2+to_evilx*(i+1),y+size/2+to_evily*(i+1),":/images/bullet1.PNG");
//            B->draw(painter,size/5,size/5);
//            //打到怪物
//        }
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
