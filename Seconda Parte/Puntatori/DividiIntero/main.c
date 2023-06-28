#include <stdio.h>
#include <stdlib.h>
/*Scrivere un programma che legge due interi introdotti dall'utente e stampa il quoziente ed il resto della divisione intera fra il più grande ed il più piccolo dei due interi. Il programma non deve utilizzare nessuna variabile di tipo int, ma solo variabili di tipo int*.

Devono essere definite le seguenti funzioni:

int * allocaMemoria() che alloca memoria per un intero e restituisce l'indirizzo dell'area di memoria allocata.

void leggiValore(int * variabile) che legge un valore introdotto dall'utente e lo memorizza all’indirizzo specificato nel parametro formale.

void riordina(int * a, int * b) che riordina due valori interi, di cui sono forniti gli indirizzi nei parametri formali, così che il primo sia più grande del secondo.

void calcolaQuoziente(int* dividendo, int* divisore, int* quoziente) che calcola il quoziente della divisione intera fra due interi, di cui sono forniti gli indirizzi nei parametri formali, e memorizza tale quoziente all’indirizzo specificato nel parametro formale.

void calcolaResto(int* dividendo, int* divisore, int* resto) che calcola il resto della divisione intera fra due interi, di cui sono forniti gli indirizzi nei parametri formali, e memorizza tale resto all’indirizzo specificato nel parametro formale.

int main() che gestisce l’interazione con l’utente, invocando le altre funzioni per allocare memoria, leggere i valori introdotti dall’utente, ordinarli dal più grande al più piccolo, e calcolare e stampare il quoziente ed il resto della divisione intera fra i due interi.
*/

int* allocaMemoria(){ 
    return malloc(sizeof(int));
}

void leggiValore(int* pointer){
    printf("Inserisci il numero: ");
    scanf("%d", pointer);
}

void riordina(int* a, int* b){
    int* c = allocaMemoria();
    *c = *a;

    if(*a <= *b){
        *a = *b;
        *b = *c;
    }
    free(c);
}

void calcolaQuoziente(int* x, int* y, int* result){
    *result = (*x) * (*y); 
}

void calcolaResto(int* x, int* y, int* result){
    riordina(x, y);
    *result = (*x) % (*y);
} 

int main(int argc, char const *argv[]){
    int* x = allocaMemoria();
    int* y = allocaMemoria();
    int* result = allocaMemoria();

    leggiValore(x);
    leggiValore(y);
    printf("numeri inseriti: %d %d\n", *x, *y);

    calcolaQuoziente(x, y, result);
    printf("quoziente: %d\n", *result);

    calcolaResto(x, y, result);
    printf("Resto: %d\n", *result);

    free(x);
    free(y);
    free(result);

    return 0;
}
