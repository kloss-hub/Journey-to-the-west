# include"pigsy.h"

Pigsy::Pigsy(int xx,int yy,int s):Eudemon (xx,yy,s,":/images/zbj.PNG"){
    range=100;
    power=3;
    upgradecost=20;
}
void Pigsy::Attack(QPainter &painter){
    this->draw(painter,20,20);
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
}
Pigsy::~Pigsy(){
//    for(int i=0;i<BulletQ.size();i++){
//        free(BulletQ.at(i));
//    }
}
