#include <stdio.h>
#include <stdlib.h>
void usage(char* programe_name){
    printf("Usage: %s determines if a number is even or odd.\n",programe_name);
    exit(0);
}
int main(int argc, char* argv[]){
    int a,b;
    
    if (argc !=2)
     usage(argv[0]);
    a = atoi(argv[1]);
    
    if (a>75)
    puts("0");

    else if(a>=60 && a<=75)
    puts("A");

    else if(a>=50 && a<=59)
    puts("B");

    else if(a>=40 && a<=49)
    puts("C");

    else if(a<40)
    puts("D");

    return 0;

}