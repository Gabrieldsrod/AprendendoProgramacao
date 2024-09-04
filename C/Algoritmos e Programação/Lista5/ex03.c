// Solicitar quantos números o usuário deseja informar, receber cada um
// deles e mostrar a média aritmética dos valores positivos no final.
#include <stdio.h>
#include <conio.h>

int main()
{
    int x, num, pos = 0;
    float soma = 0;
    float media;
    int i;

    printf("Quantos numeros deseja informar?\n");
    scanf("%i", &x);

    printf("Digite os numeros:\n");

    for (i = 1; i <= x; i++)
    {
        printf("%io numero: ", i);
        scanf("%i", &num);

        if (num > 0)
        {
            soma += num;
            pos++;
        }
    }

    media = soma / pos;

    printf("A media somente dos positivos \x82: %.2f", media2);

    getch();
    return 0;
}