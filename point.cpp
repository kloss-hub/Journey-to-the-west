#include "point.h"
Point::Point(int xx,int yy){
    x=xx;
    y=yy;
}
int Point::GetX() const
{
    return x;
}
int Point::GetY() const
{
    return y;
}
