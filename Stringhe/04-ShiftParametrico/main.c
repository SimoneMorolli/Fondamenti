/*Una funzione shiftParametrico riceve come parametro una stringa e la modifica come segue.
L'operazione di shift di una stringa s sposta di una posizione (verso destra) ciascun carattere di s.
L’ultimo carattere di s diventa il primo dopo lo shift. Ad esempio lo shift della stringa s = "abcdef"
fornisce la stringa "fabcde". La funzione shiftParametrico riceve come parametro una stringa ed un
intero x e modifica la stringa effettuando x operazioni di shift. In maniera equivalente, la stringa può
essere modificata spostando ciascun carattere di x posizioni verso destra, facendo rientrare dall’inizio
della stringa caratteri che escono dai limiti della stessa. Ad esempio, lo shift di tre posizioni della stringa
s = "abcdef" fornisce la stringa "defabc"*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void shiftParametrico(char string[], int shiftNumber){
	
	int lung = strlen(string), i;
	char nextChar, actualChar;
	printf("%s\n", string);

	for (int c = 1; c <= shiftNumber; c++){
	    actualChar = string[0];
		for (i = 1; i < lung; i++){
			nextChar = string[i];
			string[i] = actualChar;
			actualChar = nextChar;
		}
		string[0] = actualChar;
	}
}

void testShiftParametrico(){
	char string[] = "abcdef";
	shiftParametrico(string, 0);
	printf("Test shiftParametrico('abcdef', 0): Atteso = 'abcdef', Calcolato = '%s' \n", string);
	char string1[] = "abcdef";
	shiftParametrico(string1, 2);
	printf("Test shiftParametrico('abcdef', 2): Atteso = 'efabcd', Calcolato = '%s' \n", string1);
	char string2[] = "abcdef";
	shiftParametrico(string2, 1);
	printf("Test shiftParametrico('abcdef', 1): Atteso = 'fabcde', Calcolato = '%s' \n", string2);
}

int main(){
	testShiftParametrico();
}