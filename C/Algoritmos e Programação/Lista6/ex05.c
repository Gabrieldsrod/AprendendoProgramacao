// Criar um programa de calculadora que vai realizando os cálculos entre
// dois números enquanto o usuário desejar. Criar um menu de opções
// conforme mostrado a seguir:
// 1 – Soma
// 2 – Subtração
// 3 – Multiplicação
// 4 – Divisão
// 5 – Sair

#include <stdio.h>
#include <conio.h>

int main()
{
    int op;
    float num1, num2, resultado;

    do
    {
        printf("\nEscolha uma operacao:\n");
        printf("[1]Soma\n");
        printf("[2]Subtracao\n");
        printf("[3]Multiplicacao\n");
        printf("[4]Divisao\n");
        printf("[5]Sair\n");
        scanf("%i", &op);

        switch (op)
        {
            case 1:
                printf("\nDigite um numero: ");
                scanf("%f", &num1);
                printf("Digite outro numero: ");
                scanf("%f", &num2);

                resultado = num1 + num2;
                printf("Resultado da soma: %.2f\n", resultado);
                printf("Pressione ENTER para continuar...\n");

                getch();
                break;

            case 2:
                printf("\nDigite um numero: ");
                scanf("%f", &num1);
                printf("Digite outro numero: ");
                scanf("%f", &num2);

                resultado = num1 - num2;
                printf("Resultado da subtracao: %.2f\n", resultado);
                printf("Pressione ENTER para continuar...\n");

                getch();
                break;
            
            case 3:
                printf("\nDigite um numero: ");
                scanf("%f", &num1);
                printf("Digite outro numero: ");
                scanf("%f", &num2);

                resultado = num1 * num2;
                printf("Resultado da multiplicacao: %.2f\n", resultado);
                printf("Pressione ENTER para continuar...\n");

                getch();
                break;
            
            case 4:
                do
                {
                    printf("\nDigite o dividendo: ");
                    scanf("%f", &num1);
                    printf("Digite o divisor: ");
                    scanf("%f", &num2);

                    if(num2 != 0)
                    {
                        resultado = num1 / num2;
                        printf("Resultado da divisao: %.2f\n", resultado);
                        printf("Pressione ENTER para continuar...\n");

                        getch();
                    }
                    else
                    {
                        printf("ERRO: DIVISAO POR ZERO!!!\n");
                        printf("Digite outro numero para realizar o calculo...\n");
                    }
                }while (num2 == 0);
                break;
            
            case 5:
                printf("\nEncerrando o programa...\n");
                return 0;

            default:
                printf("Opcao invalida!\n");
                printf("Pressione ENTER para continuar...\n");

                getch();
                break;
        }
    } while (op != 5);
}