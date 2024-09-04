//  Faça um programa que converta todas as letras de uma string em letras
// maiúsculas. Para desenvolver o programa pode-se utilizar uma das
// seguintes estratégias: 
// 1) fazer uso das funções toupper(char) e tolower(char) 
// 2) utilizar a tabela ASCII, onde a diferença entre o valor
// do mesmo caractere em sua forma maiúscula e minúscula possui a
// diferença de 32. Exemplo: A=65, Z=90 e a=97, z=122.

// 1)
#include <stdio.h>
#include <ctype.h>

int main() {
    char string[100];
    int i;

    printf("Digite uma string: ");
    scanf("%s", string);

    for (i = 0; string[i] != '\0'; i++) {
        string[i] = toupper(string[i]);
    }

    printf("String convertida para maiusculas: %s\n", string);

    return 0;
}

// 2)
// #include <stdio.h>

// int main() {
//     char string[100];
//     int i;

//     printf("Digite uma string: ");
//     scanf("%s", string);

//     for (i = 0; string[i] != '\0'; i++) {
//         if (string[i] >= 'a' && string[i] <= 'z') {
//             string[i] = string[i] - 32;
//         }
//     }

//     printf("String convertida para maiusculas: %s\n", string);

// }


