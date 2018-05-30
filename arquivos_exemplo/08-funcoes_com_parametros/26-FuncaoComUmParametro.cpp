#include <stdio.h>

void mostraSucessor(int numero) {
    printf("O sucessor de %d é %d.", numero, numero + 1);
}

int retornaAntecessor(int numero) {
    return numero - 1;
}

int main() {

    int a;

    printf("Digite um valor: ");
    scanf("%d", &a);

    mostraSucessor(a);

    printf("\n");
    printf("O antecessor de %d é %d.", a, retornaAntecessor(a));

    getchar();
    return 0;
}
