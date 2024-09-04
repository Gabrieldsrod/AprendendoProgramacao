// Receba uma frase e uma letra do usuário, conte quantas ocorrências da letra existem na frase.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void contar_ocorrencias(char string[99], char caractere);
int main()
{
    char    str[99];
    char    caracter;

    printf("\nDigite qualquer coisa: ");
    gets(str);

    printf("\nDigite um caracter para averiguar sua presenca na string: ");
    scanf("%c", &caracter);

    contar_ocorrencias(str, caracter);
    return 0;
}

void contar_ocorrencias(char string[99], char caracter)
{
    int tamanho, i;
        int count = 0;

    tamanho = strlen(string);

    for (i = 0; i < tamanho; i++)
    {
        string[i] = tolower(string[i]);
    }

    for (int i = 0; string[i] != '\0' ; i++)
    {
        if (string[i] == caracter)
        {
            count++;
        } 
    }

    if (count == 0)
    {
        printf("O caractere %c nao foi encontrado.", caracter);
    } else
    {
        printf("O caracter %c ocorre %i vezes na string", caracter, count);
    }
}
