#include <stdio.h>
#define TABSPACES 8


int main(){
    int c =0,i,counter=0;
    while((c=getchar()) !=EOF){
        if(c== '\t'){
            for(i=0;i<(TABSPACES-counter);i++){
                putchar(' ');
            }
            counter = 0;
        }
        else if(c=='\n'){
            putchar(c);
            counter = 0;
        }
        else{
            putchar(c);
            counter++;
            if (counter==TABSPACES)
                counter=0;
        }
    }
    return 0;
}
