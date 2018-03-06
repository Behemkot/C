#include <stdio.h>
#include <math.h>

int main(){
    
    int a, b, c;
    double x1, x2, delta;
    
    printf("Podaj wspolczynniki a, b i c\n");
    scanf("%d %d %d", &a, &b, &c);
    
    // (double)(A) - tzw. "rzutowanie" zmiana typu zmiennej/wyrazenia A na typ 
    //               określony w poprzedzajacym ja nawiasie
    delta = (double)(b*b - 4*a*c);

    if(delta < 0){
        printf("Brak pierwiastkow rzeczywistych");
    }
    else if(delta == 0){
        // mnożymy prze 2.0 aby uzyskać wynik z resztą. 
        // sam operator / zwróciłby wynik bez reszty 
        x1 = -b/(a*2.0);
        printf("Jedno miejsce zerowe: x0 = %f", x1);
    }
    else{
        delta = sqrt(delta);
        x1 = (-b - delta)/(a*2.0);
        x2 = (-b + delta)/(a*2.0);
        printf("Dwa miejsca zerowe: x1 = %f x2 = %f", x1, x2);
    }

    return 0;
}
