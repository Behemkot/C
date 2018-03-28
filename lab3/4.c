/*  nie wiem jak to ładniej zakodować chociaż pewnie by się dało.
 *  można użyć switch case i sprawdzać w ktorej jesteśmy kolumnie
 *  ale to co napisałem ma chyba mniejszą złożoność obliczeniową
 */
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

// fukncja losująca liczby rzeczywiste z przedziału (min; max)
double losowa2(double min, double max) {
    double zakres = max - min;
    double dzielnik = RAND_MAX / zakres;
    double wynik;
    wynik =  min + (rand() / dzielnik);
    
    // jeżeli wylosowana liczba odpowiada min lub max losuj ponownie 
    if(wynik == min || wynik == max)
        losowa2(min, max);
    // w przeciwnym razie zwróć wylosowaną liczbę 
    else
        return wynik;
}


int main() {

    srand(time(NULL));  //ziarno funkcji losującej

    int W = 50;         //liczba wierszy
    int K = 5;          //liczba kolumn
    double tab[W][K];   //macierze którą będziemy tworzyć
    double srednia[K];  //srednia watrości z każdej kolumny powyższej macierzy

    //iteratory
    int i, j;
    
    //zerowanie wartosci
    for(i = 0; i < K; i++){
        srednia[i] = 0;
    }

    // tworzenie 1 kolumny: 1, -2, 3, -4 ...
    for(i = 0; i < W; i++){
        if(i%2 == 0)
            tab[i][0] = i + 1;
        else
            tab[i][0] = (-1)*(i + 1);
        srednia[0] += tab[i][0];
    }
    
    //tworzenie 2 kolumny: całkowite liczby losowe z przedziału <-3; 3>
    for(i = 0; i < W; i++){
        tab[i][1] = losowa(-3, 3);
        srednia[1] += tab[i][1];
    }

    //tworzenie 3 kolumny: rzeczywiste liczby losowe z przedziału (-3; 3)
    for(i = 0; i < W; i++){
        tab[i][2] = losowa2(-3, 3);
        srednia[2] += tab[i][2];
    }

    //tworzenie 4 kolumny: kwadraty liczb całkowitych 
    for(i = 0; i < W; i++){
        //funkcja potegowa z biblioteki math.h
        //pow(a, b) 
        //a - podstawa
        //b - wykładnik
        tab[i][3] = pow(i + 1, 2);
        srednia[3] += tab[i][3];
    }
    //nie mam pojecia dlaczego pierwszy element to 2 ale niech bedzie
    tab[0][3] = 2;
    srednia[3]++;

    //tworzenie 5 kolumny: nr wiersza + numer kolumny
    for(i = 0; i < W; i++){
        tab[i][4] = i + 6;
        srednia[4] += tab[i][4];
    }

    //wyświetlanie tabeli
    for(i = 0; i < W; i++){
        for(j = 0; j < K; j++){
            printf("%f\t", tab[i][j]);
        }
        printf("\n");
    }
    
    //wyświetlanie średnich wartości
    printf("\n\t\t\t\tSREDNIA\n");
    for(i = 0; i < K; i++){
        srednia[i] /= W;    //wyliczanie rzeczywistej wartości sredniej
        printf("%f\t", srednia[i]);
    }
}
