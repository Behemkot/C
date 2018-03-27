#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ciag(int n){
    if(n == 1) return -3; 
    if(n == 2) return 2; 
    else
        return 2*ciag(n-2) + 3*ciag(n-1);
    
}

int main() {
    int N = 10;
    int i;

    for(i = 1; i <= N; i++){
        printf("ciag(%d) = %d\n", i, ciag(i));
    }
}
