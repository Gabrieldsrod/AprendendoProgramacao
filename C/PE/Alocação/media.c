#include <stdio.h>
#include <stdlib.h>

void aloca(float **p, int tam);
void leitura(float *p);
void mostra(float *p, int tam);
void media(float *p, int tam);
void menoresMedia(float *p, float media, int tam);
void maioresMedia(float *p, float media, int tam);

int main()
{
    system("cls");

    float *ptr = NULL;
    int cont = 0;
    char op;

    do
    {
        aloca(&ptr, cont + 1);
        leitura(ptr + cont);
        cont++;
        printf("\nDeseja continuar <S/N>: ");
        scanf("%c", &op);
        fflush(stdin);
        printf("\n");

    } while (op == 's' || op == 'S');

    system("cls");

    media(ptr, cont);

    system("pause");
    return 0;
}

void aloca(float **p, int tam)
{
    if ((*p = (float *)realloc(*p, tam * sizeof(float))) == NULL) // importante
    {
        exit(1);
    }
    // printf("Funcao aloca - Endereco: %p\n", *p); //%p ponteiro(hexadecimal)  %u numero inteiro sem sinal
}

void leitura(float *p)
{
    printf("Digite um numero: ");
    scanf("%f", p);
    fflush(stdin);
}

void mostra(float *p, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("%.1f\n", *(p + i));
    }
}

void media(float *p, int tam)
{
    float soma = 0, media = 0;
    int cont = 0;
    int i;

    for (i = 0; i < tam; i++)
    {
        if (*(p + i) != 0)
        {
            soma += *(p + i);
            cont++;
        }
    }

    media = soma / cont;

    mostra(p, tam);
    printf("Media dos valores: %.2f", media);

    menoresMedia(p, media, tam);
    maioresMedia(p, media, tam);
}

void menoresMedia(float *p, float media, int tam)
{
    int i;
    int qmenor = 0;
    float *pmenor = NULL;

    for (i = 0; i < tam; i++)
    {
        if (*(p + i) < media)
        {
            aloca(&pmenor, qmenor + 1);
            *(pmenor + qmenor) = *(p + i);
            qmenor++;
        }
    }

    printf("\n\nValores menores que a media:\n");
    for (i = 0; i < qmenor; i++)
    {
        printf("%.1f\n", *(pmenor + i));
    }
}

void maioresMedia(float *p, float media, int tam)
{
    int i;
    int qmaior = 0;
    float *pmaior = NULL;

    for (i = 0; i < tam; i++)
    {
        if (*(p + i) > media)
        {
            aloca(&pmaior, qmaior + 1);
            *(pmaior + qmaior) = *(p + i);
            qmaior++;
        }
    }

    printf("\nValores maiores que a media:\n");
    for (int i = 0; i < qmaior; i++)
    {
        printf("%.1f\n", *(pmaior + i));
    }

}