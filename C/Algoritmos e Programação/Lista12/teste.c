#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char str_invertida[100];
    int len, i;

    // Leitura da string pelo usuário
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remover o '\n' do final da string lida por fgets
    str[strcspn(str, "\n")] = '\0';

    len = strlen(str);

    // Invertendo a string e armazenando na nova string
    for(i = 0; i < len; i++) {
        str_invertida[i] = str[len - 1 - i];
    }

    // Adicionando o caractere de fim de string
    str_invertida[len] = '\0';

    // Mostrando a string invertida
    printf("String invertida: %s\n", str_invertida);

    return 0;
}
