#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// funkcja losująca liczby całkowite z przedziału <min, max>
int losowa(int min, int max) {
    int zakres = max - min + 1;
    int dzielnik = RAND_MAX / zakres;
    return min + (rand() / dzielnik);
}

void fill(int t[], int rozmiar, int MIN, int MAX){
    int i;
    for(i = 0; i < rozmiar; i++){
        t[i] = losowa(MIN, MAX);
    }
}

int max(int t[], int rozmiar){
    int i;
    int max = t[0];
    for(i = 1; i < rozmiar; i++){
        if(max < t[i])
            max = t[i];
    }
    return max;
}

int main(){
    srand(time(NULL));

    int n = 100;
    int tab[n];
    
    fill(tab, n, 1, 10);
    printf("MAX = %d", max(tab, n));
}
