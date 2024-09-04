// Faça um programa que leia o tamanho de um vetor A e, em seguida, leia
// os n elementos do vetor. Considere que o valor máximo de elementos que
// o vetor A pode armazenar é 100. Por fim, calcule e mostre a média dos
// elementos de índice par e o produto dos elementos de índice ímpar

#include<stdio.h>

int main()
{
    int A[100];
    int tamanho, i;
    int somapar = 0;
    int contpar = 0;
    int produtoimpar = 1;
    int mediapar;
    
    printf("Digite o tamanho do vetor (Max=100):\n");
    scanf("%i", &tamanho);

    printf("\nDigite %i valores:\n", tamanho);
    for (i = 0;i < tamanho; i++)
    {
        scanf("%i", &A[i]);
    }

    for (i = 0; i < tamanho; i++) 
    {
        if (i % 2 == 0) 
        {  
            somapar += A[i];
            contpar++; 
        } 
        else 
        { 
            produtoimpar *= A[i];
        }
    }

    mediapar = (float)somapar / contpar;

    printf("\nMedia dos valores de indice par: %i\n", mediapar);
    printf("Produto dos valores de indice impar: %i\n", produtoimpar);
}