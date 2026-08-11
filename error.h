void fatal(char *message){
    char error_message[100];

    strcpy(error_message,"[!!] FATAL ERROR ");
    strncat(error_message,message,83);
    perror(error_message);
    exit(EXIT_FAILURE);
}

void *ec_malloc(unsigned int size){
    void *ptr;
    ptr = malloc(size);
    if (ptr == NULL)
    fatal("error while allocating memmory in ec_malloc");
    return ptr;
}