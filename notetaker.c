#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "error.h"


void usage(char *prog_name,char *filename){
    printf("[Usage] : %s is used to add data to >> %s\n",prog_name,filename);
    exit(0);
}
void fatal(char*);
void *ec_malloc(unsigned int);


int main(int argc, char *argv[]){
    int fd, userid;
    char* buffer; 
    char* datafile;
    
    buffer = (char*)ec_malloc(100);
    datafile = (char*)ec_malloc(20);
    strcpy(datafile,"varnotes");
    if(argc<2){
        usage(argv[0],datafile);}
    strcpy(buffer,argv[1]);
    printf("[DEBUG] buffer is at %p and contains %s\n",buffer,buffer);
    printf("[DEBUG] datafile is at %p and contains %s\n",datafile,datafile);
    userid= getuid();
    fd = open(datafile,O_RDWR|O_CREAT|O_APPEND,0644);
    if (fd == -1){
        fatal("While opening the file");
    }
    printf("[DEBUG] fd is %d\n",fd);
    int a = write(fd, &userid ,4);
        if (a == -1){
        printf("%d\n",a);
        fatal("While writing to the file");
    }
    write(fd,"\n",1);
    if(write(fd,buffer,strlen(buffer))== -1){
        fatal("while writing buffer to the file");
    }
    write(fd,"\n",1);
    if(close(fd)== -1){
        fatal("while closing the file");
    }
    printf("file saved");
    free(buffer);
    free(datafile);
    return 0;

}