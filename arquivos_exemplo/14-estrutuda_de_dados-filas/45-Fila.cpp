#include <stdio.h>
#include <iostream>
#define TAM 10

using namespace std;

void filaConstrutor(int fila[TAM], int *primeiro, int *ultimo) {
    *primeiro = 0;
    *ultimo = -1;

    for (int i = 0; i < TAM; i++) {
        fila[i] = 0;
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

bool filaVazia(int primeiro, int ultimo) {
    if (primeiro > ultimo) {
        return true;
    } else {
        return false;
    }
}

bool filaCheia(int ultimo) {
     if (ultimo == TAM - 1) {
        return true;
     } else {
        return false;
     }
}

int filaTamanho(int ultimo, int primeiro) {
    return (ultimo - primeiro) + 1;
}

//Enqueue - Enfileirar
void filaEnfileirar(int fila[TAM], int *ultimo, int valor) {
    if (filaCheia(*ultimo)) {
        cout << "A fila já está cheia.";
        cout << "\n";
    } else {
        *ultimo = *ultimo + 1;
        fila[*ultimo] = valor;
        imprimeVetor(fila);
    }
}

void filaDesenfileirar(int fila[TAM], int *primeiro, int ultimo) {

    if (filaVazia(*primeiro, ultimo)) {
        cout << "A fila já está vazia";
        cout << "\n";
    } else {
        cout << "O valor removido foi: " << fila[*primeiro];
        cout << "\n";
        fila[*primeiro] = 0;
        *primeiro = *primeiro + 1;
        imprimeVetor(fila);
    }
}

int main() {

    int fila[TAM];
    int primeiro, ultimo;
    //int valor;

    filaConstrutor(fila, &primeiro, &ultimo);
    imprimeVetor(fila);

    filaEnfileirar(fila, &ultimo, 5);
    filaEnfileirar(fila, &ultimo, 7);
    filaEnfileirar(fila, &ultimo, 10);
    filaDesenfileirar(fila, &primeiro, ultimo);

    cout << "\n";
    cout << "A primeira posição da fila é: " << primeiro;
    cout << "\n";
    cout << "A última posição da fila é: " << ultimo;


    getchar();
    return 0;
}
