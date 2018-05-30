#include <stdio.h>

int retornaComMaisDez(int numero) {
    return numero + 10;
}

void aumentaDez(int *numero) {
    *numero = *numero + 10;
}

int main() {

    int a = 7;

    printf("O valor de a: %d", a);
    printf("\n");

    a = retornaComMaisDez(a);

    printf("O valor de a: %d", a);
    printf("\n");

    aumentaDez(&a);

    printf("O valor de a: %d", a);
    printf("\n");

    getchar();
    return 0;
}

