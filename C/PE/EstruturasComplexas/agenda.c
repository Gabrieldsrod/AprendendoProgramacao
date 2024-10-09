#include <stdio.h>
#include <stdlib.h>

typedef struct agenda
{
    int reg;
    char nome[80];
    float nota;
} agenda;

void aloca(agenda **p, int tam);
void cadastro(agenda *p);
void mostra(agenda *p, int tam);

int main()
{
    agenda *alu = NULL;
    int cont = 0;
    char op;

    system("cls");
    printf("Cadastro de alunos");

    do
    {
        aloca(&alu, cont + 1);
        cadastro(alu + cont);
        cont++;

        printf("Deseja realizar outro cadastro?\n<S/N>: ");
        scanf(" %c", &op);
        fflush(stdin);

        system("cls");
    } while (op != 'N' && op != 'n');

    mostra(alu, cont);

    return 0;
} // main

void aloca(agenda **p, int tam)
{
    if ((*p = (agenda *)realloc(*p, tam * sizeof(agenda))) == NULL)
    {
        exit(1);
    }
} // aloca

void cadastro(agenda *p)
{
    static int num_reg = 1000;

    p->reg = num_reg;
    num_reg++;
    printf("Registro: %i", p->reg);
    printf("\nNome:");
    gets(p->nome);
    fflush(stdin);
    printf("Nota:");
    scanf("%f", &p->nota);
    fflush(stdin);
    printf("Cadastro realizado!\n");

} // cadastro

void mostra(agenda *p, int tam)
{
    int i;

    for (i = 0; i < tam; i++)
    {
        printf("Registro %i\nNome: %s\nNota: %.2f\n\n", (p + i)->reg, (p + i)->nome, (p + i)->nota);
    }

} // mostra
