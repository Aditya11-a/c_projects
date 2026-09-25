#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fatal(char *message){
    char error_message[100];

    strcpy(error_message,"[!!] FATAL ERROR ");
    strncat(error_message,message,83);
    perror(error_message);
    exit(EXIT_FAILURE);
}

void *ec_malloc(unsigned int size){
    void *ptr;
    ptr = malloc(size);
    if (ptr == NULL)
    fatal("error while allocating memmory in ec_malloc");
    return ptr;
}

void* ec_realloc(void* ptr,size_t new_size){
    void *ret_ptr;
    ret_ptr = realloc(ptr,new_size);
    if(ret_ptr==NULL)
    fatal("error while allocating more memmory to stack");
    return ret_ptr;
}