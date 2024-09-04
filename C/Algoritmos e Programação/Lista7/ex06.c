// Receber 12 números e armazená-los em um vetor. Ao final, exibir a
// quantidade de números negativos informados.

#include <stdio.h>

int main()
{
    int num[12], neg = 0;

    printf("Digite 12 numeros:\n");

    for (int i = 0; i < 12; i++)
    {
        scanf("%i", &num[i]);
    }

    for (int i = 0; i < 12; i++)
    {
        if (num[i] < 0)
        {
            neg++;
        }
    }
    
    printf("Quantidade de numeros negativos: %i", neg);
}




