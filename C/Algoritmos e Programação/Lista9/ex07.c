// Faça um programa que leia uma matriz 3x5 de inteiros, substitua seus
// elementos negativos por 0 e imprima a matriz original e a modificada. A
// seguir deverão ser mostrados os valores da soma dos elementos de cada
// coluna da matriz modificada.

#include<stdio.h>

int main()
{
    int original[3][5], modificada[3][5];
    int i, j;
    int somacolunas[5] = {0, 0, 0, 0, 0};

    printf("Digite os valores da matriz 3x5:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("Elemento [%i][%i]: ", i + 1, j + 1);
            scanf("%i", &original[i][j]);
        }
    }
    printf("\nMatriz Original:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%5i", original[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (original[i][j] < 0)
            {
                original[i][j] = 0;
            }
            modificada[i][j] = original[i][j];
            somacolunas[j] += modificada[i][j];
        }
    }
    printf("\nMatriz Modificada:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%5i", modificada[i][j]);
        }
        printf("\n");
    }

    printf("\nSoma dos elementos de cada coluna na matriz modificada:\n");
    for (j = 0; j < 5; j++) 
    {
        printf("Coluna %d: %d\n", j + 1, somacolunas[j]);
    }
}