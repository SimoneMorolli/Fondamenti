/*Una funzione primaMaiuscole riceve come parametro una stringa e la modifica riordinando i
caratteri della stringa così che tutti i caratteri alfabetici maiuscoli compaiono prima di tutti i caratteri
alfabetici minuscoli. Caratteri non alfabetici possono essere ignorati. L'ordine dei caratteri maiuscoli
nella stringa modificata può essere uno qualsiasi, così come l'ordine dei caratteri minuscoli. Ad
esempio, se la stringa parametro è "a%BcD/b", allora "BD%a/bc" rappresenta una possibile modifica
corretta della stringa.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void primaMaiuscole(char string[], int leng){
    int c = 0;
    char temp;
    for (int i = 0; i < leng; i++){
        if(string[i] >= 'A' && string[i] <= 'Z'){
            temp = string[c];
            string[c] = string[i];
            string[i] = temp;
            c++;
        }
    }
}

void testPrimaMaiuscole(){
    char string[] = "aBC";
    primaMaiuscole(string, strlen(string));
    printf("Test primaMaiuscole('abC'): Atteso = 'BCa', Calcolato = '%s' \n", string);

    char string1[] = "ABC";
    primaMaiuscole(string1, strlen(string1));
    printf("Test primaMaiuscole('abC'): Atteso = 'ABC', Calcolato = '%s' \n", string1);

    char string2[] = "abc";
    primaMaiuscole(string2, strlen(string2));
    printf("Test primaMaiuscole('abC'): Atteso = 'abc', Calcolato = '%s' \n", string2);

    char string3[] = "a%BcD/b";
    primaMaiuscole(string3, strlen(string3));
    printf("Test primaMaiuscole('a%BcD/b'): Atteso = 'BDac%/b', Calcolato = '%s' \n", string3);
}

int main(int argc, char const *argv[]){
    char string[50];

    printf("Inserisci la tua bellissima stringa: ");
    fgets(string, 50, stdin);
    string[strlen(string) - 1] = '\0';

    primaMaiuscole(string, strlen(string) - 1);

    printf("Questa è la tua bellissima stringa primata: %s\n", string);
    
    testPrimaMaiuscole();
    return 0;
}