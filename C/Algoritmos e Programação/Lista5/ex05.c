// A prefeitura de uma cidade de 15 habitantes fez uma pesquisa coletando
// salário e número de filhos de cada um. A prefeitura deseja saber:
// - média do salário da população;
// - média do número de filhos;
// - maior salário;
// - percentual de pessoas com salário até R$ 500,00.
#include <stdio.h>
#include <conio.h>

int main()
{
    int habit = 15;
    float sal, maiorsal = 0, somasal = 0;
    int filhos, somafil = 0, cont500 = 0;
    float medsal, medfil, percsal;
    int i;

    for (i = 1; i <= habit; i++)
    {
        printf("\nHabitante %i\n", i);

        printf("Quanto \x82 o seu salario?\nR$");
        scanf("%f", &sal);
        somasal += sal;

        if (sal > maiorsal)
        {
            maiorsal = sal;
        }

        if (sal <= 500.00)
        {
            cont500++;
        }

        printf("Quantos filhos voce tem?\n");
        scanf("%i", &filhos);
        somafil += filhos;
    }
    
    medfil = somafil / habit;

    medsal = somasal / habit;

    percsal = (float)cont500 / habit * 100;

    printf("\nMedia salarial: R$%.2f\n", medsal);
    printf("Media de filhos: %.2f\n", medfil);
    printf("Maior salario: R$%.2f\n", maiorsal);
    printf("Salarios maiores que R$500.00: %.2f%%", percsal);

    getch();
    return 0;
}