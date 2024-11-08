#include <stdio.h>


main()
{
    int base, alt, area;
    printf("Vamos calcular o valor da area de um triangulo!!\n");
    printf("Digite o valor da base: ");
    scanf("%i", &base);
    printf("Qual a altura? ");
    scanf("%i", &alt);

    area = (base*alt)/2;
    printf("A base do triangulo equivale a %i", area);
    
}