#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "error.h"
#define FILENAME "varnotes"

void *ec_malloc(unsigned int);
void fatal(char*);
int main(){
    char* buffer = ec_malloc(100);
    int read_return =1;
    printf("opening file to read\n");
    int fd = open(FILENAME,O_RDONLY);
    if(fd == -1)
        fatal("error while opening the file");
    while(read_return){
    
        read_return = read(fd,buffer,4);
        if (read_return > 0)
            write(1,buffer,read_return);
        }
    free(buffer);
    if(close(fd)== -1)
        fatal("error while closing the file");
    return 0;
    }