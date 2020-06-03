#include"gnome.h"
Gnome::Gnome(int xx,int yy,int s):Eudemon (xx,yy,s,":/images/tdgg2.png"){
    range=0;
    power=10;
    upgradecost=20;
}
void Gnome::Addbuttle(){
    count++;
    if(count>31)
        count=0;//重新计数

}
int Gnome::Attack(QPainter &painter){
    if(count>20){
        painter.drawPixmap(x+size/5, y-size/5, size/2,size/2,QPixmap(":/images/money.PNG"));//画出金钱
    }
    if(count==30){
        return power;
    }
     return 0;
}

Gnome::~Gnome(){}
