// Elabore um programa que leia um ano e chame uma função que receba
// como parâmetro o ano e retorne 1 se for um ano bissexto e 0 se não for
// um ano bissexto. A função main( ) deve mostrar a mensagem apropriada. 
#include<stdio.h>

void bissexto(int ano)
{
    if ((ano % 4 == 0 && ano % 100 != 0 ) || ano % 400 == 0) // Ano Bissexto 
    {
        printf("O ano \x82 bissexto");
    }
    else // Ano nao bissexto
    {
        printf("O ano nao \x82 bissexto");
    }
}

int main()
{
    int ano;

    printf("Vamos verificar se um ano \x82 bissexto ou nao!\n");
    printf("Digite um ano qualquer: ");
    scanf("%i", &ano);

    bissexto(ano);
}