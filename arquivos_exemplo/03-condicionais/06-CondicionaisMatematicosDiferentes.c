#include <stdio.h>

void main() {

    int a = 5;
    int b = 10;
    int c = 15;

    //Maior
    if (a > 2) {
        printf("%d é maior que 2.", a);
    }

    //Maior ou igual
    if (c >= b) {
        printf("\n");
        printf("%d é maior ou igual que %d.", c, b);
    }

    //Menor
    if (a < 10) {
        printf("\n");
        printf("%d é menor que 10.", a);
    }

    //Menor ou igual
    if (a <= 10) {
        printf("\n");
        printf("%d é menor ou igual que 10.", a);
    }

    //Diferente
    if (a != c) {
        printf("\n");
        printf("%d é diferente de %d.", a, c);
    }


    getchar();
}
