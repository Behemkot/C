/*  sposób z generowaniem wartości rekurencyjnie przy użyciu wektora
 *  jest o wiele lepszy niż zwykła rekurencja kiedy chcemy przechowywać
 *  lub wyświetlić wszystkie wygenerowane wartości zamiast tylko jednej
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n = 50;     //ilość elementów ciągu które będziemy generować 
    int ciag[n];    //definicja ciągu jako wektora liczb całkowitych
    int i = 1;      //iterator

    //generowanie n wartości ciągu i wpisywanie ich do wektora
    for(i; i <= n; i++){
        if( i == 1 )
            ciag[i] = -3;   //definicja pierwszego elementu
        else if( i == 2 )
            ciag[i] = 2;    //definicja drugiego elementu
        else                //ogólny wzór rekurencyjny poniżej
            ciag[i] = 2*ciag[i-2] + 3*ciag[i-1];
        printf("%d\n", ciag[i]);    //wypisywanie wartości
    }
}
