#include <stdio.h>

void main() {

    int a = 1;
    char b = 'b';

    //Switch com inteiro
    switch(a) {
        case 1:
            printf("Opção escolhida 1.");
            break;
        case 2:
            printf("Opção escolhida 2.");
            break;
        case 3:
            printf("Opção escolhida 3.");
            break;
        default:
            printf("Opção inválida.");
            break;
    }

    printf("\n");
    //Switch com char
    switch(b) {
        case 'a':
            printf("A letra é a.");
            break;
        case 'b':
            printf("A letra é b.");
            break;
        default:
            printf("Opção inválida.");
            break;
    }

    getchar();
}
