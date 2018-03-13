#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int losowa(int min, int max) {
    int zakres = max - min;
    int dzielnik = RAND_MAX / zakres;
    return min + (rand() / dzielnik);
}
 
int main(){

    int n;
    printf("Podaj ilosc liczb do wylosowania: ");
    scanf("%d", &n);
    
    int i;
    for(i = 1; i <= n/2; i++) {
        printf("%d\n", losowa(1,5));
    }
    
    int suma;
    double srednia;
    int j;
    for(i; i <= n; i++) {
        if(i%2 == 0){
            suma = 0;
            for(j = 0; j < 3; j++){
                suma += losowa(i,i+5);
            }
            printf("%d\n", suma);
        }
        else {
            srednia = 0;
            for(j = 0; j < 5; j++) {
                srednia += losowa(-5,5);
            }
            srednia /= 5.0;
            printf("%d\n", srednia);
        }
    }
}
