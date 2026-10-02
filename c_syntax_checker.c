#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_functions.h"
#define  ON 1 
#define OFF 0 
#define ERROR_MESSAGE printf("error in line no. %d : unexpected %c program was hoping for %c'\n",line_counter,c,*(stack.current-1))




int main(){
stack_engine(stack_builder(NULL,100));
int c =0 ,line_counter=1,error_state=OFF;
while((c=getchar())!=EOF){
    if(c=='\n') line_counter++;
    if(c=='('||c=='{'|| c=='['){
        if(push(c)=='\0'){
            stack_updater(stack.base_pointer);
            push(c);
        }
    }
    else if(c==')' || c=='}' || c== ']'){
            if(c==')'){
                if(*(stack.current-1)!='('){
                    ERROR_MESSAGE;
                    error_state=ON;
                    pop();
                    ungetc(c,stdin);
                }
                else{
                    pop();

                }}
            else if(c=='}'){
                if(*(stack.current-1)!='{'){
                    ERROR_MESSAGE;
                    error_state=ON;
                    pop();
                    ungetc(c,stdin);
                }
                else pop();
            }
            else{
                if(*(stack.current-1)!='['){
                    ERROR_MESSAGE;
                    error_state=ON;
                    pop();
                    ungetc(c,stdin);
                }
                else pop();
            }           
    } 
}
if(c==EOF){
    if(stack.base_pointer!=stack.current){
        printf("Syntax ERROR EOF reached still unclosed %c\n",*(stack.current-1));
        return 1;
    }
}
if(error_state==ON){
    return 1;
}
else{
puts("no syntax error found in the file");
return 0;}
}
