/*Una funzione nienteDoppieMaiuscole riceve come parametro una stringa e la modifica
eliminando tutte le ripetizioni consecutive di caratteri alfabetici maiuscoli. Ad esempio, se la stringa
ricevuta come parametro è " RccFFF666RFfhJJ", la stringa verrà modificata in " RccF666RFfhJ"*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void nienteDoppieMaiuscole(char string[]){
    int leng = strlen(string), count = 0;
    for (int i = 1; i < leng;){
        if((string[i - 1] == string[i]) && (string[i] >= 'A' && string[i] <= 'Z')){
            count++;
            if(count >= 2){
                for(int j = i - 1; j < leng; j++)
                    string[j] = string[j + 1];
                leng -= 1;
            }
        }
        else{
            count = 0;
            i++;
        }
    }    
}

void testNienteDoppieMaiuscole(){
    char string[] = "AAAAAA";
    nienteDoppieMaiuscole(string);
    printf("Test nienteDoppieMaiuscole (\"AAAAAA\"): Atteso = \"A\", Calcolato = \"%s\" \n", string);

    char string1[] = "RccFFF666RFfhJJ";
    nienteDoppieMaiuscole(string1);
    printf("Test nienteDoppieMaiuscole (\"RccFFF666RFfhJJ\"): Atteso = \"RccF666RFfhJ\", Calcolato = \"%s\" \n", string1);
}

int main(int argc, char const *argv[]){
    char string[50];

    printf("Inserisci la tua bellissima stringa: ");
    fgets(string, 50, stdin);
    strtok(string, "\n");

    nienteDoppieMaiuscole(string);
    printf("La tua stringa non doppiata e': %s\n", string);
    
    testNienteDoppieMaiuscole();
    return 0;
}
