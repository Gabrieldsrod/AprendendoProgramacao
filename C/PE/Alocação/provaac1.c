// Gabriel da Silva Rodrigues 248103
// Isabella Valim de Carvalho 247499
#include <stdio.h>
#include <stdlib.h>
void aloca(int **p, int tam);
void recebe(int *p);
void imprime(int *p, int tam);
void subtrair(int *p, int tam, int **pp, int *qp);
int main()
{
    int *ptr = NULL, *ppar = NULL;
    int cont = 0, qpar = 0;
    char op;
    do
    {
        aloca(&ptr, cont + 1);
        recebe(ptr + cont);
        cont++;
        printf("Deseja continuar? Sim ou nao?\nDigite S ou N: ");
        scanf("%c", &op);
        fflush(stdin);
    } while (op != 'N' && op != 'n');
    system("cls");
    printf("Numeros digitados: \n");
    imprime(ptr, cont);
    subtrair(ptr, cont, &ppar, &qpar);
    return 0;
}
void aloca(int **p, int tam)
{
    if ((*p = (int *)realloc(*p, tam * sizeof(int))) == NULL)
        exit(1);
}
void recebe(int *p)
{
    printf("Digite um numero: ");
    scanf("%i", p);
    fflush(stdin);
}
void imprime(int *p, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        printf("%i\n", *(p + i));
    }
}
void subtrair(int *p, int tam, int **pp, int *qp)
{
    int i, sub;
    for (i = 0; i < tam - 1; i += 2)
    {
        sub = *(p + i) - *(p + i + 1);
        if (sub % 2 == 0)
        {
            aloca(pp, *qp + 1);
            *(*pp + *qp) = sub;
            (*qp)++;
        }
    }
    if (tam % 2 == 1)
    {
        sub = *(p + tam - 1);
        if (sub % 2 == 0)
        {
            aloca(pp, *qp + 1);
            *(*pp + *qp) = sub;
            (*qp)++;
        }
    }
    printf("Pares armazenados:\n");
    imprime(*pp, *qp);
}
