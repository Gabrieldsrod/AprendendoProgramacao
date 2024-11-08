//ex10 lista 7

// Receber 10 números e armazená-los em um vetor. Copiar os números
// em outro vetor na ordem inversa e mostrar na tela todas as posições em que
// se tem o mesmo número nos dois vetores.

#include <stdio.h>

int main() // Função principal do programa
{
    int vetor[10], invetor[10]; // Declaração de dois vetores de inteiros com 10 posições cada
    int i; // Declaração de uma variável inteira para uso nos loops

    printf("Digite 10 numeros:\n"); // Solicita ao usuário que digite 10 números
    
    // Leitura dos 10 números e armazenamento no vetor original
    for (i = 0; i < 10; i++) // Loop que vai de 0 a 9 (10 iterações)
    {
        scanf("%i", &vetor[i]); // Lê um número do usuário e armazena na posição i do vetor
    }

    // Copia os números do vetor original para o vetor invertido na ordem inversa
    for (i = 0; i < 10; i++) // Loop que vai de 0 a 9 (10 iterações)
    {
        invetor[i] = vetor[9 - i]; // Copia o valor da posição inversa do vetor original para o vetor invertido
    } // Exemplo: invetor[0] recebe vetor[9], invetor[1] recebe vetor[8], e assim por diante

    // Exibe o vetor original
    printf("\nVetor original:\n"); // Imprime uma mensagem indicando que o vetor original será exibido
    for (i = 0; i < 10; i++) // Loop que vai de 0 a 9 (10 iterações)
    {
        printf("%i\t", vetor[i]); // Imprime o valor da posição i do vetor original seguido de uma tabulação
    }
    printf("\n"); // Imprime uma nova linha

    // Exibe o vetor invertido
    printf("Vetor invertido:\n"); // Imprime uma mensagem indicando que o vetor invertido será exibido
    for (i = 0; i < 10; i++) // Loop que vai de 0 a 9 (10 iterações)
    {
        printf("%i\t", invetor[i]); // Imprime o valor da posição i do vetor invertido seguido de uma tabulação
    }
    printf("\n"); // Imprime uma nova linha

    // Verifica e exibe as posições onde os números são iguais nos dois vetores
    printf("\nPosicoes com o mesmo numero nos dois vetores\n"); // Imprime uma mensagem indicando que as posições com números iguais serão exibidas
    printf("Posicoes: "); // Imprime a palavra "Posicoes: "

    for (i = 0; i < 10; i++) { // Loop que vai de 0 a 9 (10 iterações)
        if (vetor[i] == invetor[i]) // Verifica se o valor na posição i do vetor original é igual ao valor na posição i do vetor invertido
        {
            printf("%d ", i); // Se forem iguais, imprime a posição i
        }
    }

    return 0; // Indica que o programa terminou com sucesso
}