#ifndef POINT_H
#define POINT_H
class Point{
public:
    Point(int xx,int yy);
    int GetX() const;
    int GetY() const;
private:
    int x;
    int y;
};

#endif // POINT_H
