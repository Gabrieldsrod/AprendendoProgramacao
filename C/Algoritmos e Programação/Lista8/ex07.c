// Crie um programa que copie para um vetor os elementos de outro em
// ordem crescente.

#include <stdio.h>

int main(){
    int tamanho, i, j, aux;

    printf("Quantos elementos tera o vetor?\n");
    scanf("%i", &tamanho);

    int vetor[tamanho], crescente[tamanho];

    printf("Digite %i elementos:\n", tamanho);
    for ( i = 0; i < tamanho; i++)
    {
        scanf("%i", &vetor[i]);
    }
    
    printf("\nVetor 1 (Original):\n");
    for (i = 0; i < tamanho; i++)
    {
        printf("%i ", vetor[i]);
    }

    for ( i = 0; i < tamanho; i++)
    {
        for(j = i; j < tamanho; j++)
        {
            if(vetor[i] > vetor[j])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
    
    for ( i = 0; i < tamanho; i++)
    {
        crescente[i] = vetor[i];
    }
    
    printf("\nVetor 2 (Ordem crescente):\n");
    for (i = 0; i < tamanho; i++)
    {
        printf("%i ", crescente[i]);
    }
}