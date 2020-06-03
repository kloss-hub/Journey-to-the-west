#include"monk_sha.h"
MonkSha::MonkSha(int xx,int yy,int s):Eudemon (xx,yy,s,":/images/shs.PNG"){
    range=100;
    power=5;
    upgradecost=20;
    bulletnum=6;
}
void MonkSha::Addbuttle(){
    if(count<bulletnum)
        count++;
}
int MonkSha::Attack(QPainter &painter){
    if(target_evil&&target_evil->GetHealth()>0){
        int to_evilx=(target_evil->GetX()-x)/bulletnum;
        int to_evily=(target_evil->GetY()-y)/bulletnum;//到达目标怪物的距离
        painter.save();
        painter.setPen(QPen(Qt::yellow,2,Qt::SolidLine));
        for(int i=0;i<count;i++){
            painter.drawEllipse(QPoint(x+20,y+30),to_evilx*(i+1),to_evily*(i+1));
        }
        painter.restore();
        if(count==bulletnum)
             target_evil->BeHurt(power);//有被打到
    }
    return 0;
}
MonkSha::~MonkSha(){}
