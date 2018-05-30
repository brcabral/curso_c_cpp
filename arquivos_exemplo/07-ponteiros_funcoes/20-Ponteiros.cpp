#include <stdio.h>

int main() {

    //Variável
    int a = 20;

    //Imprimindo o valor de uma variável
    printf("O valor de a: %d", a);
    printf("\n");

    //Imprimindo o endereço de uma variável
    printf("O endereço de memória de a: %d", &a);
    printf("\n");

    //Lendo o valor de uma variável
    printf("Digite um valor para a variável a: ");
    //O & busca o endereço de memória de uma variável
    scanf("%d", &a);

    //Imprimindo o valor de uma variável
    printf("O valor de a: %d", a);
    printf("\n");

    //Imprimindo o endereço de uma variável
    printf("O endereço de memória de a: %d", &a);
    printf("\n\n");

    //VARIÁVEIS ARMAZENAM VALORES
    int b = 10;

    //PONTEIROS ARMAZENAM POSIÇÕES DA MEMÓRIA
    int *pont;   //O * define um ponteiro

    //PONTEIRO RECEBENDO A POSIÇÃO NA MEMÓRIA DA VARIÁVEL b
    pont = &b;

    //Imprimindo o valor de uma variável
    printf("O valor de b: %d", b);
    printf("\n");

    //O * pode ser lido como "CONTEÚDO APONTADO POR"
    *pont = 40;

    //Imprimindo o valor de uma variável
    printf("O valor de b: %d", b);
    printf("\n\n");

    /*
    VARIÁVEL possui
    [VALOR ARMAZENADO]
    [POSIÇÃO NA MEMÓRIA]

    PONTEIRO possui
    [POSIÇÃO DA VARIÁVEL NA MEMÓRIA]
    [POSIÇÃO NA MEMÓRIA]

    O ponteiro serve para você ter acesso direto a memória do seu programa.
    */


    getchar();
    return 0;
}
