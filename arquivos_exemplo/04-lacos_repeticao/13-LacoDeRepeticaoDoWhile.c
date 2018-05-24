#include <stdio.h>

void main() {

    int a = 1;

    //Contando até 10
    printf("Contagem progressiva.");
    printf("\n");
    do {
        printf("%d", a);
        printf("\n");
        //incrementar variável
        a++;
    } while (a <= 10);

    //Contagem regressiva
    int b = 10;
    printf("\nContagem regressiva.");
    printf("\n");
    do {
        printf("%d", b);
        printf("\n");
        //incrementar variável
        b = b - 1;
    } while (b >= 1);

    getchar();
}

