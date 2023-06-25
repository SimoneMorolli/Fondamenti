#include <stdio.h>
#include <stdlib.h>

int cercaMultiplo(int x, int y, int z){
	int result = 0;
	
	if(x % y == 0)
		result = 1;
	else if(y % z == 0)
		result = 1;
	else if(x % z == 0)
		result = 1;
	return result;
}

int cercaTerna(int array[], int dim){
	int result = 1;
	for(int i = 0; i < dim; i++)
		if(cercaMultiplo(array[i], array[i + 1], array[i + 2]) == 0)
			result = 0;
	return result;
}

int main(){
	int array[5] = {3, 4, 2, 18, 9};
	printf("Risultato aspettato: 1 Calcolato: %d\n", cercaTerna(array, 5 - 1));

	int array1[5] = {3, 4, 5, 18, 9};
	printf("Risultato aspettato: 0 Calcolato: %d\n", cercaTerna(array1, 5 - 1));
}