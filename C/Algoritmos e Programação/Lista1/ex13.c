#include <stdio.h>

int main()
{
    int dias;
    float vl, vb, imp;

    printf("Quantos dias foram trabalhados?\n");
    scanf("%i", &dias);

    vb = dias * 35;
    imp = vb * 0.08;
    vl = vb - imp;

    printf("O valor a ser pago ao encanador e de R$%2.f", vl);
    return 0;

}
