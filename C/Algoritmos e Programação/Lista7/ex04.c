// Receber 15 números e armazená-los em um vetor. Ao final, exibir o dobro
// de cada um dos números.

#include <stdio.h>

int main()
{
    int num[15];

    printf("Digite 15 numeros\n");

    for (int i = 0; i < 15; i++)
    {
        printf("NUMERO %i: ", i + 1);
        scanf("%i", &num[i]);
    }

    printf("\n");

    for (int i = 0; i < 15; i++)
    {
        printf("DOBRO DO %io: %i\n",i + 1, num[i] * 2);
    }
}