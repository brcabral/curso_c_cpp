#include <fstream>
#include <iostream>

using namespace std;

int main() {

    //Carrega o arquivo
    ifstream input("trabalhando-com-arquivo.txt");

    //String que receberá o conteúdo do arquivo
    string textoArquivo;

    //Percorre o arquivo lendo linha por linha
    for (string linha; getline(input, linha);) {
        textoArquivo += linha;
        textoArquivo += "\n";
    }

    //Exibir o conteúdo do arquivo
    cout << textoArquivo;

    getchar();
    return 0;
}
