#include <stdio.h>
#include <stdlib.h>
void usage(char* programe_name){
    printf("Usage: %s determines if a number is even or odd.\n",programe_name);
    exit(0);
}
int main(int argc, char* argv[]){
    long long int a,b;
    
    if (argc !=2)
     usage(argv[0]);
    a = atoi(argv[1]);
    b = a<<63;
    if (b == 0)
        printf("%d is even\n",a);
    else
        printf("%d is odd\n",a);
    return 0;
}