#include <stdio.h>

int tripleTutteDiverse(int array[], int leng){
    int result, y;
    if(leng == 1)
        return result;
    else{
        printf("leng: %d\n", leng);
        printf("    sto confrontando la tripla %d %d %d\n", array[leng - 2], array[leng - 1], array[leng]);
        y = ((array[leng] != array[leng - 1]) && (array[leng - 1] != array[leng - 2]));
        printf("    Risultato di y: %d\n", y);
        result = y && tripleTutteDiverse(array, leng - 1);
        return result;
    }
}

int main(int argc, char const *argv[]){
    int array[] = {1, 2, 3, 4, 4};
    printf("%d", tripleTutteDiverse(array, 4));
    return 0;
}
