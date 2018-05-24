#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main() {

    //vetor = [0][1][2]

    //matriz = [0,0][0,1]
    //         [1,0][1,1]

    //Definir uma matriz
    int matriz[2][2];

    //Passar valores para a matriz
    matriz[0][0] = 1;
    matriz[0][1] = 2;
    matriz[1][0] = 3;
    matriz[1][1] = 4;

    //Imprimir valores da matriz
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "Matriz [" << i << ", " << j << "] = " << matriz[i][j];
            cout << "\n";
        }
    }

    cout << "\n";

    //Popular o vetor em um laço de repetição
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "Digite o valor da matriz na posição [" << i << ", [" << j << "]: ";
            //Ler um valor inserida pelo usuário
            cin >> matriz[i][j];
        }
    }

    cout << "\n";

    //Imprimir valores da matriz
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "Matriz [" << i << ", " << j << "] = " << matriz[i][j];
            cout << "\n";
        }
    }

    getchar();
    return 0;
}

