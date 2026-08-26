#include <stdio.h>

int main(){
    int c ;
    int d = 0;
    while ((c = getchar()) != EOF){

        if(d == ' ' && c == ' ')
            ;
        else 
            putchar(c);
        d = c;
    }
    return 0 ;
}