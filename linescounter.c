#include <stdio.h>

int main(){
    int ln=0, c;
    while((c=getchar()) != EOF){
        if(c == '\n')
            ln++;  
    }
    printf("%d",ln);
    return 0;
}