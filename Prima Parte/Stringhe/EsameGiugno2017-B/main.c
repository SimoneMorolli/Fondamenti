/*Una funzione asteriscoNonAlfabetico riceve come parametro una stringa e la modifica
trasformando ciascun carattere non alfabetico (ovvero ciascun carattere che non è una lettera
minuscola o maiuscola dell’alfabeto inglese) in un asterisco '*'. Ad esempio, se la stringa ricevuta
come parametro è "28 giugno: L’esame è in aula Campus!", la stringa verrà modificata in
"***giugno**L*esame***in*aula*Campus*"*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void asteriscoNonAlfabetico(char string[]){
    for (int i = 0; i < strlen(string); i++){
        if(!((string[i] >= 'A' && string[i] <= 'Z') || (string[i] >= 'a' && string[i] <= 'z')))
            string[i] = '*';
    }
}

void testAsterscoNonAlfabetico(){
    char string[] = "aHJbh;";
    asteriscoNonAlfabetico(string);
    printf("Test asteriscoNonAlfabetico('aHJbh;'): Atteso = 'aHJbh*' , Calcolato = '%s' \n", string);

    char string1[] = "28 giugno: L’esame è in aula Campus!";
    asteriscoNonAlfabetico(string1);
    printf("Test asteriscoNonAlfabetico('28 giugno: L'esame e' in aula Campus!'): Atteso = '***giugno**L*esame***in*aula*Campus*' , Calcolato = '%s' \n", string1);
}

int main(int argc, char const *argv[])
{
    char string[50];

    printf("Inserisci la tua bellissima stringa: ");
    fgets(string, 50, stdin);
    strtok(string, "\n");

    asteriscoNonAlfabetico(string);
    printf("La tua bellissima stringa maiuscolata e': %s\n", string);

    testAsterscoNonAlfabetico();
    return 0;
}