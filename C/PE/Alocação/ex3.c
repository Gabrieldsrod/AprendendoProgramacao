// Idem ao exercício anterior, porém a seqüência de números reais deverá ser digitada pelo usuário,
// até que este escolha a opção N (Deseja continuar? (S/N)). Utilizar função para alocação
// dinâmica

#include <stdio.h>
#include <stdlib.h>

void aloca(float **p, int tam);
void recebe(float *p, int tam);
void imprime(float *p, int tam);
void ordemInversa(float *p, int tam);
int recebeNumeros(float **p);

int main()
{
    system("cls");

    float *ptr = NULL;
    int qntd = 0;

    qntd = recebeNumeros(&ptr);

    printf("\nNumeros digitados:\n");
    imprime(ptr, qntd);

    printf("\nNumeros em ordem inversa:\n");
    ordemInversa(ptr, qntd);

    return 0;
}

void aloca(float **p, int tam)
{
    if ((*p = (float *)realloc(*p, tam*sizeof(float))) == NULL) // importante
    {
        printf("Erro na alocacao!");
        exit(1);
    }
    // printf("Funcao aloca - Endereco: %p\n", *p); //%p ponteiro(hexadecimal)  %u numero inteiro sem sinal
}

void ordemInversa(float *p, int tam)
{
    for (int i = tam - 1; i >= 0; i--)
    {
        printf("[%i]: %.2f- Endereco: %p\n", i, *(p + i), p + i);
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
        printf("[%i]: %.2f - Endereco: %p\n", i, *(p + i), p + i);
    }
}

int recebeNumeros(float **p) 
{
    int n = 0;
    char opcao;

    do {
        n++;  // Aumenta o tamanho do array para cada novo número
        aloca(p, n);

        // Recebe o próximo número
        printf("Digite o numero %d: ", n);
        scanf("%f",&(*p)[n - 1]);     // n - 1 porque o array começa em 0

        // Pergunta ao usuário se deseja continuar
        printf("Deseja continuar? (S/N): ");
        scanf(" %c", &opcao);  // O espaço antes de %c é para ignorar qualquer caractere em branco
    } while (opcao == 'S' || opcao == 's');

    return n;
}