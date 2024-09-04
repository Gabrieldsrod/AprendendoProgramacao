// Dada uma seqüência de n números reais, determine os números que
// compõem a seqüência e o número de vezes que cada um deles ocorre na
// mesma.

#include <stdio.h>

#define MAX 100

int main() {

    int n, i, j;
    int conta[MAX] = {0};    /* contador de repeticoes de cada numero da sequencia */
    int comp = 0;            /* comprimento do vetor conta                         */		
    float seq[MAX];          /* sequencia de entrada sem repeticoes                */
    float num;

    printf("\nDigite o comprimento da sequencia: ");
    scanf("%d", &n);

    if (n > MAX) 
    {
        printf("O comprimento da sequencia excede o limite maximo de %d.\n", MAX);
        return 1;
    }

    printf("Digite uma sequencia de %d numeros reais: ", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%f", &num);
        /* procura esse numero no vetor seq a partir do inicio */
        for (j = 0; j < comp; j++) 
        {
            if (seq[j] == num) 
            {
                break;
            }
        }
        if (j == comp) 
        {
            /* se o numero nunca tinha aparecido */
            seq[comp] = num;
            conta[comp] = 1;
            comp++;
        }
        else 
        {
            conta[j]++;
        }
    }

  /* imprime o resultado */
    for (j = 0; j < comp; j++) 
    {
        printf("O numero %.2f aparece %d vezes na sequencia.\n", seq[j], conta[j]);
    }

    return 0;
}