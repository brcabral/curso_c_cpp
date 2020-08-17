#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main() {
    // Para usar acentos
    setlocale(LC_ALL, "");

    // Crie um algoritmo que leia 3 números inteiros em uma mesma linha
    // Depois coloque o resultado da multiplicacao em uma variável
    // Em seguida exiba essa variável
    int nro1, nro2, nro3, produto = 0;

    printf("Digite 3 números: ");
    scanf("%d %d %d", &nro1, &nro2, &nro3);

    produto = nro1 * nro2 * nro3;
    printf("O produto dos 3 números é %d", produto);
}
