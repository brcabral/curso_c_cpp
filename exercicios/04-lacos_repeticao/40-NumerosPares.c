#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define FIM 20

void main() {
    // Usar acentos
    setlocale(LC_ALL, "");

    // Crie um algoritmo que imprima os números pares de 10 à 20
    // Usando o while, do while e for
    int i = 10;

    printf("Numeros pares de 10 à 20 usando o while.\n");
    while (i <= FIM) {
        if (i % 2 == 0) {
            printf("%d \n", i);
        }
        i++;
    }

    printf("\n");
    printf("Numeros pares de 10 à 20 usando o do while.\n");
    i = 10;
    do {
        if (i % 2 == 0) {
            printf("%d \n", i);
        }
        i++;
    } while (i <= FIM);

    printf("\n");
    printf("Numeros pares de 10 à 20  usando o for.\n");
    for (i = 10; i <= FIM; i++) {
        if (i % 2 == 0) {
            printf("%d \n", i);
        }
    }

}
