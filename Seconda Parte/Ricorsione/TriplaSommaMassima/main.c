#include <stdio.h>

int triplaSommaMassima(int *array, int leng){
    int result, x;
    if(leng == 1)
        return result;
    else{
        x = array[leng] + array[leng - 1] + array[leng - 2];
        if(x >= triplaSommaMassima(array, leng - 1))
            result = x;
        else
            result = array[leng - 1] + array[leng - 2] + array[leng - 3];
    }
    return result;
}

int main(int argc, char const *argv[]){
    int array[] = {4, -2, 5, 7, -1, -2};
    printf("%d", triplaSommaMassima(array, 5));
    return 0;
}
