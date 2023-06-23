/*Una funzione eliminaNonNumerici riceve come parametro una stringa e la modifica eliminando
tutti i caratteri che non sono numerici. Ad esempio, se la stringa ricevuta come parametro è
"ah5$56knFGJ=) 12g", la stringa verrà modificata in "55612".*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void eliminaNonNumerici(char string[], int leng){
    int i = 0;
    while(i < leng){
        if(string[i] < '0' || string[i] > '9'){
            for (int j = i; j < leng; j++){
                string[j] = string[j + 1];
            }
            leng -= 1;
        }
        else
            i++;
    }
}

void testEliminaNonNumerici(){
    char string[] = "ashgdj,;.)(mfndkf";
    eliminaNonNumerici(string, strlen(string));
    printf("Test eliminaNonNumerici('ashgdj,;.)(mfndkf'): Atteso = '', Calcolato = '%s' \n", string);

    char string1[] = "ah5$56knFGJ=) 12g";
    eliminaNonNumerici(string1, strlen(string1));
    printf("Test eliminaNonNumerici('ah5$56knFGJ=) 12g'): Atteso = '55612', Calcolato = '%s' \n", string1);
}

int main(){
    char string[50];
    
    printf("inserisci la tua bellissima stringa: ");
    fgets(string, 50, stdin);
    string[strlen(string) - 1] = '\0';

    eliminaNonNumerici(string, strlen(string));

    printf("la stringa con soli numeri e': '%s'\n", string);

    testEliminaNonNumerici();
}