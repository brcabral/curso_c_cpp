#include <stdio.h>


int* alocaVetor(int tamanho) {
    //Cria um ponteiro auxiliar
    int *ponteiroAux;

    //Alocação dinâmica de memória
    //Função malloc: Alocar espaço na memória
    ponteiroAux = (int*) malloc(tamanho * sizeof(int));

    //Retorna o ponteiro que aponta para a primeira posição de memória do vetor alocado
    return ponteiroAux;
}

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

    int *vetor;
    int tamanho;

    //Lendo o tamanho do vetor pelo usuário
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    //Ponteiro recebe o endereço de memória que foi alocado para o vetor
    vetor = alocaVetor(tamanho);

    preencheVetor(vetor, tamanho);
    imprimeVetor(vetor, tamanho);


    //Limpar a memória reservada
    free(vetor);

    getchar();
    return 0;
}

