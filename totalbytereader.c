#include <stdio.h>

int main(){
    long nc = 0;
    while(getchar()!= EOF)
        nc++;
    printf("%ld",nc);
    return 0;
}