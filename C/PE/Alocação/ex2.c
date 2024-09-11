// Aloque espaço para uma seqüência de números reais escolhida pelo usuário. Receba os valores
// e imprima-os em ordem inversa. Utilizar função para alocação dinâmica.

#include <stdio.h>
#include <stdlib.h>

void aloca(float **p, int tam);
void recebe(float *p, int tam);
void imprime(float *p, int tam);
void ordemInversa(float *p, int tam);

int main()
{
    system("cls");

    float *ptr = NULL;
    int qntd;

    printf("Quantos numeros deseja digitar?\n");
    scanf("%int", &qntd);

    aloca(&ptr, qntd);

    printf("\n\n");
    recebe(ptr, qntd);

    printf("\n\nNumeros em ordem inversa:\n");
    ordemInversa(ptr, qntd);
    
    return 0;
}

void aloca(float **p, int tam)
{
    if((*p = (float *)realloc(*p, tam*sizeof(float))) == NULL) //importanta
    {
        printf("Erro na alocacao!");
        exit(1);
    }
    printf("Funcao aloca - Endereco: %p", *p); //%p ponteiro(hexadecimal)  %u numero inteiro sem sinal

}

void ordemInversa(float *p, int tam)
{
    for (int i = tam - 1; i >= 0; i--)
    {
        printf("[%i]: %.2f\n", i, *(p + i));
    }
}

void recebe(float *p, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("Digite o numero de [%i]: ", i);
        scanf("%f", p + i);
    }
}

void imprime(float *p, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("[%i]: %.2f\n", i, *(p + i));
    }
}
