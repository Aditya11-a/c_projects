#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

void *ec_malloc(unsigned int size){
    void *ptr=malloc(size);
    if(ptr == NULL){
        fprintf(stderr,"error while allocating space\n");
        exit(EXIT_FAILURE);}
    return ptr;
}
int main (char* argc, char* argv[]){
    int fd;
    char *datafile = (char*)ec_malloc(20);

    printf("allocated space starting from %p\n",datafile);
    strcpy(datafile,"hello");
    fd = open(datafile,O_WRONLY| O_CREAT, 0644);
    printf("the functional directory of open folder is %d\n",fd);
    return 0;
}