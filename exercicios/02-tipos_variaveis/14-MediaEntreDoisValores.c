#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main() {
    // Para usar acentos
    setlocale(LC_ALL, "");

    // Crie um algoritmo que leia 2 notas e mostre a média entre elas.
    float nota1, nota2, media = 0;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    media = ((nota1 + nota2) / 2);
    printf("A média das notas é %.2f", media);
}
