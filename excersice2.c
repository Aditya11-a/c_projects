#include <stdio.h>

int main(){
    int i, c ;
    int nwhitesp = 0;
    int notherc = 0 ;

    int ndigit[10];
    for(i=0;i<10;i++)
        ndigit[i] = 0 ;
    while((c=getchar()) != EOF){
        if(c >= '0' && c<= '9')
            ndigit[c-'0']++;
        else if(c == '\n' || c=='\t' || c==' ')
            nwhitesp++;
        else
            notherc++;
    }
    printf("digits count are as follows\n");
    for(i=0 ; i<10 ; i++)
        printf("%d ," , ndigit[i]);
    printf("no of white_spaces and other characters are %d and %d respectively", nwhitesp,notherc);
}