#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main() {
    // Usar acentos
    setlocale(LC_ALL, "");

    // Crie um algoritmo que leia 3 valores e informe se eles são
    // iguais entre si para formarem os lados de um triângulo equilátero.

    int lado1, lado2, lado3 = 0;

    printf("Digite o primeiro lado: ");
    scanf("%d", &lado1);

    printf("Digite o segundo lado: ");
    scanf("%d", &lado2);

    printf("Digite o terceiro lado: ");
    scanf("%d", &lado3);

    if (lado1 == lado2 && lado2 == lado3) {
        printf("Os lados são iguais, portanto o triângulo é equilátero");
    } else {
        printf("Os lados são diferente, portanto o triângulo não é equilátero");
    }
}
