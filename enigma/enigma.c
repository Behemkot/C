#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *polaczenia = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
char *lacznica = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char *dalej = "FRP";

int w_przod = 1;

const char *lista_pierscieni[] = {  "EKMFLGDQVZNTOWYHXUSPAIBRCJ", 
                                    "AJDKSIRUXBLHWTMCQGZNPYFVOE",
                                    "BDFHJLCPRTXVZNYEIWGAKMUSQO",
                                    NULL};

char **pierscienie;

int kolejnosc[3] = { 2, 1, 3 };


void obroc(char *p){
    int i;
    char swap = p[0];
    for(i = 0; i < 26 - 1; i++){
        p[i] = p[i + 1];
    }
    p[25] = swap;
}

char pierscien(char *p, char l){
    int pozycja = 0;
    if(w_przod == 1){
        pozycja = (int)(l - 'A'); 
        l = p[pozycja];
        return l;
    }
    else{
        char *poz = strchr(p, l);
        pozycja = (int)(poz - p);
        l = lacznica[pozycja];
        return l;
    }
} 

char powrot(char l){
    int pozycja = (int)(l - 'A');
    l = polaczenia[pozycja];
    return l;
}

void szyfruj(const char *t, char *z){
    int rozmiar = strlen(t);
    int i,j;
    for(i = 0; i < rozmiar; i++){

        if(pierscienie[0][0] == dalej[0]){
            obroc(pierscienie[1]);
            if(pierscienie[1][1] == dalej[1]){
                obroc(pierscienie[2]);
            }
        }
        obroc(pierscienie[0]);

        z[i] = t[i];

        for(j = 0; j < 3; j++){
            z[i] = pierscien(pierscienie[j], z[i]);
        }
        
        z[i] = powrot(z[i]);
        w_przod = 0;

        for(j = 2; j >= 0; j--){
            z[i] = pierscien(pierscienie[j], z[i]);
        }

    }
    w_przod = 1;
}

void deszyfruj(char t[]){

}




int main(){
    // czy szyrujemy czy deszyfrujemy

    // wczytujemy tekst
        // usun puste znaki (entery spacje)
        // zmien litery na duże
    const char *tekst = "JEBACXSTUDIA";
    char *zaszyfrowany_tekst = malloc(strlen(tekst) + 1); 
    // początkowe ustawienie pierscieni


    pierscienie  = malloc(sizeof(char *) * 3);
    pierscienie[0] = malloc((26 + 1) * 3);

    for (int i = 1; i < 3; i++) {
        pierscienie[i] = (*pierscienie + (26 + 1) * i);
    }

    for (int i = 0; i < 3; i++) {
        strcpy(pierscienie[i], lista_pierscieni[kolejnosc[i] - 1]);
    }


    // jezeli szyfrujemy
    szyfruj(tekst, zaszyfrowany_tekst);

    // jeżeli deszyfrujemy
    // deszyfruj();

    // wyświetlamy / zapisujemy do pliku
    fputs(zaszyfrowany_tekst, stdout);

    free(zaszyfrowany_tekst);
    free(pierscienie[0]);
    free(pierscienie);
}
