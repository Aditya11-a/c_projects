#include <stdio.h>
#define TABSPACE 8
#define OUT 0
#define IN 1

void space_tab(char, int);


int main(){
int word_len_coun=0 ;
int state= OUT,c=0;
while((c=getchar())!=EOF){
    if(c == ' '||c == '\t'||c == '\n'){
        state = OUT;
    }
    else{
        state = IN;
    }
    if(state){
        word_len_coun++;
        putchar(c);
    }
    else{
        space_tab(c,word_len_coun);
        word_len_coun = 1;
    }
}
return 0;


}

void space_tab(char b,int word_len_coun){
    int i,space_coun = 0;
    if(b!=' '){
        putchar(b);
    }
    else{
        space_coun++;
        while((b=getchar())==' '){
            space_coun++;
        }
        if((word_len_coun+space_coun)==TABSPACE){
            putchar('\t');
            word_len_coun = 0;}
        else{
            for(i=0;i<space_coun;i++){
                putchar(' ');
            }
            space_coun=0;
        }
        putchar(b);
    }
}

