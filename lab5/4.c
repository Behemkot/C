#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int silnia(int n){
    if(n == 0) return 1;
    if(n == 1) return 1;
    return n*silnia(n-1);
}

int main(){
    int n = 10;
    printf("%d", silnia(n));
}
