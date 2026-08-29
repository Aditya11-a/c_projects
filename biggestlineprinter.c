#include <stdio.h>
int my_getline();
void copy(char*);

char line[200];

int main(){
    int curlen, lastlen;
    char linetoprint[200] = {0};
    lastlen = 0;
    while((curlen=my_getline()) != 0){
        if(curlen > lastlen){
            copy(linetoprint);
        lastlen = curlen ;
    }
    }
    putchar('\n');
    puts(linetoprint);
    return 0;
}

int my_getline(){
    int c , counter;
    c=counter=0;
    while((c = getchar()) != '\n'){
        if(c == EOF && counter== 0)
            return 0;
        else if(c == EOF && counter != 0){
            line[counter] = 0;
            return counter;}
        line[counter] = c;
        counter++;
    }
    line[counter]=0;
    return counter;
}

void copy(char* linetoprint){
    int i=0;
    while(line[i] != 0){
        linetoprint[i] = line[i];
        i++;
    }
    linetoprint[i]= 0;
}