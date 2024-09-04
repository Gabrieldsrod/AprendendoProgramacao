// Escreva um programa que calcule todos os números inteiros divisíveis por
// um certo valor indicado pelo usuário, e compreendidos em um intervalo
// também especificado pelo usuário. O usuário deve entrar com um
// primeiro valor correspondente ao divisor e após ele vai fornecer o valor
// inicial do intervalo, seguido do valor final deste intervalo.

#include<stdio.h>

int main()
{
    int ini, fim, div, num;

    printf("Digite o valor do divisor: ");
    scanf("%i", &div);
    printf("Digite o inicio do intervalo: ");
    scanf("%i", &ini);
    printf("Digite o final do intervalo: ");
    scanf("%i", &fim);
    printf("\n");

    num = ini;

    while (num <= fim)
    {
        if (num % div == 0)
        {
            printf("%i\n", num);
        }
        num++;
    }

}