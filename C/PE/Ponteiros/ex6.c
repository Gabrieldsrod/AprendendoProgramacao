// Ler 10 elementos de um vetor. Verificar e mostrar a média dos elementos.

#include <stdio.h>
#include <stdlib.h>

void leituraVetor(int *p, int tamanho);
void mostrarVetor(int *p, int tamanho);
void mediaVetor(int *p, int tamanho);

int main() 
{
    system("cls");
    int vetor[10];
    int tamanho = 10;

    printf("Digite os elementos do vetor:\n");
    leituraVetor(vetor, tamanho);

    printf("Vetor digitado:\n");
    mostrarVetor(vetor, tamanho);

    mediaVetor(vetor, tamanho);

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

void mediaVetor(int *p, int tamanho)
{
    int soma = 0;
    float media;

    for (int i = 0; i < tamanho; i++)
    {
        soma += *(p + i);
    }
    
    media = (float) soma / tamanho;

    printf("Media de todos os elementos do vetor: %.2f\n\n", media);
}
