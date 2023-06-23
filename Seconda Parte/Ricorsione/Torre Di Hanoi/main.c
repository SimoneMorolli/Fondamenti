#include <stdio.h>

void hanoi (int discNumber, int start, int middle, int finish);

int main(int argc, char const *argv[]){
    int n;
    printf("inserisci il numero di dischi che vuoi spostare: ");
    scanf("%d", n);
    hanoi(n, 1, 2, 3);
    printf("Finito!!");
    return 0;
}

void moveDisc(int start, int finish){
    printf("Sposto il disco dalla pila %d alla pila %d\n", start, finish);
}

void hanoi (int discNumber, int start, int middle, int finish){
    if(discNumber == 1)
        moveDisc(start, finish);
    else{
        hanoi(discNumber - 1, start, finish, middle);
        moveDisc(start, finish);
        hanoi(discNumber - 1, middle, start, finish);
    }
}
