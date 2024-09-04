// Receber 10 números e, ao final, informar qual é o maior e o menor deles
#include <stdio.h>
#include <conio.h>

int main()
{
    int num = 0, maior, menor;
    int i;

    maior = num;
    menor = num;
    
    printf("Me informe 10 numeros:\n");

    for (i=1;i<=10;i++)
    {
        scanf("%i", &num);

        if (num > maior)
        {
            maior = num;
        }
        else if (num < menor)
        {
           menor = num;
        } 
    }
    printf("\nO menor numero \x82: %i", menor);
    printf("\nO maior numero \x82: %i", maior);

    getch();
    return 0;
}