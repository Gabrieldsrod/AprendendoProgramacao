#include <stdio.h>
#include <stdlib.h>

// Função para alocar dinamicamente a lista de números inseridos
int* alocar_lista(int tamanho) {
    return (int*)malloc(tamanho * sizeof(int));
}

// Função para somar os números e alocar nas listas de pares e ímpares
void alocar_par_impar(int* numeros, int tamanho, int** pares, int* tamanho_pares, int** impares, int* tamanho_impares) {
    int inicio = 0, fim = tamanho - 1;
    
    while (inicio <= fim) {
        int soma = numeros[inicio] + numeros[fim];
        
        if (soma % 2 == 0) {
            *pares = (int*)realloc(*pares, (*tamanho_pares + 1) * sizeof(int));
            (*pares)[*tamanho_pares] = soma;
            (*tamanho_pares)++;
        } else {
            *impares = (int*)realloc(*impares, (*tamanho_impares + 1) * sizeof(int));
            (*impares)[*tamanho_impares] = soma;
            (*tamanho_impares)++;
        }
        inicio++;
        fim--;
    }
}

// Função para imprimir uma lista
void imprimir_lista(int* lista, int tamanho, const char* tipo) {
    printf("%s:\n", tipo);
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    int* numeros = NULL;
    int tamanho = 0;
    int entrada;

    // Ler números do usuário até que ele digite -1
    do {
        printf("Digite um número (-10 para parar): ");
        scanf("%d", &entrada);

        if (entrada != -10) {
            numeros = (int*)realloc(numeros, (tamanho + 1) * sizeof(int));
            numeros[tamanho] = entrada;
            tamanho++;
        }
    } while (entrada != -10);

    // Verificar se o usuário inseriu números
    if (tamanho == 0) {
        printf("Nenhum número foi inserido.\n");
        return 0;
    }

    // Listas para armazenar somas pares e ímpares
    int* pares = NULL;
    int tamanho_pares = 0;
    int* impares = NULL;
    int tamanho_impares = 0;

    // Alocar somas nas listas corretas
    alocar_par_impar(numeros, tamanho, &pares, &tamanho_pares, &impares, &tamanho_impares);

    // Imprimir as listas de pares e ímpares
    imprimir_lista(pares, tamanho_pares, "PAR");
    imprimir_lista(impares, tamanho_impares, "ÍMPAR");

    // Liberar memória alocada
    free(numeros);
    free(pares);
    free(impares);

    return 0;
}
