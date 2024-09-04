/*Você assina um plano de 50 minutos no celular que custa R$ 50.00 por
mês, independente de utilizá-los integralmente ou não. Porém, se você
utilizar mais do que 50 minutos, é cobrado mais R$ 1.50 por cada minuto
que passar dos 50 do seu plano. Receber quantos minutos foram gastos
no mês e calcular o valor da conta.*/
#include<stdio.h>

int main()
{
    int minutos;
    float conta;

    printf("Quantos minutos foram gastos?\n");
    scanf("%i", &minutos);

    if (minutos <= 50)
    {
        conta = 50;
    }
    else
    {
        conta = 50 + (minutos - 50) * 1.5;
    }
    printf("O valor da conta sera de R$%.2f", conta);
}