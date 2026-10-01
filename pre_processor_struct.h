#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char word[9];
    int category;
}WORDS_GROUP;

typedef struct{
    char first_letter;
    WORDS_GROUP* first_letter_ptr;
    int word_group_size;
}FIRST_LETTERS;


typedef struct{
    int result;
    int category;
}RESULT;