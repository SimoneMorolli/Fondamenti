/*Una funzione cancellaDueNumericiUguali riceve come parametro una stringa e la modifica
rimuovendo ogni sequenza di esattamente due caratteri numerici uguali consecutivi. Ad esempio, se
la stringa ricevuta come parametro è "22cde555ee12a13367bb5", la stringa deve essere modificata in
"cde555ee12a167bb5".*/
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

void cancellaDueNumericiUguali(char string[]){
    int leng = strlen(string) - 1;

    for (int i = 0; i < leng;){
        if((string[i] >= '0' && string[i] <= '9') && (string[i] == string[i + 1])){
                if(string[i] == string[i + 2]){
                    while(string[i] == string[i + 1]){
                        i++;
                    }
                }
                else{
                    shiftLeft(string, i);
                    leng -= 2;
                }
        }
        else
            i++;
    }
    
}

void testCancellaDueNumericiUguali(){
    char string[] = "";
    cancellaDueNumericiUguali(string);
    printf("Test cancellaDueNumericiUguali(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", string);

    char string1[] = "22cde55555ee12a13367bb5";
    cancellaDueNumericiUguali(string1);
    printf("Test cancellaDueNumericiUguali(\"22cde55555ee12a13367bb5\"): Atteso = \"cde55555ee12a167bb5\", Calcolato = \"%s\" \n", string1);
}

int main(int argc, char const *argv[]){
    char string[50];

    printf("inserisci la tua bellissima stringa: ");
    fgets(string, 50, stdin);
    strtok(string, "\n");

    cancellaDueNumericiUguali(string);
    printf("La tua stringa senza due caratteri di fila alfabetici e': \"%s\"\n", string);

    testCancellaDueNumericiUguali();

    return 0;
}
