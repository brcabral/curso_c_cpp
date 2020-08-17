#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main() {
    // Usar acentos
    setlocale(LC_ALL, "");

    // Crie um algoritmo que imprima os números de 10 até 0 de forma regressiva.
    // Usando o while, do while e for
    int i = 10;

    printf("Contagem progressiva usando o while.\n");
    while (i >= 0) {
        printf("%d \n", i);
        i--;
    }

    printf("\n");
    printf("Contagem progressiva usando o do while.\n");
    i = 10;
    do {
        printf("%d \n", i);
        i--;
    } while (i >= 0);

    printf("\n");
    printf("Contagem progressiva usando o for.\n");
    for (i = 10; i >= 0; i--) {
        printf("%d \n", i);
    }

}
