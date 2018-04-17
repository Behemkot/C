#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int silnia(int n){
    int silnia = 1;
    int i;

    for(i = 1; i <= n; i++){
        silnia *= i;
    }

    return silnia;
}

int main(){
    int n = 10;
    printf("%d", silnia(n));
}
