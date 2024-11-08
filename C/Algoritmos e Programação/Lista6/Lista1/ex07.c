#include<stdio.h>

int main()
{
    int c, f;
    printf("Vamos converter Fahrenreit para Celcius!!!");
    printf("Digite a tempereatura em F: ");
    scanf("%i", &f);

    c = (f-32)/1.8;
    printf("%iF em Celcius equivalem a %iC", f, c);
    return 0;
}
