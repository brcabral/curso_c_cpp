#include <stdio.h>
#include <new>

void preencheVetor(int *vetor, int tamanho) {
    int numero = 10;
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = numero * (i+1);
    }
}

void imprimeVetor(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("O valor do vetor na posição %d é %d", i, vetor[i]);
        printf("\n");
    }
}

int main() {

    int tamanho;

    //Lendo o tamanho do vetor pelo usuário
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    //Ponteiro recebe o novo vetor vazio
    int *vetor = new int[tamanho];

    preencheVetor(vetor, tamanho);
    imprimeVetor(vetor, tamanho);

    getchar();
    return 0;
}

