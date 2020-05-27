#include"object.h"
Object::Object(int xx,int yy,QString i)
{
    x=xx;
    y=yy;
    img=i;
}
int Object::GetX() const
{
     return x;
}

int Object::GetY() const
{
    return y;
}
void Object::SetX(int xx)
{
    x=xx;
}
void Object::SetY(int yy)
{
    y=yy;
}
QString Object::GetImg() const
{
    return img;
}
void Object::draw(QPainter &painter,int w,int h)
{
    painter.drawPixmap(x,y,w,h,QPixmap(img));
}
