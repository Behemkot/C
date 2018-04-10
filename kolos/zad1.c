#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int main(){
    double x;
    int y;
    
    printf("Podaj wartość x\n");
    scanf("%lf", &x);
    
    if(x < -45 || x > 100){
        y = 1;
    }else if(x > -1 && x < 1){
        y = 2;
    }else{
        y = 0;
    }

    printf("y = %d", y);
}
