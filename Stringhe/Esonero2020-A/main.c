/*Una funzione viaParoleDaDue riceve come parametro una stringa e la modifica rimuovendo
ogni sequenza di esattamente due caratteri alfabetici consecutivi. Ad esempio, se la stringa ricevuta
come parametro è "ab12cde56ee78a67bb", la stringa deve essere modificata in "12cde5678a67".*/
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

void viaParoleDaDue(char string[]){
    int leng = strlen(string) - 1;

    for (int i = 0; i < leng;){
        if((string[i] >= 'a' && string[i] <= 'z') && (string[i + 1] >= 'a' && string[i + 1] <= 'z')){
            if(string[i + 2] >= 'a' && string[i + 2] <= 'z')
                while(string[i] >= 'a' && string[i] <= 'z')
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

void testViaParoleDaDue(){
    char string[] = "";
    viaParoleDaDue(string);
    printf("Test viaParoleDaDue(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", string);

    char string1[] = "ab12cde56ee78a67bb";
    viaParoleDaDue(string1);
    printf("Test viaParoleDaDue(\"ab12cde56ee78a67bb\"): Atteso = \"12cde5678a67\", Calcolato = \"%s\" \n", string1);
}

int main(int argc, char const *argv[]){
    char string[50];

    printf("inserisci la tua bellissima stringa: ");
    fgets(string, 50, stdin);
    strtok(string, "\n");

    viaParoleDaDue(string);
    printf("La tua stringa senza due caratteri di fila alfabetici e': %s\n", string);

    testViaParoleDaDue();

    return 0;
}
