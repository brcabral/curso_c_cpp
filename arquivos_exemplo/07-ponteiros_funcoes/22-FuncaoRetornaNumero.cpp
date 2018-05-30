#include <stdio.h>

//Definindo que a função existe
int retornoDez();
float valorDecimal();

int main() {

    int a;

    //Passando o retorno da função para uma variável
    a = retornoDez();

    printf("O valor de a: %d", a);
    printf("\n\n");


    float b;

    //Passando o retorno da função para uma variável
    b = valorDecimal();

    printf("O valor de b: %.1f", b);
    printf("\n");


    getchar();
    return 0;
}

//Função que retorno um inteiro (10)
int retornoDez() {
    return 10;
}

//Função que retorno um decimal
float valorDecimal() {
    float num = 5.5;
    return num;
}
