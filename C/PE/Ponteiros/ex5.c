// Ler 10 elementos de um vetor. Verificar e mostrar o maior elemento.

#include <stdio.h>
#include <stdlib.h>

void maiorElemento(int *p, int num);
void mostrarVetor(int *p, int tamanho);
void leituraVetor(int *p, int tamanho);

int main()
{
    system("cls");
    int vetor[10];
    int tamanho = 10;

    printf("Digite o valor dos elementos do vetor: \n");
    leituraVetor(vetor, tamanho);

    printf("\nVetor digitado:");
    mostrarVetor(vetor, tamanho);

    maiorElemento(vetor, tamanho);

    system("pause");
    return 0;
}

void maiorElemento(int *p, int tam)
{
    int maior = *p;

    for (int i = 0; i < tam; i++)
    {
        if (*(p + i) > maior)
        {
            maior = *(p + i);
        }
    }

    printf("\nMaior elemento do vetor: %i\n", maior);
}

void mostrarVetor(int *p, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("[%i]: %i\n",i , *(p + i));
    }
}

void leituraVetor(int *p, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("Elemento [%i]: ", i);
        scanf("%i", p + i);
    }
}
