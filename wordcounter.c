#include <stdio.h>
#define IN 1
#define OUT 0
int main(){
    int c, nw = 0;
    int state = OUT;
    while ((c = getchar()) != EOF){
        if(c == '\n' || c == '\t' || c == ' '){
            state = OUT ;
            putchar('\n');
        }
        else if(state == OUT){
            state = IN;
            nw++;
        }
        if(state == IN)
            putchar(c);
        }
    printf("\ntotal no of words %d\n", nw);
return 0;
}