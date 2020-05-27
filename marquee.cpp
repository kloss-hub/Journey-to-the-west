#include"marquee.h"
Marquee::Marquee(int xx,int yy,QString i,QString s1,QString s2,QString s3,QString s4):Object (xx,yy,i)
{
    sel1=s1;
    sel2=s2;
    sel3=s3;
    sel4=s4;
}
void Marquee::draw(QPainter &painter,int blocksize)
{
    painter.drawPixmap(x-blocksize,y-blocksize,blocksize*3,blocksize*3,QPixmap(img));
    painter.drawPixmap(x,y-blocksize,blocksize,blocksize,QPixmap(sel1));
    painter.drawPixmap(x+blocksize,y,blocksize,blocksize,QPixmap(sel2));
    painter.drawPixmap(x,y+blocksize,blocksize,blocksize,QPixmap(sel3));
    painter.drawPixmap(x-blocksize,y,blocksize,blocksize,QPixmap(sel4));//画出四个选项
}