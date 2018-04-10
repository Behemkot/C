#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int NWD(int a, int b){
    // dzięki temu a zawsze będzie >= b
    if(a < b){
        int swap;
        swap = a;
        a = b;
        b = swap;
    }
    
    // Algorytm Euklidesa
    int c;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main(){
    srand(time(NULL));
    
    int wek1[5];
    int wek2[5];

    printf("Podaj 5 par\n");
    int i;
    for(i = 0; i < 5; i++){
        printf("podaj %d pare\n", i+1);
        scanf("%d", &wek1[i]);
        scanf("%d", &wek2[i]);
    }

    int nwd;
    for(i = 0; i < 5; i++){
        nwd = NWD(wek1[i], wek2[i]);
        printf("NWD %d pary = %d\n", i+1, nwd);
    }
}
