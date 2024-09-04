// Faça um programa que, dado um string qualquer, procure dentro dele a ocorrência de outro string.
// Exemplo: String: Facens – Computação Procurar pelo string: put
// Resultado: O string put foi encontrado.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encontrar_string(char string[99], char substring[99]);

int main()
{
    char    str[99];
    char    localizar[99];


    printf("\nDigite qualquer coisa: ");
    gets(str);

    printf("\nDigite um caracter para averiguar sua presenca na string: ");
    gets(localizar);

    encontrar_string(str, localizar);
    return 0;
}

void encontrar_string(char string[99], char substring[99])
{
    int tam_str, tam_substr;
    int     found = 0;
    
    tam_str = strlen(string);
    tam_substr = strlen(substring);

    for (int i = 0; i <= tam_str - tam_substr; i++) {
        int j;


        for (j = 0; j < tam_substr; j++) {
            if (string[i + j] != substring[j]) {
                break;
            }
        }


        if (j == tam_substr) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("O string \"%s\" foi encontrado.\n", substring);
    } else {
        printf("O string \"%s\" nao foi encontrado.\n", substring);
    }
}
