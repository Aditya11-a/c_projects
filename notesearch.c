#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "error.h"
#define FILENAME "varnotes"
void fatal(char *);
int print_notes(int,int,char*);
int find_user_notes(int,int);
int search_filter(char*,char*);




int main(int argc, char* argv[]){
    int userid, fd,printing;
    printing = 1;
    userid = getuid();
    char* filter;
    if(argc > 1){
        filter = ec_malloc(strlen(argv[1]));
        strcpy(filter,argv[1]);
    }
    else
        filter = ec_malloc(0);
    printf("opening file\n");
    fd = open(FILENAME,O_RDONLY);
    if(fd == -1)
        fatal("in main() while opening the file\n");
    
    print_notes(fd, userid,filter);
    printf("----------[END]-----------");
    if(close(fd)== -1)
        fatal("while closing the file");
    free(filter);
    return 0 ;
}



int print_notes(int fd, int userid,char* filter){
    int note_length;
    char * heap;
    note_length = find_user_notes(fd,userid);
    while(note_length != -1){
    printf("allocating memmory in the heap\n");
    heap = (char*)ec_malloc(note_length +1);

    printf("moving note in the heap with address %p\n",heap);
    int reader = read(fd,heap,note_length);
    if(reader == -1)
        fatal("error while storing note in heap");
    heap[note_length]='\0';
    if(search_filter(heap,filter))
    printf("%s",heap);
    free(heap);
    note_length = find_user_notes(fd,userid);
    }
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
    int note_len = strlen(note);
    int key_len = strlen(keyword);
    int i , j;
    int all_matched=0;
    if(key_len==0) return 1;

    for(i=0;i<=note_len-key_len;i++){
        if(note[i]== keyword[0]){
            all_matched=1;
                for(j=1;j<key_len;j++){
                    if(note[i+j]!=keyword[j]){
                    all_matched=0;
                    break;}
                }

        }
    if(all_matched==1){
        return 1;}
    }
    return 0;

}


