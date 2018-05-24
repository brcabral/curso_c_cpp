#include <stdio.h>

void main() {
    int multiplicador = 2;

    //Tabuada
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d", multiplicador, i, multiplicador * i);
        printf("\n");
    }

    //Contando de 2 em 2
    printf("\nContando de 2 em 2:");
    printf("\n");
    for (int i = 0; i <= 10; i = i + 2) {
        printf("%d", i);
        printf("\n");
    }

    getchar();
}

