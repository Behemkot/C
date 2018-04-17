#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int NWD(int a, int b){
    // dzięki temu a zawsze będzie >= b
    if(a < b){
        int swap;
        swap = a;
        a = b;
        b = swap;
    }
    
    // Algorytm Euklidesa
    int c;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    int a = 100;
    int b = 4412;

    printf("NWD(%d,%d) = %d", a, b, NWD(a,b));
}
