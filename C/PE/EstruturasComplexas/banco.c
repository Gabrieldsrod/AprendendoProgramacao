#include <stdio.h>
#include <stdlib.h>

typedef struct cliente
{
    char nome[30];
    int conta;
    float saldo;
} cliente;

void aloca(cliente **p, int tam);
void cadastro(cliente *p);
int busca(cliente *p, int tam);
void operacao(cliente *p, int op);

int main()
{
    cliente *cli = NULL;
    int cont = 0, op, localizador;

    do
    {
        system("cls");
        printf("Banco\n\n");

        printf("[1]Cadastro\n[2]Deposito\n[3]Retirada\n[4]Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%i", &op);
        fflush(stdin);

        switch (op)
        {
        case 1:
            aloca(&cli, cont + 1);
            cadastro(cli + cont);
            cont++;
            break;

        case 2:

        case 3:
            localizador = busca(cli, cont);
            if (localizador == -1)
            {
                printf("Conta invalida");
                system("pause");
            }
            else
            {
                operacao(cli + localizador, op);
            }
            break;
        } // switch
    } while (op != 4);
    return 0;
} // main

void aloca(cliente **p, int tam)
{
    if ((*p = (cliente *)realloc(*p, tam * sizeof(cliente))) == NULL)
    {
        exit(1);
    }
}

void cadastro(cliente *p)
{
    static int n = 2000;

    printf("\nNome: ");
    gets(p->nome);
    fflush(stdin);
    p->conta = n;
    n += 10;
    p->saldo = 0;
    printf("Conta %i registrada\n\n", p->conta);
    system("pause");
}

int busca(cliente *p, int tam)
{
    int i, aux_busca;

    printf("Conta a ser movimentada: ");
    scanf("%i", &aux_busca);
    fflush(stdin);

    for (i = 0; i < tam; i++)
    {
        if ((p + i)->conta == aux_busca)
        {
            return i;
        }
    }
    return -1;
}

void operacao(cliente *p, int op)
{
    float valor;

    printf("Valor a ser depositado/retirado: R$");
    scanf("%f", &valor);

    if (op == 2) // deposito
    {
        p->saldo += valor;
    }
    else
    { // retirada/saque
        if (p->saldo >= valor)
        {
            p->saldo -= valor;
        }
        else
        {
            printf("Saldo Insuficiente\n\n");
        }

    } // else
    printf("Saldo atual: R$%.2f\n\n", p->saldo);
    system("pause");
} // operação
