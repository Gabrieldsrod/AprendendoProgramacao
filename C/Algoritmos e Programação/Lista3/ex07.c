// Receber os três lados de um triângulo em qualquer ordem (chame de
// lado1, lado2 e lado3) e classificá-lo em equilátero, isósceles ou escaleno.

#include <stdio.h>

int main()
{
    int lado1, lado2, lado3;

    printf("Digite os valores dos lados de\n um triangulo para classifica-lo.\n");

    printf("Lado 1: ");
    scanf("%i", &lado1);

    printf("Lado 2: ");
    scanf("%i", &lado2);

    printf("Lado 3: ");
    scanf("%i", &lado3);

    if (lado1 == lado2 && lado1 == lado3)
    {
        printf("O triangulo e equilatero.");
    }

    else if (lado1 == lado2  || lado1 == lado3 || lado2 == lado3)
    {
        printf("O triangulo e isosceles");
    }

    else
    {
        printf("O triangulo e escaleno");
    }

}