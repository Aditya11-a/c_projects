#include <stdio.h>

struct point{
    int x;
    int y;
};
struct rect{
    struct point a;
    struct point b;
};
struct point make(int x, int y)
    {
        struct point temp;
        temp.x = x;
        temp.y = y;
        return temp;
    }

int main(){
    struct rect rectangle;

    rectangle.a= make(2,3);
    rectangle.b= make(4,5);
    printf("%d,%d and %d,%d",rectangle.a.x,rectangle.a.y,rectangle.b.x,rectangle.b.y);
    return 0;
}