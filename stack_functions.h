#include <stdio.h>
#include "error.h"
#include <stdlib.h>


char* stack_builder(char*,int);
void stack_engine(char*);
typedef struct{
    char* base_pointer;
    char* top;
    char* current;
    int size;
    int previous_stack_size;
}STACK;

STACK stack;
int stack_update_counter=1;
void stack_engine(char* ptr){
    stack.base_pointer=ptr;
    stack.top = stack.base_pointer+stack.size;
    if(stack_update_counter!=1){
        stack.current=stack.base_pointer+stack.previous_stack_size;
    }
    else{
    stack.current = stack.base_pointer;
    }
    stack.previous_stack_size=stack.size;
}



char* stack_builder(char* buffer_ptr,int size){
    char *ptr;
    ptr = (char*)ec_realloc(buffer_ptr,size);
    stack.size=size;
    return ptr;
}


char push(char value){
    if(stack.current == stack.top){
        return NULL;
    }
    else{  
    *stack.current= value;
    stack.current++;
    return value;
    }
}

void stack_updater(char* buffer_ptr){
    stack_update_counter++;
    stack_engine(stack_builder(buffer_ptr,stack.size*stack_update_counter));
}


char pop(){
    if((stack.current-1)==(stack.base_pointer-1)){
        return NULL;
    }
    else{
        char delete_char = *(stack.current-1);
        *(stack.current-1) = NULL;
        stack.current--;
        return delete_char;
    }
}