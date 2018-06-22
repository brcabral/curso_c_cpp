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

void bubbleSort(int vetor[TAM]) {
    int aux;

    for (int i = 0; i < TAM; i++) {
        for (int j = i + 1; j < TAM; j++) {
            imprimeVetor(vetor);

            if (vetor[i] > vetor[j]) {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

int main() {
    int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};
    bubbleSort(vetor);
    imprimeVetor(vetor);

    return 0;
}
