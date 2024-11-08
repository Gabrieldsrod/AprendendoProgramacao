// ex9 lista 7

// Receber 10 números e armazená-los em um vetor. Após esta primeira
// etapa é necessário pedir para o usuário digitar um número. Verificar se este
// número está armazenado no vetor e se estiver mostrar quantas vezes o
// número esta armazenado no vetor, ou seja, quantas vezes o número se
// repete. Se o número não estiver no vetor, uma mensagem deve indicar esta
// condição e deverá ser solicitado um novo número para o usuário.


#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída

/**
 * Um vetor (ou array) é uma estrutura de dados que armazena uma coleção de elementos do mesmo tipo em uma sequência contígua de memória.
 * 
 * Características principais de um vetor:
 * - Tamanho fixo: O tamanho do vetor é definido no momento da sua criação e não pode ser alterado.
 * - Acesso direto: Os elementos do vetor podem ser acessados diretamente pelo índice , o que permite operações de leitura e escrita rápidas.
 * - Índice baseado em zero: O primeiro elemento do vetor está no índice 0, o segundo no índice 1, e assim por diante.
 * 
 * Operações comuns em um vetor:
 * - Inicialização: Definir o tamanho do vetor e, opcionalmente, inicializar seus elementos.
 * - Acesso: Ler ou modificar o valor de um elemento específico usando seu índice.
 * - Iteração: Percorrer todos os elementos do vetor, geralmente usando um loop.
 * 
 * Exemplo de uso:
 * int vetor[5]; // Declaração de um vetor de inteiros com 5 elementos
 * vetor[0] = 10; // Atribuição de valor ao primeiro elemento
 * int valor = vetor[2]; // Leitura do valor do terceiro elemento, atribuindo a uma variável
 */

int main() // Função principal do programa
{
    int vetor[10]; // Declara um vetor de 10 inteiros
    int num, i, cont = 0; // Declara variáveis inteiras para o número, índice e contador

    printf("Digite 10 numeros:\n"); // Solicita ao usuário que digite 10 números

    for (i = 0; i < 10; i++) // Loop para ler os 10 números
    {
        scanf("%i", &vetor[i]); // Lê um número e armazena no vetor
    }

    do // Loop do-while para garantir que o usuário digite um número presente no vetor
    {
        printf("\nDigite um numero para verificar se ele se encontra no vetor: "); // Solicita ao usuário que digite um número para verificar
        scanf("%i", &num); // Lê o número digitado pelo usuário

        for (i = 0; i < 10; i++) // Loop para verificar se o número está no vetor
        {
            if(vetor[i] == num) // Se o número no vetor for igual ao número digitado
            {
                cont++; // Incrementa o contador
            }
        }

        if (cont > 0) // Se o contador for maior que zero, o número está no vetor
        {
            printf("O numero %i esta presente %i vezes no vetor.", num, cont); // Exibe quantas vezes o número está presente no vetor
        }
        else // Se o contador for zero, o número não está no vetor
        {
            printf("\nO numero %i nao se encontra no vetor.\nDigite outro...\n", num); // Informa ao usuário que o número não está no vetor e solicita outro número
        }
        
    } while (cont == 0); // Repete o loop enquanto o número não estiver no vetor
}
