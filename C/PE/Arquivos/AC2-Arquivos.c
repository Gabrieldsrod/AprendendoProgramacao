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

int verifica_danca();
int verifica_aluno();

void cadastra_dance(dance *pd, int qd);
void cadastra_aluno(aluno *pa, dance *pd, int qd);

void desmatricula(aluno *pa, dance *pd);

void grava_danca(dance *pd);
void grava_aluno(aluno *pa, char *met, int pos);
void atualiza_danca(dance *pd, int numreg);

int busca_dance(dance *pd, int qd, char mod, char turn);
int busca_aluno(aluno *pa, char *cpf);
int busca_desmatriculado(aluno *pa, int qa);

void mostra_aluno(aluno *pa);
void mostra_dance(dance *pd);

int main()
{
    dance *pd = NULL;
    aluno *pa = NULL;
    int op, qd;
    aloca_dance(&pd, 1);
    qd = verifica_danca();
    if (qd == 0)
        cadastra_dance(pd, 6);
    aloca_aluno(&pa, 1);

    do
    {
        system("cls");
        printf("-----Academia de Danca-----");
        printf("\n[1]Matricula\n[2]Desmatricula\n[3]Mostrar alunos\n[4]Mostrar Dancas\n[5]Sair\nOpcao: ");
        scanf("%i", &op);
        fflush(stdin);
        switch (op)
        {
        case 1:
            mostra_dance(pd);
            cadastra_aluno(pa, pd, qd);
            break;

        case 2:
            desmatricula(pa, pd);
            break;
        case 3:
            mostra_aluno(pa);
            break;

        case 4:
            mostra_dance(pd);
            system("pause");
            break;
        }

    } while (op != 5);

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

int verifica_danca()
{
    FILE *fd = NULL;
    int qtde = 0;
    if ((fd = fopen("dancas.bin", "rb")) == NULL)
        return qtde;
    else
    {
        fseek(fd, 0, 2);
        qtde = ftell(fd) / sizeof(dance);
        fclose(fd);
        return qtde;
    }
} // verifica_danca

int verifica_aluno()
{
    FILE *fa = NULL;
    int qtde = 0;
    if ((fa = fopen("alunos.bin", "rb")) == NULL)
        return qtde;
    else
    {
        fseek(fa, 0, 2);
        qtde = ftell(fa) / sizeof(aluno);
        fclose(fa);
        return qtde;
    } // else
} // verifica_aluno

void grava_danca(dance *pd)
{
    FILE *fd = NULL;
    if ((fd = fopen("dancas.bin", "ab")) == NULL)
        printf("\nErro\n\n");
    else
        fwrite(pd, sizeof(dance), 1, fd);
    fclose(fd);
} // grava_danca

void grava_aluno(aluno *pa, char *met, int pos)
{
    FILE *fa = NULL;

    if ((fa = fopen("alunos.bin", met)) == NULL)
        printf("\nArquivo inexistente\n\n");
    else
    {
        if (strcmp(met, "rb+") == 0)
            fseek(fa, pos * sizeof(aluno), 0);
        fwrite(pa, sizeof(aluno), 1, fa);
    } // else
    fclose(fa);
} // grava_aluno

void atualiza_danca(dance *pd, int numreg)
{
    FILE *fd = NULL;
    int qd, i;

    qd = verifica_danca();
    if ((fd = fopen("dancas.bin", "rb+")) == NULL)
        printf("\nErro\n\n");
    else
    {
        for (i = 0; i < qd; i++)
        {
            fseek(fd, i * sizeof(dance), 0);
            fread(pd, sizeof(dance), 1, fd);
            if (pd->regaula == numreg)
            {
                pd->qaluno--;
                fseek(fd, i * sizeof(dance), 0);
                fwrite(pd, sizeof(dance), 1, fd);
                break; // Corrigir para sair do loop após encontrar a dança
            } // if
        } // for
    } // else
    fclose(fd);
} // atualiza_danca

void cadastra_dance(dance *pd, int qd)
{
    int i;
    for (i = 0; i < qd; i++)
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
        grava_danca(pd);
    }
} // cadastra_dance

