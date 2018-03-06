#include <stdio.h>

int main(){
   
    int n;
    int silnia = 1;
    
    printf("Podaj liczbe naturalna\n");
    scanf("%d", &n);

    int i;
    for(i = 1; i <= n; i++){
        silnia *= i;
    }

    printf("n! = %d", silnia);
}
