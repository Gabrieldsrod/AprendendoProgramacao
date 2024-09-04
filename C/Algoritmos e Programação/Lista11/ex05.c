// Elabore um programa que recebe um caractere e um número inteiro n
// menor ou igual a 20. Declare e inicialize uma string com n caracteres
// iguais ao caractere digitado.
// Exemplo:
// Caracter: a
// Número (n): 3
// Saída: aaa

#include<stdio.h>
#include<string.h>

int main() {
    char caractere;
    int num;
    char string[21];
    int i;

    do
    {
        printf("Caracter: ");
        scanf("%c", &caractere);

        printf("Numero (n): ");
        scanf("%i", &num);

        if (num <= 20) {
            for(i = 0; i < num; i++){
                string[i] = caractere;
            }
            string[num] = '\0';

            printf("Saida: %s", string); 
        } else {
            printf("O numero deve ser menor ou igual a 20!\n");
        }
    } while (num < 1 || num > 20);
}