// Realizar a soma de 2 vetores A e B de nºs reais e de tamanho igual ou inferior a 100 (n<=100)
// e gerar um vetor resultante C onde
// C[i] = A[i] + B[i]

#include <stdio.h>
#include <stdlib.h>

void soma_matrizes(float *x, float *y, float *z, int num);
void imprimir_matriz(float *x, float *y, float *z, int num);

int main() 
{
    system("cls");
    int n;
    float A[100], B[100], C[100];

    do
    {
        printf("Digite o tamanho dos vetores (max=100): ");
        scanf("%i", &n);

        if (n > 100 || n <= 0) 
        {
            printf("Tamanho inválido! O valor deve ser entre 1 e 100.\n");
        }
    } while (n > 100 || n <= 0);
    
    printf("\nDigite os elementos do vetor A:\n");
    for (int i = 0; i < n; i++) {
        printf("A[%d]: ", i);
        scanf("%f", A + i);
    }

    printf("\nDigite os elementos do vetor B:\n");
    for (int i = 0; i < n; i++) {
        printf("B[%d]: ", i);
        scanf("%f", B + i);
    }

    soma_matrizes(A, B, C, n);
    printf("\n");
    imprimir_matriz(A, B, C, n);

    return 0;
}

void soma_matrizes(float *x, float *y, float *z, int num)
{
    for (int i = 0; i < num; i++)
    {
        *(z + i) = *(x + i) + *(y + i);
    }
}

void imprimir_matriz(float *x, float *y, float *z, int num)
{
    for (int i = 0; i < num; i++, x++, y++, z++)
    {
        printf("C[%i]\t=\tA[%i]\t+\tB[%i]\n", i, i, i);
        printf("%.2f\t=\t%.2f\t+\t%.2f\n\n", *z, *x, *y);
    }
}