#include <stdio.h>

void main() {

    char letra = 'x';

    //Condicional simples
    if (letra == 'x') {
        printf("A letra é x.");
    }

    printf("\n");
    printf("O código ASCI da letra %c é %d.", letra, letra);

    //Condicional usando o código ASCI
    if (letra == 120) {
        printf("\n");
        printf("A letra é x.");
    }

    getchar();
}
