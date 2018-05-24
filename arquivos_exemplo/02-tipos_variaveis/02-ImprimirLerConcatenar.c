#include <stdio.h>

void main() {

    //Definir variável do tipo inteiro. a = 3 e b sem valor
    int a = 3, c;

    //Imprimir uma variável inteira.
    printf("%d", a);

    //Pula linha
    printf("\n");

    //Imprimir uma variável inteira concatenada com um texto
    printf("O valor da variável a é: %d", a);

    printf("\n");

    a = 5;
    printf("O valor da variável a é: %d", a);

    int b = 7;

    printf("\n");

    //Imprimir mais de uma variável inteira concatenada com um texto.
    printf("O valor da variável a e da variável b é: %d %d", a, b);

    printf("\n");

    printf("Digite um valor inteiro: ");
    //Ler uma variável inteira inserida pelo usuário
    //& - Indica que o compilador irá acessar uma parte da memória do computador (onde está a variável c)
    scanf("%d", &c);

    printf("O valor da variável c é: %d", c);

    printf("\n");

    printf("Imprimir, ler e concatenar variáveis inteira.");
    getchar();
}
