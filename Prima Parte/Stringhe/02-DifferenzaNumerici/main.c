/*Una funzione differenzaNumerici riceve come parametro una stringa e restituisce la massima
differenza (in valore assoluto) fra due caratteri numerici che appartengono alla stringa e fra i quali non
ci sono altri caratteri numerici, oppure -1 se la stringa non contiene due caratteri numerici. Ad
esempio, se la stringa ricevuta come parametro è "d2ngf67m", la funzione restituisce il valore 4, in
quanto la differenza fra 6 e 2 è 4, e fra 6 e 2 non compaiono altri caratteri numerici.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int differenzaNumerici(char string[]){
    int a, b = -1, result = 0, first = 1;
    int leng = strlen(string);


    for (int i = 0; i < leng; i++){
        if(string[i] <= '9' && string[i] >= '0' && first == 1){
            a = string[i] - '0';
            first = 0;
        }
        else if(string[i] <= '9' && string[i] >= '0' && first == 0){
            b = string[i] - '0';
            first = 2;
        }
    }
    if(b == -1)
        result = -1;
    else if(a > b)
        result = a - b;
    else
        result = b - a;
    
    return result;
}

void testDifferenzaNumerici(){
    printf("Test differenzaNumerici('abc5fsh('): Atteso = -1, Calcolato = %d\n", differenzaNumerici("abc5fsh("));
    printf("Test differenzaNumerici('d2ngf67m'): Atteso = -4, Calcolato = %d\n", differenzaNumerici("d2ngf67m"));
}

int main(int argc, char const *argv[]){
    char string[50];

    printf("Inserisci la tua bellissima stringa: ");
    fgets(string, 50, stdin);
    
    string[strlen(string) - 1] = '\0';
    printf("La differenza tra i numeri nella tua stringa e' %d\n", differenzaNumerici(string));
    
    testDifferenzaNumerici();

}
