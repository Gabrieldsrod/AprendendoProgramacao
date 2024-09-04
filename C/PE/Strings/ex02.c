// Melhore o programa, armazenando a nova seqüência em um string auxiliar.

#include <stdio.h>
#include <string.h>

void inverte_string  (char string[99], char auxiliar[99]);

int main() {
    char str[99];
    char aux[99];

    printf("Digite uma string: ");
    gets(str);


    inverte_string(str, aux);

    printf("String Invertida: %s\n", aux);

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