#include <stdio.h>
#include <stdlib.h>
int j = 42;
void fun3(){
    int i =11, j=999;
    printf("\t\t\tin [fun3] i @ 0x%016x and i=%d\n",&i,i);
    printf("\t\t\tin [fun3] j @ 0x%016x and j=%d\n",&j,j);
}
void fun2(){
    int i=7;
    printf("\t\tin [fun2] i @ 0x%016x and i=%d\n",&i,i); 
    printf("\t\tin [fun2] j @ 0x%016x and j=%d\n",&j ,j);
    printf("\t\tin [func2] setting j = 1337\n");
    j=1337;
    fun3();
    printf("\t\tback in [fun2] i @ 0x%016x and i=%d\n",&i,i);
    printf("\t\tback in [fun2] j @ 0x%016x and j=%d\n",&j,j);
}
void fun1(){
    int i =5;
    printf("\tin [fun1] i @ 0x%016x and i=%d\n",&i,i);
    printf("\tin [fun1] j @ 0x%016x and j=%d\n",&j,j);
    fun2();
    printf("\tback in [fun1] i @ 0x%016x and i=%d\n",&i,i);
    printf("\tback in [fun1] j @ 0x%016x and j=%d\n",&j,j);
}
int main(){
    int i=3;
    printf("in [main] i @ 0x%016x and i=%d\n",&i,i);
    printf("in [main] j @ 0x%016x and j=%d\n",&j,j);
    fun1();
    printf("back in [main] i @ 0x%016x and i=%d\n",&i,i);
    printf("in [main] i @ 0x%016x and j=%d\n",&j,j);
}