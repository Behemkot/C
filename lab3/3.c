/*  wszystkie kolumny zawierają ciągi arytmetyczne
 *  wartości ciągu są tworzone poprzez dodanie różnicy R do poprzedniej wartości.
 *  aby umożliwić generowanie wartości wszystkich ciągów w pojedynczym użyciu
 *  dwóch zagnieżdżonych pętli for, w wierszu 0 przechowamy R dla każdego ciągu
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int W = 50; //liczba wierszy
    int K = 5;  //liczba kolumn

    int m[W+1][K];  //macierz 51 na 5. dodajemy jeden wiersz na R
    int i,j;        //iteratory

    //Definicja R   Definicja pierwszych wyrazów ciągów
    m[0][0] = 1;    m[1][0] = 1;    // ciag 1
    m[0][1] = -1;   m[1][1] = 5;    // ciag 2
    m[0][2] = 2;    m[1][2] = 2;    // ciag 3
    m[0][3] = 2;    m[1][3] = 10;   // ciag 4
    m[0][4] = -3;   m[1][4] = 15;   // ciag 5

    for(i = 2; i < W+1; i++){
        for(j = 0; j < K; j++){
            /*  generowanie i wpisywanie wartości
             *  m[0][j]     - odpowiednie R
             *  m[i-1][j]   - wartość poprzedniego wyrazu ciągu */
            m[i][j] = m[0][j] + m[i-1][j];
        }
    }
    
    // wyświetlanie wartości wszystkich ciągów
    for(i = 1; i < W+1 ; i++){
        for(j = 0; j < K; j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}
