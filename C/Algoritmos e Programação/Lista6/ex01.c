// Criar um programa que exibe todos os números pares de 0 a 100
// utilizando while.

#include <stdio.h>

int main()
{
    int num=0;

    while (num <= 100)
    {
        if (num % 2 == 0)
        {
            printf("%i\n", num);
        }
        num++;
    }
}