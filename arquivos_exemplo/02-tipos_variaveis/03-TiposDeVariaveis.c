#include <stdio.h>
//Importar pacote para variável booleana
#include <stdbool.h>

void main() {

    //Definir as variáveis
    int a;
    float b;
    char c;  //Suporta apenas um caractere
    bool d;

    //Atribuir valores para as variáveis
    a = 5;
    b = 2.3;
    c = 'a';  // Aspas simples
    d = true;  //true = 1; false = 0

    //Imprimindo o valor da variável
    printf("O valor de a = %d", a);
    printf("\n");
    printf("O valor de b = %.2f", b);  //.2 --> Indica a quantidade de casas decimais
    printf("\n");
    printf("O valor de c = %c", c);
    printf("\n");
    printf("O valor de d = %d", d);

    printf("\n");
    printf("\n");

    printf("Digite um valor inteiro: ");
    //Ler um valor inserida pelo usuário
    scanf("%d", &a);

    printf("Digite um valor float: ");
    scanf("%f", &b);

    printf("Digite um caractere: ");
    scanf(" %c", &c);  //Inserir um espaço antes do porcentagem

    printf("Digite um valor booleano: ");
    scanf("%d", &d);


    printf("\n");
    printf("O valor de a = %d", a);
    printf("\n");
    printf("O valor de b = %.3f", b);
    printf("\n");
    printf("O valor de c = %c", c);
    printf("\n");
    printf("O valor de d = %d", d);

    printf("\n");
    getchar();
}
