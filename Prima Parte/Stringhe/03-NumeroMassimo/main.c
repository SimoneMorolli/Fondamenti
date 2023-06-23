/*Una funzione numeroMassimo riceve come parametro una stringa e restituisce il massimo
numero contenuto nella stringa, dove un numero corrisponde ad una sequenza massimale di caratteri
numerici consecutivi nella stringa. La funzione restituisce -1 se la stringa non contiene nessun carattere
numerico. Ad esempio, se la stringa ricevuta come parametro è "89afd43mg678ds4d", la funzione
restituisce il valore 678.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numeroMassimo (char string[]){
    int leng = strlen(string);
    int a = -1, b = -1;
    for (int i = 0; i < leng; i++){
        if(string[i] <= '9' && string[i] >= '0'){
            if(a == -1)
				a = string[i]-'0';
			else	
				a = a * 10 + (string[i]-'0');

			if(a > b)
				b = a;   
        }
        else
            a = -1; 
    }
    return b;
}

int main(int argc, char const *argv[])
{
    printf("%d",numeroMassimo("89afd43mg678ds4d"));
    return 0;
}
