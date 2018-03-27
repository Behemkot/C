#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int W = 50; //liczba wierszy
    int K = 5;  //liczba kolumn

    int m[W+1][K];
    int i,j;

    m[0][0] = 1;    m[1][0] = 1; 
    m[0][1] = -1;   m[1][1] = 5;
    m[0][2] = 2;    m[1][2] = 2;
    m[0][3] = 2;    m[1][3] = 10;
    m[0][4] = -3;   m[1][4] = 15;

    for(i = 2; i < W+1; i++){
        for(j = 0; j < K; j++){
            m[i][j] = m[0][j] + m[i-1][j];
        }
    }

    for(i = 1; i < W+1 ; i++){
        for(j = 0; j < K; j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}
