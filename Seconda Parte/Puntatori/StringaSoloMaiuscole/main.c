#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void maiuscole(char* string){
    while(strlen(string) != 0){
        if(*string >= 'a' && *string <= 'z')
            *string = *string - 32;
        printf("Lunghezza stringa: %d\n", strlen(string));
        printf("Stringa in modificazione: %s\n", string);
        string++;  
    }
} 

int main(int argc, char const *argv[]){
    char* string;

    printf("inserisci la stringa: ");
    scanf("%s", string);
    
    maiuscole(string);
    printf("Stringa modificata: %s", string);
    
    return 0;
}
