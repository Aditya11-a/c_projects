#include <stdio.h>
#include <stdlib.h>
int global_var;
int global_inti_var=5;

void function(){
    int stack_var;
    printf("the function's stack_var is at 0x%08x\n",&stack_var);
}

int main(){
    int stack_var;
    int static static_var;
    int static intialized_static_var=2;
    int *heap_ptr_var;
    heap_ptr_var = (int*)malloc(4);
    printf("global_var memory address is 0x%x\n",&global_var);
    printf("initilizad global_var memory address is 0x%x\n",&global_inti_var);
    printf("stack_var memory address is 0x%x\n",&stack_var);
    printf("static_var memory address is 0x%x\n",&static_var);
    printf("intialized_static_var memory is at the address 0x%x\n",&intialized_static_var);
    printf("heap_ptr is showing to address %p\n",&heap_ptr_var);
    function();
    return 0;
}