void cadastra_aluno(aluno *pa, dance *pd, int qd)
{
    char aux_dance, aux_turno;
    int reg, qaluno;

    qaluno = verifica_aluno();
    reg = busca_desmatriculado(pa, qaluno);

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

    qd = verifica_danca(); // Atualiza a quantidade de danças
    pa->numaula = busca_dance(pd, qd, toupper(aux_dance), toupper(aux_turno));
    if (pa->numaula == -1)
    {
        printf("\nAula nao encontrada...\n\n\n");
    }
    else
    {
        printf("\nAluno cadastrado!\n");
        printf("Valor mensal da aula: %.2f\n", pd->valor);
        if (reg == -1)
            grava_aluno(pa, "ab", 1);
        else
            grava_aluno(pa, "rb+", reg);
    }
    system("pause");
} // cadastra_aluno

int busca_dance(dance *pd, int qd, char mod, char turn)
{
    int i, reg = -1;
    FILE *fd = NULL;

    if ((fd = fopen("dancas.bin", "rb+")) == NULL)
        printf("\nErro\n\n");
    else
    {
        for (i = 0; i < qd; i++)
        {
            fseek(fd, i * sizeof(dance), 0);
            fread(pd, sizeof(dance), 1, fd);
            if (pd->modalidade == mod && pd->turno == turn)
            {
                pd->qaluno++;
                fseek(fd, i * sizeof(dance), 0);
                fwrite(pd, sizeof(dance), 1, fd);
                reg = pd->regaula;
                i = qd;
            } // if
        } // for
    } // else
    fclose(fd);
    return reg;
} // busca_dance

int busca_aluno(aluno *pa, char *cpf)
{
    int achou = -1, i, qa;
    FILE *fa = NULL;
    qa = verifica_aluno();
    if ((fa = fopen("alunos.bin", "rb+")) == NULL)
        printf("\nErro\n\n");
    else
    {
        for (i = 0; i < qa; i++)
        {
            fseek(fa, i * sizeof(aluno), 0);
            fread(pa, sizeof(aluno), 1, fa);
            if (strcmp(pa->CPF, cpf) == 0) 
            {
                achou = pa->numaula; // Armazena o número da aula
                pa->numaula = -1;             // Marca o aluno como desmatriculado
                fseek(fa, i * sizeof(aluno), 0);
                fwrite(pa, sizeof(aluno), 1, fa);
                i = qa;
            } // if
        } // for
    } // else
    fclose(fa);
    return achou;
} // busca aluno

int busca_desmatriculado(aluno *pa, int qa)
{
    FILE *fa = NULL;
    int i;

    if ((fa = fopen("alunos.bin", "rb")) == NULL)
        return -1;
    else
    {
        for (i = 0; i < qa; i++)
        {
            fseek(fa, i * sizeof(aluno), 0);
            fread(pa, sizeof(aluno), 1, fa);
            if(pa->numaula == -1)
            {
                fclose(fa);
                return i;
            }
        } // for
        fclose(fa);
    }
    return -1;
} // busca_vago

void desmatricula(aluno *pa, dance *pd)
{
    int achou;
    char cpf[13];

    printf("Matricula(CPF) a ser encerrada: ");
    gets(cpf);
    fflush(stdin);

    achou = busca_aluno(pa, cpf);
    
    if(achou == -1)
        printf("\nCPF Invalido\n\n");
    else
    {
        atualiza_danca(pd, achou);
        printf("Desmatricula concluida\n");
    }
    system("pause");
} // desmatricula

void mostra_dance(dance *pd)
{
    int i, qd;
    FILE *fd = NULL;

    qd = verifica_danca();
    if ((fd = fopen("dancas.bin", "rb")) == NULL)
        printf("\nArquivo Inexistente\n\n");
    else
    {
        system("cls");
        printf("RegA\tQal\tMod\tTurn\tValor\n");
        for (i = 0; i < qd; i++)
        {
            fseek(fd, i * sizeof(dance), 0);
            fread(pd, sizeof(dance), 1, fd);
            printf("%i\t%i\t%c\t%c\t%.2f\n", pd->regaula, pd->qaluno, pd->modalidade, pd->turno, pd->valor);
        }
        fclose(fd);
    }
} // mostra_dance

void mostra_aluno(aluno *pa)
{
    int i, qa;
    FILE *fa = NULL;

    qa = verifica_aluno();
    if ((fa = fopen("alunos.bin", "rb")) == NULL)
        printf("\nErro\n\n");
    else
    {
        system("cls");
        printf("CPF\tNome\tNumaula\n");

        for (i = 0; i < qa; i++)
        {
            fseek(fa, i * sizeof(aluno), 0);
            fread(pa, sizeof(aluno), 1, fa);
            printf("%s\t%s\t%i\n", pa->CPF, pa->nome, pa->numaula);
        }
        fclose(fa);
        printf("\n");
        system("pause");
    }
} // mostra_aluno
