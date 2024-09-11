// Alocar espaço para 10 números reais. Mostrar o endereço e receber do usuário os valores. Em
// seguida, alterar esses valores, somando 30 a cada elemento. Mostrar novamente o endereço (que
// deve ser o mesmo) com o novo valor. Utilizar função para alocação dinâmica.

#include <stdio.h>
#include <stdlib.h>

void aloca(float **p, int tam);
void recebe(float *p, int tam);
void somarTrinta(float *p, int tamanho);
void imprime(float *p, int tam);


int main()
{
    float *ptr=NULL;

    aloca(&ptr, 10);

    printf("\n\n");
    recebe(ptr, 10);
    imprime(ptr, 10);

    printf("\n\nNumeros acrescidos de 30:\n");
    somarTrinta(ptr, 10);
    imprime(ptr, 10);
    
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

void recebe(float *p, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("Digite o numero de [%i]: ", i);
        scanf("%f", p + i);
    }
}


void somarTrinta(float *p, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        *(p + i) += 30;
    }
}

void imprime(float *p, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("[%i]: %.2f\n", i, *(p + i));
    }
}

