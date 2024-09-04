// 8. Crie uma função capaz de multiplicar uma linha de uma matriz por um
// dado número. Faça o mesmo para uma coluna. Utilize uma matriz com 4
// linhas e 4 colunas.

#include<stdio.h>

void multiplicar_linha(int matriz[4][4], int linha, int numero) {
    for (int i = 0; i < 4; i++) {
        matriz[linha][i] *= numero;
    }
}

void multiplicar_coluna(int matriz[4][4], int coluna, int numero) {
    for (int i = 0; i < 4; i++) {
        matriz[i][coluna] *= numero;
    }
}

void imprimir_matriz(int matriz[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[4][4];
    int linha, coluna, numero;

    printf("Digite os elementos da matriz: \n");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Elemento [%i][%i]: ", i + 1, j + 1);
            scanf("%i", &matriz[i][j]);
        }
    }
    
    printf("Matriz original:\n");
    imprimir_matriz(matriz);

    printf("Digite o numero da linha (0 a 3) que deseja multiplicar: ");
    scanf("%d", &linha);
    printf("Digite o numero pelo qual deseja multiplicar a linha: ");
    scanf("%d", &numero);

    multiplicar_linha(matriz, linha, numero);

    printf("\n")
    printf("Matriz apos multiplicar a linha %d pelo número %d:\n", linha, numero);
    imprimir_matriz(matriz);

    printf("Digite o numero da coluna (0 a 3) que deseja multiplicar: ");
    scanf("%d", &coluna);
    printf("Digite o numero pelo qual deseja multiplicar a coluna: ");
    scanf("%d", &numero);

    multiplicar_coluna(matriz, coluna, numero);

    printf("\n");
    printf("Matriz apos multiplicar a coluna %d pelo número %d:\n", coluna, numero);
    imprimir_matriz(matriz);
}
