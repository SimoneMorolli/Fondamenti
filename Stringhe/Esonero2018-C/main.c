/*Una funzione paroleBenSeparate riceve come parametro una stringa e la modifica così che
nella stringa compaiano solo le parole minuscole (ovvero le sequenze massimali di caratteri alfabetici
minuscoli non accentati) della stringa parametro, dove ogni due parole consecutive sono separate
da un trattino ‘-‘. Il primo e l’ultimo carattere della stringa devono quindi essere alfabetici minuscoli,
ammesso che la stringa parametro contenga dei caratteri alfabetici minuscoli. Ad esempio, se la
stringa parametro è "123abc6/ Def1!! gh ", allora la stringa deve essere modificata in "abc-ef-gh"*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void paroleBenSeparate(char string[]){
    int leng = strlen(string);

    for (int i = 0; i < leng;){
        if(string[i] < 'a' || string[i] > 'z'){
            if(i != 0 && (string[i + 1] >= 'a' && string[i + 1] <= 'z')){
                string[i] = '-';
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

void testParoleBenSeparate(){
    char string[] = "";
    paroleBenSeparate(string);
    printf("Test paroleBenSeparate(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", string);

    char string1[] = "123abc6/ Def1!! gh ";
    paroleBenSeparate(string1);
    printf("Test paroleBenSeparate(\"123abc6/ Def1!! gh \"): Atteso = \"abc-ef-gh\", Calcolato = \"%s\" \n", string1);
}

int main(int argc, char const *argv[]){
    char string[50];

    printf("inserisci la tua bellissima stringa: ");
    fgets(string, 50, stdin);
    strtok(string, "\n");

    paroleBenSeparate(string);
    printf("La tua stringa con solo lettere minuscole separate da un \"-\" e': %s\n", string);

    testParoleBenSeparate();

    return 0;
}
