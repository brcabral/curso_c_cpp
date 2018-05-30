#include <stdio.h>
#include <string>
#include <iostream>
#include <new>

using namespace std;

struct Fruta {
    string nome;
    string cor;
};

int main() {

    //Criando uma lista de struct
    Fruta *listaDeFrutas = new Fruta[2];

    //Modificando os campos da lista do struct
    listaDeFrutas[0].nome = "morango";
    listaDeFrutas[0].cor = "vermelho";

    listaDeFrutas[1].nome = "kiwi";
    listaDeFrutas[1].cor = "verde";

    //Imprimir a lista de valores do struct
    for (int i = 0; i < 2; i++) {
        cout << "Fruta: " << listaDeFrutas[i].nome << ", cor: " << listaDeFrutas[i].cor;
        printf("\n");
    }

    getchar();
    return 0;
}
