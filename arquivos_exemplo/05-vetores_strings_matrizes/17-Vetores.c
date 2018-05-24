#include <stdio.h>
#define TAM 3

void main() {

    //Definir vetor
    int vetor[TAM], i;

    //Passar valores para o vetor
    vetor[0] = 5;
    vetor[1] = 10;
    vetor[2] = 15;

    //Imprimindo os valres do vetor
    printf("Posição 0: %d", vetor[0]);
    printf("\n");
    printf("Posição 1: %d", vetor[1]);
    printf("\n");
    printf("Posição 2: %d", vetor[2]);
    printf("\n\n");

    //Adicionando 1 para cada posição
    for (i = 0; i < TAM; i++){
        vetor[i] =  vetor[i] + 1;
    }

    //Imprimindo vetor em um laço de repetição
    for (i = 0; i < TAM; i++) {
        printf("Posição %d: %d", i, vetor[i]);
        printf("\n");
    }

    printf("\n");
    //Populando o vetor em um laço de repetição
    for (i = 0; i < TAM; i++) {
        printf("Digite o valor do vetor na posição %d: ", i);
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < TAM; i++) {
        printf("Posição %d: %d", i, vetor[i]);
        printf("\n");
    }

    getchar();
}
