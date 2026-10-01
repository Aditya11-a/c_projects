#include "pre_processor_struct.h"
#define YES 1
#define NO 0



int preprocessor_directive_line_checker();

int main(){
    int c =0 , entered_newline = YES,result = 0,line_counter=1,pipe_line_failed=0;
    while((c=getchar())!=EOF){
        if(entered_newline){
            if(c == ' '||c== '\t'){
                putchar(c);
            }
            else{
            if(c=='#'){
                
                result=preprocessor_directive_line_checker();
                if(result==1){
                    fprintf(stderr,"Syntax error in line : %d\n",line_counter);
                    pipe_line_failed =1 ;
                }
            line_counter++;
            putchar('\n');
            entered_newline= YES;
            }
            else{
            if(c == '\n'){
                entered_newline = YES;
                line_counter++;
                putchar(c);
            }
            else{
            putchar(c);
            entered_newline = NO;  
            }
            }
        }
        }
        else{
            if(c == '\n'){
                entered_newline = YES;
                line_counter++;
            }
            putchar(c);
        }
    }
    if(pipe_line_failed==1){
        return 1;
    }
    return 0;
}

