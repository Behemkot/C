#include <stdio.h>

int main(){

    int n;
    int suma = 0;

    printf("podaj liczbe naturalna\n");
    scanf("%d", &n);

    int i;
    for(i = 1; i <= n/2; i++){
        if(n%i == 0)
            suma += i;
    }

    if(suma == n)
        printf("%d jest liczba doskonala", n);
    else
        printf("%d nie jest liczba doskonala", n);

}
