#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
    
    int cyfra;

    printf("Podaj cyfre od 0 do 9\n");
    scanf("%d", &cyfra);

    switch(cyfra){
        case 0:
            printf("ZERO");
            break;
        case 1:
            printf("JEDEN");
            break;
        case 2:
            printf("DWA");
            break;
        case 3:
            printf("TRZY");
            break;
        case 4:
            printf("CZTERY");
            break;
        case 5:
            printf("PIĘĆ");
            break;
        case 6:
            printf("SZEŚĆ");
            break;
        case 7:
            printf("SIEDEM");
            break;
        case 8:
            printf("OSIEM");
            break;
        case 9:
            printf("DZIEWIEC");
    }
}
