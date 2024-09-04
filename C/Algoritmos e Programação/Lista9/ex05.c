// Faça um programa que recebe uma matriz 4x4 e realiza as seguintes
// operações:
// * Exibir a soma dos elementos da diagonal principal.
// * Colocar os elementos da diagonal principal em um vetor (uma dimensão).
// * Exibir o vetor.

#include<stdio.h>

int main()
{
    int matriz[4][4];
    int vetor[4];
    int i, j;
    int soma = 0;

    printf("Digite os valores da matriz 4x4:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Elemento [%i][%i]: ", i + 1, j + 1);
            scanf("%i", &matriz[i][j]);
        }
    }
    
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (i == j)
            {
                soma += matriz[i][j];
                vetor[i] = matriz[i][j];
            }
        }
    }
    printf("\n");

    printf("Matriz:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5i", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Soma dos numeros da diagonal principal: %i\n", soma);
    printf("Vetor dos numeros da diagonal principal:\n");
    for (i = 0; i < 4; i++)
    {
        printf("%5i", vetor[i]);
    }
}