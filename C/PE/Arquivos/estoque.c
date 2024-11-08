#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct dados
{
    int reg;
    char produto[20];
    int qtde;
    float preco;
} dados;

void aloca_dados(dados **p, int tam);
void registra_dados(dados *p, int reg);

void grava(dados *p);
int verifica();

void mostra(dados *p, int qreg);

int main()
{
    dados *pdados = NULL;
    char op;
    int qreg;

    aloca_dados(&pdados, 1);
    qreg = verifica();
    do
    {
        registra_dados(pdados, qreg);
        qreg++;

        printf("Deseja registrar mais dados?\n<S/N> : ");
        scanf("%c", &op);
        fflush(stdin);

    } while (op == 'S' || op == 's');

    return 0;
} // main

void aloca_dados(dados **p, int tam)
{
    if ((*p = (dados *)realloc(*p, tam * sizeof(dados))) == NULL)
    {
        exit(1);
    }
} // aloca_dados

void registra_dados(dados *p, int reg)
{
    p->reg = reg;
    printf("\nRegistro: %i", p->reg);

    printf("\nProduto: ");
    gets(p->produto);
    fflush(stdin);

    printf("\nQtd estoque: ");
    scanf("%i", &p->qtde);
    fflush(stdin);

    printf("\nPreco: R$");
    scanf("%f", &p->preco);
    fflush(stdin);

    grava(p);
} // registra_dados

void grava(dados *p)
{
    FILE *fptr = NULL;

    if ((fptr = fopen("estoque.bin", "ab")) == NULL)
    {
        printf("\nErro ao abrir o arquivo!");
    }
    else
    {
        fwrite(p, sizeof(dados), 1, fptr);
    }
    fclose(fptr);
} // grava

int verifica()
{
    long int cont = 0;
    FILE *fptr = NULL;

    if((fptr = fopen("estoque.bin", "rb")) == NULL)
    {
        return cont;
    }
    else
    {
        fseek(fptr, 0, 2); // posiciona no fim do arquivo
        cont = ftell(fptr)/sizeof(dados); // qtd registros no arquivo
        fclose(fptr); // fecha o arquivo
        return cont;
    }
    
} // verifica

void mostra(dados *p, int qreg)
{
    int i;
    FILE *fptr = NULL;
    system("cls");

    if((fptr = fopen("estoque.bin", "rb")) == NULL)
    {
        printf("\nErro ao abrir o arquivo");
    }
    else
    {
        for (i = 0; i < qreg; i++)
        {
            fseek(fptr, i*sizeof(dados), 0);
            fread(p, sizeof(dados), 1, fptr);
            printf("/nRegistro: %i\nProduto: %s\n Qtde: %i\nPreco: %.2f", p->reg, p->produto, p->qtde, p->preco);
        }
        fclose(fptr);
    }
} // mostra
