#include <stdio.h>

int main(){
   
    int a, b;

    printf("Podaj 2 liczby naturalne\n");
    scanf("%d %d", &a, &b);
    
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

    printf("NWD = %d", a);
}
