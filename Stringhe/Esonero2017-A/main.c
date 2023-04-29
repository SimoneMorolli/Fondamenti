/*Una funzione soloAlfabetici riceve come parametro una stringa e la modifica eliminando tutti i
caratteri che non sono alfabetici. Ad esempio, se la stringa ricevuta come parametro è
"ah5$56knFGJ=) 12g", la stringa verrà modificata in "ahknFGJg"*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void soloAlfabetici(char string[]){
    int leng = strlen(string);

    for (int i = 0; i < leng;){
        //printf("\n%d\n", !((string[i] >= 'A' && string[i] <= 'Z') || (string[i] >= 'a' && string[i] <= 'z')));
        if(!((string[i] >= 'A' && string[i] <= 'Z') || (string[i] >= 'a' && string[i] <= 'z'))){
            for (int j = i; j < leng; j++){
                string[j] = string[j + 1];
            }
            leng -= 1;            
        }
        else
            i++;
    }
}

void testSoloAlfabetici(){
    char string[] = "0&/,.&34";
    soloAlfabetici(string);
    printf("Test soloAlfabetici(\"0&/,.&34\"): Atteso = \"\", Calcolato = \"%s\" \n", string);

    char string1[] = "ah5$56knFGJ=) 12g";
    soloAlfabetici(string1);
    printf("Test soloAlfabetici(\"ah5$56knFGJ=) 12g\"): Atteso = \"ahknFGJg\", Calcolato = \"%s\" \n", string1);
}

int main(int argc, char const *argv[]){
    char string[50];

    printf("Inserisci la tua bellissima stringa: ");
    fgets(string, 50, stdin);
    strtok(string, "\n");

    soloAlfabetici(string);
    printf("La tua bellissima stringa solo alfabatici e': %s\n", string);

    testSoloAlfabetici();
    return 0;
}