#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "error.h"
#define FILENAME "varnotes"
void fatal(char *);
int print_notes(int,int);
int find_user_notes(int,int);




int main(int argc, char* argv[]){
    int userid, fd,printing;
    printing = 1;
    userid = getuid();
    printf("opening file\n");
    fd = open(FILENAME,O_RDONLY);
    if(fd == -1)
        fatal("in main() while opening the file\n");
    
    while(printing)
        printing = print_notes(fd, userid);
    printf("----------[END]-----------");
    close(fd);
return 0 ;
}



int print_notes(int fd, int userid){
    int note_length;
    char * heap;
    note_length = find_user_notes(fd,userid);
    heap = ec_malloc(note_length +1);
    while(note_length != -1){
    printf("allocating memmory in the heap\n");
    heap = (char*)ec_malloc(note_length +1);

    printf("moving note in the heap with address %p\n",heap);
    int reader = read(fd,heap,note_length);
    if(reader == -1)
        fatal("error while storing note in heap");
    heap[note_length]='\0';
    printf("%s",heap);
    free(heap);
    note_length = find_user_notes(fd,userid);
    }
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
    
    byte=length=0;
        while(byte != '\n'){
            if(read(fd,&byte,1)!= 1)
               return -1;
            length ++;
        }
    }
    lseek(fd,length *-1,SEEK_CUR);
    return length;
}

