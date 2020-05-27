#include "tangseng.h"
Tangseng::Tangseng(int xx,int yy,QString path)
{
    x=xx;
    y=yy;
    ImgPath=path;
}
void Tangseng:: hurt(int h)
{
    health-=h;
}
int Tangseng::GetHealth()const
{
    return health;
}
QString Tangseng::GetImgPath() const
{
    return ImgPath;
}
