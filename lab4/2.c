#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double losowa(double min, double max) {
    double zakres = max - min;
    double dzielnik = RAND_MAX / zakres;
    double wynik;
    return min + (rand() / dzielnik);
}

int main(){
    srand(time(NULL));

    int n = 7;      //rozmiar macierzy kwadratowej
    double m[n][n]; //macierz n na n
    int i, j;       //iteratory 

    //współrzędne minimum
    int i_min = 0;  // wiersz = 0
    int j_min = 1;  // kolumna = 1. [0][0] znajdowałoby się na przekątnej, dlatego 1

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            m[i][j] = losowa(0, 1);             //wypełnianie wartości
            if(j > i)                           //jeżeli wypełniamy komórke ponad przekontną
                if(m[i][j] < m[i_min][j_min]){  //to sprawdź czy wpisywana wartość < min
                    i_min = i;                  //jeżeli tak to zdefiniuj nowe położenie min
                    j_min = j;
                }
        }
    }
    //wyświetlanie 
    printf("Pozycja minimum\n");
    printf("[%d][%d]", i_min + 1, j_min + 1);
}
