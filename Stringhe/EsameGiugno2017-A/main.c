/*Una funzione rendiMaiuscole riceve come parametro una stringa e la modifica trasformando
tutte le lettere minuscole (non accentate) dell’alfabeto inglese nelle corrispondenti lettere maiuscole.
Ad esempio, se la stringa ricevuta come parametro è "28 giugno - Aula Campus", la stringa verrà
modificata in "28 GIUGNO - AULA CAMPUS"*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void rendiMaiuscole(char string[], int leng){
    for (int i = 0; i < leng; i++){
        if(string[i] >= 'a' && string[i] <= 'z')
            string[i] -= 32;
    }
    
}

void testRendiMaiuscole(){
    char string[] = "aBC";
    rendiMaiuscole(string, strlen(string));
    printf("Test rendiMaiuscole('aBC')): Atteso = 'ABC', Calcolato = '%s' \n", string);

    char string1[] = "28 giugno - Aula Campus";
    rendiMaiuscole(string1, strlen(string1));
    printf("Test rendiMaiuscole('28 giugno - Aula Campus')): Atteso = '28 GIUGNO - AULA CAMPUS', Calcolato = '%s' \n", string1);
}

int main(){
    char string[50];
    
    printf("Insersci la tua bellissima stringa: ");
    fgets(string, 50, stdin);
    strtok(string, "\n");

    rendiMaiuscole(string, strlen(string));
    printf("Questa e' la tua bellissima stringa maiuscolata: %s\n", string);

    testRendiMaiuscole();
}