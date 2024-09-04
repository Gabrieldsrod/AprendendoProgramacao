// 9. Crie uma função capaz de somar os elementos das linhas L1 e L2 de uma
// matriz. O resultado deve ser colocado na linha L2. Faça o mesmo com a
// multiplicação. A matriz deverá conter 2 linhas e 6 colunas. 

#include<stdio.h>

void soma_linhas(int matriz[2][6]) {
    for (int i = 0; i < 6; i++) {
        matriz[1][i] += matriz[0][i];
    }
}

void multiplicar_linhas(int matriz[2][6]) {
    for (int i = 0; i < 6; i++) {
        matriz[1][i] *= matriz[0][i];
    }
}

void imprimir_matriz(int matriz[2][6]) {
    for (int i = 0; i < 2; i++) {
        for(int j = 0; j < 6; j++)
        {
            printf("%5i", matriz[i][j]);
        }
        printf("\n");
    }
}

void copiar_matriz(int origem[2][6], int destino[2][6]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            destino[i][j] = origem[i][j];
        }
    }
}

int main() {
    int matriz[2][6];
    int copia_matriz[2][6];

    printf("Digite os elementos da matriz[2][6]:\n");
    for (int i = 0; i < 2; i++) {
        for(int j = 0; j < 6; j++) {
            printf("Elemento [%i][%i]: ", i + 1, j + 1);
            scanf("%i", &matriz[i][j]);
        }
    }
    copiar_matriz(matriz, copia_matriz);
    
    printf("Matriz Original:\n");
    imprimir_matriz(matriz);

    soma_linhas(matriz);
    printf("\nMatriz somando L1 em L2:\n");
    imprimir_matriz(matriz);

    multiplicar_linhas(copia_matriz);
    printf("\nMatriz multiplicando L1 em L2:\n");
    imprimir_matriz(copia_matriz);
    printf("\n");
}