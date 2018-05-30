#include <stdio.h>
#include <fstream>

int main() {

    //Cursor que irá percorrer cada letra do arquivo
    int c;

    //Ponteiro que irá armazenar o arquivo
    FILE *file;

    //Abre o arquivo
    //O r indica o arquivo será lido (read)
    file = fopen("trabalhando-com-arquivo.txt", "r");

    //Verifica se o arquivo existe
    if (file) {
        //Percorre o arquivo até o fim
        while ((c = getc(file)) != EOF) {
            //Imprimir na tela o conteúdo do arquivo (letra por letra)
            printf("%c", c);
        }
        //Fecha o arquivo
        fclose(file);
    }

    getchar();
    return 0;
}
