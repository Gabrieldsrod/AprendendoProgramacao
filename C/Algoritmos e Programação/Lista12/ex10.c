// 10. Escreva um programa que leia uma matriz de ordem 5x5 de números
// reais e chama uma função que mostre a matriz. A seguir calcule e mostre:
// a) a soma dos elementos da primeira coluna;
// b) a soma dos elementos da terceira linha da matriz. 

#include<stdio.h>

void imprimir_matriz(float matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++)
        {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }
}

float soma_primeira_coluna(float matriz[5][5]) {
    float soma = 0;
    for (int i = 0; i < 5; i++) {
        soma += matriz[i][0];
    }

    return soma;
}

float soma_terceira_linha(float matriz[5][5]) {
    float soma = 0;
    for (int j = 0; j < 5; j++) {
        soma += matriz[2][j];
    }
    
    return soma;
}

int main() {
    float matriz[5][5];
    float soma_coluna, soma_linha;

    printf("Digite os elementos da matriz[5][5]:\n");
    for (int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("Elemento [%i][%i]: ", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        }
    }

    printf("Matriz 5x5:\n");
    imprimir_matriz(matriz);

    soma_coluna = soma_primeira_coluna(matriz);
    printf("Soma dos elementos da primeira coluna: %.2f\n", soma_coluna);

    soma_linha = soma_terceira_linha(matriz);
    printf("Soma dos elementos da terceira linha: %.2f\n", soma_linha);
}