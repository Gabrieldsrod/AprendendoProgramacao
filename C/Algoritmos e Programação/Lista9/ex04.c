// Faça um programa que recebe uma matriz 3x3 e gera uma segunda matriz
// com o dobro de cada valor. No final, exiba a segunda matriz na tela

#include <stdio.h>

int main()
{
    int A[3][3], B[3][3];
    int i, j; 

    printf("Digite os valores da matriz:\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("VALOR [%i][%i]: ", i + 1, j + 1);
            scanf("%2i", &A[i][j]);
        }
    }

    for ( i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            B[i][j] = A[i][j] * 2;
        }
    }
    
    printf("\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("%2i", B[i][j]);
        }
        printf("\n");
    }
}