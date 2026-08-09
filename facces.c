#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

void usage(char *prog_name,char *filename){
    printf("usage : %s <to add data to >%s\n",prog_name,filename);
    exit(0); 
}
void *fatal(char*);
void *ec_malloc(size_t);

int main(int argc,char *argv[]){
    int fd;
    char* buffer, *datafile;
    buffer = ec_malloc(100);
    datafile = ec_malloc(20);
    strcpy(datafile,"tmpnotes");
    if (argc <2)
        usage(argv[0],datafile);
    strcpy(buffer,argv[1]);
    
    printf("[debug] buffer is at %p  / '%s' \n",buffer,buffer);
    printf("[debug] datafile is at %p / '%s'\n",datafile,datafile);
    strcat(buffer, "\n");
    fd = open(datafile,O_WRONLY|O_CREAT|O_APPEND,0644);
    if (fd == -1){
        fatal("in main() while opening the file\n");
        exit(EXIT_FAILURE);
    }
    printf("file discripter is %d\n",fd);
    int w = write(fd,buffer,strlen(buffer));
    if(w == -1){
        fatal("error while writing to the file\n");
        exit(EXIT_FAILURE);
    }
    if(w < strlen(buffer)){
        fatal("can't write the complete buffer\n");
        exit(EXIT_FAILURE);
    }
    printf("added %d bytes from buffer to datafile\n",w);
    //printf("new content of datafile %s",datafile);
    if (close(fd)== -1){
        fatal("error while closing the file.\n");
        exit(EXIT_FAILURE);
    }
    printf("saved and closed");
    
return 0;
}
void *fatal(char* message){
    char error_message[100];
    strcpy(error_message,"!! [Fatal]");
    strncat(error_message,message,88);
    perror(error_message);
    exit(-1);
}

void *ec_malloc(size_t a){
    void *ptr= malloc(a);
    if (ptr== NULL){
        perror("error while allocating space in heap\n");
    }
return ptr;
}
