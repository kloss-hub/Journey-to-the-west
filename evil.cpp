#include "evil.h"
Evil::Evil(int hl,int ht,int r,QString i,QVector<Point *> p,int s):Object (p.at(0)->GetX(),p.at(0)->GetY(),i)
{
    health=hl;
    hurt=ht;
    reward=r;
    Path=p;
    speed=s;
}

void Evil::BeHurt(int h)
{
    health-=h;
}

void Evil::GetSlow()
{
    slowdown=true;
}

void Evil::move()
{
    int sp=speed;
    if(slowdown){
        sp=speed/2;
    }//减速的时间期限
    else {
        sp=speed;
    }
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
        x-=sp;
    }
    if(x<p2->GetX()){
        x+=sp;
    }
    if(y>p2->GetY()){
        y-=sp;
    }
    if(y<p2->GetY()){
        y+=sp;
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

void Evil::draw(QPainter &painter, int w, int h)
{
    Object::draw(painter,w,h);
    painter.save();
    painter.setPen(QPen(1));
    painter.setBrush(QBrush(Qt::red));
    painter.drawRect(x-20,y-10,health,5);
    painter.restore();
}
