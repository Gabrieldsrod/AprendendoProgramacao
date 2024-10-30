#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
    int dia;
    int mes;
    int ano;
} data;

typedef struct pessoa
{
    char nome[31];
    char fone[21];
    data nasc;
} pessoa;

void alocaPessoa(pessoa **p, int qp);
void cadastraContato(pessoa *p);
void procuraContato(pessoa *p, int qp);
int buscaContato(pessoa *p, int qp, char *aux_nome);
void imprimeContato(pessoa *p);
void listaContato(pessoa *p, int qp);
void maiuscula(char *s);

int main()
{
    pessoa *pp = NULL;
    int op, cont = 0;

    system("cls");
    printf("-------Lista de contatos-------");
    printf("\n\nAdicione o primeiro contato!");

    alocaPessoa(&pp, cont + 1);
    cadastraContato(pp + cont);
    cont++;

    do
    {
        system("cls");
        printf("-------Lista de contatos-------");
        printf("\nEscolha uma operacao:");
        printf("\n[1]Adicionar Contato\n[2]Buscar Contato\n[3]Listar todos os contatos\n[4]Encerrar\nOpcao: ");
        scanf("%i", &op);
        fflush(stdin);

        switch (op)
        {
        case 1:
            alocaPessoa(&pp, cont + 1);
            cadastraContato(pp + cont);
            cont++;
            break;
        case 2:
            procuraContato(pp, cont);
            break;
        case 3:
            listaContato(pp, cont);
            break;
        }
    } while (op != 4);

    return 0;
} // main

void alocaPessoa(pessoa **p, int qp)
{
    if ((*p = (pessoa *)realloc(*p, qp * sizeof(pessoa))) == NULL)
    {
        exit(1);
    }
} // alocaPessoa

void cadastraContato(pessoa *p)
{
    printf("\nNome: ");
    gets(p->nome);
    fflush(stdin);
    maiuscula(p->nome);

    printf("\nTelefone: ");
    gets(p->fone);
    fflush(stdin);

    printf("\nData de Nascimento\nDia: ");
    scanf("%i", &p->nasc.dia);
    fflush(stdin);
    printf("Mes(Numero): ");
    scanf("%i", &p->nasc.mes);
    fflush(stdin);
    printf("Ano: ");
    scanf("%i", &p->nasc.ano);
    fflush(stdin);

    printf("\nContato cadastrado com sucesso!\n");
    system("pause");
} // cadastraContato

void procuraContato(pessoa *p, int qp)
{
    int pos;
    char aux_nome[31];

    printf("\nNome a ser procurado: ");
    gets(aux_nome);
    fflush(stdin);
    maiuscula(aux_nome);

    pos = buscaContato(p, qp, aux_nome);

    if (pos == -1)
    {
        printf("\nContato nao encontrado...\n\n");
    }
    else
    {
        printf("\n\nNome\t\tTelefone\t\tData de Nasc.");
        imprimeContato(p + pos);
    }
    system("pause");
} // procuraContato

int buscaContato(pessoa *p, int qp, char *aux_nome)
{
    int i;

    for (i = 0; i < qp; i++)
    {
        if (strcmp((p + i)->nome, aux_nome) == 0)
        {
            return i;
        }
    }
    return -1;
} // buscaContato

void imprimeContato(pessoa *p)
{
    printf("\n%-30s\t%-20s\t%02i/%02i/%04i\n", p->nome, p->fone, p->nasc.dia, p->nasc.mes, p->nasc.ano);
}

void listaContato(pessoa *p, int qp)
{

    int i;
    {
        printf("\n\n%-30s\t%-20s\t%s", "Nome", "Telefone", "Data de Nasc.");

        for (i = 0; i < qp; i++)
        {
            imprimeContato(p + i);
        }
    }
    system("pause");
}

void maiuscula(char *s)
{
    int i, tam = strlen(s);
    for (i = 0; i < tam; i++, s++)
    {
        if (*s >= 'a' && *s <= 'z')
        {
            *s -= 32;
        }
    }
} // maiuscula
