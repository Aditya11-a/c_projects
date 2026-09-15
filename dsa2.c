#include <stdio.h>
#include <stdlib.h>
void usage(char* programe_name){
    printf("Usage: %s is used to compare two nos.\n You have to give the two nos. as the argument while executing.\n",programe_name);
    exit(0);
}
int main(int argc, char* argv[]){

    long long int a , b ;
    if (argc !=3)
     usage(argv[0]);
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    if (a>b)
        printf("%d is greater",a);
    else
        printf("%d is greater",b);
    return 0;
}