// Criar um programa que exibe todos os números ímpares de 0 a 100
// utilizando do-while.

#include <stdio.h>

int main()
{
    int num = 0;
    do
    {
        if (num % 2 != 0)
        {
            printf("%i\n",num);
        }
        num++;
    } while (num <=100);
}
