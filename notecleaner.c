#include <stdio.h>
#include <stdlib.h>
#include "error.h"
#define FILENAME "varnotes"
#include <fcntl.h>
#include <unistd.h>


void fatal(char*);

int main(){
    int fd;
    printf("opening varnotes and wiping all the data");
    fd = open("varnotes", O_RDWR|O_TRUNC);
    if (fd== -1){
        fatal("error opening the file");
    }
    return 0;
}