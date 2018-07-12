#include <stdio.h>
#include <iostream>
#define TAM 10

using namespace std;

void imprimeVetor(int vetor[TAM]) {
    int tamanhoLista = sizeof(vetor)/sizeof(int);

    for(int i = 0; i <= tamanhoLista; i++) {
        cout << vetor[i];
        if (i <= (tamanhoLista - 1)) {
            cout << " | ";
        }
    }
    cout << "\n";
}

void merge(int vetor[TAM], int indiceEsquerda, int meio, int indiceDireita) {
    //Calcula o tamanho dos vetores
    int n1 = meio - indiceEsquerda + 1;
    int n2 = indiceDireita - meio;

    cout << "n1: " << n1 << "\n";
    cout << "n2: " << n2 << "\n";

    //Cria os vetores temporários
    int vetorEsquerda[n1], vetorDireita[n2];

    //Preencher o vetorEsquerda com os valores do vetor principal.
    for (int i = 0; i < n1; i++) {
        vetorEsquerda[i] = vetor[indiceEsquerda + i];
    }

    cout << "Vetor esquerda:  ";
    imprimeVetor(vetorEsquerda);

    //Preencher o vetorDireita com os valores do vetor principal.
    for (int i = 0; i < n2; i++) {
        vetorDireita[i] = vetor[meio + 1 + i];
    }

    cout << "Vetor direita:  ";
    imprimeVetor(vetorDireita);

    int i, j = 0;
    int k = indiceEsquerda;

    while (i < n1 && j < n2) {
        if (vetorEsquerda[i] <= vetorDireita[j]) {
            vetor[k] = vetorEsquerda[i];
            i++;
        } else {
            vetor[k] = vetorDireita[j];
            j++;
        }
        k++;
    }

    //Se estiver faltando alguns elementos do vetorEsquerdo, colocar os elementos no vetor principal
    while (i < n1) {
        vetor[k] = vetorEsquerda[i];
        i++;
        k++;
    }

    //Se estiver faltando alguns elementos do vetorDireita, colocar os elementos no vetor principal
    while (j < n2) {
        vetor[k] = vetorDireita[j];
        j++;
        k++;
    }
}

void mergeSort(int vetor[TAM], int indiceEsquerda, int indiceDireita) {
    if (indiceEsquerda < indiceDireita) {
        int meio = indiceEsquerda + ((indiceDireita - indiceEsquerda) / 2);
        //int meio = ((indiceDireita - indiceEsquerda) / 2);

        //Do meio para trás
        mergeSort(vetor, indiceEsquerda, meio);

        //Do meio para frente
        mergeSort(vetor, (meio + 1), indiceDireita);

        imprimeVetor(vetor);

        //Junta os dois subarrays que foram criados
        merge(vetor, indiceEsquerda, meio, indiceDireita);
    }
}

int main() {
    int vetor[TAM] = {10,9,8,7,6,5,4,3,2,1};
    mergeSort(vetor, 0, (TAM - 1));
    imprimeVetor(vetor);

    return 0;
}

