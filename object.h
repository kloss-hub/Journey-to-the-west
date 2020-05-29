#ifndef OBJECT_H
#define OBJECT_H
#include <QString>
#include <QPainter>
class Object{
public:
    Object(int xx,int yy,QString i);
    void SetX(int xx);
    void SetY(int yy);
    int GetX() const;       //获取横坐标
    int GetY() const;       //获取横坐标
    QString GetImg() const; //获取图片路径
    void Changeimag(QString i);
    void draw(QPainter &,int w,int h);
protected:
    int x,y;//坐标
    QString img;//图片
};

#endif // OBJECT_H
