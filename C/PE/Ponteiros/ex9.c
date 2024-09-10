// Ler um vetor (A) com 15 elementos. Construir um vetor B do mesmo tipo e tamanho, sendo que
// cada elemento de B seja o fatorial do elemento correspondente de A. (utilizar a função recursiva
// direta p/ fatorial).

#include <stdio.h>
#include <stdlib.h>

void leituraVetor(long int *p, int tamanho);
void mostrarVetor(long int *p, int tamanho);
void vetorFatorado(long int *p, long int *x, int tamanho);
int fatorial(int n);
void transferirFatorial(long int *x, long int *y, int tamanho);

int main()
{
    system("cls");
    long int A[15], B[15];
    int tamanho = 15;

    printf("Digite os elementos do vetor:\n");
    leituraVetor(A, tamanho);

    printf("Vetor A:\n");
    mostrarVetor(A, tamanho);

    transferirFatorial(A, B, tamanho);

    printf("Vetor B (Fatorial de A):       (PS.: valores precisos de 1! ate 12!) \n");
    vetorFatorado(B, A, tamanho);

    system("pause");
    return 0;
}

void leituraVetor(long int *p, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("Elemento [%i]: ", i);
        scanf("%ld", p + i);
    }
}
void mostrarVetor(long int *p, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("[%i]: %ld\n", i, *(p + i));
    }
}

void vetorFatorado(long int *p, long int *x, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("[%i]: %ld! = %ld\n", i, *(x +i), *(p + i));
    }
}

void transferirFatorial(long int *x, long int *y, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        {
            *(y+ i) = *(x + i) * fatorial(*(x + i) - 1);
        }
    }
}

int fatorial(int n) 
{
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}
