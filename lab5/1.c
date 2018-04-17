#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*  w jezyku c nie ma funkcji zwracającej wartość True lub False
 *  dlatego warto zapamietać że if(0) jest równoznaczne z if(False)
 *  a if(1) równoznaczne z if(True)
 *
 *  funkcje które powinny zwracać "prawda" lub "fałsz" muszą zwracać 1 lub 0
 */
int pierwsza(int n){
    if(n <= 0) return 0;
    if(n == 1) return 0;
    int i;
    for(i = 2; i <= sqrt(n); i++){
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int doskonala(int n){
    int suma = 0;

    int i;
    if(n <= 1) return 0;

    for(i = 1; i <= n/2; i++){
        if(n%i == 0)
            suma += i;
    }

    if(suma == n)
        return 1;
    else
        return 0;
}

int main(){
    int n = 100;
    int i;

    for(i = 0; i < n; i++){
        printf("%d\t%d\t%d\n", i, pierwsza(i), doskonala(i));
    }
}
