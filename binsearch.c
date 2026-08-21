#include <stdio.h>

int binsearch(int, int[] ,int );
int main(){
    int a[] = {1,2,3,4,5,6,7,8,9};
    if(binsearch(9,a,9))
        printf("no. is inside the array");
    else
        printf("not inside");
    return 0;
}
int binsearch(int x,int v[],int n){
    int high , mid , low ;
    low = 0;
    high = n-1;
    while(low <= high){
        mid = (low + high)>>1;
        if(x < v[mid])
            high = mid -1;
        else if(x>v[mid])
            low = mid +1;
        else
            return 1;
    }
return 0;
}

