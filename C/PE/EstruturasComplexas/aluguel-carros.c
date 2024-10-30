// Fazer um programa para LOCADORA DE VEICULOS. Alocar dinamicamente espaço e cadastrar 15 carros,
// sendo 5 [P]equenos, 5 [M]édios e 5 [G]randes (iniciar o status como [L]ivre). Em seguida, fazer o menu para:

// [1]Locação - mostrar todos os carros cadastrados. Em seguida alocar dinamicamente espaço para 1 cliente e, receber 
// o CPF, nome do cliente, tipo de carro e o tempo de permanecia desejado. buscar o numero do carro disponivel,
// de acordo com o tipo. Não esquecer de:
//     - Na estrutura cliente: guardar o numero do carro alugado.
//     - Na estrutura carro: mudar o status para [O]cupado.

// [2]Devolução - encerra a locação e apresenta o relatório, de acordo com o CPF do cliente. Mostrar o nome do cliente,
// o numero do registro do carro, o tipo do carro, o tempo de permanencia em dias e calcular o valor a ser pago. Não
// esquecer de:
//     - na estrutura carro: mudar o status para [L]ivre.

// [3]Fim


// [P]equeno - diária R$150,00 / [M]édio - diária R$200,00 / [G]rande - diária R$250,00


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct carro {
    int     reg_carro;
    char    tipo;
    char    status;
} carro;

typedef struct cliente {
    char    CPF[13];
    char    nome[80];
    int     num_reg;
    int     dias;
} cliente;

void aloca_carro(carro **pcar, int qcar);
void aloca_cliente(cliente **pcli, int qcli);
void cadastra_carro(carro *pcar, int qcar);
void cadastra_cliente(cliente *pcli, carro *pcar);
void devolucao(cliente *pcli, int qcli, carro *pcar, int qcar);
int busca_carro(carro *pcar, char tipo_car);
int busca_CPF(cliente *pcli, int qcli, char *aux);
void mostra_carro(carro  *pcar, int qcar);

main()
{
    carro *car = NULL;
    cliente *cli = NULL;
    int op, cont = 0, pos;

    aloca_carro(&car, 15);

    cadastra_carro(car, 15);

    do {
        system("cls");
        printf("LOCADORA DE VEICULOS\n");
        printf("[1]Locacao\n[2]Devolucao\n[3]Sair\nEscolha: ");
        scanf("%i", &op);
        fflush(stdin);

        switch (op) {
            case 1:
                aloca_cliente(&cli, cont + 1);
                cadastra_cliente(cli + cont, car);
                cont++;
                break;
            case 2:
                devolucao(cli, cont, car, 15);
                break;
        }// switch
    } while (op != 3);
}// main

void aloca_carro(carro **pcar, int qcar)
{
    if(*pcar = (carro *) realloc(*pcar, qcar * sizeof(carro))) {
        exit(1);
    }
}// aloca_carro

void aloca_cliente(cliente **pcli, int qcli)
{
    if(*pcli = (cliente *) realloc(*pcli, qcli * sizeof(cliente))) {
        exit(1);
    }
}// aloca_cliente

void cadastra_carro(carro *pcar, int qcar)
{
    int i;
    for(i = 0; i < qcar; i++, pcar++) {
        pcar->reg_carro = i + 1;
        pcar->status = 'L';
        if(i < 5) {
            pcar->tipo = 'P';
        } else if(i < 10) {
            pcar->tipo = 'M';
        } else {
            pcar->tipo = 'G';
        }
    }
}// cadastra_carro

void cadastra_cliente(cliente *pcli, carro *pcar)
{
    char tipcar;
    int numcar;
    printf("\nTipo de Carro [P - M - G]: ");
    scanf("%c", &tipcar);
    fflush(stdin);
    tipcar = toupper(tipcar);

    numcar = busca_carro(pcar, tipcar);

    if(numcar == -1) {
        printf("\nNao ha carro disponivel desse tipo!\n\n\n");
    } else {
        pcli->num_reg = numcar;
        printf("\nCPF: ");
        gets(pcli->CPF);
        fflush(stdin);
        printf("\nNome: ");
        gets(pcli->nome);
        fflush(stdin);
        printf("\nDias: ");
        scanf("%i", &pcli->dias);
        fflush(stdin);

        (pcar + numcar)->status = 'A';

        printf("\nCadastro feito com sucesso!\nCarro: %i\n\n\n", pcli->num_reg);
    }
    system("pause");
}// cadastra_cliente

void devolucao(cliente *pcli, int qcli, carro *pcar, int qcar){
    char aux_cpf[13], tip;
    int pos, reg, tempo;
    printf("\nCPF a ser encerrado: ");
    gets(aux_cpf);
    fflush(stdin);
    pos = busca_CPF(pcli, qcli, aux_cpf);
    if(pos == -1) {
        printf("\nCPF invalido\n");
    }
    else
    {
        reg  = (pcli + pos)->num_reg;
        (pcar + reg - 1)->status = 'L';
        tip = (pcar + reg - 1)->tipo;
        tempo = (pcli + pos)->dias;

        printf('Tipo de carro: %c\n', tip);
        switch(tip)
        {
            case 'P':
                printf("Valor a ser pago: R$%.2f\n", tempo * 150);
                break;
            case 'M':
                printf("Valor a ser pago: R$%.2f\n", tempo * 200);
                break;
            case 'G':
                printf("Valor a ser pago: R$%.2f\n", tempo * 250);
                break;
        }// switch
    }// else
    system("pause");
}// devolucao

int busca_carro(carro *pcar, char tipo_car)
{
    int i;
    for(i = 0; i < 15; i++) {
        if((pcar+i)->tipo == tipo_car && (pcar+i)->status == 'L') {
            (pcar+i)->status = 'A';
            return (pcar+i)->reg_carro;
        }
    }
    return -1;
}// busca_carro

int busca_CPF(cliente *pcli, int qcli, char *aux)
{
    int i;
    for(i = 0; i < qcli; i++, pcli++) {
        if(strcmp(pcli->CPF, aux) == 0) {
            printf("\nNome: %s\nCarro: %i\nDias: %i\n", pcli->nome, pcli->num_reg, pcli->dias);
            return i;
        }
    }
    return -1;
}// busca_CPF