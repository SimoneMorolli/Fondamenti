#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
//12345x67y890ab7c
void nascondiIntero(char string[]){
	int leng = strlen(string) - 1;
	for(int i = 0; i < leng;){
		if(string[i] >= '0' && string[i] <= '9' && string[i + 1] >= '0' && string[i + 1] <= '9' && string[i + 2] >= '0' && string[i + 2] <= '9'){
			string[i + 1] = '*';
			while(string[i + 3] >= '0' && string[i + 3] <= '9'){
				for(int j = i; j < strlen(string); j++)
					string[j + 2] = string [j + 3];
				leng -= 1;
			}
		}
		else
			i++;
	}
}

int main(){
	char string[50];
	int x;
	
	printf("inserisci la bellissima stringa: ");
	fgets(string, 50, stdin);
	strtok(string, "\n");
	
	nascondiIntero(string);

	printf("%s", string);

}