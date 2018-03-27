#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 50;
    
    int ciag[n];

    int i = 1;
    for(i; i <= n; i++){
        if( i == 1 ){
            ciag[i] = -3;
        }
        else if( i == 2 ){
            ciag[i] = 2;
        }
        else{
            ciag[i] = 2*ciag[i-2] + 3*ciag[i-1];
        }
        printf("%d\n", ciag[i]);
    }
}
