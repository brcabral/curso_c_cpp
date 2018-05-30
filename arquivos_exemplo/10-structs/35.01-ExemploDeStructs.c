#include <stdio.h>
#include <string.h>

struct palavra {
    int ordem;
    char letra;
    char texto[255];
};


int main() {

    //Criar um struct do tipo palavra
    struct palavra primeiraPalavra;

    //Modificando os campos do struct
    primeiraPalavra.ordem = 10;
    primeiraPalavra.letra = 'p';
    strcpy(primeiraPalavra.texto, "palavrinha");

    //Imprimir os valores do struct
    printf("Ordem: %d, primeira letra: %c e palavra: %s", primeiraPalavra.ordem, primeiraPalavra.letra, primeiraPalavra.texto);

    getchar();
    return 0;
}
