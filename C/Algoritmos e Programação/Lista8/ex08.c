//ex8 lista 8
// Escreva um algoritmo que leia um vetor de n elementos inteiros. Ordene o
// vetor em ordem decrescente e exiba-o.

#include <stdio.h>

int main()
{                           // Função principal do programa
    int tamanho, i, j, aux; // Declaração de variáveis inteiras

    printf("Quantos elementos tera o vetor?\n"); // Pergunta ao usuário quantos elementos o vetor terá
    scanf("%i", &tamanho);                       // Lê o número de elementos do vetor

    int vetor[tamanho]; // Declara um vetor com o tamanho especificado pelo usuário

    printf("Digite %i elementos:\n", tamanho); // Pede ao usuário para digitar os elementos do vetor
    for (i = 0; i < tamanho; i++)              // Loop para ler os elementos do vetor
    {
        scanf("%i", &vetor[i]); // Lê cada elemento do vetor
    }

    for (i = 0; i < tamanho; i++) // Loop para ordenar o vetor
    {
        for (j = i; j < tamanho; j++) // Loop interno para comparar os elementos
        {
            if (vetor[i] < vetor[j]) // Se o elemento atual for menor que o próximo elemento
            {
                // A variável 'aux' é usada como uma variável auxiliar para armazenar temporariamente o valor de 'vetor[i]'
                // Isso é necessário para realizar a troca dos elementos de posição no vetor
                aux = vetor[i];

                // Atribui o valor de 'vetor[j]' para 'vetor[i]'
                // Agora 'vetor[i]' tem o valor que estava em 'vetor[j]'
                vetor[i] = vetor[j];

                // Atribui o valor armazenado em 'aux' (que era o valor original de 'vetor[i]') para 'vetor[j]'
                // Agora 'vetor[j]' tem o valor que estava em 'vetor[i]'
                vetor[j] = aux;
            }
        }
    }

    printf("\nVetor em ordem decrescente:\n"); // Imprime o vetor ordenado em ordem decrescente
    for (i = 0; i < tamanho; i++)              // Loop para imprimir cada elemento do vetor
    {
        printf("%i ", vetor[i]); // Imprime cada elemento do vetor
    }
}