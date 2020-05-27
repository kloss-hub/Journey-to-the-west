#include"monkey_king.h"
#include <math.h>
MonkeyKing::MonkeyKing(int xx,int yy,int s):Eudemon (xx,yy,s,":/images/swk.PNG"){
    range=150;
    power=5;
    upgradecost=30;
}
//void MonkeyKing::Addbuttle(){
////    if(target_evil){
////        if(BulletQ.size()<20)
////            BulletQ.append((new Bullet(0,0,":/images/bullet1.PNG")));
////    }
////    else {
////        BulletQ.clear();
////    }
//}
void MonkeyKing::Attack(QPainter &painter){
    if(target_evil&&target_evil->GetHealth()>0){
        int to_evilx=(target_evil->GetX()-x)/10;
        int to_evily=(target_evil->GetY()-y)/10;//到达目标怪物的距离
//        float rate=to_evilx?(float)to_evily/(float)to_evilx:0;//计算tan
        for(int i=0;i<10;i++){
            Bullet *B=new Bullet(x+size/2+to_evilx*(i+1),y+size/2+to_evily*(i+1),":/images/bullet1.PNG");
            B->draw(painter,size/5,size/5);
            //打到怪物
        }
     target_evil->BeHurt(power);//被打到
    }
}
MonkeyKing::~MonkeyKing(){
//    for(int i=0;i<BulletQ.size();i++){
//        free(BulletQ.at(i));
//    }
}
