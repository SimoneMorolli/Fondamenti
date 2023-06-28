#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x;
    int y;
} point;

typedef struct parallelogram {
    point bs;
    point ad;
    int b;
} parallelogram;

int fill(parallelogram p[]) {
    FILE* file = fopen("D:/Programmazione/C/RepoFondamenti/Fondamenti/Seconda Parte/File/Prallelogrammi/inputoutput.txt", "r");
    if (file == NULL) {
        perror("Impossibile aprire il file");
        return 0;
    }

    printf("File aperto correttamente\n");

    int i = 0;

    while (fscanf(file, "%d %d %d %d %d", &p[i].bs.x, &p[i].bs.y, &p[i].ad.x, &p[i].ad.y, &p[i].b) == 5) {
        printf("Entrato nel while per inserire tutto\n");
        i++;
    }

    fclose(file);
    return i;
}

void printP(parallelogram p[], int dim) {
    printf("Entrato nella funzione di printf\n");
    printf("i: %d\n", dim);
    for (int i = 0; i < dim; i++) {
        printf("Entrato nel ciclo di printf\n");
        printf("Parallelogramma %d:\n", i + 1);
        printf("Punto bs:\n");
        printf("    x: %d\n", p[i].bs.x);
        printf("    y: %d\n", p[i].bs.y);
        printf("Punto ad:\n");
        printf("    x: %d\n", p[i].ad.x);
        printf("    y: %d\n", p[i].ad.y);
        printf("Lunghezza b: %d\n", p[i].b);
    }
}

int main() {
    parallelogram p[50];
    int count = fill(p);

    printP(p, count);

    return 0;
}