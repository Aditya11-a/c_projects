#include <stdio.h> 

int main(){
    int c,position=0,space_count=0,i;
    int a=0, tab_no=0,space_no=0;
    int tabspace= 8;
    while((c=getchar())!=EOF){
        tabspace = 8*((position/8)+1);
        if(c!=' ' && c!='\n'){
        if(c=='\t'){
        putchar(c);
        position = tabspace;
        space_count=0;
        a=0;
            }
        else{
            if(a){
                if((position+space_count)>=tabspace){
                space_no=(position+space_count)%8;
                tab_no=((position+space_count)/8)-(position/8);
                for(i=0;i<tab_no;i++){
                    putchar('\t');
                }
                for(i=0;i<space_no;i++){
                    putchar(' ');
                }}
                else{
                    for(i=0;i<space_count;i++){
                        putchar(' ');
                    }
                }
                a = 0;
                position = position+space_count;
                space_count =0;
            }
            putchar(c);
            position++;
        }
        }
        else if(c == '\n'){
            putchar(c);
            position=0;
            tabspace=8;
            space_count=0;
            a=0;
        }

        else{
            space_count++;
            a=1;
        }
         
    }
}