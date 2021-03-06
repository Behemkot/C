#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *polaczenia = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
char *lacznica = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char *dalej = "FRP";

int w_przod = 1;

const char *lista_pierscieni[] = {  "EKMFLGDQVZNTOWYHXUSPAIBRCJ", 
                                    "AJDKSIRUXBLHWTMCQGZNPYFVOE",
                                    "BDFHJLCPRTXVZNYEIWGAKMUSQO",
                                    NULL};

char **pierscienie;

int kolejnosc[3] = { 1, 3, 2 };


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

void resetuj_pierscienie(){
    for (int i = 0; i < 3; i++) {
        strcpy(pierscienie[i], lista_pierscieni[kolejnosc[i] - 1]);
    }
}

void szyfruj(const char *t, char *z){
    int rozmiar = strlen(t);
    int i,j;
    for(i = 0; i < rozmiar; i++){
        obroc(pierscienie[0]);
        if(pierscienie[0][0] == dalej[0]){
            obroc(pierscienie[1]);
            if(pierscienie[1][1] == dalej[1]){
                obroc(pierscienie[2]);
            }
        }

        z[i] = t[i];

        for(j = 0; j < 3; j++){
            z[i] = pierscien(pierscienie[j], z[i]);
        }
        
        z[i] = powrot(z[i]);
        w_przod = 0;

        for(j = 2; j >= 0; j--){
            z[i] = pierscien(pierscienie[j], z[i]);
        }
        w_przod = 1;
    }
}

void deszyfruj(const char *t, char *z){
    resetuj_pierscienie();
    szyfruj(t, z);
}




int main(){

    FILE *file = fopen("text.txt", "r");
    FILE *zaszyfrowany = fopen("zaszyfrowany_tekst.txt", "wa");
    FILE *odszyfrowany = fopen("odszyfrowany_tekst.txt", "wa");

    char c;
    int i = 0;
    int dlugosc = 100;
    char t[dlugosc];
    
    pierscienie  = malloc(sizeof(char *) * 3);
    pierscienie[0] = malloc((26 + 1) * 3);

    for (int i = 1; i < 3; i++) {
        pierscienie[i] = (*pierscienie + (26 + 1) * i);
    }

    resetuj_pierscienie();

    char wybor;
    printf("szyfrowanie, czy deszyfrowanie? s/d\n");
    scanf("%c", &wybor);

    if(wybor == 's'){

        if(file == NULL){
            perror("Error: ");
            exit(-10);
        }

        int i = 0;
        while(!feof(file)){
            c = (char)fgetc(file);

            if(isspace(c)){
                c = 'X';
            }
            else{
                c = toupper(c);
            }
            t[i] = c;
            i++;
        }
        t[i-2] = '\0';

        for(i = 0; i < dlugosc; i++){
            if(t[i] == '\0')
                break;
            printf("%c", t[i]);
        }
        printf("\n");

        fclose(file);

        char *zaszyfrowany_tekst = malloc(strlen(t) + 1); 

        szyfruj(t, zaszyfrowany_tekst);
        fputs(zaszyfrowany_tekst, zaszyfrowany);

        free(zaszyfrowany_tekst);

    }
    else if(wybor == 'd'){
        if(file == NULL){
            perror("Error: ");
            exit(-10);
        }

        int i = 0;
        while(!feof(file)){
            c = (char)fgetc(file);
            if(isspace(c)){
                c = 'X';
            }
            t[i] = c;
            i++;
        }
        t[i-2] = '\0';

        for(i = 0; i < dlugosc; i++){
            if(t[i] == '\0')
                break;
            printf("%c", t[i]);
        }
        printf("\n");

        fclose(file);

        char *odszyfrowany_tekst = malloc(strlen(t) + 1);
    
        deszyfruj(t, odszyfrowany_tekst);
        odszyfrowany_tekst[strlen(odszyfrowany_tekst) - 1] = '\0';
        fputs(odszyfrowany_tekst, odszyfrowany);
    }
    else{
        perror("Error: Nieodpowiednie polecenie.");
        exit(0);
    }

    free(pierscienie[0]);
    free(pierscienie);
}
