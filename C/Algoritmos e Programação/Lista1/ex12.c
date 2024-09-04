#include <stdio.h>

int main() 
{
    int hn, he;
    float sal;

    printf("Digite o total de horas normais trabalhadas no mes: ");
    scanf("%d", &hn);

    printf("Digite o total de horas extras trabalhadas no mes: ");
    scanf("%d", &he);

    sal = (hn * 10) + (he * 15);

    printf("O salario total do empregado e: R$ %.2f\n", sal);

    return 0;
}
