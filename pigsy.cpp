# include"pigsy.h"

Pigsy::Pigsy(int xx,int yy,int s):Eudemon (xx,yy,s,":/images/pig1.png"){
    range=100;
    power=2;
    upgradecost=20;
    bulletnum=6;
}
void Pigsy::Addbuttle(){
    if(target_evil&&target_evil->GetHealth()>0){
        if(BulletQ.size()<bulletnum)
            BulletQ.append((new Bullet(0,0,":/images/bullet2.png")));
    }
    else {
        BulletQ.clear();
    }
}
int Pigsy::Attack(QPainter &painter){
    if(target_evil&&target_evil->GetHealth()>0){
        Changeimag(":/images/pig2.png");
        int to_evilx=(target_evil->GetX()-x)/bulletnum;
        int to_evily=(target_evil->GetY()-y)/bulletnum;//到达目标怪物的距离
        for(int i=0;i<BulletQ.size();i++){
            BulletQ.at(i)->SetX(x+size/2+to_evilx*(i+1));
            BulletQ.at(i)->SetY(y+size/2+to_evily*(i+1));
            BulletQ.at(i)->draw(painter,size/5,size/5);
        }
        if(BulletQ.size()==bulletnum){
            target_evil->GetSlow();//有足够多的子弹，被打到,减速
            target_evil->BeHurt(power);//同时扣血
        }

    }
    else{
        Changeimag(":/images/pig1.png");
    }

//    if(target_evil&&target_evil->GetHealth()>0){
//        int to_evilx=(target_evil->GetX()-x)/10;
//        int to_evily=(target_evil->GetY()-y)/10;//到达目标怪物的距离
////        float rate=to_evilx?(float)to_evily/(float)to_evilx:0;//计算tan
//        for(int i=0;i<10;i++){
////            Bullet *B=new Bullet(x+size/2+to_evilx*(i+1),y+size/2+to_evily*(i+1),":/images/bullet1.PNG");
////            B->draw(painter,size/5,size/5);
////            //打到怪物
//        }
//     target_evil->BeHurt(power);//被打到
//    }
    return 0;
}
Pigsy::~Pigsy(){
    for(int i=0;i<BulletQ.size();i++){
        free(BulletQ.at(i));
    }
}
