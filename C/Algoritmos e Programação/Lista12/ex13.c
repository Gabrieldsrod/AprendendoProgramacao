// 13. Elabore um programa que recebe uma string e um caractere. Na
// sequência invoque duas funções cujos objetivos são:
// a) retornar o número de vezes que esse caractere aparece na string;
// b) retornar um número inteiro que indica o índice da primeira ocorrência
// do caractere na string, isto é se o caractere for encontrado, caso contrário
// retorne -1.

#include<stdio.h>
#include<ctype.h>

int contar_ocorrencias(char str[], char caractere) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (toupper(str[i]) == toupper(caractere)) {
            count++;
        }
    }

    return count;
}

int indice_primeira_ocorrencia(char str[], char caractere) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (toupper(str[i]) == toupper(caractere)) {
            return i;
        }
    }
    return -1;
}

int main() {
    char string[100];
    char caractere;

    printf("Digite uma string: ");
    gets(string);

    printf("Digite um caractere para verificar sua presenca na string: ");
    scanf(" %c", &caractere);

    int ocorrencias = contar_ocorrencias(string, caractere);
    printf("O caractere %c, aparece %i vezes na string.\n", caractere, ocorrencias);

    int primeira_ocorrencia = indice_primeira_ocorrencia(string, caractere);
    if (primeira_ocorrencia != -1) {
        printf("Primeira ocorrencia de %c: indice %i\n", caractere, primeira_ocorrencia);
    }   else {
        printf("O caractere nao se encontra na string\n.");
    }

    return 0;
}
