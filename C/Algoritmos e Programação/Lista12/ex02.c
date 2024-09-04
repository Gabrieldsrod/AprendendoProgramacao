// Elabore um programa que leia o preço de uma mercadoria e o percentual
// de reajuste e chame função que receba estes valores como parâmetro e
// retorne o novo preço da mercadoria com reajuste. Na função main( ) deve
// ser mostrado o preço da mercadoria depois do aumento, bem como o
// percentual aplicado.

#include<stdio.h>

float reajuste(float preco, float percentual);

int main() {
    float preco_mercadoria;
    float perc_reajuste;
    float preco_reajustado;

    printf("Qual o preco da mercadoria?\nR$");
    scanf("%f", &preco_mercadoria);

    printf("Qual o percentual do reajuste?\n");
    scanf("%f", &perc_reajuste);

    preco_reajustado = reajuste(preco_mercadoria, perc_reajuste);
    printf("\nNovo preco da mercadoria com reajuste de %.2f%%: R$%.2f\n", perc_reajuste, preco_reajustado);
}

float reajuste(float preco, float percentual) {
    float  ajuste;

    ajuste = preco * ((percentual / 100) + 1);
    return ajuste;
}