// Faça um programa que recebe uma matriz 5x3 e informa qual é o maior
// elemento dela e sua posição.

#include <stdio.h>

int main(){
    int matriz[5][3];
    int mlinha, mcoluna;
    int i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Valor [%i][%i]:", i + 1, j + 1);
            scanf("%i", &matriz[i][j]);

            if(i == 0 && j == 0)
            {
                mlinha = i;
                mcoluna = j;
            }
            else 
            {
                if(matriz[i][j] > matriz[mlinha][mcoluna])
                {
                    mlinha = i;
                    mcoluna = j;
                }
            }
        }
    }
}