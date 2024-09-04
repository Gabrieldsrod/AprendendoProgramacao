// Escreva um programa que leia uma matriz de ordem 3 de números
// inteiros e mostre a matriz. Na sequência calcule e mostre:
// a) a soma dos elementos pares da matriz;
// b) a média de todos os elementos da matriz;
// c) a quantidade de elementos ímpares da matriz.

#include<stdio.h>

int main(){
    int matriz[3][3];
    int i, j;
    int somapar = 0, contimpar = 0, somatotal = 0;
    int aux, conttotal = 3 * 3;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf("Elemento [%i][%i]: ", i + 1, j + 1);
            scanf("%i", &matriz[i][j]);
        }
    }

    printf("\nMatriz digitada:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%5i", matriz[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            aux = matriz[i][j];
            somatotal += aux;
            if (aux % 2 == 0){
                somapar += aux;
            } else{
                contimpar++;
            }
        }
    }

    float media = (float)somatotal / conttotal;

    printf("\nSoma dos elementos pares: %i\n", somapar);
    printf("Media total dos elementos: %.2f\n", media);
    printf("Quantidade de elementos impares: %i\n", contimpar);
}