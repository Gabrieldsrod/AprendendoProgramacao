#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIARIA_S 85;
#define DIARIA_F 45;

typedef struct hospede
{
    int quarto; // número do quarto
    char nome[80];
    int acompanhante; // quantidade de acompanhantes
    char categoria;   // [S]olteiro / [F]amiliar
    int dias;         // tempo de permanência – em dias
} hospede;

typedef struct quarto
{
    int num;        // número do quarto
    char categoria; // [S]olteiro / [F]amiliar
    char status;    // [L]ivre / [O]cupado
} quarto;

void aloca_quarto(quarto **p, int tam);
void aloca_hospede(hospede **p, int tam);
void checkin(hospede *ph, quarto *pq);

int main()
{
    hospede *hsp = NULL;
    quarto *qrt = NULL;
    int cont = 0, op, i;

    do
    {
        system("cls");
        printf("Controle de Quarto/Hospedes");
        printf("[1]Check-in\n[2]Check-out\n[3]Sair\nEscolha: ");
        scanf("%i", op);
        fflush(stdin);

        for (i = 0; i < 15; i++)
        {
            aloca_quarto(&qrt, i + 1);

            (qrt + i)->num = i + 1;
            (qrt + i)->status = 'L';

            if (i < 5)
            {
                (qrt + i)->categoria = 'S';
            }
            else
            {
                (qrt + i)->categoria = 'F';
            }
        }

        switch (op)
        {
        case 1:
            aloca_hospede(&hsp, cont + 1);
            checkin(hsp + cont, qrt);
            cont++;
            break;

        default:
            break;
        }
    } while (op != 3);

    return 0;
} // main

void aloca_quarto(quarto **p, int tam)
{
    if ((*p = (quarto *)realloc(*p, tam * sizeof(quarto))) == NULL)
    {
        exit(1);
    }
} // aloca quarto

void aloca_hospede(hospede **p, int tam)
{
    if ((*p = (hospede *)realloc(*p, tam * sizeof(hospede))) == NULL)
    {
        exit(1);
    }
} // aloca hospede

void checkin(hospede *ph, quarto *pq)
{
    int verifica, acomp;
    char categoria;

    printf("\n-----------Check-in----------\n");

    do
    {
        printf("Quantos acompanhates?\n");
        scanf("%i", ph->acompanhante + 1);

        if (ph->acompanhante > 1)
        {
            ph->categoria = 'F';
        }
    } while (ph->acompanhante < 0);

} // checkin
