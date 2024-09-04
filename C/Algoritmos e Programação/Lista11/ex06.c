// Escreva um programa que receba um conjunto de caracteres e mostre o
// seu inverso. Exemplo: texto recebido = matriz, texto inverso = zirtam. 

#include<stdio.h>
#include<string.h>

int main() {
    char palavra[100];
    int tamanho, i;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    tamanho = strlen(palavra);

    printf("Texto inverso: ");

    for(i = tamanho - 1; i >= 0; i--) {
        printf("%c", palavra[i]);
    }
}