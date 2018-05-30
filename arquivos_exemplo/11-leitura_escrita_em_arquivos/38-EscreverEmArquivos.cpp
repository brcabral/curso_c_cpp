#include <stdio.h>
#include <fstream>

using namespace std;

int main() {

    //Cria o objeto do arquivo
    ofstream arquivo;

    //Abre o arquivo ou cria caso não exista
    arquivo.open("trabalhando-com-arquivo.txt", ios_base::app);

    //Escreve no arquivo
    arquivo << "Uni e Gracinha\n";

    //Fecha o arquivo
    arquivo.close();

    getchar();
    return 0;
}
