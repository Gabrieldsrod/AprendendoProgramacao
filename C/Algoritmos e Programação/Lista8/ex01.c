// Dados dois vetores A e B, ambos com 5 elementos, determine o produto
// escalar desses vetores.

#include<stdio.h>

int main()
{
    int A[5], B[5];
    int i;
    int produto = 0;


    printf("Digite 5 valores para o vetor A:\n");
    for(i = 0;i < 5;i++)
    {
        scanf("%i", &A[i]);
    }

    printf("Digite 5 valores para o vetor B:\n");
    for(i = 0; i < 5;i++)
    {
        scanf("%i", &B[i]);
    }

    for(i = 0;i < 5;i++)
    {
        produto += A[i] * B[i];
    }

    printf("\nProduto escalar destes vetores: %i", produto);
}