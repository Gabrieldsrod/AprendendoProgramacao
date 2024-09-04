// Leia 10 números inteiros e armazene em um vetor A. Crie dois novos
// vetores A1 e A2. Copie os valores ímpares de A para A1, e os valores
// pares de A para A2. Note que cada um dos vetores A1 e A2 tem no
// máximo 10 elementos, mas nem todos os elementos são utilizados. No
// final escreva os elementos utilizados de A1 e A2.

#include <stdio.h>

int main()
{
    int A[10], A1[10], A2[10];
    int i, j1 = 0, j2 = 0;

    printf("Digite 10 valores:\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%i", &A[i]);
    }

    //A1 e A2
    for (i = 0; i < 10; i++)
    {
        if(A[i] % 2 == 0)
        {
            A2[j2++] = A[i];
        }
        else
        {
            A1[j1++] = A[i];
        }
    }

    printf("A1: ");
    for ( i = 0; i < j1; i++)
    {
        printf("%i ", A1[i]);
    }
    printf("\n");

    printf("A2: ");
    for ( i = 0; i < j2; i++)
    {
        printf("%i ", A2[i]);
    }
}