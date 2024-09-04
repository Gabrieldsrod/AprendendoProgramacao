// Faça um programa que, dado um string qualquer, inverta todas as suas letras e apresente isso ao usuário.
// Exemplo:
// String: Alunos da Facens
// Resultado: snecaF ad sonulA

#include <stdio.h>
#include <string.h>

void inverte_string  (char string[99]);

int main() {
    char str[99];

    printf("Digite uma string: ");
    gets(str);

    inverte_string(str);
    return 0;
}

void inverte_string (char string[99]) {
    int    i;
    int    tam;

    tam = strlen(string);

    for (i = tam - 1; i >= 0; i--) {
        printf("%c", string[i]);
    }
}

