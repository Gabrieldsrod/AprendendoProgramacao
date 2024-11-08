#include <stdio.h>

int main()
{
    float s, t, vm;

    printf("Vamos calcular a velocidade media do percurso.\n");

    printf("Quantos km foram percorridos? ");
    scanf("%f", &s);

    printf("Em quantas horas foi realizado o percurso?");
    scanf("%f", &t);

    vm = s / t;

    printf("A velocidade media do veiculo neste percurso corresponde a %.2f.\n", vm);
    return 0;

}
