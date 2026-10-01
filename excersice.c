#include "pre_processor_struct.h"
#include <string.h>
#include <stdio.h>

WORDS_GROUP d_words_group[]={
    [0].word="define",[0].category=2,
    [1].word="hello",[1].category=0,
    [2].word="",[2].category='\0'
};

char buffer[9]="hello";
WORDS_GROUP* ptr = d_words_group;
int main(){
int i=0 , word_group_size;
for(i=0;i<strlen((const char *)ptr);i++){
if((strcmp(buffer,(ptr+i)->word))==0)
    printf("hello");}
}