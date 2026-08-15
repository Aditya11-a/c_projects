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
    printf("opening file");
    fd = open(FILENAME,O_RDONLY);
    if(fd == -1)
        fatal("in main() while opening the file");
    
    while(printing)
        printing = print_notes(fd, userid);
    printf("----------[END]-----------");
    close(fd);
return 0 ;
}



int print_notes(int fd, int userid){
    
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

