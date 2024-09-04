// Permita ao usuário digitar quantas linhas e quantas colunas ele quer
// preencher uma matriz de números inteiros. A matriz não deverá
// ultrapassar 10 linhas e 10 colunas. Obtenha e mostre um vetor que seja a
// soma dos elementos de cada uma das colunas preenchidas da matriz.

#include<stdio.h>

int main(){
    int linhas, colunas;
    
    do
    {
        printf("Quantas linhas e colunas a matriz deve ter?\n(Limite de 10 linhas e 10 colunas)\n");
        scanf("%i %i", &linhas, &colunas);

        if (linhas < 1 || linhas > 10) {
            printf("Quantidade de linhas invalida, digite um valor entre 1 e 10...\n");
        }

        if (colunas < 1 || colunas > 10) {
            printf("Quantidade de colunas invalida, digite um valor entre 1 e 10...\n");
        }
    } while (linhas < 1 || linhas > 10 || colunas < 1 || colunas > 10);
    
    int matriz[linhas][colunas];
    int i, j;
    int somacolunas[colunas];

    for (j = 0; j < colunas; j++) {
        somacolunas[j] = 0;
    }

    printf("Digite os elementos da matriz %ix%i:\n", linhas, colunas);
    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            printf("Valor de [%i][%i]: ", i + 1, j + 1);
            scanf("%i", &matriz[i][j]);
            somacolunas[j] += matriz[i][j];
        }
    }

    printf("\nMatriz:\n");
    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            printf("%5i", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nVetor com a soma das colunas:\n");
    for ( j = 0; j < colunas; j++)
    {
        printf("%5i", somacolunas[j]);
    }
}