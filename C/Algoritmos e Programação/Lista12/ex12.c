// 12. Escreva um programa que possua uma função capaz de inserir um dado
// caractere em uma posição da string, a qual também é determinada pelo
// usuário. Portanto, a função deve receber três parâmetros: string,
// caractere e posição.
#include<stdio.h>
#include<string.h>

void inserir_caractere(char str[], char caractere, int posicao) {
    int tamanho = strlen(str);

    // Verifica se a posição é válida
    if (posicao < 0 || posicao > tamanho) {
        printf("Posição inválida!\n");
        return;
    }

    // Move os caracteres para a direita para abrir espaço para o novo caractere
    for (int i = tamanho; i >= posicao; i--) {
        str[i + 1] = str[i];
    }

    // Insere o caractere na posição especificada
    str[posicao] = caractere;
}

int main() {
    char str[100];
    char caractere;
    int posicao;

    // Leitura da string pelo usuário
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remover o newline ao final da string
    str[strcspn(str, "\n")] = '\0';

    // Leitura do caractere a ser inserido
    printf("Digite o caractere a ser inserido: ");
    scanf(" %c", &caractere);

    // Leitura da posição de inserção
    printf("Digite a posição onde o caractere deve ser inserido: ");
    scanf("%d", &posicao);

    // Chama a função para inserir o caractere na posição especificada
    inserir_caractere(str, caractere, posicao);

    // Imprime a string resultante
    printf("String após a inserção: %s\n", str);

    return 0;
}