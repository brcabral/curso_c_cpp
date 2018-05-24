#include <stdio.h>

void main() {

    int a = 6, b = 2;

    //Soma
    printf("A soma %d + %d = %d", a, b, a + b);
    printf("\n");

    //Subtração
    printf("A subtração %d - %d = %d", a, b, a - b);
    printf("\n");

    //Multiplicação
    printf("A multiplicação %d * %d = %d", a, b, a * b);
    printf("\n");

    //Divisão
    printf("A divisão %d / %d = %d", a, b, a / b);
    printf("\n");

    int c = 7;
    //Resto da divisão
    printf("O resto da divião %d / %d = %d", c, b, c % b);
    printf("\n");

    //Valor absoluto
    printf("O valor absoluto de -3 = %d", abs(-3));
    printf("\n");

    getchar();
}
