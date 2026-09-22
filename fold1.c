#include <stdio.h>
#include "error.h"
#include <string.h>
#define LINE_LIMIT 80
void clear_buffer(char*);
int main(){
    int c=0,position=0,word_len=0,coloum=0,i,rep=0;
    float lines_required;    
    char* buffer = ec_malloc(400);
    char*start = buffer;
    char*start1 = start;
    while((c=getchar())!=EOF){
        if(c!='\n'&& c!='\t' && c!=' '){
            *buffer = c ;
            buffer++;
        }
        else{
            *buffer=0;
            word_len=strlen(start);
            lines_required= (word_len/LINE_LIMIT);
            if(lines_required>=1){
                while(word_len!=0){
                        while((LINE_LIMIT-position)!=0 && word_len!=0){
                                printf("%c",*start1);
                                position++;
                                word_len--;
                                start1++;
                        }
                        if(word_len){
                        putchar('-');
                        putchar('\n');
                        putchar('-');
                        position=1;}
                }
                start1=start;
                buffer=start;
            }
            else{
            if((position+word_len)<=LINE_LIMIT)
            printf("%s",start);
            else{
                putchar('\n');
                position=0;
                printf("%s",start);
            }
            position +=word_len;
            buffer=start;
                }
        }
        if(c=='\n'){
                putchar(c);
                position=0;
        }
        if(c=='\t'){
            putchar(c);
            coloum = (position/8)+1;
            position = 8*(coloum);
            if(position>=LINE_LIMIT){
                putchar('\n');
                position=0;
            }
        }
        if(c==' '){
                putchar(c);
                position++;
                if(position>=LINE_LIMIT){
                   putchar('\n');
                position=0;     
                }
        }
    }
    free(start);
    return 0;
}

void clear_buffer(char* ptr){
    int i;
    for(i=0;i<100;i++){
        *ptr = 0;
        ptr++;
    }
}