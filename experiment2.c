#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#define FILENAME "varnotes"
#include "error.h"

void fatal(char *);
int find_user_notes(int, int);
int search_filter(char*,char*);

int main(int argc, char* argv[]){
    int fd , userid , reader,note_length;
    char *heap;
    char *filter;
    userid = getuid();
    if (argc>1){
        filter = ec_malloc(strlen(argv[1]));
        strcpy(filter,argv[1]);
    }
    else 
        filter = ec_malloc(0);
    printf("opening the file\n");
    fd = open(FILENAME,O_RDONLY);
    if (fd == -1)
        fatal("in main while opening the file");
    note_length = find_user_notes(fd,userid);
    while(note_length != -1){
    printf("allocating memmory in the heap\n");
    heap = (char*)ec_malloc(note_length +1);

    printf("moving note in the heap with address %p\n",heap);
    reader = read(fd,heap,note_length);
    if(reader == -1)
        fatal("error while storing note in heap");
    heap[note_length]='\0';
    if(search_filter(heap,filter))
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

int search_filter(char* note,char*keyword){
    int i , match;
    match = 0;
    if(strlen(keyword)== 0)
        return 1;
    for(i=0;i<strlen(note);i++){
        if(note[i]==keyword[match])
            match++;
        else{
            if(note[i]==keyword[0])
                match=1;
            else
                match = 0;
        }
    if(match == strlen(keyword))
        return 1;
    }
        return 0;
    
}
