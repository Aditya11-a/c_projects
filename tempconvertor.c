#include <stdio.h>
#include <stdlib.h>
void usage(char * programname){
    printf("%s is used to convert fharenhite to celcius\n",programname);
    printf("syntax ./%s <arugument1> <argument2>\n give first arguments \'F\' for f to C and \'C\'  for c to f \n ");
    printf("give second arguments the value to be converted");
    exit(0);
}

void f_to_c(float );
void c_to_F(float);
int main(int argc , char* argv[]){
    int i;
    printf("%d\n",argc);
    for(i=0;i<argc;i++){
        printf("%s\n",argv[i]);
    }
    if (argc<2)
        usage(argv[0]);
    float temp = atof(argv[2]);
    char arg1 = *argv[1];
    if (arg1 == 70)
        f_to_c(temp);
    else if(arg1 == 67)
        c_to_F(temp);
    else 
        usage(argv[0]);
    return 0;
}

void f_to_c(float ttoc){
    float c = (5/9)*ttoc-32;
    printf("%f in celcius is %f",ttoc,c);
}

void c_to_F(float ttoc){
    float c = (9/5*ttoc)+32;
    printf("%f in farenhite is %f",ttoc,c);
}