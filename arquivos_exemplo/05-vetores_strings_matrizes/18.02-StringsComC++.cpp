#include <stdio.h>
#include <string>
#include <iostream>


int main() {

    std::string palavra;

    printf("Digite uma palavra: ");

    //Ler a string
    std::cin >> palavra;

    //Imprimir na tela
    std::cout << "A palavra digita é: " << palavra;

    getchar();
    return 0;
}
