//ex11 lista 7

// Os números, como as letras, também são símbolos e um número
// palíndromo é aquele que é igual quando lido nos dois sentidos (da esquerda
// para a direita ou da direita para a esquerda), como por exemplo, 14541,7117
// e 3333. Receba um número (pergunte o tamanho do número e então receba
// cada parte dele) e informe se ele é ou não palíndromo.

#include <stdio.h>

int main() {
    int tamanho, i, palindromo = 1; // Declara variáveis: tamanho do número, índice do loop e condição de verdadeiro ou falso (1 e 0 respectivamente) para verificar se é palíndromo

    // Passo 1: Solicitar o tamanho do número
    printf("Digite o tamanho do numero: ");
    scanf("%d", &tamanho); // Lê o tamanho do número digitado pelo usuário

    int numero[tamanho]; // Declara um vetor para armazenar os dígitos do número

    // Passo 2: Receber cada dígito do número e armazená-los em um vetor
    printf("Digite os digitos do numero:\n");
    for (i = 0; i < tamanho; i++) { // Loop para ler cada dígito do número
        printf("Digito %d: ", i + 1); // Solicita o dígito ao usuário
        scanf("%d", &numero[i]); // Armazena o dígito no vetor
    }

    // Passo 3: Verificar se o número é um palíndromo
    for (i = 0; i < tamanho / 2; i++) { // Loop até a metade do vetor
        if (numero[i] != numero[tamanho - 1 - i]) { // Compara os dígitos simetricamente
            palindromo = 0; // Se algum dígito não for igual ao seu simétrico, não é palíndromo
            break; // Sai do loop se encontrar uma diferença
        }
    }

    // Passo 4: Informar ao usuário se o número é ou não um palíndromo
    if (palindromo) { // Se a condição palindromo ainda for 1, é um palíndromo
        printf("O numero e um palindromo.\n");
    } else { // Caso contrário, não é um palíndromo
        printf("O numero nao e um palindromo.\n");
    }

    return 0; // Indica que o programa terminou com sucesso
}