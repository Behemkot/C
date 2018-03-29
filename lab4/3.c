#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// funkcja losująca liczby całkowite z przedziału <min, max>
int losowa(int min, int max) {
    int zakres = max - min;
    int dzielnik = RAND_MAX / zakres;
    return min + (rand() / dzielnik);
}

// prosta funkcja sprawdzająca czy liczba jest liczbą pierwszą
int pierwsza(int n){
    if(n == 1) return 0;
    int i;
    for(i = 2; i <= sqrt(n); i++){
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int main(){
    srand(time(NULL));

    int N = 7;      //rozmiar macierzy
    int m[N][N];    //macierze N na N
    int l_prim = 0; //ilość liczb pierwszych
    int i, j;       //iteratory
    int p;          //zmienna pomocnicza

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            m[i][j] = losowa(1, 100);
            p = pierwsza(m[i][j]);
            if(p == 1){
                printf("[%d][%d] = %d\n", i + 1, j + 1, m[i][j]);
                l_prim++;
            }
        }
    }
    printf("%d l.p. w macierzy\n", l_prim);
}
