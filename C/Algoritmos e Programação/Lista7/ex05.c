// Receber 12 números e armazená-los em um vetor. Ao final, exibir quais
// foram os números positivos informados.

#include <stdio.h>

int main()
{
    int num[12];

    printf("Digite 12 numeros:\n");

    for (int i = 0; i < 12; i++)
    {
        scanf("%i", &num[i]);
    }

    printf("\nNumeros positivos identificados:\n");
    
    for (int i = 0; i < 12; i++)
    {
        if (num[i] > 0)
        printf("%i\n", num[i]);
    }
}