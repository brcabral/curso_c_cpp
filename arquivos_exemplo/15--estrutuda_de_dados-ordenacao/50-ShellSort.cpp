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

void shellSort(int vetor[TAM]) {
    int j, atual;
    int h = 1;

    //Qual será a distância dos valores analisados
    while (h < TAM) {
        h = ((3 * h) + 1);
    }

    while (h > 1) {
        //Reduz a distância dos valores analisados
        h = h / 3;

        for (int i = h; i < TAM; i++) {
            atual = vetor[i];
            j = i - h;

            imprimeVetor(vetor);

            //Analisando os números anteriores
            while ((j >= 0) && (atual < vetor[j])) {
                //Posiciona os elementos para frente
                vetor[j + h] = vetor[j];
                j = j - h;
            }

            //Inserir o elemento na posição i (menor número) na posição correta
            vetor[j + h] = atual;
        }

    }
}

int main() {
    int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};
    shellSort(vetor);
    imprimeVetor(vetor);

    return 0;
}

