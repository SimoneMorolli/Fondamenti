/*Una funzione occorrenzeConsecutive riceve come parametro una stringa. La funzione stampa
un messaggio che indica quale carattere ha il maggior numero di occorrenze consecutive nella
stringa e quante sono tali occorrenze. Ad esempio se la stringa ricevuta come parametro è
"abbbbbccccbbccccaeefff", la funzione stampa un messaggio del tipo "Il carattere con il maggior
numero di occorrenze consecutive è 'b' che ha 5 occorrenze consecutive"*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void occorrenzeConsecutive(char string[], int leng){
    char temp = string[0], result = temp;
    int c = 1, x = 0;
    for (int i = 1; i < leng; i++){
        if(string[i] == temp)
            c++;
        else if(c > x){
            x = c;
            result = temp;
            temp = string[i];
            c = 1;
        }
        else{
            c = 1;
            temp = string[i];
        }
    }
    printf("Il carattere con il maggior numero di occorrenze consecutive e' %c che ha %d occorrenze consecutive\n", result, x);
}

void testOccorrenzeConsecutive(){
    printf("----------TEST----------\n");
    char string[] = "abbbbbccccbbccccaeefff";
    printf("Test occorrenze('abbbbbccccbbccccaeefff'): Atteso = 'Il carattere con il maggior numero di occorrenze consecutive e' 'b' che ha 5 occorrenze consecutive', Calcolato: ");
    occorrenzeConsecutive(string, strlen(string));

    char string1[] = "aaaaa";
    printf("Test occorrenze('aaaaa'): Atteso = 'Il carattere con il maggior numero di occorrenze consecutive e' 'a' che ha 5 occorrenze consecutive', Calcolato: ");
    occorrenzeConsecutive(string1, strlen(string1));
    printf("----------TEST----------\n");
}

int main(){
    char string[50];
    
    printf("Inserisci la tua bellissima stringa: ");
    fgets(string, 50, stdin);

    string[strlen(string)] = '\0';

    occorrenzeConsecutive(string, strlen(string));

    testOccorrenzeConsecutive();
    return 0;
}
