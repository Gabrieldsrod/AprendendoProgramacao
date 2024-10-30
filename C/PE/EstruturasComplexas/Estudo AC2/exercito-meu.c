#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct militar
{
    char CPF[13];  // CPF do militar
    char nome[20]; // nome do militar
    int numreg;    // número do registro da carreira
} militar;

typedef struct carreira
{
    int reg;          // registro da patente
    int qmilitar;     // quantidade de militares daquela patente
    char org[20];     // organização - exemplo: exército, aeronáutica, marinha
    char patente[20]; // exemplo: soldado, cabo, sargento
    float salario;    // valor do salário
} carreira;

void alocaCarreira(carreira **c, int qc);
void alocaMilitar(militar **m, int qm);

void cadastroCarreira(carreira *c, int qc);
void cadastroMilitar(militar *m, carreira *c, int qc);

int buscaPatente(carreira *c, int qc, char *porg, char *ppat);
int buscaCPF(militar *m, int qm, char *aux_CPF);

void trocaPatente(militar *m, int qm, carreira *c, int qc);

void mostra_carreira(carreira *c, int qc);
void mostra_militar(militar *m, int qm);

void maiuscula(char *s);

int main()
{
    militar *pm = NULL;
    carreira *pc = NULL;

    int qc = 5, qm = 0, op;

    alocaCarreira(&pc, qc);
    cadastroCarreira(pc, qc);

    do
    {
        system("cls");
        printf("[1]Cadastro Militar\n[2]Troca Patente\n[3]Mostra Patente\n[4]Mostra Militar\n[5]Sair\nOpcao: ");
        scanf("%i", &op);

        switch (op)
        {
        case 1:
            alocaMilitar(&pm, qm + 1);
            cadastroMilitar(pm + qm, pc, qc);
            qm++;
            break;

        case 2:
            trocaPatente(pm, qm, pc, qc);
            break;

        case 3:
            mostra_carreira(pc, qc);
            break;

        case 4:
            mostra_militar(pm, qm);
            break;
        }//switch
    } while (op < 5);

    return 0;
} // main

void alocaCarreira(carreira **c, int qc)
{
    if ((*c = (carreira *)realloc(*c, qc * sizeof(carreira))) == NULL)
    {
        exit(1);
    }
} // alocaCarreira

void alocaMilitar(militar **m, int qm)
{
    if ((*m = (militar *)realloc(*m, qm * sizeof(militar))) == NULL)
    {
        exit(1);
    }
} // alocaMilitar

void cadastroCarreira(carreira *c, int qc)
{
    int i;

    for (i = 0; i < qc; i++)
    {
        (c + i)->reg = i + 1;

        (c + i)->qmilitar = 0;

        printf("Qual a Organizazacao?\nExercito \\ Marinha \\ Aeronautica : ");
        gets((c + i)->org);
        fflush(stdin);
        maiuscula((c + i)->org);

        printf("\nPatente: ");
        gets((c + i)->patente);
        fflush(stdin);
        maiuscula((c + i)->patente);

        printf("Salario: R$");
        scanf("%f", &(c + i)->salario);
        fflush(stdin);
    } // for
} // cadastroCarreira

void cadastroMilitar(militar *m, carreira *c, int qc)
{
    char aux_org[20], aux_pat[20];

    printf("\nCPF: ");
    gets(m->CPF);
    fflush(stdin);

    printf("\nNome: ");
    gets(m->nome);
    fflush(stdin);

    printf("\nOrganizacao: ");
    gets(aux_org);
    fflush(stdin);
    maiuscula(aux_org);

    printf("\nPatente: ");
    gets(aux_pat);
    fflush(stdin);
    maiuscula(aux_pat);

    m->numreg = buscaPatente(c, qc, aux_org, aux_pat);

    if (m->numreg == -1)
    {
        printf("\nOrganizacao/patente nao encontrada...");
    }
    else
    {
        printf("\nMilitar cadastrado com sucesso.\nRegistro:%i\nSalario: R$%.2f\n\n", m->numreg, (c + (m->numreg) - 1)->salario);
    }
    system("pause");
} // cadastroMilitar

int buscaPatente(carreira *c, int qc, char *porg, char *ppat)
{
    int i;

    for (i = 0; i < qc; i++, c++)
    {
        if ((strcmp(c->org, porg) == 0) && (strcmp(c->patente, ppat) == 0))
        {
            c->qmilitar++;
            return c->reg;
        } // if
    } // for
    return -1;
} // buscPatente

int buscaCPF(militar *m, int qm, char *aux_CPF)
{
    int i;

    for (i = 0; i < qm; i++, m++)
    {
        if (strcmp(m->CPF, aux_CPF) == 0)
        {
            return i;
        } // if
    } // for
    return -1;
} // buscaCPF

void trocaPatente(militar *m, int qm, carreira *c, int qc)
{
    int pos;
    char aux_cpf[13], aux_org[20], aux_pat[20];

    printf("CPF: ");
    gets(aux_cpf);
    fflush(stdin);

    pos = buscaCPF(m, qm, aux_cpf);

    if (pos == -1)
    {
        printf("\nCPF nao encontrado...\n");
    }
    else
    {
        printf("\nNova organização: ");
        gets(aux_org);
        fflush(stdin);
        maiuscula(aux_org);

        printf("\nNova patente: ");
        gets(aux_pat);
        fflush(stdin);
        maiuscula(aux_org);

        (c + ((m + pos)->numreg) - 1)->qmilitar--;
        (m + pos)->numreg = buscaPatente(c, qc, aux_org, aux_pat);

        if ((m + pos)->numreg == -1)
        {
            printf("\nPatente/organizacao nao encontradas\n\n");
        } // if
        else
        {
            printf("\nAtualizacao realizado com sucesso!\nNovo registro: %i\tNovo salario: R$%.2f\n\n", (m + pos)->numreg, (c + ((m + pos)->numreg) - 1)->salario);
        }
        system("pause");
    } // else

} // trocaPatente

void maiuscula(char *s)
{
    int tam = strlen(s), i;

    for (i = 0; i < tam; i++, s++)
    {
        if (*s >= 'a' && *s <= 'z')
        {
            *s -= 32;
        }
    }
} // maiuscula

void mostra_carreira(carreira *c, int qc)
{
    int i;
    for (i = 0; i < qc; i++, c++)
        printf("\nRegistro: %i\nQtde militares: %i\nOrganizacao: %s\nPatente: %s\nSalario: R$%.2f\n\n", c->reg, c->qmilitar, c->org, c->patente, c->salario);
    system("pause");
} // mostra_carreira

void mostra_militar(militar *m, int qm)
{
    int i;
    for (i = 0; i < qm; i++, m++)
        printf("\nCPF: %s\nNome: %s\nNum do Registro: %i\n\n", m->CPF, m->nome, m->numreg);
    system("pause");
} // mostra_militar