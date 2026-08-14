#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#define FILENAME "varnotes"
#include "error.h"

int find_user_notes(int,int);

int main(){
    int fd , userid;
    userid= getuid();
    printf("opening the file");
    fd = open(FILENAME,O_RDONLY);
    if (fd == -1)
        fatal("error in main() while opening the file");
    
    printf("the length of the notes of the user is %d",find_user_notes(fd,userid));
    return 0;
}

int find_user_notes(int fd, int uid){
    int note_id = -1;
    int note_length ;
    unsigned char byte;
    while(note_id != uid){
        if(read(fd,&note_id,4)!=4)
            return -2;
        if(read(fd,&byte,1)!= 1)
            return -1;
        
        byte=note_length=0;
        while(byte != '\n'){
            if(read(fd,&byte,1)!= 1)
                return -3;
            note_length ++;
        }
    }
    lseek(fd,note_length *-1,SEEK_CUR);
    return note_length;
}