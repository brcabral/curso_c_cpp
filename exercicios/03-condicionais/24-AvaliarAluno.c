#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main() {
    // Usar acentos
    setlocale(LC_ALL, "");

    // Crie um algoritmo que leia 3 notas e calcule a média entre elas.
    // Se o valor for maior que 7 informe que o aluno foi aprovado,
    // senão foi reprovado

    float nota1, nota2, nota3, media = 0;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    media = ((nota1 + nota2 + nota3) / 3);

    if (media > 7) {
        printf("O aluno foi aprovado com média %.2f", media);
    } else {
        printf("O aluno foi reprovado com média %.2f", media);
    }
}
