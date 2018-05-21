#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char polaczenia[] = {"YRUHQSLDPXNGOKMIEBFZCWVJAT"};
char lacznica[] =   {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
char dalej[] = {"FRP"};

int w_przod = 1;

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
    int pozycja;
    if(w_przod == 1){
        pozycja = (int)(l - 'A'); 

        ///////////////////////////////////////////
        char z = l;                         ///////
        char y = p1[pozycja];               ///////
        printf("p1:\t%c ---> %c\n", z, y);  ///////
        ///////////////////////////////////////////

        l = p1[pozycja];
        return l;
    }
    else{
        char *poz = strchr(p1, l);
        pozycja = (int)(poz - p1);

        ///////////////////////////////////////////
        char z = l;                         ///////
        char y = lacznica[pozycja];         ///////
        printf("p1:\t%c ---> %c\n", z, y);  ///////
        ///////////////////////////////////////////

        l = lacznica[pozycja];
        return l;

    }
} 


char pierscien2(char l){
    int pozycja;
    if(w_przod == 1){
        pozycja = (int)(l - 'A'); 

        ///////////////////////////////////////////
        char z = l;                         ///////
        char y = p2[pozycja];               ///////
        printf("p2:\t%c ---> %c\n", z, y);  ///////
        ///////////////////////////////////////////
    
        l = p2[pozycja];
        return l;
    }
    else{
        char *poz = strchr(p2, l);
        pozycja = (int)(poz - p2);

        ///////////////////////////////////////////
        char z = l;                         ///////
        char y = lacznica[pozycja];         ///////
        printf("p2:\t%c ---> %c\n", z, y);  ///////
        ///////////////////////////////////////////

        l = lacznica[pozycja];
        return l;

    }
}

char pierscien3(char l){
    int pozycja;

    if(w_przod == 1){
        pozycja = (int)(l - 'A'); 

        ///////////////////////////////////////////
        char z = l;                         ///////
        char y = p3[pozycja];               ///////
        printf("p3:\t%c ---> %c\n", z, y);  ///////
        ///////////////////////////////////////////
    
        l = p3[pozycja];
        return l;
    }
    else{
        char *poz = strchr(p3, l);
        pozycja = (int)(poz - p3);
        
        ///////////////////////////////////////////
        char z = l;                         ///////
        char y = lacznica[pozycja];         ///////
        printf("p3:\t%c ---> %c\n", z, y);  ///////
        ///////////////////////////////////////////

        l = lacznica[pozycja];
        return l;
    }
}

char powrot(char l){
    int pozycja = (int)(l - 'A');

    char z = l;
    char y = polaczenia[pozycja];
    printf("powrot:\t%c ---> %c\n", z, y);

    l = polaczenia[pozycja];
    return l;
}



void szyfruj(char t[], int rozmiar){
    int i;

    for(i = 0; i < rozmiar; i++){

        ///////////////////////////////////////////////////////////
        printf("\n");
        fputs(lacznica, stdout);
        printf("\n");
        fputs(p1, stdout);
        printf("\n");
        fputs(p2, stdout);
        printf("\n");
        fputs(p3, stdout);
        printf("\n");
        //////////////////////////////////////////////////////////

        t[i] = pierscien3(pierscien2(pierscien1(t[i])));
        
        w_przod = 0;
        t[i] = powrot(t[i]);

        t[i] = pierscien1(pierscien2(pierscien3(t[i])));


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

        w_przod = 1;
    }
}

int main(){
    // czy szyrujemy czy deszyfrujemy

    // wczytujemy tekst
        // usun puste znaki (entery spacje)


    char tekst[] = {"A"};
    // początkowe ustawienie pierscieni
    


    // jezeli szyfrujemy
    szyfruj(tekst, strlen(tekst));

    // jeżeli deszyfrujemy
    // deszyfruj();

    // wyświetlamy / zapisujemy do pliku

    fputs(tekst, stdout);
}
