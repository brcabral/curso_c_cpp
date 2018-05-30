#include <stdio.h>

//Função sem retorno que desenha a borda
void desenhaBorda() {
    printf("|-----------------|");
    printf("\n");
}

int main() {
    //Chamando a função.
    desenhaBorda();

    printf("hello world!");
    printf("\n");

    desenhaBorda();

    getchar();
    return 0;
}
