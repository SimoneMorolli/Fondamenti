/*Una funzione soloNumeri riceve come parametro una stringa e la modifica così che nella stringa
compaiano solo i numeri (ovvero le sequenze massimali di caratteri numerici) della stringa parametro,
dove ogni due numeri consecutivi sono separati da un singolo spazio. Il primo e l’ultimo carattere della
stringa devono quindi essere numerici, ammesso che la stringa parametro contenga dei caratteri
numerici. Ad esempio, se la stringa parametro è "abc123d/ 45a!! 36 ", allora la stringa deve essere
modificata in "123 45 36"*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void soloNumeri(char string[]){
    int leng = strlen(string);

    for (int i = 0; i < leng;){
        if(string[i] < '0' || string[i] > '9'){
            if(i != 0 && (string[i + 1] >= '0' && string[i + 1] <= '9')){
                string[i] = ' ';
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
    }  
}

void testSoloNumeri(){
    char string[] = "";
    soloNumeri(string);
    printf("Test SoloNumeri(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", string);

    char string1[] = "abc123d/ 45a!! 36 ";
    soloNumeri(string1);
    printf("Test SoloNumeri(\"abc123d/ 45a!! 36 \"): Atteso = \"123 45 36\", Calcolato = \"%s\" \n", string1);
}

int main(int argc, char const *argv[]){
    char string[50];

    printf("inserisci la tua bellissima stringa: ");
    fgets(string, 50, stdin);
    strtok(string, "\n");

    soloNumeri(string);
    printf("La tua stringa con solo numeri separate da \" \" e': %s\n", string);

    testSoloNumeri();

    return 0;
}
