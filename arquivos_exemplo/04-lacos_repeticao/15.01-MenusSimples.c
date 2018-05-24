#include <stdio.h>

void main() {

    int opcao;
    //Menu simples

    printf("1- Opção 1");
    printf("\n");
    printf("2- Opção 2");
    printf("\n");
    printf("3- Opção 3");
    printf("\n");
    printf("Escolha uma opção: ");

    //Ler a opção inserida pelo usuário
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            printf("A opção 1 foi escolhida.");
            break;
        case 2:
            printf("A opção 2 foi escolhida.");
            break;
        case 3:
            printf("A opção 3 foi escolhida.");
            break;
        default:
            printf("Opção inválida.");
            break;
    }

    getchar();
}

