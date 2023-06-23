#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void xInRilievo(char string[]){
    int leng = strlen(string);

    for (int i = 0; i < leng;){
        if(string[i] != 'X'){
            if(i != 0 && string[i + 1] == 'X'){
                string[i] = ' ';
                i++;
            }
            else{
                for (int j = i; j < leng; j++)
                    string[j] = string[j + 1];
                leng -= 1;
            }
        }
        else
            i++;
    }
}

int main(int argc, char const *argv[]){
    char string[50];

    printf("Inserisci la tua bellissima stringa: ");
    fgets(string, 50, stdin);
    strtok(string, "\n");

    xInRilievo(string);
    printf("La tua bellissima stringa con solo X e': %s", string);
    
    return 0;
}
