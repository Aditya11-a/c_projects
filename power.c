#include <stdio.h>
int power(int,int);
int main(){
    int i;
    for(i=0 ; i<10 ; i++){
        printf("2^%d is %d\n",i,power(2,i));
        printf("-3^%d is %d\n",i,power(-3,i));
    }
    return 0;
}

int power(int base , int pwr){ //only takes positive power.
    int i , result;
    i = result = 0;
    if(pwr == 0)
        result = 1;
    else if(pwr == 1)
        result= base;
    else{
        result = base;
    for(i=2;i<=pwr;i++){
        result= result*base;
    }
}
    return result;
}