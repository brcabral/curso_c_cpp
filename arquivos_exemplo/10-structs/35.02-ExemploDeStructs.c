#include <stdio.h>
#include <string.h>

struct palavra {
    int ordem;
    char letra;
    char texto[255];
};


int main() {

    //Criando uma lista de struct
    struct palavra listaDePalavras[3];

    //Modificando os campos da lista do struct
    listaDePalavras[0].ordem = 0;
    listaDePalavras[0].letra = 'd';
    strcpy(listaDePalavras[0].texto, "dahora");

    listaDePalavras[1].ordem = 1;
    listaDePalavras[1].letra = 'l';
    strcpy(listaDePalavras[1].texto, "legal");

    listaDePalavras[2].ordem = 2;
    listaDePalavras[2].letra = 'b';
    strcpy(listaDePalavras[2].texto, "bacana");

    //Imprimir a lista de valores do struct
    for (int i = 0; i < 3; i++) {
        printf("Ordem: %d, primeira letra: %c e palavra: %s", listaDePalavras[i].ordem, listaDePalavras[i].letra, listaDePalavras[i].texto);
        printf("\n");
    }

    getchar();
    return 0;
}
