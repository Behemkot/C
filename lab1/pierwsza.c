#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n;
    int odpowiedz = 1;

    printf("Podaj liczbe naturalna\n");
    scanf("%d", &n);

    if(n == 1)
        odpowiedz = 0;
    int i = 2;
    for(i; i <= n/2; i++){
        if(n%i == 0){
            odpowiedz = 0;
        }
    }

    if(odpowiedz == 1){
        printf("Liczba %d jest pierwsza", n);
    }else{
        printf("Liczba %d nie jest pierwsza", n);
    }

}
