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

void insertionSort(int vetor[TAM]) {
    int j, atual;

    for (int i = 1; i < TAM; i++) {
        atual = vetor[i];
        j = i - 1;

        imprimeVetor(vetor);

        //Analisando os números anteriores
        while ((j >= 0) && (atual < vetor[j])) {
            //Posiciona os elementos para frente
            vetor[j + 1] = vetor[j];
            j--;
        }

        //Inserir o elemento na posição i (menor número) na posição correta
        vetor[j + 1] = atual;
    }
}


int main() {
    int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};
    insertionSort(vetor);
    imprimeVetor(vetor);

    return 0;
}
