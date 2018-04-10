#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double losowa(double min, double max) {
    double zakres = max - min;
    double dzielnik = RAND_MAX / zakres;
    return min + (rand() / dzielnik);
}

int main(){
    srand(time(NULL));
    
    double p1; //minimum
    double p2; //maximum
    double srednia = 0;
    int licznik = 0;    //zlicza wartości większe od 30% sredniej
    int dodatnie = 0;
    int i;

    double wektor[100];
    
    printf("Podaj zakres liczb pseudolosowych\np1 = ");
    scanf("%lf", &p1);
    printf("\np2 = ");
    scanf("%lf", &p2);

    for(i = 0; i < 100; i++){
        wektor[i] = losowa(p1, p2);
        srednia += wektor[i];
    }
    
    srednia /= 100.0;

    for(i = 0; i < 100; i++){
        if(wektor[i] > 0){
            dodatnie++;
        }
        if(wektor[i] > 0.3*srednia){
            licznik++;
        }
    }

    printf("srednia = %f\n", srednia);
    printf("dodatnie = %d\n", dodatnie);
    printf("wieksze niż 30 sredniej = %d", licznik);
}
