#include <stdio.h>
#include <stdbool.h>

void main() {

    bool a = true;
    bool b = false;

    //Se a for verdadeiro
    if (a) {
        printf("A é verdadeiro.");
    }

    printf("\n");
    //Se b for falso
    if (b) {
        printf("B é verdadeiro.");
    } else {
        printf("B é falso.");
    }

    //Comparando uma falsidade
    if (!b) {
        printf("\n");
        printf("B é falso.");
    }

    getchar();
}
