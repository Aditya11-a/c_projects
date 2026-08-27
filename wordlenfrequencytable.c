#include <stdio.h>
#define OUT 0
#define IN 1

int main(){
    int i , c , state,j;
    int frequency[17];
    state = OUT;
    i =c=0;
    for(i=0;i<17;i++){
        frequency[i] = 0;
    }
    printf("frequency before counting\n");
    for(i=0;i<17;i++){
         printf("%d",frequency[i]);
    }
    putchar('\n');
    i = 0;
    while((c = getchar()) != EOF ){
        if(c == '\t'|| c=='\n' || c == ' ')
            state = OUT;
        else if (state == OUT){
            if (i<16)
                ++frequency[i];
            else
                ++frequency[16];
            state = IN;
            i = 0;
        }

        if(state == IN)
            i++;
    }
    if (i<16)
            ++frequency[i];
    else
            ++frequency[16];
    
    printf("\nthe frequency are as below\n");
    for(i=1;i<17;i++){
         printf("%d",frequency[i]);
    }
    putchar('\n');
    for(i=1;i<17;i++){
        if(frequency[i]>0){
            printf("%d |",i);
            for(j=0;j<frequency[i];j++){
                printf("*");
            }
            putchar('\n');
        }
        else if (i == 16 && frequency[i]>0){
            printf("15+ |");
            for(j=0;j<frequency[i];j++){
                printf("*");
            }
            putchar('\n');
        }
    }
    return 0 ;
}