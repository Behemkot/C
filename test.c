#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char lacznica[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
char dalej[] = {"FRP"};

char pierscienie[3][26] = { "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
                            "AJDKSIRUXBLHWTMCQGZNPYFVOE",
                            "BDFHJLCPRTXVZNYEIWGAKMUSQO"};

int kolejnosc[3] = { 2, 1, 3 };

char p1[] = {"AJDKSIRUXBLHWTMCQGZNPYFVOE"};
char p2[] = {"EKMFLGDQVZNTOWYHXUSPAIBRCJ"};
char p3[] = {"BDFHJLCPRTXVZNYEIWGAKMUSQO"};

void obroc(char p[]){
    int i;
    char swap = p[0];
    for(i = 0; i < 26 - 1; i++){
        p[i] = p[i + 1];
    }
    p[25] = swap;
}

char pierscien1(char l){
    int pozycja = (int)(l - 'A'); 

    ///////////////////////////////////////////
    char z = l;                         ///////
    char y = p1[pozycja];               ///////
    printf("p1:\t%c ---> %c\n", z, y);  ///////
    ///////////////////////////////////////////

    l = p1[pozycja];
    
    return l;
} 


char pierscien2(char l){
    int pozycja = (int)(l - 'A'); 

    ///////////////////////////////////////////
    char z = l;                         ///////
    char y = p2[pozycja];               ///////
    printf("p2:\t%c ---> %c\n", z, y);  ///////
    ///////////////////////////////////////////
    
    l = p2[pozycja];
    return l;
}

char pierscien3(char l){
    int pozycja = (int)(l - 'A'); 

    ///////////////////////////////////////////
    char z = l;                         ///////
    char y = p2[pozycja];               ///////
    printf("p3:\t%c ---> %c\n", z, y);  ///////
    ///////////////////////////////////////////
    
    l = p3[pozycja];
    return l;
}



void szyfruj(char t[], int rozmiar){
    int i;

    for(i = 0; i < rozmiar; i++){
        t[i] = pierscien3(pierscien2(pierscien1(t[i])));

        if(p1[0] == dalej[0]){
            printf("Obrot p2 bo p1 na %c\n", p1[0]);       ///////
            obroc(p2);
            if(p2[1] == dalej[1]){
                printf("Obrot p3 bo p2 na %c\n", p2[0]);   ///////
                obroc(p3);
            }
        }
        printf("Obrot p1 bo zaszyfrowalismy litere\n");    ///////
        obroc(p1);
    }
}

int main(){
    // czy szyrujemy czy deszyfrujemy

    // wczytujemy tekst
        // usun puste znaki (entery spacje)
        // zmien litery na duże
    char tekst[] = {"JEBACXSTUDIA"};
    
    // początkowe ustawienie pierscieni

    // jezeli szyfrujemy
    szyfruj(tekst, 12);

    // jeżeli deszyfrujemy
    // deszyfruj();

    // wyświetlamy / zapisujemy do pliku

    fputs(tekst, stdout);
}
