// Receber 10 números e, ao final, informar quantos são positivos e quantos
// são negativos.
#include <stdio.h>
#include <conio.h>

int main ()
{
    int num, pos = 0, neg = 0;
    int i;

    printf("Digite 10 numeros:\n");
    for (i=0;i<10;i++)
    {
        scanf("%i", &num);

        if(num > 0)
        {
            pos++;
        }
        else if(num < 0)
        {
            neg++;
        }
    }
    
    printf("\n%i POSITIVOS\n%i NEGATIVOS", pos, neg);

    getch();
    return 0;
}