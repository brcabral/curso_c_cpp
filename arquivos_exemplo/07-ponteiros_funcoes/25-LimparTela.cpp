#include <stdio.h>
#include <stdlib.h>

int main() {

    int a;

    printf("Digite um valor para a variável a: ");
    scanf("%d", &a);

    //Limpar a tela.
    system("clear");

    printf("O valor digitado foi: %d", a);
    printf("\n");

    getchar();
    return 0;
}

