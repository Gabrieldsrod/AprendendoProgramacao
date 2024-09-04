// Faça um programa que, dado um string qualquer, inverta e armazene todas as suas letras sem auxílio
// de uma string auxiliar, ou seja, utilizando a mesma string. Apresente isso ao usuário

#include <stdio.h>
#include <string.h>

void inverte_string (char str[99]);

int main()
{
    char string[99];
    char auxiliar[99];

    printf("Digite uma string: ");
    gets(string);

    inverte_string(string, auxiliar);

}

void inverte_string (char str[99], aux[99]);
{
    int i;
    int tam;

    tam = strlen(str);

    for (int i = 0; i < tam; i++)
    {
        str[i] = str[tamanho - i - 1];
    }

    str[tam] = '\0';
    
}
