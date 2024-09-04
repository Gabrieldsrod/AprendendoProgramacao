// Receber números enquanto o usuário quiser digitá-los (a cada número
// informado peça que o usuário digite 1 se quiser informar mais um número
// ou 2 se quiser parar). No final, exibir:
//  o maior número;
//  a média aritmética dos números.

#include <stdio.h>

int main()
{
    int num = -9999;
    float soma = 0;
    float media;
    int maior = 0;
    int qnt = 0;
    int stp = 0;


    do
    {
        printf("Digite um numero: ");
        scanf("%i", &num);
        qnt++;
        soma += num;

        if(num > maior)
        {
            maior = num;
        }

        printf("Deseja continuar?\n[1]Sim\n[2]Nao\n");
        scanf("%i", &stp);

        while (stp != 1 && stp != 2) 
        {
            printf("Opcao invalida.\nDeseja continuar?\n[1]Sim\n[2]Nao\n");
            scanf("%d", &stp);
        }

        printf("\n");
    } while (stp == 1);
    
    media = soma / qnt;

    printf("Maior numero: %i\n", maior);
    printf("Media aritmetica do numeros: %.2f\n", media);
}