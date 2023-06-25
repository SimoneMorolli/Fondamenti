/*Una funzione soloParole riceve come parametro una stringa e la modifica così che nella stringa
compaiano solo le parole (ovvero le sequenze massimali di caratteri alfabetici maiuscoli o minuscoli
non accentati) della stringa parametro, dove ogni due parole consecutive sono separate da un
singolo spazio. Il primo e l’ultimo carattere della stringa devono quindi essere alfabetici, ammesso che
la stringa parametro contenga dei caratteri alfabetici. Ad esempio, se la stringa parametro è
"123abc6/ def1!! gh ", allora la stringa deve essere modificata in "abc def gh"*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void soloParole(char string[]){
	int leng = strlen(string);

	for (int i = 0; i < leng;){
		if((string[i]  < 'a' || string[i]  > 'z') || (string[i]  < 'A' || string[i]  > 'Z')){
			if(i != 0 && (string[i + 1]  >= 'a' && string[i + 1]  <= 'z') || (string[i + 1]  >= 'A' && string[i + 1]  <= 'Z')){
				string[i] = ' ';
				i++;
			}
			else{
				for (int j = i; j < leng; j++)
					
			}
		}
	}
}