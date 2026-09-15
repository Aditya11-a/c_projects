#include <stdio.h>

int main(){
    int first, second ; 
    puts("enter two nos. that you want to change positions.");
    first= getchar();
    second= getchar();
    printf("first no. is %c and second no. is %c\n",first,second);
    printf("now in reversed order . 1st is %c and second is %c.\n",second,first);
    return 0 ;
}