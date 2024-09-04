// Melhore o programa, trocando as maiúsculas por minúsculas e vice-versa, quando necessário.
// Exemplo - Resultado: Snecaf Ad Sonula
// • Será necessário utilizar as funções toupper(char) e tolower(char), que transformam um caracter
// para maiúscula e minúscula respectivamente, ou
// • Utilizar os valores da tabela ASCII: A = 65, Z = 90 a = 97, z = 122, portanto para passar de
// MAIÚSCULA para minúscula basta somar 32 e o inverso, subtrair 32.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void inverte_string  (char string[99], char auxiliar[99]);
void troca_maiuscula_minuscula (char string[99]);
void capitalizar_primeira_letra(char string[99]);

int main() {
    char str[99];
    char aux[99];

    printf("Digite uma string: ");
    gets(str);


    inverte_string(str, aux);

    capitalizar_primeira_letra(aux);

    return 0;
}

void inverte_string(char string[99], char auxiliar[99]) {
    int i, j;
    int tam;

    tam = strlen(string);

    for (i = tam - 1, j = 0; i >= 0; i--, j++) {
        auxiliar[j] = string[i];
    }
    auxiliar[j] = '\0';
}

void capitalizar_primeira_letra(char string[99]) {
    int i;
    int tam;

    tam = strlen(string);

    for (i = 0; i < tam; i++)
    {
        string[i] = tolower(string[i]);
    }
    
    // Capitalize the first letter of the string
    if (islower(string[0])) {
        string[0] = toupper(string[0]);
    }

    // Capitalize the first letter of every word
    for (i = 1; i < tam; i++) {
        if (isspace(string[i - 1]) && islower(string[i])) {
            string[i] = toupper(string[i]);
        }
    }

    printf("String com a a primeira letra de cada palavra sendo maiuscula: %s\n", string);
}
// if (string[i] )