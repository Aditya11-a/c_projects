#include <stdio.h>
#include "error.h"
#include <string.h>
#define LINE_LIMIT 80
void clear_buffer(char*);
int main(){
    int position=0,c,i,word_len=0;
    char* buffer= ec_malloc(100);
    char*start = buffer;
    char*start1 = start;
    while((c = getchar())!=EOF){
        if(position>=(LINE_LIMIT+1)){
            position=0;
            putchar('\n');
        }
        else{
        if(c != '\n'&& c != '\t' && c != ' '){
            *buffer = c;
            buffer++;
            position++;
        }
        else{
            *buffer=0;
            buffer=start;
            word_len=strlen(start);
            if(word_len>LINE_LIMIT){
                for(i=0;i<(LINE_LIMIT-1);i++){
                    printf("%c",*start1);
                    start1++;
                }
                putchar('-');
                putchar('\n');
                putchar('-');
                for(i=0;i<(word_len-(LINE_LIMIT-1));i++){
                    printf("%c",*start1);
                    start1++;
                }
                start1=start;
            }
            else{
            if((position+strlen(start))>LINE_LIMIT)
                putchar('\n');   
            printf("%s",start);
            clear_buffer(start);
            position +=word_len;
        }
        if(c=='\n'){
            if(position==LINE_LIMIT){
            putchar(c);
        }
            else;
        }
        else if(c == ' '){
            if(position!=LINE_LIMIT){
                putchar(c);
            }
        }
        else if(c == '\t'){
            putchar('\t');
        }
    }
}

}
free(start);
return 0 ;
}

void clear_buffer(char* ptr){
    int i;
    for(i=0;i<100;i++){
        *ptr = 0;
        ptr++;
    }
}