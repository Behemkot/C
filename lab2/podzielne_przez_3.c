#include <stdio.h>

int main() {

    int n;
    printf("Podaj ilosc liczb do wyswietlenia:\n");
    scanf("%d", &n);

    int i;
    for(i = 1; i <= n; i++){
        printf("%d\t", 3 * i);
    }
}
