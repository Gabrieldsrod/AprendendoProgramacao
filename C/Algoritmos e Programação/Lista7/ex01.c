// Receber 10 números e armazená-los em um vetor. Ao final, exibir os
// números na ordem que foram recebidos

#include <stdio.h>

int main()
{
    int i;
    int num[10];

    printf("Digite 10 numeros:\n");

    for (i = 0; i < 10; i++)
    {
        printf("%io numero:", i + 1);
        scanf("%i", &num[i]);
    }

    printf("\n");

    for (i = 0; i < 10; i++)
    {
        printf("%i\n", num[i]);
    }
}