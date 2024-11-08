#include<stdio.h>

int main()
{
    float km, l, cm;
    printf("Vamos calcular o consumo medio da sua viagem.\n");
    printf("Insira a distancia percorrida (em km): ");
    scanf("%f", &km);

    printf("Insira quantos litros foram gastos: ");
    scanf("%f", &l);

    cm = km / l;

    printf("O consumo medio de combustivel nesta viagem foi de %.2fkm/litro.\n", cm);
    return 0;

}