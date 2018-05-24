#include <stdio.h>

void main() {

    int a = 5;
    float b = 2.5;
    char c = 'x';
    int opcao = 1;

    //Condição simples
    if (a == 5) {
        printf("A variável a é igual a cinco.");
    }

    if (b == 2.5) {
        printf("\n");
        printf("A variável b é igual a 2.5.");
    }

    if (c == 'x') {
        printf("\n");
        printf("A variável c é igual a x.");
    }

    printf("\n");
    //Número par ou ímpar
    if ((a % 2) == 0) {
        printf("O número %d é par", a);
    } else {
        printf("O número %d é impar", a);
    }

    printf("\n");
    //Condicional composta
    if (opcao == 1) {
        printf("A opção é igual à 1.");
    } else if (opcao == 2) {
        printf("A opção é igual à 2.");
    } else {
        printf("A opção NÃO é igual à 1 ou 2.");
    }

    getchar();  // Para Linux
}
