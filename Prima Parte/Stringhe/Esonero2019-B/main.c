/*Una funzione dueMinuscolePerVolta riceve come parametro una stringa e la modifica così che
ogni sequenza di almeno due caratteri alfabetici minuscoli venga trasformata in una sequenza di
esattamente due caratteri alfabetici minuscoli (a scelta fra quelli della sequenza preesistente). Ad
esempio, se la stringa ricevuta come parametro è "acbvd45dshAfdkf", la stringa può essere modificata
in "ac45dsAfd "*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void dueMinuscolePerVolta(char string[]){
    int leng = strlen(string) - 2;

    for (int i = 0; i < leng;){
        if((string[i] >= 'a' && string[i] <= 'z') && (string[i + 1] >= 'a' && string[i + 1] <= 'z') && (string[i + 2] >= 'a' && string[i + 2] <= 'z')){
            for (int j = i; j < leng; j++)
                string[j + 2] = string[j + 3];
            leng -= 1;
        }
        else
            i++;
    }
}

void testDueMinuscolePerVolta(){
    char string[] = "";
    dueMinuscolePerVolta(string);
    printf("Test dueMinuscolePerVolta(\"\"): Atteso = \"\", Calcolato = \"%s\" \n", string);

    char string1[] = "acbvd45dshAfdkf";
    dueMinuscolePerVolta(string1);
    printf("Test dueMinuscolePerVolta(\"acbvd45dshAfdkf\"): Atteso = \"ac45dsAfd\", Calcolato = \"%s\" \n", string1);
}

int main(int argc, char const *argv[]){
    char string[50];

    printf("inserisci la tua bellissima stringa: ");
    fgets(string, 50, stdin);
    strtok(string, "\n");

    dueMinuscolePerVolta(string);
    printf("La tua stringa con almeno due caratteri consecutivi e': %s\n", string);

    testDueMinuscolePerVolta();

    return 0;
}
