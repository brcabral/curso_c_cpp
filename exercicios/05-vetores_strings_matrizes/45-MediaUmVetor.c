#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 3

void main() {
    // Usar acentos
    setlocale(LC_ALL, "");

    // Crie um algoritmo que leia 3 valores para um vetor de 3 posições
    // depois calcule a média dos valores acessando o vetor.
    float vetor[TAM];
    float soma = 0;

    for (int i = 0; i < TAM; i++) {
        printf("Digite o %dº valor: ", i+1);
        scanf("%f", &vetor[i]);
    }

    for (int i = 0; i < TAM; i++) {
        soma += vetor[i];
    }

    printf("A média dos valores digitados é %.2f.", (soma / TAM));
}
