#include <stdio.h>

int main() {

    int i, j;
    int linhas;
    int colunas;
    int **matriz;

    printf("Digite a quantidade de linhas da matriz: ");
    scanf("%d", &linhas);

    printf("Digite a quantidade de colunas da matriz: ");
    scanf("%d", &colunas);

    //Alocando memória para as linhass
    matriz = (int**) malloc(linhas * sizeof(int*));

    //Alocando memória para as colunas de cada linhas
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*) malloc(colunas * sizeof(int));
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = i + j;
            //printf("O valor da matriz[%d,%d] = %d", i, j, matriz[i][j]);
            //printf("\n");
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    free(matriz);

    getchar();
    return 0;
}
