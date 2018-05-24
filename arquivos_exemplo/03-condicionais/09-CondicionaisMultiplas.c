#include <stdio.h>

void main() {

    int a = 10;

    //Conectivo lógico e (and), se UMA COMPARAÇÃO for FALSA não entra no bloco
    if (a > 5 && a < 15) {
        printf("A variável a está entre 5 e 15.");
    }

    //Conectivo lógico ou (or), se UMA COMPARAÇÃO for VERDADEIRA já entra no bloco
    if (a > 5 || a > 15) {
        printf("\n");
        printf("A variável a é maior que 5 ou 15.");
    }

    //Misturando conectivos
    if ((a > 5 && a < 15) || (a == 20) ) {
        printf("\n");
        printf("A variável a está entre 5 e 15 ou é igual a 20.");
    }

    getchar();
}
