/*
 * ni chuja nie wiem dlaczego to nie działa...
 * zwraca zawsze 0.000000
 * jak ktoś znajdzie błąd to dajcie znać 
 *
 */

#include <stdio.h>

int main(){
    
    int waluta;
    double pln;
    double kwota;

    printf("Podaj walute (cyfra)\n");
    printf("1. EURO\n");
    printf("2. DOLAR\n");
    printf("3. FRANK\n");
    printf("4. FUNT\n");
    printf("5. JEN\n");

    scanf("%d", &waluta);

    printf("Podaj kwote\n");
    scanf("%f", &kwota);

    switch (waluta) {
        case 1: pln = kwota / 4.1942; break;
        case 2: pln = kwota / 3.4066; break;
        case 3: pln = kwota / 3.5865; break;
        case 4: pln = kwota / 4.7200; break;
        case 5: pln = kwota / 3.1970; break;
        default: printf("Error");
    }

    printf("%f", pln);  
}
