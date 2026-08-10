#include <stdio.h>
#include <fcntl.h> 
#include <unistd.h>
#include <stdint.h>
void display_flags(char*,uint64_t );
void binary_prints(uint64_t );

int main(){
    display_flags("O_RDONLY",O_RDONLY);
    display_flags("O_WRONLY",O_WRONLY);
    display_flags("o_RDWR",O_RDWR);
    printf("\n");
    display_flags("O_APPEND",O_APPEND);
    display_flags("O_CREAT",O_CREAT);
return 0;
}

void display_flags(char* label,uint64_t value){
    printf("%s\t:%llu\t",label,value);
    binary_prints(value);
    printf("\n");
}

void binary_prints(uint64_t value){
   uint64_t mask = 0xFF00000000000000ULL;
   uint64_t shift = 56;
   uint64_t byte, byte_iterator, bit_iterator;
   for(byte_iterator=0; byte_iterator<8;byte_iterator++){
        byte = (value & mask)>>shift;
        printf(" ");
        for(bit_iterator=0;bit_iterator<8;bit_iterator++){
            if (byte & 0x80){
            printf("1");}
            else{
                printf("0");
            }
            byte <<= 1;
            } 
            mask >>= 8 ;
            shift -= 8;
        }
    }
