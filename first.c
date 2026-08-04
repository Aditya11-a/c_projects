#include <stdio.h>
#include <stdlib.h>

void function(){
    int varr = 5;
    static int static_var=5;
    printf("in function var is %d and static_var is %d\n",varr,static_var);
    varr++;
    static_var++;
}
int main(){
static int static_var = 1234;
int i;
for(i=0;i<5;i++){
    printf("in main static_var is %d\n",static_var);
    function();
}
return 0;
}