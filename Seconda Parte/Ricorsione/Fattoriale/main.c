#include <stdio.h>

int Fattoriale (int n){
    int fatt;
    
    if(n != 1)
        fatt = n * Fattoriale(n - 1);
    else
        fatt = 1;
    return fatt;    
}

int main(int argc, char const *argv[]){
    int n;

    printf("inserire il numero che si vuole fattorizzare: ");
    scanf("%d", &n);

    printf("il numero fattorizzato e': %d", Fattoriale(n));

    return 0;
}
