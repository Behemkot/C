#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(){

    FILE *file;
    char c;
    char t[100];

    file = fopen("text.txt", "r");

    if(file == NULL){
        perror("Error: ");
        exit(-10);
    }
    else{
        printf("Plik istnieje\n");
    }

    int i = 0;
    while(!feof(file)){
        c = (char)fgetc(file);

        if(isspace(c)){
            c = 'X';
        }
        else{
            toupper(c);
        }
        t[i] = c;
        i++;
    }
    t[i++] = '\0';

    for(i = 0; i < 100; i++){
        if(t[i] == '\0')
            break;
        printf("%c\n", t[i]);
    }



    fclose(file);
    return 0;
}
