#include <stdio.h>
#include <iostream>
#define TAM 10

using namespace std;

void imprimeVetor(int vetor[TAM]) {
    for(int i = 0; i < TAM; i++) {
        cout << vetor[i];
        if (i < (TAM - 1)) {
            cout << " - ";
        }
    }
    cout << "\n";
}

bool buscaSimples(int vetor[TAM], int valorProcurado, int *posicao) {

    bool foiEncontrado = false;

    for (int i = 0; i < TAM; i++) {
        if (vetor[i] == valorProcurado) {
            foiEncontrado = true;
            *posicao = i;
        }
    }

    return foiEncontrado;
}

int main() {

    int vetor[TAM] = {4, 7, 12, 19, 27, 30, 35, 42, 85, 92};
    int valorProcurado;
    int posicao;

    imprimeVetor(vetor);

    printf("\n");
    printf("Qual número deseja encontrar: ");
    scanf("%d", &valorProcurado);

    if (buscaSimples(vetor, valorProcurado, &posicao)) {
        cout << "O valor foi encontrado na posição: " << posicao;
    } else {
        cout << "O valor não foi encontrado.";
    }

    getchar();
    return 0;
}
