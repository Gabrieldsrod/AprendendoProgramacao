// Faça um programa que recebe uma matriz 3x4 e mostra a soma dos seus
// elementos

#include<stdio.h>

int main()
{
    int matriz[3][4];
    int i, j, soma = 0;


    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Valor [%i][%i]:", i + 1, j + 1);
            scanf("%i", &matriz[i][j]);
        }
    }

    printf("\n");

    for (i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            soma += matriz[i][j];
        }
    }

    printf("A soma de todos os valores da matriz resulta em: %i", soma);
}