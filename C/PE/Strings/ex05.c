// Faça um programa que, dado um string qualquer, procure dentro dele a ocorrência de um determinado
// caracter. Exemplo: String: Facens – Computação Procurar pela letra: x
// Resultado: O caracter x não foi encontrado.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encontrar_caracter(char string[99], char caractere);
int main()
{
    char    str[99];
    char    caracter;

    printf("\nDigite qualquer coisa: ");
    gets(str);

    printf("\nDigite um caracter para averiguar sua presenca na string: ");
    scanf("%c", &caracter);

    encontrar_caracter(str, caracter);
    return 0;
}

void encontrar_caracter(char string[99], char caracter)
{
    int tamanho, i;

    tamanho = strlen(string);

    for (i = 0; i < tamanho; i++)
    {
        string[i] = tolower(string[i]);
    }
    
    for (i = 0; string[i] != '\0' ; i++)
    {
        if (string[i] == caracter)
        {
            printf("O caracter %c foi encontrado.", caracter);
            return;
        }
    }
    printf("O caracter %c nao foi encontrado.", caracter);
}