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

    //Criando um ponteiro para o struct
    Fruta *primeiraFruta = new Fruta;

    //Modificando os campos do struct
    primeiraFruta->nome = "banana";
    primeiraFruta->cor = "amarela";

    //Imprimir os valores do struct
    cout << "Fruta: " << primeiraFruta->nome << ", cor: " << primeiraFruta->cor;

    getchar();
    return 0;
}
