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

void shiftParametrico(char string[], int shiftNumber, int leng){
	
	int i;
	char nextChar, actualChar;

	for (int c = 1; c <= shiftNumber; c++){
	    actualChar = string[0];
		for (i = 1; i < leng; i++){
			nextChar = string[i];
			string[i] = actualChar;
			actualChar = nextChar;
		}
		string[0] = actualChar;
	}
}

void testShiftParametrico(){
	char string[] = "abcdef";
	shiftParametrico(string, 0, strlen(string));
	printf("\nTest shiftParametrico('abcdef', 0): Atteso = 'abcdef', Calcolato = '%s' \n", string);

	char string1[] = "abcdef";
	shiftParametrico(string1, 2, strlen(string1));
	printf("Test shiftParametrico('abcdef', 2): Atteso = 'efabcd', Calcolato = '%s' \n", string1);
	
	char string2[] = "abcdef";
	shiftParametrico(string2, 1, strlen(string2));
	printf("Test shiftParametrico('abcdef', 1): Atteso = 'fabcde', Calcolato = '%s' \n", string2);
}

int main(){
	char string[50];
	int x;
	
	printf("inserisci la bellissima stringa: ");
	fgets(string, 50, stdin);
	printf("inserisci il numero di volte che vuoi shiftare la stringa: ");
	scanf("%d", &x);
	
	string[strlen(string - 1)] = '\0';
	
	shiftParametrico(string, x, strlen(string) - 1);

	printf("la tua stringa shiftata di %d volte e': %s", x, string);

	testShiftParametrico();
}