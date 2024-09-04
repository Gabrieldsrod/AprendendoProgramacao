// Escreva um programa que leia uma matriz 4x5 de números reais e a
// exiba. Leia a seguir um número e verifique se esse número lido está ou
// não na matriz. Se estiver, escrever uma mensagem dizendo que o
// número está na matriz e em quais posições (linha e coluna) da matriz ele
// se encontra.

#include<stdio.h>

int main(){
    float matriz[4][5];
    float numero;
    int encontrado = 0;
    int i, j;

    printf("Digite os valores da matriz 4x5:\n");
    for(i = 0; i < 4; i++){
        for (j = 0; j < 5; j++){
            printf("Valor [%i][%i]: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
        }
    }

    printf("\nQual valor deseja verificar na matriz?\n");
    scanf("%f", &numero);
    printf("\n");

    for(i = 0; i < 4; i++){
        for (j = 0; j < 5; j++){
            if (matriz[i][j] == numero){
                printf("O numero %.2f foi encontrado na posicao [%i][%i] da matriz.\n", numero, i+1, j+1);
                encontrado = 1;
            }
        }
    }

    if (!encontrado){
        printf("O numero %.2f nao foi encontrado na matriz.", numero);
    }   
}