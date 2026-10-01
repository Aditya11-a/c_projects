#include <stdio.h>
#include "error.h"
#include <stdlib.h>
#include "stack_functions.h"
#define  ON 1 ;
#define OFF 0 ;




int main(){
    int c = 0 , line_counter =0, pre_processor_state=OFF ; 
    stack_engine(stack_builder(NULL,100));
    while((c=getchar())!=EOF){
        if(c=='#'){
            pre_processor_state=ON;
        }
        else{
            pre_processor_state = OFF;
        }

        if(pre_processor_state){
            if(c=='<'){
                push('<');
            }
        }
    }
}




