// 6. Faça um programa que leia um vetor de 10 posições de números reais e
// chame uma função para encontrar e retornar o maior valor do vetor, a
// seguir divida todos os elementos do vetor pelo maior valor encontrado.
// Mostre o vetor após os cálculos.

#include<stdio.h>

float encontrar_maior(float vetor[], int tamanho) {
    float maior = vetor[0];

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }

    return maior;
}

void dividir_por_maior(float vetor[],int tamanho, float maior) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] /= maior;
    }   
}

int main() {
    float vetor[10];
    float maior;

    printf("Digite 10 numeros reais: \n");
    for (int i = 0; i < 10; i++) {
        scanf("%f", &vetor[i]);
    }
    
    maior = encontrar_maior(vetor, 10);

    dividir_por_maior(vetor, 10, maior);

    printf("Vetor apos a divisao pelo maior valor:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%6.2f", vetor[i]);
    }
    printf("\n");
}    