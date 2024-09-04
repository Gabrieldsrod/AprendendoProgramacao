// Receber 8 números e armazená-los em um vetor. Ao final, pedir para o
// usuário escolher uma posição do vetor e exibir o número contido nela.

#include <stdio.h>

int main ()
{
    int num[8];
    int posicao;

    printf("Digite 8 numeros:\n");

    for (int i = 0; i < 8; i++)
    {
        printf("NUMERO %i: ", i + 1);
        scanf("%i", &num[i]);
    }

    

    do
    {
        printf("Digite a posicao de 1 a 8 para exibir o numero contido no vetor: ");
        scanf("%i", &posicao);

        if (posicao < 1 || posicao > 8)
        {
        printf("Posicao invalida!\n");
        }
        else
        {
            printf("Numero da posicao %i: %i", posicao, num[posicao - 1]);
        }
    }while (posicao < 1 || posicao > 8);
}