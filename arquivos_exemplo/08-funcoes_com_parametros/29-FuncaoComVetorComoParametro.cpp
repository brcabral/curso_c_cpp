#include <stdio.h>

//Vetores sempre são passados como referência nas funções
//Portanto é indiferente passar o valor (int vetor[]) ou a posição do ponteiro (int *vetor)
//sizeof(int) = o tamanho da variável inteira ocupa na memória, que é 2 byte

void imprimeVetorPonteiro(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("O valor do vetor na posição %d é %d", i, vetor[i]);
        printf("\n");
    }
}

void imprimeVetor(int vetor[]) {
    for (int i = 0; i <= sizeof(vetor)/sizeof(int); i++) {
        printf("O valor do vetor na posição %d é %d", i, vetor[i]);
        printf("\n");
    }
}

void modificaVetorPonteiro(int *vetor) {
    for (int i = 0; i <= sizeof(vetor)/sizeof(int); i++) {
        vetor[i] = vetor[i] + 1;
    }
}

void modificaVetor(int vetor[]) {
    for (int i = 0; i <= sizeof(vetor)/sizeof(int); i++) {
        vetor[i] = vetor[i] + 1;
    }
}


int main() {

    int v[3] = {1,2,3};
    imprimeVetorPonteiro(v, 3);
    printf("\n");

    imprimeVetor(v);
    printf("\n");

    modificaVetorPonteiro(v);
    imprimeVetorPonteiro(v, 3);
    printf("\n");

    modificaVetor(v);
    imprimeVetor(v);

    getchar();
    return 0;
}


