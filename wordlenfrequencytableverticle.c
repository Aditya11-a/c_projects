#include <stdio.h>
#define OUT 0
#define IN 1

int main(){
    int i , c , state,j,k,highest;
    int frequency[17] , checker[17];
    state = OUT;
    i = c = k = highest=0;
    for(i=0;i<17;i++){
        checker[i]=0;
    }
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
        k = frequency[i]>0 ;
        if(k){
            printf("%d",i);
            highest = (highest > frequency[i]) ? highest : frequency[i];
            checker[i]=1;
        }
    }
    putchar('\n');
    for(i=0;i<highest;i++){
        for(j=1;j<17;j++){
            if(frequency[j]>0){
                printf("*");
                frequency[j]--;
            }
            else if(frequency[j]==0 && checker[j]==1)
                printf(" ");
        }
        putchar('\n');
    }
    return 0 ;
}