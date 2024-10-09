// Dado a estrutura abaixo, implemente uma rotina de cadastro, deve-se consultar o usuário
// para continuar. O registro deve ser gerado automaticamente pelo sistema. Utilizar
// alocação dinâmica e ponteiros para a estrutura.
// struct agenda{
// int reg;
// char nome[80];
// float nota;
// };

#include <stdio.h>
#include <stdlib.h>

typedef struct agenda
{
    int reg;
    char nome[80];
    float nota;
} agenda;

agenda cadastro();

int main()
{
    agenda a1[10];
    char op;
    int i, cont = 0;

    system("cls");
    printf("Cadastro de alunos\n");
    
    do {
        if (cont < 10)
        {
            a1[cont] = cadastro();
            cont++;
        }
        else
        {
            printf("Cadastro lotado\n");
        }

        printf("Deseja continuar? <S/N>: ");
        scanf(" %c", &op);
        printf("\n");
        fflush(stdin);
    } while (op != 'N' && op != 'n');

    for (i = 0; i < cont; i++)
    {
        printf("\nRegistro: %i\nNome: %s\nNota: %.2f\n", a1[i].reg, a1[i].nome, a1[i].nota);
    }

    return 0;
}

agenda cadastro()
{
    agenda aux;
    static int n = 0;

    aux.reg = n++;
    printf("Nome: ");
    gets(aux.nome);
    fflush(stdin);
    printf("Nota: ");
    scanf("%f", &aux.nota);
    fflush(stdin);

    return aux;
}
