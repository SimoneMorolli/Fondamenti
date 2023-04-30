/*Una funzione soloParole riceve come parametro una stringa e la modifica così che nella stringa
compaiano solo le parole (ovvero le sequenze massimali di caratteri alfabetici maiuscoli o minuscoli
non accentati) della stringa parametro, dove ogni due parole consecutive sono separate da un
singolo spazio. Il primo e l’ultimo carattere della stringa devono quindi essere alfabetici, ammesso che
la stringa parametro contenga dei caratteri alfabetici. Ad esempio, se la stringa parametro è
"123abc6/ def1!! gh ", allora la stringa deve essere modificata in "abc def gh"*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void soloParole(char string[]){
    int leng = strlen(string);
    for (int i = 0; i < leng;){
        if(!((string[i] >= 'A' && string[i] <= 'Z') || (string[i] >= 'a' && string[i] <= 'z'))){
            if(i!=0 && ((string[i+1]>='a' && string[i+1]<='z')|| (string[i+1]>='A' && string[i]<='Z'))) {
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

void testSoloParole(){
    char string[] = "";
    soloParole(string);
    printf("Test soloParole(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", string);

    char string1[] = "123abc6/ def1!! gh ";
    soloParole(string1);
    printf("Test soloParole(\"123abc6/ def1!! gh \"): Atteso = \"abc def gh\", Calcolato = \"%s\" \n", string1);
}

int main(){
    char string[50];

    printf("Inserisci la tua bellissima stringa: ");
    fgets(string, 50, stdin);
    strtok(string, "\n");

    soloParole(string);

    printf("La tua stringa solo alfabetizzata e': %s\n", string);

    testSoloParole();
}