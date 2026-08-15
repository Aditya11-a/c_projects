#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#define FILENAME "varnotes"
#include "error.h"

void fatal(char *);
int find_user_notes(int, int);
int main(){
    int fd , userid , reader,note_length;
    char *heap;
    userid = getuid();
    
    printf("opening the file\n");
    fd = open(FILENAME,O_RDONLY);
    if (fd == -1)
        fatal("in main while opening the file");
    note_length = find_user_notes(fd,userid);
    printf("allocating memmory in the heap\n");
    heap = (char*)ec_malloc(note_length +1);
    printf("moving note in the heap with address %p\n",heap);
    reader = read(fd,heap,note_length);
    if(reader == -1)
        fatal("error while storing note in heap");
    printf("%s",heap);
    free(heap);
    if(close(fd) == -1)
        fatal("error while closing the file");
    return 0;
    
}

int find_user_notes(int fd, int uid){
    int note_id = -1;
    int length ;
    unsigned char byte;
    while(note_id != uid){
        if(read(fd,&note_id,4)!=4)
            return -1;
        if(read(fd,&byte,1)!= 1)
            return -1;
    }
    byte=length=0;
        while(byte != '\n'){
            if(read(fd,&byte,1)!= 1)
               return -1;
            length ++;
        }
    lseek(fd,length *-1,SEEK_CUR);
    return length;
}