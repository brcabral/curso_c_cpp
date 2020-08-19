#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main() {
    // Usar acentos
    setlocale(LC_ALL, "");

    // Preencha uma matriz 2 x 2 lendo os valores do usuário e
    // depois troque os valores entre a primeira e a segunda linha
    int matriz[2][2], vetorAux[2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Digite da matriz na posição [%d][%d] valor: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\n");
    printf(">>> Antes da troca <<<\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("O valor da matriz na posição [%d][%d] valor é %d. ", i, j, matriz[i][j]);
            printf("\n");
        }
    }

    for (int i = 0; i <= 2; i++) {
        vetorAux[i] = matriz[0][i];
    }

    matriz[0][0] = matriz[1][0];
    matriz[0][1] = matriz[1][1];
    matriz[1][0] = vetorAux[0];
    matriz[1][1] = vetorAux[1];

    printf("\n");
    printf(">>> Depois da troca <<<\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("O valor da matriz na posição [%d][%d] valor é %d. ", i, j, matriz[i][j]);
            printf("\n");
        }
    }
}
