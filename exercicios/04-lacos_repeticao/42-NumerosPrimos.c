#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

void main() {
    // Usar acentos
    setlocale(LC_ALL, "");

    // Crie um algoritmo que se o valor lido é primo ou não.
    int i = 10;
    bool isPrimo = false;

    printf("Numeros primos de 2 à 100.\n");
    for (i = 2; i <= 100; i++) {
        isPrimo = true;
        for (int j = 2; j <= i; j++) {
            if (i != j && i % j == 0) {
                isPrimo = false;
            }
        }

        if (isPrimo) {
            printf("O número %d é primo. \n", i);
        }
    }

}
