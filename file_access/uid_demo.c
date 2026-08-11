#include <stdio.h>

int main(){
    printf("real uid - %d",getuid());
    printf("effective uid - %d",geteuid());
return 0;
}