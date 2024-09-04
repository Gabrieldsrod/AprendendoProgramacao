// Receber 10 números e armazená-los em um vetor. Ao final, exibir os
// números na ordem inversa da que foram recebidos.

#include <stdio.h>

int main()
{
    int num[10];

    printf("Digite 10 numeros:\n");

    for (int i = 0; i < 10; i++)
    {
        scanf("%i", &num[i]);
    }

    printf("\nNumeros em ordem inversa:\n");

    for (int i = 10 - 1; i >= 0 ; i--)
    {
        printf("%i\n", num[i]);
    }
}