// Escreva um programa para receber o saldo inicial de uma conta bancária
// de um cliente. A seguir ler um número indeterminado de pares de valores
// indicando respectivamente o tipo da operação, sendo: 1.Depósito
// 2.Retirada 3.Fim e também o valor. Quando for informado para o tipo o
// código 3, o programa deve ser encerrado e impresso o saldo final da
// conta com as seguintes mensagens: CONTA ZERADA, CONTA
// ESTOURADA (se o saldo for negativo) ou CONTA PREFERENCIAL (se o
// saldo for positivo)

#include <stdio.h>
#include <conio.h>

int main()
{
    int opcao;
    float saldo_inicial, saldo_atual, valor;

    printf("Digite seu saldo inicial:\nR$");
    scanf("%f", &saldo_inicial);

    saldo_atual = saldo_inicial;

    do
    {
        printf("\nDigite o numero do tipo de operacao desejado:\n");
        printf("[1]Deposito\n[2]Retirada\n[3]Sair\n");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nDigite o valor do deposito:\nR$");
            scanf("%f", &valor);

            saldo_atual += valor;

            printf("Pressione ENTER para continuar...\n");
            getch();
            
            break;
        
        case 2:
            printf("\nDigite o valor do saque:\nR$");
            scanf("%f", &valor);

            saldo_atual -= valor;
            
            printf("Pressione ENTER para continuar...\n");
            getch();
            break;
        
        case 3:
            if(saldo_atual ==0)
            {
                printf("\nCONTA ZERADA\n");
            }
            else if (saldo_atual < 0)
            {
                printf("\nCONTA ESTOURADA\n");
            }
            else
            {
                printf("\nCONTA PREFERENCIAL\n");
            }

            printf("Saldo final da conta: R$%.2f", saldo_atual);
            
            break;

        default:
            printf("\nTipo de operacao invalida!\n");
            printf("Pressione ENTER para tentar novamente...");
            getch();

            break;
        }
    }while (opcao != 3);
}