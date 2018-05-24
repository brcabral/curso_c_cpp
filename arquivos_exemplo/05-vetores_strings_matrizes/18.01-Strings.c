#include <stdio.h>

void main() {

    //Declarar uma string
    char palavra[10];

    printf("Digite uma palavra: ");  //Não obrigatório

    //Limpar o buffer
    setbuf(stdin, 0);

    //Ler a string
    fgets(palavra, 10, stdin);

    //[t][e][s][t][e][ ][ ][ ][ ][ \0]
    // \0 - Indica a última posição do vetor

    //Limpa as casas não utilizadas
    palavra[strlen(palavra) - 1] = '\0';

    //Imprimir na tela
    printf("A palavra digitada é: %s", palavra);

    getchar();
}
