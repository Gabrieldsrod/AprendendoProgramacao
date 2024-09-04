// Leia duas matrizes 4x4 e escreva uma terceira com os maiores elementos
// de cada posição.

#include <stdio.h>

int main()
{
    int A[4][4], B[4][4], C[4][4];
    int i, j;

    printf("Digite os valores da Matriz A 4x4:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Elemento [%i][%i]: ", i + 1, j + 1);
            scanf("%i", &A[i][j]);
        }
    }

    printf("\nDigite os valores da Matriz B 4x4:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Elemento [%i][%i]: ", i + 1, j + 1);
            scanf("%i", &B[i][j]);
        }
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (A[i][j] > B[i][j])
            {
                C[i][j] = A[i][j];
            }
            else if (A[i][j] < B[i][j])
            {
                C[i][j] = B[i][j];
            }
            else if (A[i][j] == B[i][j])
            {
                C[i][j] = A[i][j];
            }
        }
    }

    printf("\nMatriz A:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5i", A[i][j]);
        }
        printf("\n");
    }
    printf("Matriz B:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5i", B[i][j]);
        }
        printf("\n");
    }
    printf("\nMatriz C:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5i", C[i][j]);
        }
        printf("\n");
    }
}