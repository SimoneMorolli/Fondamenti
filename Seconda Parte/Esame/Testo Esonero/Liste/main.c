#include <stdio.h>
#include <stdlib.h>

typedef struct cordinate{
    int x;
    int y;
} cordinate;

typedef struct nodo{
    cordinate origine;
    int lenght;
    struct nodo* next;
} nodo;


nodo* insert(nodo* head){
    nodo* newNodo = malloc(sizeof(nodo));

    printf("Inserisci i valori: ");
    scanf("%d", &(newNodo->origine.x));
    scanf("%d", &(newNodo->origine.y));
    scanf("%d", &(newNodo->lenght));
    newNodo->next = NULL;

    if(head == NULL)
        head = newNodo;
    else{
        nodo* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNodo;
    }
    return head;
}


void deleteElementById(nodo* head, int value){
    nodo* delete;
    int done = 1;
    
    while(head->next != NULL && delete){
        printf("\n\n%d\n\n", head->next->lenght);
        if(head->next->lenght == value){
            delete = head->next;
            head->next = delete->next;
            free(delete);
            done = 0;
        }
        else
            head = head->next;
    }
    if(done) printf("non esiste nessun elemento con valore 12\n");
}


void printList (nodo* nodo){
    if(nodo == NULL)
        printf("\n");
    else{
        printf("Punti origine:\n ");
        printf("    x: %d\n", nodo->origine.x);
        printf("    y: %d\n", nodo->origine.y);
        printf("    lunghezza: %d\n", nodo->lenght);
        printList(nodo->next);
    }
}



/**********************************************
 ************ FUNZIONE PRINCIPALE ************
 **********************************************/

int main() {
	/* inizializza la lista */
    nodo* head = NULL;

	int risposta = -1;			// per interazione con utente

	while(risposta != 0) {
		/* richiedi un'operazione all'utente */
		printf("Che operazione vuoi svolgere?\n");
		printf("1 -> Inserimento\n");
		printf("2 -> Cancellazione\n");
		printf("3 -> Visualizzazione\n");
		printf("0 -> Termina il programma\n");
		scanf("%d", &risposta);

		/* gestisci le operazioni dell'utente */
		if(risposta==1)
            head = insert(head);
		else if(risposta==2)
            deleteElementById(head, 12);
		else if(risposta==3)
            printList(head);
		else if(risposta==0)
			printf("Finito!\n\n");
		else printf("Selezione non valida!\n\n");
	}
}