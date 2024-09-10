// Ler 10 elementos de um vetor e colocá-los na ordem crescente.

#include <stdio.h>
#include <stdlib.h>

void leituraVetor(int *p, int tamanho);
void mostrarVetor(int *p, int tamanho);
void ordemCrescente(int *p, int tamanho);

int main() 
{
    system("cls");
    int vetor[10];
    int tamanho = 10;

    printf("Digite os elementos do vetor:\n");
    leituraVetor(vetor, tamanho);

    printf("Vetor organizado:\n");
    mostrarVetor(vetor, tamanho);

    ordemCrescente(vetor, tamanho);

    printf("\nVetor reordenado em ordem CRESCENTE:\n");
    mostrarVetor(vetor, tamanho);

    system("pause");
    return 0;
}

void leituraVetor(int *p, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("Elemento [%i]: ", i);
        scanf("%i", p + i);
    }
}

void mostrarVetor(int *p, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("[%i]: %i\n",i , *(p + i));
    }                   
}

void ordemCrescente(int *p, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = i; j < tamanho; j++)
        {
            if (*(p + i) > *(p + j))
            {
                int temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
        }
    }
}
