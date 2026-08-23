#include <stdio.h>

int funct_1(){
    printf("this is a function 1\n");
    return 1;
}

int funct_2(){
    printf("this is function 2\n");
    return 2;
}

int main(){
    int value;
    int (*funct_ptr)();

    funct_ptr = funct_1;
    printf("funct_ptr points to %p\n",funct_ptr);
    value = funct_ptr();
    printf("vlaue returned was %d\n",value);
    funct_ptr = funct_2;
    printf("funct_ptr points to %p\n",funct_ptr);
    value = funct_ptr();
    printf("it returned value %d\n",value);
return 0;

}