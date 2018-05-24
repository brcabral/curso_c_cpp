#include <stdio.h>

void main() {

    int a = 1;

    //Contando até 10
    printf("Contagem progressiva.");
    printf("\n");
    while (a <= 10) {
        printf("%d", a);
        printf("\n");
        //incrementar variável
        a = a + 1;
    }

    //Contagem regressiva
    int b = 10;
    printf("\nContagem regressiva.");
    printf("\n");
    while (b >= 1) {
        printf("%d", b);
        printf("\n");
        //incrementar variável
        b--;
    }

    getchar();
}

