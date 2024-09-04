// Dada uma matriz 7x7 de valores inteiros, elabore um programa que faça a
// leitura destes valores e ao final da leitura encontre a sua matriz transposta
// e a escreva. Obs.: Matriz transposta, em matemática, é o resultado da
// troca de linhas por colunas em uma determinada matriz.

#include<stdio.h>

int main(){
    int original[7][7], transposta[7][7];
    int i, j;

    for (i = 0; i < 7; i++){
        for (j = 0; j < 7; j++){
            printf("Elemento [%i][%i]: ", i + 1, j + 1);
            scanf("%i", &original[i][j]);
        }
    }


    for (i = 0; i < 7; i++){
        for (j = 0; j < 7; j++){
            transposta[j][i] = original[i][j];
        }
    }

    printf("\nMatriz ORIGINAL:\n");
    for (i = 0; i < 7; i++){
        for (j = 0; j < 7; j++){
            printf("%5i", original[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatriz TRANSPOSTA:\n");
    for (i = 0; i < 7; i++){
        for (j = 0; j < 7; j++){
            printf("%5i", transposta[i][j]);
        }
        printf("\n");
    }
}


