#include <stdio.h>

typedef struct point{
    unsigned x;
    unsigned y;
}Point;
typedef struct rect{
    Point a;
    Point b;
}Rect;
Point make(unsigned x, unsigned y)
    {
        Point temp;
        temp.x = x;
        temp.y = y;
        return temp;
    }
Point middle(Rect r){
    Point temp;
    temp.x = (((r.a.x + r.b.x)) >>1);
    temp.y = (((r.a.y + r.b.y)) >>1);
    return temp;
}
Point addpoint(Rect r){
    r.a.x += r.b.x;
    r.a.y += r.b.y;
    return r.a;
}

int pinrect(Point p, Rect r){
    return p.x >= r.a.x && p.x < r.b.x && p.y >= r.a.y && p.y < r.b.y ; 
}


int main(){
    Rect rectangle;
    Point c = {2,3};
    rectangle.a= make(2,2);
    rectangle.b= make(4,4);
    if(pinrect(c,rectangle))
        printf("%u,%u is inside rectangle",c.x,c.y);
    return 0;
}