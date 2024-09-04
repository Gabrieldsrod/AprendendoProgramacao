// Crie um programa que recebe primeiramente um sobrenome e depois o
// nome de uma pessoa, ou seja, receba em diferentes cadeias de strings.
// Mostre o nome e sobrenome concatenando os nomes digitados. Retorne
// também a quantidade de caracteres dessa string formada pelo nome
// completo. 

#include<stdio.h>
#include<string.h>

int main(){
    char sobrenome[100];
    char nome[100];
    int tamanho = 0;

    printf("Digite seu sobrenome: ");
    gets(sobrenome);

    printf("Digite seu nome: ");
    gets(nome);

    tamanho = strlen(sobrenome) + strlen(nome);

    strcat(nome,sobrenome);

    printf("%s\n", nome);
    printf("Numero de caracteres: %i", tamanho);
}