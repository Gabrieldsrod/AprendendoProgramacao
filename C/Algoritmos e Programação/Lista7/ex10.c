// Receber 10 números e armazená-los em um vetor. Copiar os números
// em outro vetor na ordem inversa e mostrar na tela todas as posições em que
// se tem o mesmo número nos dois vetores.

#include <stdio.h>

int main()
{
    int vetor[10], invetor[10];
    int i;

    printf("Digite 10 numeros:\n");
    
    for (i = 0; i < 10; i++)
    {
        scanf("%i", &vetor[i]);
    }

    for (i = 0; i < 10; i++)
    {
        invetor[i] = vetor[9 - i];
    }

    printf("\nVetor original:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%i\t", vetor[i]);
    }
    printf("\n");

    printf("Vetor invertido:\n");
    for (i = 0; i < 10; i++)
    {
        printf("%i\t", invetor[i]);
    }
    printf("\n");

    printf("\nPosicoes com o mesmo numero nos dois vetores\n");
    printf("Posicoes: ");

    for (i = 0; i < 10; i++) {
        if (vetor[i] == invetor[i]) 
        {
            printf("%d ", i);
        }
    }

    return 0;
}
