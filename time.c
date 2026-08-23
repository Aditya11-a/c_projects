#include <stdio.h>
#include <time.h>


int main(){
    struct tm current_time , *time_ptr;
    int hour, day, minute ,seconds , month ,year; 
    
    
    long int seconds_from_epoch = time(0);
    printf("%d\n",seconds_from_epoch);
    time_ptr = &current_time;
    localtime_r(&seconds_from_epoch,time_ptr);

    hour = current_time.tm_hour;
    minute = time_ptr -> tm_min;
    seconds = *((int*)time_ptr);

    printf("%02d:%02d:%02d",hour,minute,seconds);
    return 0;
} 