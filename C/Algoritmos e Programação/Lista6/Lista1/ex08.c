#include<stdio.h>

int main()
{
    float raio, c;
    printf("Vamos calcular o perimetro de uma circuferencia.\n");
    printf("Digite o valor do raio:\t");
    scanf("%f", &raio);

    c = 2 * 3.14 * raio;
    printf("O perimetro desta circuferencia equivale a %.2f\n", c);

}