#include <stdio.h>
#include <iostream>
#define TAM 10

using namespace std;

void imprimeVetor(int vetor[TAM]) {
    for(int i = 0; i < TAM; i++) {
        cout << vetor[i];
        if (i < (TAM - 1)) {
            cout << " | ";
        }
    }
    cout << "\n";
}

void selectionSort(int vetor[TAM]) {
    //Recebe a posicao inicial para o menor valor
    int posicaoMenorValor, aux;

    //Analisa os elementos na frente
    for(int i = 0; i < TAM; i++) {
        posicaoMenorValor = i;

        imprimeVetor(vetor);

        for (int j = i + 1; j < TAM; j++) {
            //Caso encontre um valor menor à frente do analisado
            if (vetor[j] < vetor[posicaoMenorValor]) {
                posicaoMenorValor = j;
            }
        }

        //Se há um elemento menor, troca os valores de posição
        if (posicaoMenorValor != i) {
            aux = vetor[i];
            vetor[i] = vetor[posicaoMenorValor];
            vetor[posicaoMenorValor] = aux;
        }
    }
}

int main() {
    int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};
    selectionSort(vetor);
    imprimeVetor(vetor);

    return 0;
}

