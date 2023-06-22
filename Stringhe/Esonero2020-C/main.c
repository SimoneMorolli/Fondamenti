/*Una funzione nienteNumeriDueCifre riceve come parametro una stringa e la modifica
rimuovendo ogni sequenza di esattamente due caratteri numerici consecutivi. Ad esempio, se la
stringa ricevuta come parametro è "12ab123fg67xyh2iu09", la stringa deve essere modificata in
"ab123fgxyh2iu".*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void shiftLeft(char string[], int i){
    int leng = strlen(string);
    
    for (int j = i; j < leng; j++)
        string[j] = string[j + 1];
    leng = strlen(string);
    for (int j = i; j < leng; j++)
        string[j] = string[j + 1];
}

void nienteNumeriDueCifre(char string[]){
    int leng = strlen(string) - 1;

    for (int i = 0; i < leng; i++){
        if((string[i] >= '0' && string[i] <= '9') && (string[i + 1] >= '0' && string[i + 1] <= '9')){
            if(string[i + 2] >= '0' && string[i + 2] <= '9')
                while(string[i] >= '0' && string[i] <= '9')
                    i++;
            else{
                shiftLeft(string, i);
                leng -= 2;
            }
        }
        else
            i++;
    }
    
}