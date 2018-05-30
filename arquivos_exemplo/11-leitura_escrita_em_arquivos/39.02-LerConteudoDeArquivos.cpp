#include <stdio.h>
#include <fstream>
#include <string.h>

int main() {

    //Cursor que irá percorrer cada letra do arquivo
    int c;
    char conteudoTexto[255];
    int i = 0;

    //Ponteiro que irá armazenar o arquivo
    FILE *file;

    //Abre o arquivo
    //O r indica o arquivo será lido (read)
    file = fopen("trabalhando-com-arquivo.txt", "r");

    //Verifica se o arquivo existe
    if (file) {
        //Percorre o arquivo até o fim
        while ((c = getc(file)) != EOF) {
            //Vetor de char recebe um caracter
            conteudoTexto[i] = c;

            //Incrementa o indíce da letra no vetor
            i++;
        }
        //Fecha o arquivo
        fclose(file);
    }

    //Imprimindo o conteúdo lido
    for (i = 0; i < strlen(conteudoTexto) - 1; i++) {
        printf("%c", conteudoTexto[i]);
    }

    getchar();
    return 0;
}
