#include <stdio.h>

//Função que retorno um char
char retornaLetra() {
    return 'x';
}

char retornaAsci() {
    return 120;
}

int main() {

    char letra, asci;

    letra = retornaLetra();

    printf("O valor de letra: %c", letra);
    printf("\n\n");

    asci = retornaAsci();

    printf("O valor de ASCI: %c", asci);
    printf("\n");


    getchar();
    return 0;
}
