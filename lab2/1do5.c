#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int n;
    int suma = 0;
    int liczba;
    double srednia;

    /*  inicjowanie generatora pseudolosowego
     *
     *  void srand(unsigned int seed)
     *  seed - punkt startowy generatora pseudolosowego
     *
     *  jezeli nie wywolamy funkcji srand to rand() bedzie generowal takie same liczby
     *  tak samo w przypadku seed == 1
     */
    srand(time(NULL));

    printf("Podaj ilosc liczb do wylosowania: ");
    scanf("%d", &n);
    
    int i;
    for(i = 0; i < n; i++){
        // a + rand() % b - losowanie z przedziału <a;b>
        liczba = 1 + rand() % 5;
        printf("%d\t", liczba);

        suma += liczba;
    }
    
    /* (double)suma - zmiana typu na double zeby wynik wyszedl z przecinkiem 
     * a nie jako liczba calkowita
     */
    srednia = (double)suma / n;
    printf("\n%f", srednia);
}
