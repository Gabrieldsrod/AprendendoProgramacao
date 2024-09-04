// 11. Crie um programa capaz de chamar uma função que transforma todos os
// caracteres de uma string em minúsculos. 

#include<stdio.h>
#include<ctype.h>

void transforma_minusculo(char string[]) {
    for (int i = 0; string[i] != '\0'; i++) {
        string[i] = tolower(string[i]);
    }
}

int main() {
    char str[100];

    printf("Digite uma string: ");
    gets(str);

    transforma_minusculo(str);

    printf("String em minusculos: %s\n", str);
}
