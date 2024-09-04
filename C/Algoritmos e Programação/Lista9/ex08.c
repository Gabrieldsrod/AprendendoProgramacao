// Define-se como elemento minimax de uma matriz o menor elemento da
// linha onde se encontra o maior elemento da matriz. Faça um programa que
// recebe uma matriz 4x4 e mostra qual é seu elemento minimax, bem como
// sua posição na matriz.
#include <stdio.h>

int main()
{
    int matriz[4][4];
    int i, j;
    int maior, linham, colunam;
    int minimax, colunaminimax;

    printf("Digite os elementos da matriz 4x4:\n");
    for (i = 0; i < 4; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            printf("Valor[%i][%i]: ", i + 1, j + 1);
            scanf("%i", &matriz[i][j]);
        }
    }

    maior = matriz[0][0];
    linham = 0;
    colunam = 0;
    for (i = 0; i < 4; i++)
    {
        for ( j = 0; j < 4; j++)
        {
            if (matriz[i][j] > maior)
            {
                maior = matriz[i][j];
                linham = i;
                colunam = j;
            }
        }
    }

    minimax = matriz[linham][0];
    colunaminimax = 0;
    for (j = 1;j < 4; j++)
    {
        if (matriz[linham][j] < minimax)
        {
            minimax = matriz[linham][j];
            colunaminimax = j;
        }
    }

    printf("\nElemento minimax: %i\n", minimax);
    printf("Posicao [%i][%i]", linham + 1, colunaminimax + 1);
}

