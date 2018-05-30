#include <stdio.h>
#include <fstream>

using namespace std;

int main() {
    ofstream meuArquivo;

    meuArquivo.open("limpando-arquivo.txt");

    meuArquivo << "";

    meuArquivo.close();

    getchar();
    return 0;
}
