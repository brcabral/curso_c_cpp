#include <stdio.h>

void mostraSoma(int primeiroNumero, int segundoNumero) {
    printf("A soma de %d e %d é %d", primeiroNumero, segundoNumero, (primeiroNumero + segundoNumero));
    printf("\n");
}

int retornaSoma(int primeiroNumero, int segundoNumero) {
    return primeiroNumero + segundoNumero;
}

int main() {

    int a = 5, b = 7;

    mostraSoma(a, b);

    printf("A soma de %d e %d é %d", a, b, retornaSoma(a, b));

    getchar();
    return 0;
}
