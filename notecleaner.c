#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#define FILENAME "varnotes"
#include <fcntl.h>
#include <unistd.h>


void fatal(char*);

int main(){
    int fd;
    printf("opening varnotes and wiping all the data\n");
    fd = open(FILENAME, O_RDWR|O_TRUNC);
    if (fd== -1){
        fatal("error opening the file");
    }
    int a = close(fd);
    if (a == -1)
        fatal("while closing the file.\n");
    return 0;
}