// Os números, como as letras, também são símbolos e um número
// palíndromo é aquele que é igual quando lido nos dois sentidos (da esquerda
// para a direita ou da direita para a esquerda), como por exemplo, 14541,7117
// e 3333. Receba um número (pergunte o tamanho do número e então receba
// cada parte dele) e informe se ele é ou não palíndromo.

#include <stdio.h>

int main() {
    int tamanho, i, palindromo = 1;

    // Passo 1: Solicitar o tamanho do número
    printf("Digite o tamanho do numero: ");
    scanf("%d", &tamanho);

    int numero[tamanho];

    // Passo 2: Receber cada dígito do número e armazená-los em um vetor
    printf("Digite os digitos do numero:\n");
    for (i = 0; i < tamanho; i++) {
        printf("Digito %d: ", i + 1);
        scanf("%d", &numero[i]);
    }

    // Passo 3: Verificar se o número é um palíndromo
    for (i = 0; i < tamanho / 2; i++) {
        if (numero[i] != numero[tamanho - 1 - i]) {
            palindromo = 0;
            break;
        }
    }

    // Passo 4: Informar ao usuário se o número é ou não um palíndromo
    if (palindromo) {
        printf("O numero e um palindromo.\n");
    } else {
        printf("O numero nao e um palindromo.\n");
    }

    return 0;
}