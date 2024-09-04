// Receber 10 números e armazená-los em um vetor. Após esta primeira
// etapa é necessário pedir para o usuário digitar um número. Verificar se este
// número está armazenado no vetor e se estiver mostrar quantas vezes o
// número esta armazenado no vetor, ou seja, quantas vezes o número se
// repete. Se o número não estiver no vetor, uma mensagem deve indicar esta
// condição e deverá ser solicitado um novo número para o usuário.

#include <stdio.h>

int main()
{
    int vetor[10];
    int num, i, cont = 0;

    printf("Digite 10 numeros:\n");

    for (i = 0; i < 10; i++)
    {
        scanf("%i", &vetor[i]);
    }

    do
    {
        printf("\nDigite um numero para verificar se ele se encontra no vetor: ");
        scanf("%i", &num);

        for (i = 0;i < 10; i++)
        {
            if(vetor[i] == num)
            {
                cont++;
            }
        }

        if (cont > 0)
        {
            printf("O numero %i esta presente %i vezes no vetor.", num, cont);
        }
        else
        {
            printf("\nO numero %i nao se encontra no vetor.\nDigite outro...\n", num);
        }
        
    } while (cont == 0);
}