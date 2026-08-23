#include <stdio.h>
#include <time.h>

void dump_struct_tm_bytes(struct tm*,int );
int main(){
    struct tm current_time , *time_ptr;
    int hour, day, minute ,seconds , month ,year; 
    
    
    long int seconds_from_epoch = time(0);
    printf("%d\n",seconds_from_epoch);
    time_ptr = &current_time;
    localtime_r(&seconds_from_epoch,time_ptr);
    dump_struct_tm_bytes(time_ptr,sizeof(struct tm));
    hour = current_time.tm_hour;
    minute = time_ptr -> tm_min;
    seconds = *((int*)time_ptr);

    printf("%02d:%02d:%02d",hour,minute,seconds);
    
    
    return 0;
} 


void dump_struct_tm_bytes(struct tm *time_ptr, int size){
    int i;
    unsigned char* raw_ptr = (unsigned char*)time_ptr;
    printf("struct tm bytes is located at %p\n",raw_ptr);
    for (i=0 ; i<size ; i++){
        printf("%02x ",raw_ptr[i]);
        if(i%16 == 15)
            printf("\n");
        }
    printf("\n");
}