// Leia uma matriz numérica quadrada 5x5 e calcule a soma dos elementos
// que:
// a) estão logo acima da diagonal principal;
// b) estão logo abaixo da diagonal principal;
// c) estão acima da diagonal principal;
// d) estão abaixo da diagonal principal.

#include<stdio.h>

int main(){
    int matriz[5][5];
    int soma_acima = 0, soma_abaixo = 0, soma_logo_acima = 0, soma_logo_abaixo = 0;
    int i, j;

    printf("Digite os valores da matriz 5x5:\n");
    for (i = 0;i < 5; i++){
        for (j = 0; j < 5; j++){
            printf("Elemento [%i][%i]: ", i + 1, j + 1);
            scanf("%i", &matriz[i][j]);
        }
    }

    for (i = 0;i < 5; i++){
        for (j = 0; j < 5; j++){
            if (i == j - 1) {
                // Elementos logo acima da diagonal principal
                soma_logo_acima += matriz[i][j];
            } 
            else if (i == j + 1) {
                // Elementos logo abaixo da diagonal principal
                soma_logo_abaixo += matriz[i][j];
            }
            if (j > i) {
                // Elementos acima da diagonal principal
                soma_acima += matriz[i][j];
            } 
            else if (j < i) {
                // Elementos abaixo da diagonal principal
                soma_abaixo += matriz[i][j];
            }
        }
    }
    
    printf("\nMatriz:\n");
    for (i = 0;i < 5; i++){
        for (j = 0; j < 5; j++){
            printf("%4i ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nSoma dos elementos logo acima da diagonal principal: %d\n", soma_logo_acima);
    printf("Soma dos elementos logo abaixo da diagonal principal: %d\n", soma_logo_abaixo);
    printf("Soma dos elementos acima da diagonal principal: %d\n", soma_acima);
    printf("Soma dos elementos abaixo da diagonal principal: %d\n", soma_abaixo);

}