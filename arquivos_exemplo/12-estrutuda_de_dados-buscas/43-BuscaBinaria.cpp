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

bool buscaBinaria(int vetor[TAM], int valorProcurado, int *posicao) {
    int limiteEsquerda = 0;
    int limiteDireita = TAM - 1;
    int meio;

    while (limiteEsquerda <= limiteDireita) {
        //Encontra o meio do vetor
        meio = (limiteEsquerda + limiteDireita) / 2;

        //Quando o valor pesquisado está no meio
        if (vetor[meio] == valorProcurado) {
            *posicao = meio;
            return true;
        }

        //Ajusta os limites para um nova pesquisa
        if (vetor[meio] < valorProcurado) {
            limiteEsquerda = meio + 1;
        } else {
            limiteDireita = meio - 1;
        }
    }

    return false;
}

int main() {

    int vetor[TAM] = {4, 7, 12, 19, 27, 30, 35, 42, 85, 92};
    //int vetor[TAM] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110};
    int valorProcurado;
    int posicao;

    imprimeVetor(vetor);

    printf("\n");
    printf("Qual número deseja encontrar: ");
    scanf("%d", &valorProcurado);

    if (buscaBinaria(vetor, valorProcurado, &posicao)) {
        cout << "O valor foi encontrado na posição: " << posicao;
    } else {
        cout << "O valor não foi encontrado.";
    }

    getchar();
    return 0;
}
