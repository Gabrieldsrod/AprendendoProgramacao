// Escreva um programa com uma função que receba 3 valores de entrada e
// retorne o maior valor entre estes três valores.

#include<stdio.h>

int maior_valor (int x, int y, int z) {
    if (x >= y && x >= z) {
        return x;
    }
    else if (y >= x && y >= z) { 
        return y;
    }
    else {
        return z;
    }
}

int main() {
    int valor1, valor2, valor3;

    printf("Digite o primeiro valor: ");
    scanf("%i", &valor1);

    printf("Digite o segundo valor: ");
    scanf("%i", &valor2);

    printf("Digite o terceiro valor: ");
    scanf("%i", &valor3);

    printf("Maior valor: %i\n", maior_valor(valor1, valor2, valor3));

    return 0;
}