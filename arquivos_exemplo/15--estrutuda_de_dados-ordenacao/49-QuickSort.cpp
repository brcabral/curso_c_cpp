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

void quickSort(int vetor[TAM], int inicio, int fim) {
    int limiteEsquerda, limiteDireita, pivo, meio, aux;

    limiteEsquerda = inicio;
    limiteDireita = fim;

    //Ajustando os valores auxiliares
    meio = (int) ((limiteEsquerda + limiteDireita) / 2);
    pivo = vetor[meio];

    while (limiteDireita > limiteEsquerda) {
        imprimeVetor(vetor);

        while (vetor[limiteEsquerda] < pivo) {
            limiteEsquerda = limiteEsquerda + 1;
        }

        while (vetor[limiteDireita] > pivo) {
            limiteDireita = limiteDireita - 1;
        }

        if (limiteEsquerda <= limiteDireita) {
            //Troca os valores de posição
            aux = vetor[limiteEsquerda];
            vetor[limiteEsquerda] = vetor[limiteDireita];
            vetor[limiteDireita] = aux;

            //Faz com que os limites caminhem para o meio
            limiteEsquerda = limiteEsquerda + 1;
            limiteDireita = limiteDireita - 1;
        }
    }

    //Recursão para continuar ordenando caso necessário
    if (inicio < limiteDireita) {
        quickSort(vetor, inicio, limiteDireita);
    }

    //Recursão para continuar ordenando caso necessários
    if (limiteEsquerda < fim) {
        quickSort(vetor, limiteEsquerda, fim);
    }
}

int main() {
    //int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};
    int vetor[TAM] = {70,16,7,50,5,35,96,85,10,27};
    quickSort(vetor, 0, TAM);
    imprimeVetor(vetor);

    return 0;
}

