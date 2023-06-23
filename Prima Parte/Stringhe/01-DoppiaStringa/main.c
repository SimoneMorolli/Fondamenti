/*Una funzione doppiaStringa riceve come parametro una stringa e verifica se essa consiste di due
ripetizioni della stessa sottostringa, restituendo 1 o 0 in caso di verifica positiva o negativa. Ad esempio,
se la stringa ricevuta come parametro è "ciaociao", la funzione restituisce il valore 1, mentre se la
stringa parametro è "abcba" la funzione restituisce il valore 0.*/
#include <stdio.h>
#include <string.h>

int doppiaStringa (char string[]){
    //printf("sono entrato nella funzione\n");
    int lung = strlen(string);
    
    if(lung%2 != 0)
        return 0;

    for (int i = 1; i < lung; i++)
    {
        //printf("sono entrato nel primo ciclo\n");
        if(string[0] == string[i]){
            //printf("sono entrato nel if per la %d\n", i);
            int j = 1, c = i + 1;
            while(string[j] == string[c] && string[c] != '\0'){
                //printf("sono entrato nel secondo ciclo\n");
                //printf("Sto Paragonando %c con %c\n", string[j], string[c]);
                    j++;
                    c++;
            }
            if(string[c] == '\0'){
                //printf("Torno 1\n");
                return 1;
            }
        }
    }
}

void testDoppiaStringa(){
    printf("Test doppiaStringa('a'): Atteso = 0, Calcolato = %d \n", 	doppiaStringa("a"));
    printf("Test doppiaStringa('aa'): Atteso = 1, Calcolato = %d \n", 	doppiaStringa("aa"));
    printf("Test doppiaStringa('obcdabcd'): Atteso = 0, Calcolato = %d \n", doppiaStringa("obcdabcd"));
    printf("Test doppiaStringa('ciaociao'): Atteso = 1, Calcolato = %d \n", doppiaStringa("ciaociao"));
    printf("Test doppiaStringa('caccacacca'): Atteso = 1, Calcolato = %d \n", doppiaStringa("caccacacca"));
    printf("Test doppiaStringa('abcba'): Atteso = 0, Calcolato = %d \n", doppiaStringa("abcba"));
    printf("Test doppiaStringa(''): Atteso = 1, Calcolato = %d \n", doppiaStringa(""));
}

int main(int argc, char const *argv[])
{
    char string[50];
    int c;

    printf("Inserire la stringa da verificare: ");
    fgets(string, 50, stdin);
    
    string[strlen(string)-1]='\0';

    c = doppiaStringa(string);

    if(c == 1)
        printf("Stringa Doppia");
    else
        printf("Stringa non doppia (sad)");

    testDoppiaStringa();
    return 0;
}
