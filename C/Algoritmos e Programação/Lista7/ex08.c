// Receber números do usuário para preencher um vetor de 10 posições,
// porém, só é permitido armazenar no vetor números positivos (repetir até que
// as 10 posições do vetor estejam preenchidas). No final, exiba a soma de
// todos os números que estão nas posições ímpares do vetor.

#include <stdio.h>

int main() {
    int numpos[10];
    int num;
    int soma_posicoes_impares = 0;

    printf("Digite 10 numeros positivos:\n");

    for (int i = 0; i < 10; i++) 
    {
        do 
        {
            printf("Numero %i: ", i + 1);
            scanf("%i", &num);

            if (num > 0) 
            {
                numpos[i] = num;
            } 
            else 
            {
                printf("Numero invalido! Insira um valor POSITIVO.\n");
            }
        } while (num <= 0);
    }

    for (int i = 0; i < 10; i++) 
    {
        if (i % 2 != 0) 
        {
            soma_posicoes_impares += numpos[i];
        }
    }

    printf("\nSoma dos numeros nas posicoes impares do vetor: %i\n", soma_posicoes_impares);
}
