#include <stdio.h>
#include <stdlib.h>
void usage(char* programe_name){
    printf("Usage: %s determines if a number is even or odd.\n",programe_name);
    exit(0);
}
int main(int argc, char* argv[]){
    long long int a,b , s=0;
    
    if (argc !=2)
     usage(argv[0]);
    a = atoi(argv[1]);
    s = (a*(a+1))>>1;
    printf("%lld",s);
        return 0;
}