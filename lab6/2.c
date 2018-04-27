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

/* funkcja wypełniająca tablice t o podanym rozmiarze 
 * liczbami całkowitymi z przedziału <MIN; MAX>
 * void fill - void ponieważ funkcja nie zwraca żadnej wartości tylko modyfikuje obiekt 
 * np funkcja zamieniająca wartości 2 liczb też nie zwraca żadnej wartości 
 *
 * void zamien(int a, int b){
 *      int swap = a;
 *      a = b;
 *      b = swap;
 * }
 */
void fill(char *t, int rozmiar, int MIN, int MAX){
    int i;
    for(i = 0; i < 2 * rozmiar; i +=2 ){
        t[i] = (char)(losowa(MIN, MAX) + 48);
        t[i + 1] = "\n";
    }
}

int main(){
    srand(time(NULL));

    int N = 100;
    char tab[N*2];    //char ponieważ do pliku zapiszemy znaki, nie liczby
    
    fill(tab, N, 1, 5);

    FILE *plik;
    plik = fopen("2.txt", "w");

    fprintf(plik, "%s", tab);
    fclose(plik);
}
