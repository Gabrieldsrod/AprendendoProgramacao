// Ler e armazenar 2 notas, verificar se estão no intervalo de 0 à 10. Calcular a média para 100
// alunos (utilizar matrizes) e verificar :
// se m >= 7 – imprimir APROVADO
// se 4 <= m < 7 – imprimir EXAME
// se m < 4 – imprimir REPROVADO.

#include <stdio.h>

void verificar_situacao(float *media, int size);

int main()
{
    float notas[10][2];
    float medias[10];
    int i, j;

    for (i = 0; i < 10; i++)
    {
        printf("Aluno %d:\n", i + 1);
        for (j = 0; j < 2; j++)
        {
            do
            {
                printf("Digite a nota %d (entre 0 e 10): ", j + 1);
                scanf("%f", &notas[i][j]);

                if (notas[i][j] < 0 || notas[i][j] > 10)
                {
                    printf("Nota invalida! Digite uma nota entre 0 e 10.\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }

        medias[i] = (*(notas[i]) + *(notas[i] + 1)) / 2.0; // ou medias[i] = (notas[i][0] + notas[i][1]) / 2.0;

        printf("\n");
    }

    verificar_situacao(medias, 10);

    return 0;
}

void verificar_situacao(float *media, int size)
{
    for (int i = 0; i < size; i++, media++)
    {
        printf("Aluno %d: ", i + 1);

        if (*media >= 7.0)
        {
            printf("Media: %.2f - APROVADO\n", *media);
        }
        else if (*media >= 4.0 && *media < 7.0)
        {
            printf("Media: %.2f - EXAME\n", *media);
        }
        else
        {
            printf("Media: %.2f - REPROVADO\n", *media);
        }
    }
}
