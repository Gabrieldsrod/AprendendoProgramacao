#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct dance
{
    int regaula;
    int qaluno;
    char modalidade;
    char turno;
    float valor;
} dance;

typedef struct aluno
{
    char CPF[13];
    char nome[80];
    int numaula;
} aluno;

void aloca_dance(dance **pd, int qd);
void aloca_aluno(aluno **pa, int qa);

void cadastra_dance(dance *pd, int qd);
void mostra_dance(dance *pd, int qd);
int busca_dance(dance *pd, int qd, char mod, char turn);

void cadastra_aluno(aluno *pa, dance *pd, int qd);
void mostra_aluno(aluno *pa, int qa);

int main()

{
    dance *pd = NULL;
    aluno *pa = NULL;
    int op, qa = 0, qd = 6;
    aloca_dance(&pd, qd);
    cadastra_dance(pd, qd);

    do
    {
        system("cls");
        printf("-----Academia de Danca-----");
        printf("\n[1]Matricula\n[2]Mostrar alunos\n[3]Encerrar\nOpcao: ");
        scanf("%i", &op);
        fflush(stdin);

        switch (op)
        {
        case 1:
            aloca_aluno(&pa, qa + 1);
            mostra_dance(pd, qd);
            cadastra_aluno(pa + qa, pd, qd);
            qa++;
            break;

        case 2:
            mostra_aluno(pa, qa);
            break;
        }

    } while (op != 3);

    return 0;
} // main

void aloca_dance(dance **pd, int qd)
{
    if ((*pd = (dance *)realloc(*pd, qd * sizeof(dance))) == NULL)
    {
        exit(1);
    }
} // aloca_dance

void aloca_aluno(aluno **pa, int qa)
{
    if ((*pa = (aluno *)realloc(*pa, qa * sizeof(aluno))) == NULL)
    {
        exit(1);
    }
} // aloca_aluno

void cadastra_dance(dance *pd, int qd)
{
    int i, j;
    for (i = 0; i < qd; i++, pd++)
    {
        pd->regaula = i + 1;
        pd->qaluno = 0;
        if (i < 3)
        {
            pd->modalidade = 'B';
        }
        else
        {
            pd->modalidade = 'S';
        }
        for (j = 0; j < qd; j++)
        {
            if (pd->regaula == 1 || pd->regaula == 4)
            {
                pd->turno = 'M';
            }
            else if (pd->regaula == 2 || pd->regaula == 5)
            {
                pd->turno = 'T';
            }
            else
            {
                pd->turno = 'N';
            }
        }
        if (pd->turno == 'M')
        {
            pd->valor = 300;
        }
        else if (pd->turno == 'T')
        {
            pd->valor = 250;
        }
        else
        {
            pd->valor = 350;
        }
    }
} // cadastra_dance

int busca_dance(dance *pd, int qd, char mod, char turn)
{
    int i;
    for (i = 0; i < qd; i++, pd++)
    {
        if (pd->modalidade == mod && pd->turno == turn)
        {
            pd->qaluno++;
            return pd->regaula;
        }
    }
    return -1;
} // busca_dance

void mostra_dance(dance *pd, int qd)
{
    int i;
    system("cls");
    printf("RegA\tQal\tMod\tTurn\tValor\n");
    for (i = 0; i < qd; i++, pd++)
    {
        printf("%i\t%i\t%c\t%c\t%.2f\n", pd->regaula, pd->qaluno, pd - > modalidade, pd->turno, pd->valor);
    }
} // mostra_dance

void cadastra_aluno(aluno *pa, dance *pd, int qd)
{
    char aux_dance, aux_turno;
    int reg;
    printf("\n\nDigite seu CPF: ");
    gets(pa->CPF);
    fflush(stdin);
    printf("\nDigite seu nome: ");
    gets(pa->nome);
    fflush(stdin);
    printf("\nQual a modalidade desejada?\n[B]allet\t[S]apateado\nOpcao: ");
    scanf("%c", &aux_dance);
    fflush(stdin);

    printf("\nQual o turno desejado?\n[M]anha\t[T]Tarde\t[N]oite\nOpcao: ");
    scanf("%c", &aux_turno);
    fflush(stdin);

    reg = busca_dance(pd, qd, toupper(aux_dance), toupper(aux_turno));
    if (reg == -1)
    {
        printf("\nAula nao encontrada...\n\n\n");
    }
    else
    {
        pa->numaula = reg;
        printf("\nAluno cadastrado!!\n\n");
    }
    system("pause");
} // cadastra_aluno

void mostra_aluno(aluno *pa, int qa)
{
    int i;
    system("cls");
    printf("CPF\tNome\tNumaula\n");
    for (i = 0; i < qa; i++, pa++)
    {
        printf("%s\t%s\t%i\n", pa->CPF, pa->nome, pa->numaula);
    }
    system("pause");
} // mostra_aluno