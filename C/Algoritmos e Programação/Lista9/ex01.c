// Faça um programa que recebe uma matriz 4x3 e mostre a matriz na tela
// em formato de tabela.

#include<stdio.h>

int main()
{
    int matriz[4][3];


    for (int linha = 0; linha < 4; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            printf("Valor [%i][%i]:", linha + 1, coluna + 1);
            scanf("%i", &matriz[linha][coluna]);
        }
    }

    printf("\n");

    for (int linha = 0; linha < 4; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            printf("%4i ", matriz[linha][coluna]);
        }
        printf("\n");
    }
}