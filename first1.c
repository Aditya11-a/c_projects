#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void *errorchecked_malloc(unsigned int);
int main(int argc, char* arg[]){
char *char_ptr;
int *int_ptr;
int mem_size;
if (argc <2){
 mem_size = 50;
}
else{
    mem_size= atoi(arg[1]);
}
if (mem_size <36){
    fprintf(stderr,"give the size bigger than 36");
    exit(-1);
}
printf("allocating %d bytes in heap to char_ptr\n",mem_size);
char_ptr = (char *)errorchecked_malloc(mem_size);

strcpy(char_ptr,"This memory is located in the heap\n");
printf("char_ptr %p --> %s\n",char_ptr,char_ptr);
mem_size=12;
printf("allocating %d bytes in heap to int_ptr\n",mem_size);
int_ptr = (int*)errorchecked_malloc(mem_size);

*int_ptr=1197;
printf("int_ptr %p --> %d\n",int_ptr,*int_ptr);
printf("freeing char_ptr\n");
free(char_ptr);
mem_size = 23;
printf("allocating new %d bytes of memory\n",mem_size);
char_ptr = (char*)errorchecked_malloc(mem_size);

strcpy(char_ptr,"new memmory allocated\n");
printf("char_ptr %p --> %s\n",char_ptr,char_ptr);
printf("freeing char_ptr\n");
free(char_ptr);
printf("freeing int_ptr\n");
free(int_ptr);
return 0;
}

void *errorchecked_malloc(unsigned int size){
void *ptr = malloc(size);
if (ptr == NULL){
    fprintf(stderr,"can't allocate memory");
    exit(-1);
}
return ptr;
}