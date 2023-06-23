/*Una funzione sommaNumeri riceve come parametro una stringa e la modifica così che nella
stringa compaiano solo i numeri (ovvero le sequenze massimali di caratteri numerici) della stringa
parametro, dove ogni due numeri consecutivi sono separati da un ‘+’. Il primo e l’ultimo carattere
della stringa devono quindi essere numerici, ammesso che la stringa parametro contenga dei
caratteri numerici. Ad esempio, se la stringa parametro è "abc123d/ 45a!! 36 ", allora la stringa deve
essere modificata in "123+45+36"*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void sommaNumeri(char string[]){
    int leng = strlen(string);
    
    for (int i = 0; i < leng;){
        if((string[i] < '0' || string[i] > '9')){
            if(i != 0 && (string[i + 1] >= '0' && string[i + 1] <= '9')){
                string[i] = '+';
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
        printf("Stringa di %d volte: %s\n", i, string);
    }
}

void testSommaNumeri(){
    char string[] = "";
    sommaNumeri(string);
    printf("Test sommaNumeri(\"\"): Atteso = \" \", Calcolato = \"%s\" \n", string);

    char string1[] = "abc123d/ 45a!! 36 ";
    sommaNumeri(string1);
    printf("Test sommaNumeri(\"\"): Atteso = \" \", Calcolato = \"%s\" \n", string1);
}

int main(){
    char string[50];

    printf("Inserisci la tua bellissima string: ");
    fgets(string, 50, stdin);
    strtok(string, "\n");

    sommaNumeri(string);
    printf("Questa e' la tua stringa solo con i numeri: %s\n", string);
    
    testSommaNumeri();
}