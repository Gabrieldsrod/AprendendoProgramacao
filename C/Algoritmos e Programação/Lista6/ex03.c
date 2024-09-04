// Receber a nota de um aluno no módulo 1 e no módulo 2 e calcular a
// média deles. O usuário só pode digitar notas no intervalo de 0 a 10, caso
// ele digite um valor inválido, deve digitar novamente.

#include <stdio.h>

int main()
{
    float mod1, mod2;
    float media;

    do
    {
        printf("Digite a nota do modulo 1: ");
        scanf("%f", &mod1);

        if(mod1 <0 || mod1 > 10)
        {
            printf("Nota invalida. O valor deve ser de 0 a 10!");
        }
    } while (mod1 <0 || mod1 > 10);
    
    do
    {
        printf("Digite a nota do modulo 2: ");
        scanf("%f", &mod2);

        if(mod2 <0 || mod2 > 10)
        {
            printf("Nota invalida. O valor deve ser de 0 a 10!\n");
        }
    } while (mod2 <0 || mod2 > 10);

    media = (mod1 + mod2) / 2;

    printf("A media das notas e %2.f", media);
}