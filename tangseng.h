#ifndef TANGSENG_H
#define TANGSENG_H
#include <QString>
class Tangseng{
public:
    Tangseng(int xx,int yy,QString path);
    void hurt(int h);
    int GetHealth()  const;//得到生命值
    QString GetImgPath() const; //获取图片路径
private:
    int health=100;
    QString ImgPath;
    int x;
    int y;
};

#endif // TANGSENG_H
