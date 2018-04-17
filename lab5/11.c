#include <stdio.h>
#include <stdlib.h>

int fib(int n){
    if(n == 1) return 1;
    if(n == 2) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main(){
    int n = 15;
    printf("%d", fib(n));
}
