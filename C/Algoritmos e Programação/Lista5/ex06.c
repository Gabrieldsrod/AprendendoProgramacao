// Desenvolver um programa que recebe a altura e o sexo (1 para
// masculino, 2 para feminino) de 15 pessoas. Este programa deverá
// mostrar no final:
// - a menor altura do grupo;
// - a média de altura das mulheres;
// - o número de homens;
// - o sexo da pessoa mais alta.

#include <stdio.h>

#define MASCULINO 1
#define FEMININO 2

int main()
{
    float altura, medialt, somam;
    float menor = 999;
    float maiorm = 0;
    float maiorf = 0;
    int sexo, i;
    int homens = 0, mulheres = 0;

    for(i=1;i<=15;i++)
    {
        printf("Qual a sua altura?\n");
        scanf("%f", &altura);

        printf("Qual o seu sexo?\n[1]Masculino\n[2]Feminino\n");
        scanf("%i", &sexo);

        if (sexo == MASCULINO)
        {
            homens++;
            if(altura < menor)
            {
                menor = altura;
            }
            
            if(altura > maiorm)
            {
                maiorm = altura;
            }
        }

        else if (sexo == FEMININO)
        {
            mulheres++;
            somam += altura;

            if(altura < menor)
            {
                menor = altura;
            }

            if(altura > maiorf)
            {
                maiorf = altura;
            }
        }

        else
        {
            printf("Sexo invalido");
            i--;
        }
        printf("\n");
    }

    medialt = somam / mulheres;

    printf("O menor do grupo tem %.2fm\n", menor);

    if (mulheres > 0)
    {
        medialt = somam / mulheres;
        printf("A media de altura das mulheres e %.2f metros\n", medialt);
    }
    else
    {
        printf("Não ha mulheres no grupo para calcular a media de altura\n");
    }

    printf("O numero de homens e %i\n", homens);

    if (maiorm > maiorf)
    {
        printf("O sexo do maior e MASCULINO\n");
    }
    else if(maiorf > maiorm)
    {
        printf("O sexo do maior e FEMININO\n");
    }
}