/*Una funzione alPiuDueConsecutivi riceve come parametro una stringa e la modifica così che
ogni sequenza di almeno due caratteri consecutivi uguali venga trasformata in una sequenza di
esattamente due caratteri consecutivi uguali. Ad esempio, se la stringa ricevuta come parametro è
"abbbbacccddaaaa", la stringa deve essere modificata in "abbaccddaa"*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void alPiuDueCOnsecutivi(char string[]){
    int leng = strlen(string) - 1;

    for (int i = 0; i < leng;){
        if((string[i] == string[i + 1]) && (string[i + 1] == string[i + 2])){
            for (int j = i; j < leng; j++)
                string[j + 1] = string[j + 2];
            leng -= 1;
        }
        else
            i++;
    }
}

void testAlPiuDueCOnsecutivi(){
    char string[] = "";
    alPiuDueCOnsecutivi(string);
    printf("Test alPiuDueCOnsecutivi(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", string);

    char string1[] = "abbbbacccddaaaa";
    alPiuDueCOnsecutivi(string1);
    printf("Test alPiuDueCOnsecutivi(\"abbbbacccddaaaa\"): Atteso = \"abbaccddaa\", Calcolato = \"%s\" \n", string1);
}

int main(int argc, char const *argv[]){
    char string[50];

    printf("inserisci la tua bellissima stringa: ");
    fgets(string, 50, stdin);
    strtok(string, "\n");

    alPiuDueCOnsecutivi(string);
    printf("La tua stringa con almeno due caratteri consecutivi e': %s\n", string);

    testAlPiuDueCOnsecutivi();

    return 0;
}
