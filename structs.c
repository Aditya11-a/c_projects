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


int main(){
    Rect rectangle;

    rectangle.a= make(2,2);
    rectangle.b= make(4,4);
    Point mid= middle(rectangle);
    Point add= addpoint(rectangle);
    printf("%u,%u",add.x,add.y);
    return 0;
}