#include <stdio.h>
#include <string>
#include <iostream>

//Indica que o pacote std será usado em todo o escopo da classe.
//Isso evita duplicidade com outras implementações com nomes semelhantes.
//Além de facilitar o uso de uma classe ou funções.
using namespace std;

int main() {

    //Definindo uma variável string
    string palavra;

    //Imprimir na tela
    cout << "Digite uma palavra: ";

    //Ler a string
    cin >> palavra;

    //Imprimir na tela concatenando strings
    cout << "A palavra digita é: " << palavra;

    getchar();
    return 0;
}
