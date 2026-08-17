#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"

int search_filter(char*,char*);
int main(int argc, char* argv[]){
    char *a;
    char* b;
    a = ec_malloc(100);
    b = ec_malloc(100);
    strcpy(a,"hi how are you bye");
    strcpy(b,argv[1]);
    if(search_filter(a,b))
        printf("%s",a);
    return 0;
}
int search_filter(char* note,char*keyword){
    int i , match;
    match = 0;
    if(strlen(keyword)== 0)
        return 1;
    for(i=0;i<strlen(keyword);i++){
        if(note[i]==keyword[match])
            match++;
        else{
            if(note[i]==keyword[0])
                match=1;
            else
                match = 0;
        }
    }
    printf("%d",match);
    if(match == strlen(keyword))
        return 1;
    else
        return 0;
}