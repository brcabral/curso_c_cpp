#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main() {
    // Usar acentos
    setlocale(LC_ALL, "");

    // Crie um algoritmo que leia 2 valores
    // Crie um menu (usando switch) com 4 opções
    // 1 - somar, 2 - subtrair, 3 - dividir, 4 - multiplicar
    // Depos que o usuário escolher uma opção mostre o resultado
    // da operação escolhida com os dois valores lidos.

    int num1, num2, opcao = 0;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    printf("SELECIONE UMA OPÇÃO\n");
    printf("1 - somar | 2 - subtrair | 3 - dividir | 4 - multiplicar\n");
    printf("Digite a operação desejada: ");
    scanf("%d", &opcao);

    printf("\n");
    switch(opcao) {
        case 1:
            printf("SOMA\n");
            printf("%d + %d = %d", num1, num2, (num1 + num2));
            break;
        case 2:
            printf("SUBTRAÇÃO\n");
            printf("%d - %d = %d", num1, num2, (num1 - num2));
            break;
        case 3:
            if (num2 != 0) {
                printf("DIVISÃO\n");
                float resultado = num1 / num2;
                printf("%d / %d = %.2f", num1, num2, resultado);
                break;
            } else {
                printf("O divisor não pode ser igual a zero");
                break;
            }
        case 4:
            printf("MULTIPLICAÇÃO\n");
            printf("%d * %d = %d", num1, num2, (num1 * num2));
            break;
        default :
            printf("OPÇÃO INVÁLIDA!");
            break;
    }
}
