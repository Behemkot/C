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

    srand(time(NULL));  //ziarno funkcji losującej

    int N = 100;        //to powinno być podawane przez użytkownika
    double v[N];        //N-elementowy wektor
    double v_max = 0;   //najwieksza wartość wektora
    double v_min = 1;   //najmniejsza wartość wektora
    double srednia = 0;
    int i;              //iterator

    /*  wypełnianie wektora los. l. rzeczywistymi <0; 1>
     *  szukanie v_min i v_max
     *  wyliczanie sredniej
     */

    for(i = 0; i < N; i++){
        v[i] = losowa(0, 1);

        if(v[i] < v_min)
            v_min = v[i];
        else if(v[i] > v_max)
            v_max = v[i];
        
        srednia += v[i];
    }
    srednia /= N;       //wyliczanie rzeczywistej wartości średniej

    int w_srd = 0;      //ilość wartosci wiekszych od średniej

    for(i = 0; i < N; i++)
        if(v[i] > srednia)
            w_srd++;

    //wyswietlanie  
    printf("ILOSC\t%d\n", N);
    printf("SREDNIA\t%f\n", srednia);
    printf("MIN\t%f\n", v_min);
    printf("MAX\t%f\n", v_max);
    printf("W. SR\t%d\n", w_srd);
}
