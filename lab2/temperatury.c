#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*  funkcje deklarujemy przed funkcją main (po też można ale troche inaczej)
 *  funkcje w C mają forme:
 *  typ_zwracanej_wartosci nazwa_funkcji(typ_argumentu1 argument1, typ_arg2 arg2, ...){
 *      kod funkcji
 *      return zwracana_wartosc
 *  }
 */

double losowa(double min, double max) {
    double zakres = max - min;
    double dzielnik = RAND_MAX / zakres;
    return min + (rand() / dzielnik);
}
 
int main() {
   
    /*  INNY SPOSOB NA LOSOWANIE
     *  
     *  może troche trudniejszy, ale praktyczny jeśli stworzy się funkcję
     *  pod zadaniem wrzucę wam kod który możecie wkleić do dowolnego programu
     */
    double min = -273.15;
    double max = 1000.0;
    double zakres = max - min;
    double dzielnik = RAND_MAX / zakres;
    double temperatura;

    srand(time(NULL));

    int i;
    for(i = 0; i < 10; i++){
        // temperatura = losowa(min, max);
        // równoznaczne z 
        temperatura = min + (rand() / dzielnik);

        // %.Xf - float do X miejscu po przecinku
        printf("%.2f\n", temperatura);
    }
}
