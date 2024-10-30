#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
    char nome[80];
    char RA[7];
    float nota[2]; // nota de 2 provas
    float media;   // média arimética das provas
} aluno;

void aloca(aluno **p, int tam);
void cadastro(aluno *p);
int buscar(aluno *p, int tam);
void alterarNota(aluno *p);
void media(aluno *p);
void mostraNotas(aluno *p);

int main()
{
    aluno *alu = NULL;
    int cont = 0, op, opnotas, localizador;

    do
    {
        system("cls");
        printf("Diario Eletronico\n\n");
        printf("Qual operacao deseja realizar?\n");
        printf("[1]Cadastro de Alunos\n[2]Controle de Notas\n[3]Sair\nEscolha: ");
        scanf("%i", &op);
        fflush(stdin);

        switch (op)
        {
        case 1:
            aloca(&alu, cont + 1);
            cadastro(alu + cont);
            cont++;
            break;
        case 2:
            system("cls");
            localizador = buscar(alu, cont);
            if (localizador == -1)
            {
                printf("RA invalido");
                break;
            }
            else
            {
                printf("\n\nRA %s: %s", (alu + localizador)->RA, (alu + localizador)->nome);

                do
                {
                    printf("\nO que deseja fazer?\n");
                    printf("[1]Mostrar nota\n[2]Alterar nota\n[3]Cancelar\n");
                    printf("Escolha: ");
                    scanf("%i", &opnotas);

                    switch (opnotas)
                    {
                    case 1:
                        mostraNotas(alu + localizador);
                        break;

                    case 2:
                        alterarNota(alu + localizador);
                        break;

                    case 3:
                        break;
                    }
                } while (opnotas != 3);
                break;
            }
        } // switch
    } while (op != 3);

    printf("\n");
    system("pause");
    return 0;
} // main

void aloca(aluno **p, int tam)
{
    if ((*p = (aluno *)realloc(*p, tam * sizeof(aluno))) == NULL)
    {
        exit(1);
    }
} // aloca

void cadastro(aluno *p)
{
    int i;

    printf("\nNome: ");
    gets(p->nome);
    fflush(stdin);
    printf("RA: ");
    gets(p->RA);
    fflush(stdin);
    for (i = 0; i < 2; i++)
    {
        printf("Nota %i: ", i + 1);
        scanf("%f", &p->nota[i]);
    }

    media(p);
    printf("Aluno cadastrado!\n");
    system("pause");
} // cadastro

int buscar(aluno *p, int tam)
{
    char aux_busca[7];
    int i;

    printf("\nRA do aluno: ");
    gets(aux_busca);
    fflush(stdin);

    for (i = 0; i < tam; i++)
    {
        if (strcmp(aux_busca, (p + i)->RA) == 0)
        {
            return i;
        }
    }
    return -1;
} // buscar

void alterarNota(aluno *p)
{
    char op;
    int opprova, i;

    printf("\nDeseja alterar alguma nota deste aluno?\n<S/N>: ");
    scanf(" %c", &op);
    fflush(stdin);
    if (op == 'S' || op == 's')
    {
        printf("\nQual nota deseja alterar?\n");
        printf("[0]Ambas\n[1]Nota 1\n[2]Nota 2\n[3]Cancelar\n");
        printf("Escolha: ");
        scanf("%i", &opprova);

        switch (opprova)
        {
        case 0:
            for (i = 0; i < 2; i++)
            {
                printf("Nota %i: ", i + 1);
                scanf("%f", &p->nota[i]);
                fflush(stdin);
            }
            media(p);
            break;
        case 1:
            printf("Nota 1: ");
            scanf("%f", &p->nota[0]);
            fflush(stdin);
            media(p);
            break;
        case 2:
            printf("Nota 2: ");
            scanf("%f", &p->nota[1]);
            fflush(stdin);
            media(p);
            break;
        case 3:
            break;
        } // switch
    } // if
} // alterar nota

void media(aluno *p)
{
    float soma = 0;
    int i;

    for (i = 0; i < 2; i++)
    {
        soma += *(p->nota + i);
    }

    soma /= 2;

    p->media = soma;
} // media

void mostraNotas(aluno *p)
{
    int i;
    for (i = 0; i < 2; i++)
    {
        printf("Nota %i: %.2f", i + 1, p->nota[i]);
    }
    printf("Media: %.2f", p->media);
    system("pause");
} // mostra notas