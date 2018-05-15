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



void przyporzadkuj(char **p){
    int i;
    for(i = 0; i < 3; i++){
        p[0][i] = lista_pierscieni[kolejnosc[0] - 1][i];
        p[1][i] = lista_pierscieni[kolejnosc[1] - 1][i];
        p[2][i] = lista_pierscieni[kolejnosc[2] - 1][i];
    }
}

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
        z[i] = t[i];
        for(j = 0; j < 3; j++){
            z[i] = pierscien(pierscienie[j], z[i]);
        }
        
        powrot(z[i]);
        w_przod = 0;

        for(j = 2; j >= 0; j--){
            z[i] = pierscien(pierscienie[j], z[i]);
        }

        if(pierscienie[0][0] == dalej[0]){
            obroc(pierscienie[1]);
            if(pierscienie[1][1] == dalej[1]){
                obroc(pierscienie[2]);
            }
        }
        obroc(pierscienie[0]);
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

    int i;
    pierscienie  = (char **)malloc(sizeof(char *) * 3);
    pierscienie[0] = (char *)malloc(sizeof(char) * 26 * 3);

    for(i = 0; i < 3; i++)
        pierscienie[i] = (*pierscienie + 26 * i);

    przyporzadkuj(pierscienie);
    // jezeli szyfrujemy
    szyfruj(tekst, zaszyfrowany_tekst);

    // jeżeli deszyfrujemy
    // deszyfruj();

    // wyświetlamy / zapisujemy do pliku
    fputs(zaszyfrowany_tekst, stdout);

    free(zaszyfrowany_tekst);
}
