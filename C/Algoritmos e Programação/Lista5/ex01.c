// Solicitar quantos números o usuário deseja informar, receber cada um
// deles e mostrar a média aritmética no final.

#include <stdio.h>
#include <conio.h>

int main ()
{
    int x, num;
    float soma = 0, media;
    int i;

    printf("Quantos numeros devo solicitar?\n");
    scanf("%i", &x);

    printf("Digite os numeros:\n");

    for(i=1;i<=x; i++)
    {
        printf("%i° numero: ", i);
        scanf("%i", &num);
        soma += num;
    }

    media=soma/x;

    printf("A media aritm\x82tica destes numeros \x82: %.2f", media);

    
    getch();
    return 0;
}