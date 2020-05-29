//#include"monk_sha.h"
//MonkSha::MonkSha(int xx,int yy,int s):Eudemon (xx,yy,s,":/images/shs.PNG"){
//    range=100;
//    power=5;
//    upgradecost=20;
//    bulletnum=6;
//}
//void MonkSha::Addbuttle(){
//    if(count<bulletnum)
//        count++;
//}
//void MonkSha::Attack(QPainter &painter){
//    if(target_evil&&target_evil->GetHealth()>0){
//        int to_evilx=(target_evil->GetX()-x)/bulletnum;
//        int to_evily=(target_evil->GetY()-y)/bulletnum;//到达目标怪物的距离
////        float rate=to_evilx?(float)to_evily/(float)to_evilx:0;//计算tan
////        for(int i=0;i<10;i++){
////            Bullet *B=new Bullet(x+size/2+to_evilx*(i+1),y+size/2+to_evily*(i+1),":/images/bullet1.PNG");
////            B->draw(painter,size/5,size/5);
////            //打到怪物
////        }
//        for(int i=0;i<count;i++){
//            painter.save();
//            painter.setPen(QPen(1));
//            painter.setBrush(QBrush(Qt::yellow));
//            painter.drawEllipse(QPoint(x+40,y+40),to_evilx*(i+1),to_evily*(i+1));
//            painter.restore();
//        }
//        if(count==bulletnum)
//             target_evil->BeHurt(power);//有被打到
//    }
//}
