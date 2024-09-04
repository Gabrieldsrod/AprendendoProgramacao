// Faça um programa que recebe uma matriz 3x4 e mostra a média dos
// elementos de uma linha escolhida pelo usuário

#include <stdio.h>

int main()
{
    int matriz[3][4];
    int i, j;
    int linha;
    float soma, media;

    printf("Digite os valores da matriz 3x4:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Valor [%i][%i]: ", i + 1, j + 1);
            scanf("%i", &matriz[i][j]);
        }
    }

    printf("\nMatriz:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5i", matriz[i][j]);
        }
        printf("\n");
    }

    do
    {
        printf("Escolha uma linha da matriz para realizar a media de seus valores:\n[1] ou [2] ou [3]\n");
        scanf("%i", &linha);

        if (linha < 1 || linha > 3)
        {
            printf("Linha inválida!!!\n");
            continue;
        }

        soma = 0;
        for (j = 0; j < 4; j++)
        {
            soma += matriz[linha - 1][j];
        }
        media = soma / 4;
        break;

    } while (linha < 1 || linha > 3);

    printf("Media dos valores da linha %i: %.2f\n", linha, media);
}