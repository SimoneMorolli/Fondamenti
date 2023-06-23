#include <stdio.h>

int quadrati (int *array, int leng){
    int next = array[leng];
    int prev = array[leng - 2];
    int result, x;
    if(leng == 1)
        return 0;
    else{
        printf("leng: %d\n", leng);
        printf("    sto confrontando la tripla %d %d %d\n", array[leng - 2], array[leng - 1], array[leng]);
        x = (array[leng - 1] == next * next) || (array[leng - 1] == prev * prev);
        printf("    Risultato di x: %d\n", x);
        if(x)
            return 1;
        quadrati(array, leng - 1);
    }
}

int main(int argc, char const *argv[]){
    int array[] = {7, 5, 12, 4};
    int array1[] = {7, 4, 2, -3};
    int array2[] = {-3, 9, 2, 3};
    printf("Test 0 (Atteso 0): %d\n", quadrati(array, 3));
    printf("Test 1 (Atteso 1): %d\n", quadrati(array1, 3));
    printf("Test 2 (Atteso 1): %d\n", quadrati(array2, 3));
    return 0;
}
