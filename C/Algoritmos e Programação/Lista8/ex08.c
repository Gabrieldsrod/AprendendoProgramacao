// Escreva um algoritmo que leia um vetor de n elementos inteiros. Ordene o
// vetor em ordem decrescente e exiba-o.

#include <stdio.h>

int main(){
    int tamanho, i, j, aux;

    printf("Quantos elementos tera o vetor?\n");
    scanf("%i", &tamanho);

    int vetor[tamanho];

    printf("Digite %i elementos:\n", tamanho);
    for ( i = 0; i < tamanho; i++)
    {
        scanf("%i", &vetor[i]);
    }
    
    for ( i = 0; i < tamanho; i++)
    {
        for(j = i; j < tamanho; j++)
        {
            if(vetor[i] < vetor[j])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    
    printf("\nVetor em ordem decrescente:\n");
    for (i = 0; i < tamanho; i++)
    {
        printf("%i ", vetor[i]);
    }
}