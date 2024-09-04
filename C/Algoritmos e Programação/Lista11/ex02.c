// Escreva um programa que receba uma palavra que contenha no máximo
// 10 caracteres e no mínimo 3. Caso a palavra digitada não esteja de
// acordo, informe a quantidade de caracteres digitados e leia uma nova
// palavra.

#include <stdio.h>
#include <string.h>

int main() {
    char palavra[99]; // Espaço para 10 caracteres + terminador nulo
    int tamanho;

    do {
        printf("Digite uma palavra (3 a 10 caracteres): ");
        scanf("%s", palavra);
        tamanho = strlen(palavra);

        if (tamanho < 3 || tamanho > 10) {
            printf("A palavra tem %i caracteres. Por favor, digite novamente.\n", tamanho);
        }
    } while (tamanho < 3 || tamanho > 10);

    printf("Palavra valida: %s\n", palavra);

    return 0;
}