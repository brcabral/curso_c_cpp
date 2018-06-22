#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define TAM 10

using namespace std;

//Cria uma pilha e limpa ela
void pilhaConstrutor(int pilha[TAM], int *topo) {
    //O valor negativo indica que a pilha está vazia.
    *topo = -1;

    //Configura todos os valores da pilha igual zero
    for (int i = 0; i < TAM; i++) {
        pilha[i] = 0;
    }
}

void imprimeVetor(int vetor[TAM]) {
    for(int i = 0; i < TAM; i++) {
        cout << vetor[i];
        if (i < (TAM - 1)) {
            cout << " - ";
        }
    }
    cout << "\n";
}

bool pilhaVazia(int topo) {
    if (topo == -1) {
        return true;
    } else {
        return false;
    }
}

bool pilhaCheia(int topo) {
    if (topo == TAM - 1) {
        return true;
    } else {
        return false;
    }
}

int pilhaTamanho(int topo) {
    return topo + 1;
}

int pilhaGet(int pilha[TAM], int *topo) {
    if (pilhaVazia(*topo)) {
        cout << "A pilha já está vazia";
        cout << "\n";
        return 0;
    } else {
        return pilha[*topo];
    }
}

int gerarValor() {
    srand((unsigned)time(NULL));
    return (rand() % 100) + 1;
}

//Adiciona um valor na pilha
void pilhaPush(int pilha[TAM], int *topo, int valor) {
    //Verifica se a pilha já está cheia
    if (pilhaCheia(*topo)) {
        cout << "A pilha já está cheia.";
        cout << "\n";
    } else {
        *topo = *topo + 1;
        pilha[*topo] = valor;
        imprimeVetor(pilha);
    }
}

//Remove um valor na pilha
void pilhaPop(int pilha[TAM], int *topo) {
    if (pilhaVazia(*topo)) {
        cout << "A pilha já está vazia";
        cout << "\n";
    } else {
        cout << "O valor removido foi: " << pilha[*topo];
        cout << "\n";
        pilha[*topo] = 0;
        *topo = *topo - 1;
        imprimeVetor(pilha);
    }
}

int main() {

    int pilha[TAM];
    int topo;

    pilhaConstrutor(pilha, &topo);
    imprimeVetor(pilha);

    pilhaPush(pilha, &topo, 5);
    pilhaPush(pilha, &topo, 7);

    cout << "O último valor da pilha é: " << pilhaGet(pilha, &topo);
    cout << "\n";
    cout << "O tamanho da pilha é: " << pilhaTamanho(topo);
    cout << "\n";

    pilhaPop(pilha, &topo);

    getchar();
    return 0;
}
