#include <stdio.h>
#include <stdlib.h>
#define IN 1
#define OUT 0 
void file_ender_checker(int a){
    if(a==EOF)
        exit(0);
}
int main(){
    int c=0,quote=OUT,comment=OUT,type=0,entered=0,holder=0,type2=0,counter=0;
    char buffer[3];
    buffer[2]=0;
    while((c=getchar())!=EOF){
        if(quote){
            putchar(c);
            if(counter){
            if(type2=='"'){
            if(c=='"'){
                quote=OUT;
            }}
            else{
            if(c==39){
                quote=OUT;
            }}
            }
            else{
            if(type2=='"'){
            if(holder !=92 && c=='"'){
                quote=OUT;
            }}
            else{
            if(holder !=92 && c==39){
                quote=OUT;
            }}}
            if(c=='\\' && holder==c)
                counter=1;
            else
                counter=0;
            holder = c;
            
        }
        else{
        if(comment==OUT && c=='/'){
            buffer[0]=c;
            c=getchar();
            file_ender_checker(c);
            if(c=='*' || c=='/'){
                comment=IN;
                type=c;
                entered=1;
            }
            else{
                buffer[1]=c;
                printf("%s",buffer);
            }
        }
        else{
            if(comment==OUT){
            if(c=='"' || c==39){
                quote=IN;
                type2=c;
            }
            putchar(c);}
        }
        if(comment && type=='*'){
            if(holder=='*' && entered!=1 && c=='/'){
                comment=OUT;
                
            }
            else{
            entered=0;
            }
            holder=c;
        }
        else if(comment && type=='/'){
            if(c=='\n'){
                comment=OUT;
                putchar('\n');
            }
            
        }
    }

    }   
return 0;
}